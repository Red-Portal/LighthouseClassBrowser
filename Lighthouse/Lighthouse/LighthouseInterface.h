#ifndef __LIGHTHOUSEINTERFACE__
#define __LIGHTHOUSEINTERFACE__

#include "LighthouseMain.h"

class LighthouseInterface
{
private:
	LighthouseMain _mainModule;

	std::string _firstBrowserResult;
	
	std::string _secondBrowserResult_first;
	std::string _secondBrowserResult_second;
	std::string _secondBrowserMovePostion;

	std::string _thirdBrowserMovePosition;

	std::string _fourthBrowserMovePosition;

public:
	LighthouseInterface() = default;

	void firstBrowserDataPush(std::string); //push the new app state, pull the changed data state
	std::string firstBrowserDataPull();

	void secondBrowserDataPush(std::string);
	std::string secondBrowserDataPull_first();
	std::string secondBrowserDataPUll_second();
	std::string secondBrowserMovePositionPull();

	void thirdBrowserDataPush(std::string);
	std::string thirdBrowserMovePositionPull();
	
	void fourthBrowserDataPush(std::string);
	std::string fourthBrowserMovePositionPull();
};
#endif