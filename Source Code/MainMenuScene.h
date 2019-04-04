#ifndef __MAINMENU_SCENE_H__
#define __MAINMENU_SCENE_H__
#include <cocos2d.h>
#include <ui/CocosGUI.h>
using namespace cocos2d;
using namespace ui;
class MainMenuScene : public Layer
{
public:
	static Scene* createScene();
	virtual bool init();
	void menuCloseCallBack(Ref* psender);
	CREATE_FUNC(MainMenuScene);
	void createButton();
private:

};
#endif // !_MAINMENU_SCENE_H_

