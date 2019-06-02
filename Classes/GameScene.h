#ifndef __GAME_SCENE_H__
#define __GAME_SCENE_H__

#include "cocos2d.h"
#include <string>
#include "Square.h"
using namespace cocos2d;
class GameScene : public cocos2d::Layer
{
public:
    static cocos2d::Scene* createScene();

    virtual bool init();
	void spriteSheet();
	void initBoard();
	void randomNumber();
	void onKeyPressed(EventKeyboard::KeyCode keyCode, Event *pevent);
	void onKeyReleased(EventKeyboard::KeyCode keyCode, Event *pevent);
	void moveUp();
	void moveDown();
	void moveLeft();
	void moveRight();
	Vec2 customSize(double, double);
	void createButton();
	bool checkGameOver();
	//bool checkGameWin();
	void update(float dt);
    // implement the "static create()" method manually
    CREATE_FUNC(GameScene);
private:
	void goToMenu(Ref *sender);
	void undo(Ref *sender);
	void reset(Ref *sender);
	//cocos2d::PhysicsWorld *sceneWorld;
	int board[4][4];
	bool checkWin;
	Square *square;
};

#endif // __GAME_SCENE_H__
