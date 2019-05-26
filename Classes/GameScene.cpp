#include "GameScene.h"

USING_NS_CC;

Scene* GameScene::createScene()
{
	//create scene
	auto scene = Scene::createWithPhysics();
	scene->getPhysicsWorld()->setDebugDrawMask(PhysicsWorld::DEBUGDRAW_ALL);

	//create layer
	auto layer = GameScene::create();
	layer->setPhysicsWorld(scene->getPhysicsWorld());

	//add layer to the scene
	scene->addChild(layer);
	return scene;
}


// on "init" you need to initialize your instance
bool GameScene::init()
{
    if ( !Layer::init() )
    {
        return false;
    }

    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
	int xMid = visibleSize.width / 2 + origin.x;
	int yMid = visibleSize.height / 2 + origin.y;

	auto edgeBody = PhysicsBody::createEdgeBox(visibleSize, PHYSICSBODY_MATERIAL_DEFAULT);
	auto edgeNode = Node::create();
	edgeNode->setPosition(Point(xMid, yMid));
	edgeNode->setPhysicsBody(edgeBody);
	this->addChild(edgeNode);

	square = new Square("0.png", this);
    return true;
}