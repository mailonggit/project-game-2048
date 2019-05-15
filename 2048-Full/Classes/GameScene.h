#ifndef _GAME_SCENE_H_
#define _GAME_SCENE_H_
#include <cocos2d.h>
#include <ui/CocosGUI.h>
using namespace cocos2d;
using namespace ui;
class GameScene : public Layer
{
public:
	static Scene* createScene();
	virtual bool init();
	void menuCloseCallBack(Ref* psender);
	CREATE_FUNC(GameScene);
	void createButton();
private:

};

#endif // !_GAME_SCENE_H_
