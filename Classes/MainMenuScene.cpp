#include "MainMenuScene.h"
#include "GameScene.h"
#include "Definitions.h"
#include "HelpScene.h"
#include "AboutScene.h"
USING_NS_CC;

Scene* MainMenuScene::createScene()
{
	auto scene = Scene::create();
	auto layer = MainMenuScene::create();
	//add layer to the scene
	scene->addChild(layer);
	return scene;
}


// on "init" you need to initialize your instance
bool MainMenuScene::init()
{
    if ( !Layer::init() )
    {
        return false;
    }

    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

	//create background
	auto background = Sprite::create("background.png");
	background->setPosition(Point(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));
	this->addChild(background);

	//create title
	auto lbl_title = Label::createWithTTF("2048", "fonts/Marker Felt.ttf", 50);
	lbl_title->setPosition(customSize(0.9));
	lbl_title->enableShadow(Color4B::BLUE);
	this->addChild(lbl_title, 1);
	//create button
	createButton();

    return true;
}
void MainMenuScene::createButton()
{
	//play item
	auto playItem = MenuItemImage::create("play-button.png", "play-button.png", CC_CALLBACK_1(MainMenuScene::goToGameScene, this));
	playItem->setPosition(customSize(0.7));

	//how to play item
	auto helpItem = MenuItemImage::create("how-to-play-button.png", "how-to-play-button.png", CC_CALLBACK_1(MainMenuScene::goToHelpScene, this));
	helpItem->setPosition(customSize(0.5));

	//contributors item
	auto aboutItem = MenuItemImage::create("contributors-button.png", "contributors-button.png", CC_CALLBACK_1(MainMenuScene::goToAboutScene, this));
	aboutItem->setPosition(customSize(0.3));

	//exit game item
	auto exitItem = MenuItemImage::create("exit-button.png", "exit-button.png", CC_CALLBACK_1(MainMenuScene::ExitGame, this));
	exitItem->setPosition(customSize(0.1));

	//create list of item
	auto menu = Menu::create(playItem, helpItem, aboutItem, exitItem, NULL);
	menu->setPosition(Point::ZERO);

	this->addChild(menu);//add menu to the scene
}
Vec2 MainMenuScene::customSize(double a)
{
	auto visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();
	return Vec2(visibleSize.width / 2 + origin.x, a * visibleSize.height + origin.y);
}
void MainMenuScene::goToGameScene(cocos2d::Ref *sender)
{
	auto scene = GameScene::createScene();
	Director::getInstance()->replaceScene(TransitionFade::create(TRANSITION_TIME, scene));
}
void MainMenuScene::goToHelpScene(cocos2d::Ref *sender)
{
	auto scene = HelpScene::createScene();
	Director::getInstance()->replaceScene(TransitionFade::create(TRANSITION_TIME, scene));
}
void MainMenuScene::goToAboutScene(cocos2d::Ref *sender)
{
	auto scene = AboutScene::createScene();
	Director::getInstance()->replaceScene(TransitionFade::create(TRANSITION_TIME, scene));
}
void MainMenuScene::ExitGame(cocos2d::Ref *sender)
{
	Director::getInstance()->end();
}
