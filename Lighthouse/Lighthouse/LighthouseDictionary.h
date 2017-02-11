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

#ifndef __LIGHTHOUSETREE__
#define __LIGHTHOUSETREE__

//this class is for updating the CodeElements asynchronously
//the source analyzation tool will analyze the source,
//make them into CodeElement protobuf messages, and push the into here

//the main module will update it's data by switching the data in hand 
//stored within the dictionary.

//this operation should be able to be done asynchronously
//thus this module is supposed to be thread safe
class LighthouseDictionary
{
private:
	std::unordered_map<std::string, Lighthouse::CodeElement::CodeElement> _elementsUnorderedMap;
	std::mutex _lock;
public:
	LighthouseDictionary() = default;
	~LighthouseDictionary() = default;

	auto findElement_mtx(Lighthouse::CodeElement::CodeElement const&)->Lighthouse::CodeElement::CodeElement&;
	void setElement_mtx(Lighthouse::CodeElement::CodeElement);
};
#endif