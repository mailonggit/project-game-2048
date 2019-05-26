#include "MainMenuScene.h"
#include "GameScene.h"
#include "Definitions.h"
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
	int xMid = visibleSize.width / 2 + origin.x;
	int yMid = visibleSize.height / 2+ origin.y;
	//create background
	auto background = Sprite::create("menu-background.png");
	background->setPosition(Point(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));
	this->addChild(background);

	//create title
	auto Name = Label::createWithTTF("2048", "fonts/Marker Felt.ttf", 50);
	Name->setPosition(Vec2(xMid, yMid + 100));
	Name->enableShadow(Color4B::RED);
	this->addChild(Name, 1);

	//play item
	auto playItem = MenuItemImage::create("play-button.png", "play-button.png", CC_CALLBACK_1(MainMenuScene::goToGameScene, this));
	playItem->setPosition(Point(xMid, yMid));

	//create list of item
	auto menu = Menu::create(playItem, NULL);
	menu->setPosition(Point::ZERO);
	this->addChild(menu);//add menu to the scene


    return true;
}
void MainMenuScene::goToGameScene(cocos2d::Ref *sender)
{
	auto scene = GameScene::createScene();
	Director::getInstance()->replaceScene(TransitionFade::create(TRANSITION_TIME, scene));
}