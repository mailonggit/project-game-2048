#include "EndScene.h"
USING_NS_CC;
Scene* EndScene::createScene()
{
	auto scene = Scene::create();
	auto layer = EndScene::create();
	scene->addChild(layer);
	return scene;
}
bool EndScene::init()
{
	if (!Layer::init())
	{
		return false;
	}
	return true;
}
void EndScene::menuCloseCallBack(Ref* psender)
{

}