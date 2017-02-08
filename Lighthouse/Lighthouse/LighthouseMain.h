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

#ifndef __LIGHTHOUSEMAIN__
#define __LIGHTHOUSEMAIN__
#include "LighthouseTree.h"
#include "ProtobufFiles/LighthouseCodeElement.pb.h"
#include "ProtobufFiles/LighthouseState.pb.h"

class LighthouseMain
{
private:
	
public:
	explicit LighthouseMain() = default;

	auto firstBrowserProcessEvent(Lighthouse::CodeElement::CodeElement)->std::tuple<Lighthouse::CodeElement::CodeElement>;
	auto secondBrowserProcessEvent(Lighthouse::CodeElement::CodeElement)->std::tuple<Lighthouse::CodeElement::CodeElement, Lighthouse::CodeElement::CodeElement>;
	//auto thirdBrowserProcessEvent(Lighthouse::CodeElement::CodeElement);
	//auto fourthBrowserProcessEvent(Lighthouse::CodeElement::CodeElement);

	auto exceptionHandler(std::string)->Lighthouse::CodeElement::CodeElement;
};
#endif