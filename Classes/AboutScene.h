#ifndef __ABOUT_SCENE_H__
#define __ABOUT_SCENE_H__

#include "cocos2d.h"
#include <ui/CocosGUI.h>
using namespace cocos2d;
using namespace ui;
class AboutScene : public cocos2d::Layer
{
public:
    static cocos2d::Scene* createScene();

    virtual bool init();   
    // implement the "static create()" method manually
	Vec2 customSize(double );
	void script();
    CREATE_FUNC(AboutScene);
private:
	void goToMenuScene(Ref *sender);
};

#endif // __ABOUT_SCENE_H__
