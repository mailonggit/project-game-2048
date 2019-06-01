#ifndef __HELP_SCENE_H__
#define __HELP_SCENE_H__

#include "cocos2d.h"
#include <ui/CocosGUI.h>
using namespace cocos2d;
using namespace ui;
class HelpScene : public cocos2d::Layer
{
public:
    static cocos2d::Scene* createScene();

    virtual bool init();   
	Vec2 customSize(double);
	void script();
    // implement the "static create()" method manually
    CREATE_FUNC(HelpScene);
private:
	void goToMenuScene(Ref *sender);
};

#endif // __HELP_SCENE_H__
