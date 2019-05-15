#include "MainMenuScene.h"
#include "GameScene.h"
#include "EndScene.h"
USING_NS_CC;
int xMid, yMid;
Scene* MainMenuScene::createScene()
{
	auto scene = Scene::create();
	auto layer = MainMenuScene::create();
	scene->addChild(layer);
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
	auto background = LayerColor::create(Color4B(0, 0, 0, 255));
	background->setVisible(true);
	this->addChild(background);
	//create label "2048-game"
	auto Name = Label::createWithTTF("2048", "fonts/Marker Felt.ttf", 50);
	Name->setPosition(Vec2(xMid, yMid + 150));
	Name->enableShadow(Color4B::RED);
	this->addChild(Name, 1);

	createButton();
	return true;
}
void MainMenuScene::menuCloseCallBack(Ref* psender)
{
	CCLOG("MenuCallBack Clicked!");
	//Director::getInstance()->replaceScene
}
void MainMenuScene::createButton()
{
	//create play buton
	auto btn_play = Button::create("button-menuscene.png");
	//create label for play button
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
	auto btn_help = Button::create("button-menuscene.png");
	//create label for how to play button
	auto lbl_help = Label::createWithTTF("How To Play", "fonts/Marker Felt.ttf", 30);
	btn_help->setTitleLabel(lbl_help);
	btn_help->setPosition(Vec2(xMid, yMid));
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
	auto btn_exit = Button::create("button-menuscene.png");
	//create name of button
	auto lbl_exit = Label::createWithTTF("Exit", "fonts/Marker Felt.ttf", 30);
	btn_exit->setTitleLabel(lbl_exit);
	btn_exit->setPosition(Vec2(xMid, yMid - 80));
	btn_exit->addTouchEventListener([&](Ref* sender, Widget::TouchEventType type)
	{
		switch (type)
		{
		case cocos2d::ui::Widget::TouchEventType::BEGAN:
			break;
		case cocos2d::ui::Widget::TouchEventType::MOVED:
			break;
		case cocos2d::ui::Widget::TouchEventType::ENDED:
			Director::getInstance()->replaceScene(EndScene::createScene());
			break;
		case cocos2d::ui::Widget::TouchEventType::CANCELED:
			break;
		default:
			break;
		}
	});
	this->addChild(btn_exit);
}