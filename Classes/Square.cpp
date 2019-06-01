#include "Square.h"
#include "Definitions.h"
USING_NS_CC;
Square::Square(cocos2d::Layer *layer, std::string name, int i, int j)
{
	visibleSize = Director::getInstance()->getVisibleSize();
	origin = Director::getInstance()->getVisibleOrigin();
	auto image = Sprite::create(name);
	int quarX = visibleSize.width / 4 + origin.x;
	int halfY = 3 * visibleSize.height / 5 + origin.y;
	image->setPosition(Point(quarX + i * image->getContentSize().width , halfY  - j * image->getContentSize().height));
	layer->addChild(image);
}
