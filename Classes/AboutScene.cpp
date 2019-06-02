#include "AboutScene.h"
#include "MainMenuScene.h"
#include "Definitions.h"
USING_NS_CC;

Scene* AboutScene::createScene()
{
	auto scene = Scene::create();
	auto layer = AboutScene::create();
	//add layer to the scene
	scene->addChild(layer);
	return scene;
}


// on "init" you need to initialize your instance
bool AboutScene::init()
{
    if ( !Layer::init() )
    {
        return false;
    }

    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

	//create background
	auto background = Sprite::create("background.png");
	background->setPosition(customSize(0.5, 0.5));
	this->addChild(background);

	//create title
	auto lbl_title = Label::createWithTTF("Contributors", "fonts/Marker Felt.ttf", 50);
	lbl_title->setPosition(customSize(0.5, 0.9));
	lbl_title->enableShadow(Color4B::BLUE);
	this->addChild(lbl_title, 1);

	//script
	script();

	//create backToMenu item
	auto backToMenu = MenuItemImage::create("back-to-menu-button.png", "back-to-menu-button.png", CC_CALLBACK_1(AboutScene::goToMenuScene, this));
	backToMenu->setPosition(customSize(0.5, 0.1));

	//add item to menu
	auto menu = Menu::create(backToMenu, NULL);
	menu->setPosition(Vec2::ZERO);
	this->addChild(menu);
    return true;
}
Vec2 AboutScene::customSize(double a, double b)
{
	auto visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();
	return Vec2(a * visibleSize.width  + origin.x, b * visibleSize.height + origin.y);
}
void AboutScene::script()
{
	char *name[4] = { "Mai Hoang Long", "Nguyen Tien Dung", "Dang Quoc Cuong", "Nguyen Loc" };
	for (int i = 0; i < 4; ++i)
	{
		auto lbl_name = Label::createWithTTF(name[i], "fonts/Marker Felt.ttf", 30);
		lbl_name->setPosition(customSize(0.5, 0.8 - 0.1 * i));
		lbl_name->enableShadow(Color4B::GREEN);
		this->addChild(lbl_name, 1);
	}
}
void AboutScene::goToMenuScene(Ref *sender)
{
	Director::getInstance()->popScene();
}