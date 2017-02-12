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

auto LighthouseDictionary::findElement_mtx(Lighthouse::CodeElement::CodeElement const& element)
->Lighthouse::CodeElement::CodeElement&
{
	auto& key = element._name();

	std::lock_guard<std::mutex> guard(_lock);

	if (_elementsUnorderedMap.count(key) == 0)
	{
		_elementsUnorderedMap[key] = element;
		return _elementsUnorderedMap[key];
	}
	else
		return _elementsUnorderedMap[key];
}
void LighthouseDictionary::setElement_mtx(Lighthouse::CodeElement::CodeElement element)
{
	std::lock_guard<std::mutex>	guard(_lock);
	_elementsUnorderedMap[element._name()] = element;
}