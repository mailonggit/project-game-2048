#include "SplashScene.h"
#include "MainMenuScene.h"
#include "Definitions.h"
USING_NS_CC;

Scene* SplashScene::createScene()
{
	auto scene = Scene::create();
	auto layer = SplashScene::create();
	//add layer to the scene
	scene->addChild(layer);
	return scene;
}


// on "init" you need to initialize your instance
bool SplashScene::init()
{
    if ( !Layer::init() )
    {
        return false;
    }

    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

	//create loading bar
	auto loadingBar = LoadingBar::create("loading-bar.png");
	loadingBar->setDirection(LoadingBar::Direction::LEFT);
	loadingBar->setPosition(visibleSize / 2);
	loadingBar->setPercent(0);
	this->addChild(loadingBar);
	this->schedule([=](float delta)
	{
		float percent = loadingBar->getPercent();
		percent += cocos2d::RandomHelper::random_int(1, 5);
		loadingBar->setPercent(percent);
		if (percent > loadingBar->getContentSize().width)
		{
			this->unschedule("updateLoadingBar");
		}

	}, 0.1f, "updateLoadingBar");
	//run schedule
	this->schedule(schedule_selector(SplashScene::goToMainMenuScene), DISPLAY_TIME_SPLASH_SCENE);
    return true;
}
void SplashScene::goToMainMenuScene(float dt)
{
	auto scene = MainMenuScene::createScene();
	Director::getInstance()->replaceScene(TransitionFade::create(TRANSITION_TIME, scene));
}