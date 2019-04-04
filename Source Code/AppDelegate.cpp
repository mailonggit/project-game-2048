#include "AppDelegate.h"
#include "HelloWorldScene.h"
#include <vector>
#include "MainMenuScene.h"
using namespace std;

// #define USE_AUDIO_ENGINE 1
// #define USE_SIMPLE_AUDIO_ENGINE 1

#if USE_AUDIO_ENGINE && USE_SIMPLE_AUDIO_ENGINE
#error "Don't use AudioEngine and SimpleAudioEngine at the same time. Please just select one in your game!"
#endif

#if USE_AUDIO_ENGINE
#include "audio/include/AudioEngine.h"
using namespace cocos2d::experimental;
#elif USE_SIMPLE_AUDIO_ENGINE
#include "audio/include/SimpleAudioEngine.h"
using namespace CocosDenshion;
#endif

USING_NS_CC;

static cocos2d::Size designResolutionSize = cocos2d::Size(500, 400);
static cocos2d::Size smallResolutionSize = cocos2d::Size(512, 384);
static cocos2d::Size mediumResolutionSize = cocos2d::Size(1024, 768);
static cocos2d::Size largeResolutionSize = cocos2d::Size(2048, 1536);

AppDelegate::AppDelegate()
{
}

AppDelegate::~AppDelegate() 
{
#if USE_AUDIO_ENGINE
    AudioEngine::end();
#elif USE_SIMPLE_AUDIO_ENGINE
    SimpleAudioEngine::end();
#endif
}

// if you want a different context, modify the value of glContextAttrs
// it will affect all platforms
void AppDelegate::initGLContextAttrs()
{
    // set OpenGL context attributes: red,green,blue,alpha,depth,stencil,multisamplesCount
    GLContextAttrs glContextAttrs = {8, 8, 8, 8, 24, 8};

    GLView::setGLContextAttrs(glContextAttrs);
}

// if you want to use the package manager to install more packages,  
// don't modify or remove this function
static int register_all_packages()
{
    return 0; //flag for packages manager
}

bool AppDelegate::applicationDidFinishLaunching() 
{
	initOpenGL();
	initDirector();
	initMultiResolution();
	register_all_packages();
	createAndRunScene();
	return true;
}

// This function will be called when the app is inactive. Note, when receiving a phone call it is invoked.
void AppDelegate::applicationDidEnterBackground() {
    Director::getInstance()->stopAnimation();

#if USE_AUDIO_ENGINE
    AudioEngine::pauseAll();
#elif USE_SIMPLE_AUDIO_ENGINE
    SimpleAudioEngine::getInstance()->pauseBackgroundMusic();
    SimpleAudioEngine::getInstance()->pauseAllEffects();
#endif
}

// this function will be called when the app is active again
void AppDelegate::applicationWillEnterForeground() {
    Director::getInstance()->startAnimation();

#if USE_AUDIO_ENGINE
    AudioEngine::resumeAll();
#elif USE_SIMPLE_AUDIO_ENGINE
    SimpleAudioEngine::getInstance()->resumeBackgroundMusic();
    SimpleAudioEngine::getInstance()->resumeAllEffects();
#endif
}

void AppDelegate::initOpenGL()
{
	auto director = Director::getInstance();
	auto glview = director->getOpenGLView();
	//required for AppDelegate
	if (!glview)
	{
#if(CC_TARGET_PLATFORM == CC_PLATFORM_WIN32 ||  CC_TARGET_PLATFORM == CC_PLATFORM_MAC ||  CC_TARGET_PLATFORM == CC_PLATFORM_LINUX)
		glview = GLViewImpl::createWithRect("Cocos2dx", Rect(0 , 0, 
			designResolutionSize.width, designResolutionSize.height));
#else
		glview = GLViewImpl::create("Cocos2dx");
#endif
		director->setOpenGLView(glview);
	}
}

void AppDelegate::initMultiResolution()
{
	auto director = Director::getInstance();
	auto glview = director->getOpenGLView();
	glview->setDesignResolutionSize(designResolutionSize.width, designResolutionSize.height, ResolutionPolicy::NO_BORDER);
	vector<string> searchPaths;
	float scaleFactor = 1.0f;
	Size frameSize = glview->getFrameSize();
	if (frameSize.height > mediumResolutionSize.height)
	{
		searchPaths.push_back("res/HDR");
		scaleFactor = largeResolutionSize.height / designResolutionSize.height;
	}
	else if (frameSize.height > smallResolutionSize.height)
	{
		searchPaths.push_back("res/HD");
		scaleFactor = mediumResolutionSize.height / designResolutionSize.height;
	}
	else//largeResolutionSize
	{
		searchPaths.push_back("res/SD");
		scaleFactor = smallResolutionSize.height / designResolutionSize.height;
	}
	director->setContentScaleFactor(scaleFactor);
	FileUtils::getInstance()->setSearchPaths(searchPaths);
}
//initialize Director, setting frame rate
void AppDelegate::initDirector()
{
	auto director = Director::getInstance();
	director->setAnimationInterval(1.0 / 60);
	//director->setDisplayStats(true);//display statistic on the bottom left corner
}
//create game scene and activate it in the Director
void AppDelegate::createAndRunScene()
{
	auto scene = MainMenuScene::createScene();
	Director::getInstance()->runWithScene(scene);
}