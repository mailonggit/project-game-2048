#include "GameScene.h"
#include "EndScene.h"
#include "WinScene.h"
#include "Definitions.h"
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

	//create sprite sheet
	spriteSheet();

	//create button
	createButton();

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
void GameScene::spriteSheet()
{
	//create sprite
	auto background = Sprite::create("background.png");
	auto background_title = Sprite::create("button.png");
	
	//set position for sprite
	background->setPosition(customSize(0.5, 0.5));
	background_title->setPosition(customSize(0.5, 0.9));

	//create label
	auto lbl_title = Label::createWithTTF("2048", "fonts/Marker Felt.ttf", 50);
	lbl_title->setPosition(customSize(0.5, 0.9));
	lbl_title->enableShadow(Color4B::BLUE);
	
	//add sprite and label to the scene
	this->addChild(background);
	this->addChild(lbl_title, 1);	
	this->addChild(background_title);
}
void GameScene::createButton()
{
	//create item for home, undo, reset
	
	auto home = MenuItemImage::create("home.png", "home.png", CC_CALLBACK_1(GameScene::goToMenu, this));
	auto undo = MenuItemImage::create("undo.png", "undo.png", CC_CALLBACK_1(GameScene::undo, this));
	auto reset = MenuItemImage::create("reset.png", "reset.png", CC_CALLBACK_1(GameScene::reset, this));
	
	//set position for sprite
	home->setPosition(customSize(0.1, 0.9));
	undo->setPosition(customSize(0.7, 0.9));
	reset->setPosition(customSize(0.9, 0.9));

	auto menu = Menu::create(home, undo, reset, NULL);
	menu->setPosition(Vec2::ZERO);
	//add menu to the scene
	this->addChild(menu);
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
	//up 28
	//down 29
	//left 26
	//right 27
	if ((int)keyCode == 26 && checkGameOver() == false)
	{
		log("You've just pressed left, number %d!", keyCode);
		moveUp();
		randomNumber();
	}

	else if ((int)keyCode == 27 && checkGameOver() == false)
	{
		log("You've just pressed right, number %d!", keyCode);
		moveDown();
		randomNumber();
	}
	else if ((int)keyCode == 28 && checkGameOver() == false)
	{
		log("You've just pressed up, number %d!", keyCode);
		moveLeft();
		randomNumber();
	}
	else if ((int)keyCode == 29 && checkGameOver() == false)
	{
		log("You've just pressed down, number %d!", keyCode);
		moveRight();
		randomNumber();
	}
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
			//print square
			std::string name = std::to_string(board[i][j]) + ".png";
			square = new Square(this, name, i, j);
			//check win
			if (board[i][j] == 64)
			{
				auto scene = WinScene::createScene();
				Director::getInstance()->replaceScene(TransitionFade::create(TRANSITION_TIME, scene));
			}
			//check game over
			else if (checkGameOver() == true)
			{
				auto scene = EndScene::createScene();
				Director::getInstance()->replaceScene(TransitionFade::create(TRANSITION_TIME, scene));
			}
		}
	}
}
Vec2 GameScene::customSize(double a, double b)
{
	auto visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();
	return Vec2(a * visibleSize.width  + origin.x, b * visibleSize.height + origin.y);
}
void GameScene::goToMenu(Ref *sender)
{
	Director::getInstance()->popScene();
}
void GameScene::undo(Ref *sender)
{

}
void GameScene::reset(Ref *sender)
{
	auto scene = GameScene::createScene();
	Director::getInstance()->replaceScene(TransitionFade::create(0.5, scene));
}
bool GameScene::checkGameOver()
{
	for (int i = 0; i < 4; ++i)
	{
		for (int j = 0; j < 4; ++j)
		{
			if (board[i][j] == board[i][j + 1])
			{
				return false;
			}
		}
	}
	for (int i = 0; i < 4; ++i)
	{
		for (int j = 0; j < 4; ++j)
		{
			if (board[j][i] == board[j + 1][i])
			{
				return false;
			}
		}
	}
	return true;
}