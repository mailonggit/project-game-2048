#ifndef __MODE_H__
#define __MODE_H__

#include "cocos2d.h"
#include <ui/CocosGUI.h>
using namespace cocos2d;
using namespace ui;
class Mode : public cocos2d::Layer
{
public:
    static cocos2d::Scene* createScene();

    virtual bool init();   
    // implement the "static create()" method manually
	Vec2 customSize(double, double);
	void createButton();
    CREATE_FUNC(Mode);
private:
	void goToMode1(Ref *sender);
	void goToMode2(Ref *sender);

};

#endif // __MODE_H__
