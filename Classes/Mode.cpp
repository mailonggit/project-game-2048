#include "Mode.h"
#include "Mode1.h"
#include "Mode2.h"
#include "Definitions.h"
USING_NS_CC;

Scene* Mode::createScene()
{
	auto scene = Scene::create();
	auto layer = Mode::create();
	//add layer to the scene
	scene->addChild(layer);
	return scene;
}


// on "init" you need to initialize your instance
bool Mode::init()
{
    if ( !Layer::init() )
    {
        return false;
    }

    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

	//create background
	auto background = Sprite::create("mode-background.png");
	background->setPosition(customSize(0.5, 0.5));
	this->addChild(background);

	//create title
	auto lbl_title = Label::createWithTTF("MODE", "fonts/Marker Felt.ttf", 50);
	lbl_title->setPosition(customSize(0.5, 0.9));
	lbl_title->enableShadow(Color4B::BLUE);
	this->addChild(lbl_title, 1);
	
	//create button for mode
	createButton();

    return true;
}
void Mode::createButton()
{
	//create mode1 item
	auto mode1 = MenuItemImage::create("mode1-button.png", "mode1-button.png", CC_CALLBACK_1(Mode::goToMode1, this));
	mode1->setPosition(customSize(0.5, 0.7));

	//create mode2 item
	auto mode2 = MenuItemImage::create("mode2-button.png", "mode2-button.png", CC_CALLBACK_1(Mode::goToMode2, this));
	mode2->setPosition(customSize(0.5, 0.5));

	//add item to menu
	auto menu = Menu::create(mode1, mode2, NULL);
	menu->setPosition(Vec2::ZERO);
	this->addChild(menu);
}
Vec2 Mode::customSize(double a, double b)
{
	auto visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();
	return Vec2(a * visibleSize.width  + origin.x, b * visibleSize.height + origin.y);
}
void Mode::goToMode1(Ref *sender)
{
	auto scene = Mode1::createScene();
	Director::getInstance()->replaceScene(TransitionFade::create(TRANSITION_TIME, scene));
}
void Mode::goToMode2(Ref *sender)
{
	auto scene = Mode2::createScene();
	Director::getInstance()->replaceScene(TransitionFade::create(TRANSITION_TIME, scene));
}