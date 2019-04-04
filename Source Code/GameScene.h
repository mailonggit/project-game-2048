#ifndef __GAME_SCENE_H__
#define __GAME_SCENE_H__
#include <cocos2d.h>
#include <ui\CocosGUI.h>
using namespace cocos2d;
using namespace ui;
class GameScene : public Layer
{
public:
	static Scene* createScene();
	virtual bool init();
	void menuCloseCallBack(Ref* psender);
	void createButton(int, int);
	CREATE_FUNC(GameScene);	
};
#endif // !_GAME_SCENE_H_

