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
    if ( !Layer::init())
    {
        return false;
    }

    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

	//spritesheet for main menu scene
	spriteSheet();
	
	//create button
	createButton();

    return true;
}
void MainMenuScene::spriteSheet()
{
	//background
	auto background = LayerColor::create(Color4B(0, 0, 0, 255));
	background->setVisible(true);
	this->addChild(background);

	//sprite for mat long, dung, cuong, loc
	auto matlong = Sprite::create("matlong.png");
	auto matdung = Sprite::create("matdung.png");
	auto matcuong = Sprite::create("matcuong.png");
	auto matloc = Sprite::create("matloc.png");

	//set position for mat long, dung, cuong, loc
	matlong->setPosition(customSize(0.15, 0.8));
	matdung->setPosition(customSize(0.85, 0.8));
	matcuong->setPosition(customSize(0.15, 0.25));
	matloc->setPosition(customSize(0.85, 0.25));

	//add sprite to scene
	this->addChild(matlong);
	this->addChild(matdung);
	this->addChild(matcuong);
	this->addChild(matloc);

	//create title
	auto lbl_title = Label::createWithTTF("2048", "fonts/Marker Felt.ttf", 50);
	lbl_title->setPosition(customSize(0.5, 0.9));
	lbl_title->enableShadow(Color4B::BLUE);
	this->addChild(lbl_title, 1);
}
void MainMenuScene::createButton()
{
	//play item, how to play, contributors, exit game
	auto playItem = MenuItemImage::create("play-button.png", "play-button.png", CC_CALLBACK_1(MainMenuScene::goToGameScene, this));
	auto helpItem = MenuItemImage::create("how-to-play-button.png", "how-to-play-button.png", CC_CALLBACK_1(MainMenuScene::goToHelpScene, this));
	auto aboutItem = MenuItemImage::create("contributors-button.png", "contributors-button.png", CC_CALLBACK_1(MainMenuScene::goToAboutScene, this));
	auto exitItem = MenuItemImage::create("exit-button.png", "exit-button.png", CC_CALLBACK_1(MainMenuScene::ExitGame, this));

	//set position for sprite
	playItem->setPosition(customSize(0.5, 0.7));
	helpItem->setPosition(customSize(0.5, 0.5));
	aboutItem->setPosition(customSize(0.5, 0.3));
	exitItem->setPosition(customSize(0.5, 0.1));

	//create list of item
	auto menu = Menu::create(playItem, helpItem, aboutItem, exitItem, NULL);
	menu->setPosition(Point::ZERO);

	this->addChild(menu);//add menu to the scene
}
Vec2 MainMenuScene::customSize(double a, double b)
{
	auto visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();
	return Vec2(a * visibleSize.width + origin.x, b * visibleSize.height + origin.y);
}
void MainMenuScene::goToGameScene(cocos2d::Ref *sender)
{
	auto scene = GameScene::createScene();
	Director::getInstance()->pushScene(TransitionFade::create(TRANSITION_TIME, scene));
}
void MainMenuScene::goToHelpScene(cocos2d::Ref *sender)
{
	auto scene = HelpScene::createScene();
	Director::getInstance()->pushScene(TransitionFade::create(TRANSITION_TIME, scene));
}
void MainMenuScene::goToAboutScene(cocos2d::Ref *sender)
{
	auto scene = AboutScene::createScene();
	Director::getInstance()->pushScene(TransitionFade::create(TRANSITION_TIME, scene));
}
void MainMenuScene::ExitGame(cocos2d::Ref *sender)
{
	Director::getInstance()->end();
}
