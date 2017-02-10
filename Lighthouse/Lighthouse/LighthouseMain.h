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
#include "LighthouseHeader.h"

// this class is the main event processing unit.
// it updates the received CodeElement using 'Dictionary' class
// and outputs the child CodeElements according the 'set logic'
// the 'set logic' is browser specific
class LighthouseMain
{
private:
	std::shared_ptr<LighthouseDictionary> _dictionary;

	// this method generates 'exception' type CodeElement messages
	auto exceptionHandler(std::string)->Lighthouse::CodeElement::CodeElement;

public:
	explicit LighthouseMain(std::shared_ptr<LighthouseDictionary> const&);

	//this method handles event from the first browser
	auto firstBrowserProcessEvent(Lighthouse::CodeElement::CodeElement&&)
		->std::tuple<Lighthouse::CodeElement::CodeElement>;

	//this method handles events from the second browser
	auto secondBrowserProcessEvent(Lighthouse::CodeElement::CodeElement&&)
		->std::tuple<Lighthouse::CodeElement::CodeElement, Lighthouse::CodeElement::CodeElement>;


	/* currently unused code */
	//auto thirdBrowserProcessEvent(Lighthouse::CodeElement::CodeElement);
	//auto fourthBrowserProcessEvent(Lighthouse::CodeElement::CodeElement);
};
#endif