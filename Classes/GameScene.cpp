#include "GameScene.h"

USING_NS_CC;

Scene* GameScene::createScene()
{
	//create scene
	auto scene = Scene::createWithPhysics();
	scene->getPhysicsWorld()->setDebugDrawMask(PhysicsWorld::DEBUGDRAW_ALL);

	//create layer
	auto layer = GameScene::create();
	layer->setPhysicsWorld(scene->getPhysicsWorld());

	//add layer to the scene
	scene->addChild(layer);
	return scene;
}


// on "init" you need to initialize your instance
bool GameScene::init()
{
    if ( !Layer::init() )
    {
        return false;
    }

    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
	int xMid = visibleSize.width / 2 + origin.x;
	int yMid = visibleSize.height / 2 + origin.y;

	auto edgeBody = PhysicsBody::createEdgeBox(visibleSize, PHYSICSBODY_MATERIAL_DEFAULT);
	auto edgeNode = Node::create();
	edgeNode->setPosition(Point(xMid, yMid));
	edgeNode->setPhysicsBody(edgeBody);
	this->addChild(edgeNode);
	//background
	auto background = Sprite::create("menu-background.png");
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
	board[4][4] = 0;
	randomNumber();
	randomNumber();
}
void GameScene::randomNumber()
{
	int i, j;
	do
	{
		i = cocos2d::RandomHelper::random_int(0, 4);
		j = cocos2d::RandomHelper::random_int(0, 4);
	} while (board[i][j] != 0);//value in location i, j = 0 => out of the loop
	board[i][j] = 2;
}
void GameScene::onKeyPressed(EventKeyboard::KeyCode keyCode, Event *pevent)
{
	//right 27
	//left 26
	//down 29
	//up 28
	if ((int)keyCode == 28)
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
	else if ((int)keyCode == 26)
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
			std::string name = std::to_string(board[i][j]) + ".png";
			square = new Square(this, name, i, j);
		}
	}
}
//void GameScene::render(float dt)
//{
//	
//	for (int i = 0; i < 4; ++i)
//	{
//		for (int j = 0; j < 4; ++j)
//		{
//			std::string name = std::to_string(board[i][j]) + ".png";
//			square = new Square(this, name, i, j);
//		}
//	}
//}