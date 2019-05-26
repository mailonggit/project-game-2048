#include "EndScene.h"

USING_NS_CC;

Scene* EndScene::createScene()
{
	auto scene = Scene::create();
	auto layer = EndScene::create();
	//add layer to the scene
	scene->addChild(layer);
	return scene;
}


// on "init" you need to initialize your instance
bool EndScene::init()
{
    if ( !Layer::init() )
    {
        return false;
    }

    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    return true;
}
