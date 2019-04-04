#include "MainMenuScene.h"
#include "GameScene.h"
USING_NS_CC;
int xMid, yMid;
Scene* MainMenuScene::createScene()
{
	auto scene = Scene::create();//create Scene
	auto layer = MainMenuScene::create();//Create Layer
	scene->addChild(layer);//Layer is a child of Scene
	return scene;
}
bool MainMenuScene::init()
{
	if (!Layer::init())
	{
		return false;
	}
	Vec2 origin = Director::getInstance()->getVisibleOrigin();
	Vec2 visibleSize = Director::getInstance()->getVisibleSize();
	xMid = origin.x + visibleSize.x / 2;
	yMid = origin.y + visibleSize.y / 2;
	//color
	auto background = LayerColor::create(Color4B(255, 0, 0, 255));
	background->setVisible(true);
	this->addChild(background);
	//create label "2048-game"
	auto gameName = Label::createWithTTF("2048", "fonts/Marker Felt.ttf", 50);
	gameName->setPosition(Vec2(xMid, yMid + 150));//set position for name
	gameName->enableShadow(Color4B::RED);//shadow Effect
	this->addChild(gameName, 1);
	
	createButton();
	return true;
}
void MainMenuScene::menuCloseCallBack(Ref* psender)
{
	CCLOG("MenuCallBack Clicked");
	//Director::getInstance()->replaceScene(GameScene::createScene());
}
void createSpriteSheet()
{
	SpriteFrameCache::getInstance()->addSpriteFramesWithFile("2048-game.plist");//load sprite-sheet from .plist file
}
void MainMenuScene::createButton()
{
	//create play button
	auto btn_play = Button::create();
	//create label for button
	auto lbl_play = Label::createWithTTF("Play Game", "fonts/Marker Felt.ttf", 30);
	btn_play->setTitleLabel(lbl_play);
	btn_play->setPosition(Vec2(xMid, yMid + 80));
	btn_play->addTouchEventListener([&](Ref* sender, Widget::TouchEventType type)
	{
		switch (type)
		{
		case cocos2d::ui::Widget::TouchEventType::BEGAN:
			break;
		case cocos2d::ui::Widget::TouchEventType::MOVED:
			break;
		case cocos2d::ui::Widget::TouchEventType::ENDED:
			Director::getInstance()->replaceScene(GameScene::createScene());
			break;
		case cocos2d::ui::Widget::TouchEventType::CANCELED:
			break;
		default:
			break;
		}
	});
	this->addChild(btn_play);
	//create how to play button
	auto btn_help = Button::create();
	//create label for button
	auto lbl_help = Label::createWithTTF("How To Play", "fonts/Marker Felt.ttf", 30);
	btn_help->setTitleLabel(lbl_help);
	btn_help->setPosition(Vec2(xMid, yMid + 40));
	btn_help->addTouchEventListener([&](Ref* sender, Widget::TouchEventType type)
	{
		switch (type)
		{
		case cocos2d::ui::Widget::TouchEventType::BEGAN:
			break;
		case cocos2d::ui::Widget::TouchEventType::MOVED:
			break;
		case cocos2d::ui::Widget::TouchEventType::ENDED:
			break;
		case cocos2d::ui::Widget::TouchEventType::CANCELED:
			break;
		default:
			break;
		}
	});
	this->addChild(btn_help);
	//create exit button
	auto btn_exit = Button::create();
	//create name for button
	auto lbl_exit = Label::createWithTTF("Exit", "fonts/Marker Felt.ttf", 30);
	btn_exit->setTitleLabel(lbl_exit);
	btn_exit->setPosition(Vec2(xMid, yMid));
	btn_exit->addTouchEventListener([&](Ref* sender, Widget::TouchEventType type)
	{
		switch (type)
		{
		case cocos2d::ui::Widget::TouchEventType::BEGAN:
			break;
		case cocos2d::ui::Widget::TouchEventType::MOVED:
			break;
		case cocos2d::ui::Widget::TouchEventType::ENDED:
			break;
		case cocos2d::ui::Widget::TouchEventType::CANCELED:
			break;
		default:
			break;
		}
	});
	this->addChild(btn_exit);
}
//create Menu
//Vector<MenuItem*> menuItems;
//auto closeItem = MenuItemImage::create("CloseNormal.png", "CloseSelected.png",
//CC_CALLBACK_1(MainMenuScene::menuCloseCallBack, this));//create close Item
//menuItems.pushBack(closeItem);//add close Item in the array of Item
//auto menu = Menu::createWithArray(menuItems);//create menu with array of item
//this->addChild(menu, 1);//menu is a child of MainMenuScene