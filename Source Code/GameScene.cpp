#include "GameScene.h"
USING_NS_CC;
Scene* GameScene::createScene()
{
	auto scene = Scene::create();
	auto layer = GameScene::create();
	scene->addChild(layer);
	return scene;
}
bool GameScene::init()
{
	if (!Layer::init())
	{
		return false;
	}
	auto direction = Director::getInstance();
	Vec2 origin = direction->getVisibleOrigin();
	Vec2 visibleSize = direction->getVisibleSize();
	int xMid = origin.x + visibleSize.x / 2;
	int yMid = origin.y + visibleSize.y / 2;

	//create score label
	auto lbl_score = Label::createWithTTF("Score", "fonts/Marker Felt.ttf", 30);
	lbl_score->setPosition(Vec2(xMid - 50, yMid + 160));
	this->addChild(lbl_score);

	//create hint label
	auto lbl_hint = Label::createWithTTF("Hint", "fonts/Marker Felt.ttf", 30);
	lbl_hint->setPosition(xMid + 100, yMid + 160);
	this->addChild(lbl_hint);

	createButton(xMid, yMid);
	return true;
}
void GameScene::createButton(int xMid, int yMid)
{
	auto btn_menu = Button::create();
	auto lbl_menu = Label::createWithTTF("Menu", "fonts/Marker Felt.ttf", 30);
	btn_menu->setTitleLabel(lbl_menu);
	btn_menu->setPosition(Vec2(50, 360));
	btn_menu->addTouchEventListener([&](Ref* sender, Widget::TouchEventType type)
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
	this->addChild(btn_menu);
}
void GameScene::menuCloseCallBack(Ref* psender)
{
	CCLOG("CallBack");
}