#ifndef __WIN_SCENE_H__
#define __WIN_SCENE_H__

#include "cocos2d.h"
#include <ui/CocosGUI.h>
using namespace cocos2d;
using namespace ui;
class WinScene : public cocos2d::Layer
{
public:
	static cocos2d::Scene* createScene();

	virtual bool init();
	// implement the "static create()" method manually
	Vec2 customSize(double, double);
	void createButton();
	void script();
	CREATE_FUNC(WinScene);
private:
	void goToModeScene(Ref *sender);
	void exitGame(Ref *sender);
};

#endif // __WIN_SCENE_H__
