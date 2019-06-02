#include "HelpScene.h"
#include "MainMenuScene.h"
#include "Definitions.h"
USING_NS_CC;

Scene* HelpScene::createScene()
{
	auto scene = Scene::create();
	auto layer = HelpScene::create();
	//add layer to the scene
	scene->addChild(layer);
	return scene;
}
// on "init" you need to initialize your instance
bool HelpScene::init()
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
	auto lbl_title = Label::createWithTTF("Instruction", "fonts/Marker Felt.ttf", 50);
	lbl_title->setPosition(customSize(0.5, 0.9));
	lbl_title->enableShadow(Color4B::BLUE);
	this->addChild(lbl_title, 1);

	//script
	script();

	//create backToMenu item
	auto backToMenu = MenuItemImage::create("back-to-menu-button.png", "back-to-menu-button.png", CC_CALLBACK_1(HelpScene::goToMenuScene, this));
	backToMenu->setPosition(customSize(0.5, 0.1));

	//add item to menu
	auto menu = Menu::create(backToMenu, NULL);
	menu->setPosition(Vec2::ZERO);
	this->addChild(menu);
    return true;
}
Vec2 HelpScene::customSize(double a, double b)
{
	auto visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();
	return Vec2(a * visibleSize.width  + origin.x, b * visibleSize.height + origin.y);
}
void HelpScene::script()
{
	char *content[6] = {"Swipe up, down, left or right to move the tiles.", "When two tiles with the same number touch,", 
	"they merge into one!", "You win when you reach number 2048.", "You lose when the board full of number", "and can not swipe anymore."};

	for (int i = 0; i < 6; ++i)
	{
		auto lbl_name = Label::createWithTTF(content[i], "fonts/Marker Felt.ttf", 20);
		lbl_name->setPosition(customSize(0.5, 0.8 - 0.1 * i));
		lbl_name->enableShadow(Color4B::RED);
		this->addChild(lbl_name, 1);
	}
}
void HelpScene::goToMenuScene(Ref *sender)
{
	Director::getInstance()->popScene();
}