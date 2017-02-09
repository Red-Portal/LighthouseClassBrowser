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

#include <gtest/gtest.h>
#include <memory>
#include "ProtobufFiles/LighthouseCodeElement.pb.h"
#include "ProtobufFiles/LighthouseState.pb.h"
#include "LighthouseInterface.h"

#ifdef __TEST__
/* class test fixtures*/
struct LighthouseInterfaceTest : testing::Test
{
	LighthouseInterface _interface;
};
struct LighthouseMainTest: testing::Test
{
	LighthouseMain _mainModule;
};
struct LighthouseDictionaryTest: testing::Test
{
	LighthouseDictionary _dict;
};

TEST_F(LighthouseInterfaceTest, FirstBrowserPushPullTest)
{
	_interface.firstBrowserDataPush();
	_interface.firstBrowserDataPull();
	EXPECT_EQ();
}
TEST_F(LighthouseInterfaceTest, SecondBrowserPushPullTest)
{
	_interface.secondBrowserDataPush();
	_interface.secondBrowserDataPull_first();
	_interface.secondBrowserDataPull_second();
	EXPECT_EQ();
	EXPECT_EQ();
}
TEST_F(LighthouseMainTest, FirstBrowserProcessTest)
{
	auto result = _mainModule.firstBrowserProcessEvent();
	auto first = std::get<0>(result);

	EXPECT_EQ();
}
TEST_F(LighthouseMainTest, SecondBrowserProcessTest)
{
	auto result = _mainModule.secondBrowserProcessEvent();
	auto first = std::get<0>(result);
	auto second = std::get<1>(result);

	EXPECT_EQ();
	EXPECT_EQ();
}
TEST_F(LighthouseDictionaryTest, DictionarySetFindTest)
{
	_dict.setElement();
	auto result = _dict.findElement();

	EXPECT_EQ();
}
#endif