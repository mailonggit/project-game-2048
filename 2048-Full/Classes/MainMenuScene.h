#ifndef _MAINMENU_SCENE_H_
#define _MAINMENU_SCENE_H_
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
