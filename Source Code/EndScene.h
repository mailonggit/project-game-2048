#ifndef __END_SCENE_H__
#define __END_SCENE_H__
#include <cocos2d.h>
using namespace cocos2d;
class EndScene : public Layer
{
public:
	EndScene();
	~EndScene();

	static Scene* createScene();
	virtual bool init();
	void menuCloseCallBack(Ref* psender);
	CREATE_FUNC(EndScene);
private:

};
#endif // !_END_SCENE_H_

