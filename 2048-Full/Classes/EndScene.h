#ifndef _END_SCENE_H_
#define _END_SCENE_H_
#include <cocos2d.h>
using namespace cocos2d;
class EndScene : public Layer
{
public:
	static Scene* createScene();
	virtual bool init();
	void menuCloseCallBack(Ref* psender);
	CREATE_FUNC(EndScene);

private:

};

#endif // !_END_SCENE_H_
