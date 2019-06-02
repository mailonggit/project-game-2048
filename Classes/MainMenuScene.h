#ifndef __MAIN_MENU_SCENE_H__
#define __MAIN_MENU_SCENE_H__

#include "cocos2d.h"
#include <ui/CocosGUI.h>
using namespace cocos2d;
using namespace ui;
class MainMenuScene : public cocos2d::Layer
{
public:
    static cocos2d::Scene* createScene();

    virtual bool init();
	void createButton();
	Vec2 customSize(double, double);
	void spriteSheet();
    // implement the "static create()" method manually
    CREATE_FUNC(MainMenuScene);
private:
	void goToGameScene(cocos2d::Ref *sender);
	void goToHelpScene(cocos2d::Ref *sender);
	void goToAboutScene(cocos2d::Ref *sender);
	void ExitGame(cocos2d::Ref *sender);
};

#endif // __MAIN_MENU_SCENE_H__
