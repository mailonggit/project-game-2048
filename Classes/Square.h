#ifndef __SQUARE_H__
#define __SQUARE_H__

#include "cocos2d.h"
#include <string>
class Square
{
public:
	Square(cocos2d::Layer *layer, std::string name, int i, int j);

private:
	cocos2d::Size visibleSize;
	cocos2d::Vec2 origin;
};

#endif // __SQUARE_H__
