#ifndef __GAME_SCENE_H__
#define __GAME_SCENE_H__

#include "cocos2d.h"
#include "BoardGame.h"
#include <string>
using namespace cocos2d;
class GameScene : public cocos2d::Layer
{
public:
    static cocos2d::Scene* createScene();

    virtual bool init();
	void initBoard();
	void randomNumber();

	void setPhysicsWorld(cocos2d::PhysicsWorld *world) { sceneWorld = world; };
	void onKeyPressed(EventKeyboard::KeyCode keyCode, Event *pevent);
	void onKeyReleased(EventKeyboard::KeyCode keyCode, Event *pevent);
	void moveUp();
	void moveDown();
	void moveLeft();
	void moveRight();
	void update(float dt);
	//void render(float dt);
    // implement the "static create()" method manually
    CREATE_FUNC(GameScene);
private:
	
	cocos2d::PhysicsWorld *sceneWorld;
	int board[4][4];
	Square *square;
};

#endif // __GAME_SCENE_H__
