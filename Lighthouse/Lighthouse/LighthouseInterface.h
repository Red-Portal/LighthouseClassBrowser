/*
==========================================================================
Copyright 2017 Red - Portal, jzi040941

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

http ://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.
==========================================================================
*/

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