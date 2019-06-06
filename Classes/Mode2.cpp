#include "Mode2.h"
#include "WinScene.h"
#include "MainMenuScene.h"
#include "Definitions.h"

USING_NS_CC;
Scene* Mode2::createScene()
{
	//create scene
	auto scene = Scene::create();

	//create layer
	auto layer = Mode2::create();

	//add layer to the scene
	scene->addChild(layer);
	return scene;
}
bool Mode2::init()
{
	if (!Layer::init())
	{
		return false;
	}

	//create sprite sheet
	spriteSheet();

	//create button
	createButton();

	//init board
	initBoard();

	//key listener
	auto listener = EventListenerKeyboard::create();
	listener->onKeyPressed = CC_CALLBACK_2(Mode2::onKeyPressed, this);
	listener->onKeyReleased = CC_CALLBACK_2(Mode2::onKeyReleased, this);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);

	//update change
	this->scheduleUpdate();
	return true;
}
void Mode2::spriteSheet()
{
	//create sprite
	auto background = Sprite::create("mode2-background.png");
	auto background_title = Sprite::create("button.png");
	auto background_score = Sprite::create("score-background.png");

	//set position for sprite
	background->setPosition(customSize(0.5, 0.5));
	background_title->setPosition(customSize(0.5, 0.9));
	background_score->setPosition(customSize(0.8, 0.75));

	//create label
	auto lbl_title = Label::createWithTTF("2048", "fonts/Marker Felt.ttf", 50);
	lbl_title->setPosition(customSize(0.5, 0.9));
	lbl_title->enableShadow(Color4B::BLUE);

	String *Score = String::createWithFormat("%i", score);
	lbl_score = Label::createWithTTF(Score->getCString(), "fonts/Marker felt.ttf", 25);
	lbl_score->setPosition(customSize(0.8, 0.73));
	lbl_title->enableShadow(Color4B::BLUE);
	this->addChild(lbl_score, 1);

	//add sprite and label to the scene
	this->addChild(background);
	this->addChild(lbl_title, 1);
	this->addChild(background_title);
	this->addChild(background_score);

}
void Mode2::createButton()
{
	//create item for home, undo, reset

	auto home = MenuItemImage::create("home.png", "home.png", CC_CALLBACK_1(Mode2::goToMenu, this));
	auto undo = MenuItemImage::create("undo.png", "undo.png", CC_CALLBACK_1(Mode2::undo, this));
	auto reset = MenuItemImage::create("reset.png", "reset.png", CC_CALLBACK_1(Mode2::reset, this));

	//set position for sprite
	home->setPosition(customSize(0.1, 0.9));
	undo->setPosition(customSize(0.7, 0.9));
	reset->setPosition(customSize(0.9, 0.9));

	auto menu = Menu::create(home, undo, reset, NULL);
	menu->setPosition(Vec2::ZERO);
	//add menu to the scene
	this->addChild(menu);
}
void Mode2::initBoard()
{
	score = 0;
	size = 0;
	timer = 0;
	for (int i = 0; i < 4; ++i)
	{
		for (int j = 0; j < 4; ++j)
		{
			board[i][j] = 0;
		}
	}
	srand(time(NULL));
	randomNumber();
	randomNumber();
}
void Mode2::randomNumber()
{
	int i, j;
	do
	{
		i = cocos2d::RandomHelper::random_int(0, 3);
		j = cocos2d::RandomHelper::random_int(0, 3);
		if (checkZero() == false)//no more zero in the board
		{
			return;//out of function
		}
	} while (board[i][j] != 0);//loop until has no zero
	if (checkZero() == true)//has zero
	{
		int number = cocos2d::RandomHelper::random_int(0, 100);
		number < 90 ? board[i][j] = 2 : board[i][j] = 4;
	}
}
void Mode2::onKeyPressed(EventKeyboard::KeyCode keyCode, Event *pevent)
{
	//up 28
	//down 29
	//left 26
	//right 27
	if ((int)keyCode == 26 && checkGameOver() == false)
	{
		log("You've just pressed up, number %d!", keyCode);
		moveUp();
		randomNumber();
	}

	else if ((int)keyCode == 27 && checkGameOver() == false)
	{
		log("You've just pressed down, number %d!", keyCode);
		moveDown();
		randomNumber();
	}
	else if ((int)keyCode == 28 && checkGameOver() == false)
	{
		log("You've just pressed left, number %d!", keyCode);
		moveLeft();
		randomNumber();
	}
	else if ((int)keyCode == 29 && checkGameOver() == false)
	{
		log("You've just pressed right, number %d!", keyCode);
		moveRight();
		randomNumber();
	}
}
void Mode2::onKeyReleased(EventKeyboard::KeyCode keyCode, Event *pevent)
{

}
void Mode2::Swap(int &a, int &b)
{
	int temp = a;
	a = b;
	b = temp;
}
void Mode2::moveUp()
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
					score += board[j][i];
					String *Score = String::createWithFormat("%i", score);
					lbl_score->setString(Score->getCString());
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
	//add new value of board to the stack and increase the size of stack
	//Undo.push(board);
	size++;
	
}
void Mode2::moveDown()
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
					score += board[j][i];
					String *Score = String::createWithFormat("%i", score);
					lbl_score->setString(Score->getCString());
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
	//add new value of board to the stack and increase the size of stack
	//Undo.push(board);
	size++;
}
void Mode2::moveLeft()
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
					score += board[i][j];
					String *Score = String::createWithFormat("%i", score);
					lbl_score->setString(Score->getCString());
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
	//add new value of board to the stack and increase the size of stack
	//Undo.push(board);
	size++;
}
void Mode2::moveRight()
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
					score += board[i][j];
					String *Score = String::createWithFormat("%i", score);
					lbl_score->setString(Score->getCString());
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
	//add new value of board to the stack and increase the size of stack
	//Undo.push(board);
	size++;
}
void Mode2::update(float dt)
{
	//this->schedule(schedule_selector(Mode2::tick));
	timer += dt;
	log("Timer: %f", timer);
	if (timer > 5)
	{
		randomNumber();
		timer = 0;
	}
	//display board
	for (int i = 0; i < 4; ++i)
	{
		for (int j = 0; j < 4; ++j)
		{
			//display square
			std::string name = std::to_string(board[i][j]) + ".png";
			square = new Square(this, name, i, j);
			//check win
			if (board[i][j] == 2048)
			{
				auto scene = WinScene::createScene();
				Director::getInstance()->replaceScene(TransitionFade::create(TRANSITION_TIME, scene));
			}
		}
	}
	//check game over
	if (checkGameOver() == true)
	{
		//Director::getInstance()->pause();
		//label for loser
		auto message = Label::createWithTTF("You loseeeeeeeeee!", "fonts/Marker felt.ttf", 50);
		message->setPosition(customSize(0.5, 0.5));
		message->enableShadow(Color4B::RED);
		this->addChild(message, 1);

		//create item
		auto playAgainItem = MenuItemImage::create("play-again.png", "play-again.png", CC_CALLBACK_1(Mode2::reset, this));
		auto exitItem = MenuItemImage::create("exit.png", "exit.png", CC_CALLBACK_1(Mode2::Exit, this));

		//set position for button
		playAgainItem->setPosition(customSize(0.5, 0.3));
		exitItem->setPosition(customSize(0.5, 0.1));

		//add all the item to menu
		auto menu = Menu::create(playAgainItem, exitItem, NULL);
		menu->setPosition(Vec2::ZERO);
		this->addChild(menu);
	}
}
void Mode2::tick(float dt)
{
}
Vec2 Mode2::customSize(double a, double b)
{
	auto visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();
	return Vec2(a * visibleSize.width + origin.x, b * visibleSize.height + origin.y);
}
bool Mode2::checkZero()
{
	for (int i = 0; i < 4; ++i)
	{
		for (int j = 0; j < 4; ++j)
		{
			if (board[i][j] == 0)
			{
				return true;
			}
		}
	}
	return false;
}
bool Mode2::checkGameOver()
{
	if (checkZero())
	{
		return false;
	}
	else
	{
		for (int i = 0; i < 4; ++i)
		{
			for (int j = 0; j < 3; ++j)//j < 3 because j + 1
			{
				if (board[i][j] == board[i][j + 1])
				{
					return false;
				}
			}
		}
		for (int i = 0; i < 4; ++i)
		{
			for (int j = 0; j < 3; ++j)
			{
				if (board[j][i] == board[j + 1][i])
				{
					return false;
				}
			}
		}
	}
	return true;
}
void Mode2::goToMenu(Ref *sender)
{
	auto scene = MainMenuScene::createScene();
	Director::getInstance()->replaceScene(TransitionFade::create(TRANSITION_TIME, scene));
}
void Mode2::undo(Ref *sender)
{
	//repeat until stack empty and size < 1
	/*if (!Undo.empty() && size > 1)
	{
		int	copyBoard[4][4] = Undo.top();
	}*/
}
void Mode2::reset(Ref *sender)
{
	auto scene = Mode2::createScene();
	Director::getInstance()->replaceScene(TransitionFade::create(0.5, scene));
}
void Mode2::Exit(Ref *sender)
{
	Director::getInstance()->end();
}