#include "GameScene.h"

USING_NS_CC;

Scene* GameScene::createScene()
{
	//create scene
	auto scene = Scene::create();

	//create layer
	auto layer = GameScene::create();

	//add layer to the scene
	scene->addChild(layer);
	return scene;
}


// on "init" you need to initialize your instance
bool GameScene::init()
{
	if (!Layer::init())
	{
		return false;
	}

	auto visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();
	int xMid = visibleSize.width / 2 + origin.x;
	int yMid = visibleSize.height / 2 + origin.y;

	//background
	auto background = Sprite::create("game-background.png");
	background->setPosition(Point(xMid, yMid));
	this->addChild(background);

	//init board
	initBoard();

	//key listener
	auto listener = EventListenerKeyboard::create();
	listener->onKeyPressed = CC_CALLBACK_2(GameScene::onKeyPressed, this);
	listener->onKeyReleased = CC_CALLBACK_2(GameScene::onKeyReleased, this);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);

	//update change
	this->scheduleUpdate();
	return true;
}
void GameScene::initBoard()
{
	for (int i = 0; i < 4; ++i)
	{
		for (int j = 0; j < 4; ++j) 
		{
			board[i][j] = 0;
		}
	}
	randomNumber();
	randomNumber();
	checkEnd = false;
	checkUp = checkDown = checkLeft = checkRight = false;
}
void GameScene::randomNumber()
{
	int i = 0, j = 0;
	while (board[i][j] != 0)
	{
		i = cocos2d::RandomHelper::random_int(0, 3);
		j = cocos2d::RandomHelper::random_int(0, 3);
		if (board[i][j] == 0)
		{
			break;
		}
		//board[i][j] != 0
	}
	board[i][j] = 2;
}
void GameScene::onKeyPressed(EventKeyboard::KeyCode keyCode, Event *pevent)
{
	//right 27
	//left 26
	//down 29
	//up 28
	if ((int)keyCode == 26)
	{
		log("You've just pressed left, number %d!", keyCode);
		moveUp();
		randomNumber();
	}

	else if ((int)keyCode == 27)
	{
		log("You've just pressed right, number %d!", keyCode);
		moveDown();

		randomNumber();
	}
	else if ((int)keyCode == 28)
	{
		log("You've just pressed up, number %d!", keyCode);
		moveLeft();
		randomNumber();
	}
	else if ((int)keyCode == 29)
	{
		log("You've just pressed down, number %d!", keyCode);
		moveRight();
		randomNumber();
	}

	//this->schedule(schedule_selector(GameScene::render));
	//log("Key with keycode %d pressed", keyCode);
}
void GameScene::onKeyReleased(EventKeyboard::KeyCode keyCode, Event *pevent)
{

}
void Swap(int &a, int &b)
{
	int temp = a;
	a = b;
	b = temp;
}
void GameScene::moveUp()
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 3; ++j)
		{
			for (int k = j + 1; k < 4; ++k)
			{
				if (board[j][i] == board[k][i] && board[j][i] != 0)
				{
					board[j][i] *= 2;
					board[k][i] = 0;
					break;
				}
				else
				{
					if (board[j][i] == 0 && board[k][i] != 0)
					{
						Swap(board[j][i], board[k][i]);
					}
					else if (board[j][i] != 0 && board[k][i] != 0 && board[j][i] != board[k][i])
					{
						checkUp = true;
						break;
					}
				}
			}
		}
	}
}
void GameScene::moveDown()
{
	for (int i = 0; i < 4; ++i)//on the row
	{
		for (int j = 3; j >= 1; j--)//on the columm
		{
			for (int k = j - 1; k >= 0; k--)
			{

				if (board[j][i] == board[k][i] && board[j][i] != 0)
				{
					board[j][i] *= 2;
					board[k][i] = 0;
					break;
				}
				else
				{
					if (board[j][i] == 0 && board[k][i] != 0)
					{
						Swap(board[j][i], board[k][i]);
						//break;
					}
					else if (board[j][i] != 0 && board[k][i] != 0 && board[j][i] != board[k][i])
					{
						checkDown = true;
						break;
					}

				}
			}
		}
	}
}
void GameScene::moveLeft()
{
	for (int i = 0; i < 4; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			for (int k = j + 1; k < 4; ++k)
			{
				if (board[i][j] == board[i][k] && board[i][j] != 0)
				{
					board[i][j] *= 2;
					board[i][k] = 0;
					break;
				}
				else
				{
					if (board[i][j] == 0 && board[i][k] != 0)
					{
						Swap(board[i][j], board[i][k]);
					}
					else if (board[i][j] != 0 && board[i][k] != 0 && board[i][j] != board[i][k])
					{
						checkLeft = true;
						break;
					}
				}
			}
		}
	}
}
void GameScene::moveRight()
{
	for (int i = 0; i < 4; ++i)
	{
		for (int j = 3; j >= 1; j--)
		{
			for (int k = j - 1; k >= 0; k--)
			{
				if (board[i][j] == board[i][k] && board[i][j] != 0)
				{
					board[i][j] *= 2;
					board[i][k] = 0;
					break;
				}
				else
				{
					if (board[i][j] == 0 && board[i][k] != 0)
					{
						Swap(board[i][j], board[i][k]);
					}
					else if (board[i][j] != 0 && board[i][k] != 0 && board[i][j] != board[i][k])
					{
						checkRight = true;
						break;
					}
				}
			}
		}
	}
}
void GameScene::update(float dt)
{
	for (int i = 0; i < 4; ++i)
	{
		for (int j = 0; j < 4; ++j)
		{
			//print square
			std::string name = std::to_string(board[i][j]) + ".png";
			square = new Square(this, name, i, j);
			//check win
			if (board[i][j] == 64)
			{
				auto visibleSize = Director::getInstance()->getVisibleSize();
				Vec2 origin = Director::getInstance()->getVisibleOrigin();
				//create label for win
				auto lbl_win = Label::createWithTTF("Ok, you win! Don't need to discuss", "fonts/Marker Felt.ttf", 30);
				lbl_win->setPosition(Point(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));
				lbl_win->enableShadow(Color4B::RED);
				this->addChild(lbl_win, 1);
			}
			//check game over
			else if ((checkUp == true && checkDown == true && checkLeft == true && checkRight == true) || checkEnd == true)
			{
				auto visibleSize = Director::getInstance()->getVisibleSize();
				Vec2 origin = Director::getInstance()->getVisibleOrigin();
				//create label for loser
				auto lbl_win = Label::createWithTTF("You foooooooool!", "fonts/Marker Felt.ttf", 30);
				lbl_win->setPosition(Point(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));
				lbl_win->enableShadow(Color4B::RED);
				this->addChild(lbl_win, 1);
			}
		}
	}
}
GameScene::~GameScene()
{
	delete square;
}