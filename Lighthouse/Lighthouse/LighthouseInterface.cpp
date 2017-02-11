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

#include "LighthouseHeader.h"

LighthouseInterface::LighthouseInterface() : _dictionary(std::make_shared<LighthouseDictionary>()), _mainModule(_dictionary)
{}

void LighthouseInterface::updateElement_mtx(std::string const& update)
{
	Lighthouse::CodeElement::CodeElement element;
	element.ParseFromString(update);
	
	_dictionary->setElement_mtx(std::move(element));
}

bool LighthouseInterface::firstBrowserDataPush(std::string const& data)
{
	Lighthouse::CodeElement::CodeElement element;
	element.ParseFromString(data);

	auto result = _mainModule.firstBrowserProcessEvent(std::move(element));
	auto collection = std::get<0>(result);

	if (collection._type() == Lighthouse::CodeElement::CodeElement_ElementType_EXCEPTION)
		return false;
	else
	{
		_firstBrowserResult = collection.SerializeAsString();
		return true;
	}
}
std::string LighthouseInterface::firstBrowserDataPull()
{
	return _firstBrowserResult;
}
bool LighthouseInterface::secondBrowserDataPush(std::string const& data)
{
	Lighthouse::CodeElement::CodeElement element;
	element.ParseFromString(data);

	auto result = _mainModule.secondBrowserProcessEvent(std::move(element));
	auto first = std::get<0>(result);
	auto second = std::get<1>(result);

	if (first._type() == Lighthouse::CodeElement::CodeElement_ElementType_EXCEPTION)
		return false;
	else
	{
		_secondBrowserResult_first = first.SerializeAsString();
		_secondBrowserResult_second = second.SerializeAsString();
		return true;
	}
}
std::string LighthouseInterface::secondBrowserDataPull_first()
{
	return _secondBrowserResult_first;
}
std::string LighthouseInterface::secondBrowserDataPull_second()
{
	return _secondBrowserResult_second;
}
std::string LighthouseInterface::secondBrowserMovePositionPull()
{
	return _secondBrowserMovePostion;
}

////void LighthouseInterface::thirdBrowserDataPush(std::string data)
//{
//	Lighthouse::CodeElement::CodeElement element;
//	element.ParseFromString(data);
//
//	auto result = _mainModule.thirdBrowserProcessEvent(element);
//}
//std::string LighthouseInterface::thirdBrowserMovePositionPull()
//{
//	return _thirdBrowserMovePosition;
//}
////void LighthouseInterface::fourthBrowserDataPush(std::string data)
//{
//	Lighthouse::CodeElement::CodeElement element;
//	element.ParseFromString(data);
//
//	auto result = _mainModule.fourthBrowserProcessEvent(element);
//}
//std::string LighthouseInterface::fourthBrowserMovePositionPull()
//{
//	return _fourthBrowserMovePosition;
//}
