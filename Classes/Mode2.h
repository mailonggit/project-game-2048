#ifndef __MODE2_H__
#define __MODE2_H__

#include "cocos2d.h"
#include <string>
#include "Square.h"
#include <stack>
using namespace cocos2d;
using namespace std;
class Mode2 : public cocos2d::Layer
{
public:
    static cocos2d::Scene* createScene();

    virtual bool init();
	void spriteSheet();
	void initBoard();
	void randomNumber();
	void onKeyPressed(EventKeyboard::KeyCode keyCode, Event *pevent);
	void onKeyReleased(EventKeyboard::KeyCode keyCode, Event *pevent);
	void Swap(int &, int &);
	void moveUp();
	void moveDown();
	void moveLeft();
	void moveRight();
	Vec2 customSize(double, double);
	void createButton();
	bool checkZero();
	bool checkGameOver();
	//bool checkGameWin();
	void tick(float dt);
	void update(float dt);
    // implement the "static create()" method manually
    CREATE_FUNC(Mode2);
private:
	void goToMenu(Ref *sender);
	void undo(Ref *sender);
	void reset(Ref *sender);
	void Exit(Ref *sender);
	//cocos2d::PhysicsWorld *sceneWorld;
	int board[4][4], score;
	float timer;
	bool checkWin;
	Square *square;
	Label *lbl_score;
	//stack<int[4][4]> Undo;
	int size;
};

#endif // __GAME_SCENE_H__
