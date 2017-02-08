/*
==========================================================================
LighthouseClassBrowser, a smalltalk Class Browser style plugin module
Copyright (C) 2017  Red-Portal, jzi040941

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
==========================================================================
*/

#ifndef __LIGHTHOUSEINTERFACE__
#define __LIGHTHOUSEINTERFACE__

#include "LighthouseMain.h"

class LighthouseInterface
{
private:
	LighthouseMain _mainModule;
	LighthouseDictionary _dictionary;

	std::string _firstBrowserResult;
	
	std::string _secondBrowserResult_first;
	std::string _secondBrowserResult_second;
	std::string _secondBrowserMovePostion;

	/*std::string _thirdBrowserMovePosition;

	std::string _fourthBrowserMovePosition;*/

public:
	void updateElement_mtx(std::string const& );

	bool firstBrowserDataPush(std::string const& ); //push the new app state, pull the changed data state
	std::string firstBrowserDataPull();

	bool secondBrowserDataPush(std::string const& );
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