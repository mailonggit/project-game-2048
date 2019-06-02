#include "WinScene.h"
#include "MainMenuScene.h"
#include "Definitions.h"
#include "GameScene.h"
USING_NS_CC;

Scene* WinScene::createScene()
{
	auto scene = Scene::create();
	auto layer = WinScene::create();
	//add layer to the scene
	scene->addChild(layer);
	return scene;
}
// on "init" you need to initialize your instance
bool WinScene::init()
{
	if (!Layer::init())
	{
		return false;
	}

	auto visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	//create background
	auto background = Sprite::create("win-background.png");
	background->setPosition(customSize(0.5, 0.5));

	this->addChild(background);

	//create button
	createButton();
	return true;
}
Vec2 WinScene::customSize(double a, double b)
{
	auto visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();
	return Vec2(a * visibleSize.width + origin.x, b * visibleSize.height + origin.y);
}
void WinScene::createButton()
{
	//create item
	auto playAgainItem = MenuItemImage::create("play-again.png", "play-again.png", CC_CALLBACK_1(WinScene::goToGameScene, this));
	auto exitItem = MenuItemImage::create("exit.png", "exit.png", CC_CALLBACK_1(WinScene::exitGame, this));

	//set position for button
	playAgainItem->setPosition(customSize(0.5, 0.3));
	exitItem->setPosition(customSize(0.5, 0.1));

	//add all the item to menu
	auto menu = Menu::create(playAgainItem, exitItem, NULL);
	menu->setPosition(Vec2::ZERO);
	this->addChild(menu);
}
void WinScene::goToGameScene(Ref *sender)
{
	auto scene = GameScene::createScene();
	Director::getInstance()->replaceScene(TransitionFade::create(0.5, scene));
}
void WinScene::exitGame(Ref *sender)
{
	Director::getInstance()->end();
}