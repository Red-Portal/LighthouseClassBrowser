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

	/*std::string _thirdBrowserMovePosition;

	std::string _fourthBrowserMovePosition;*/

public:
	LighthouseInterface() = default;

	bool firstBrowserDataPush(std::string); //push the new app state, pull the changed data state
	std::string firstBrowserDataPull();

	bool secondBrowserDataPush(std::string);
	std::string secondBrowserDataPull_first();
	std::string secondBrowserDataPull_second();
	std::string secondBrowserMovePositionPull();

	//bool thirdBrowserDataPush(std::string);
	//std::string thirdBrowserMovePositionPull();
	//
	//bool fourthBrowserDataPush(std::string);
	//std::string fourthBrowserMovePositionPull();
};
#endif