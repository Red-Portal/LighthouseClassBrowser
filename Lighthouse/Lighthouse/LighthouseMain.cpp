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

#include "LighthouseMain.h"

LighthouseMain::LighthouseMain(LighthouseDictionary& dict)
{
	_dictionary = std::make_shared<LighthouseDictionary>(dict);
}

//argument: CodeElement object of type 'collection' the collection should contain all the selected
//sourcefiles(for C++, C#), packages(for Java)
//return : CodeElement object of type 'collection' containing all the children classes of the selected elements
auto LighthouseMain::firstBrowserProcessEvent(Lighthouse::CodeElement::CodeElement&& element)
->std::tuple<Lighthouse::CodeElement::CodeElement>
{
	Lighthouse::CodeElement::CodeElement collection;
	collection.set__type(Lighthouse::CodeElement::CodeElement_ElementType_COLLECTION);
	
	if (element._type() != Lighthouse::CodeElement::CodeElement_ElementType_COLLECTION)
		return std::make_tuple(exceptionHandler("Wrong input Type"));

	auto updatedElement = _dictionary->findElement(element);

	for (auto&& i : updatedElement._child())
	{
		if (i._type() != Lighthouse::CodeElement::CodeElement_ElementType_TOP)
			return std::make_tuple(exceptionHandler("Wrong Child Element Type: should be a sourcefile/package"));

		for (auto&& j : i._child())
		{
			auto ptr = collection.add__child();
			*ptr = j;
		}
	}

	return std::make_tuple(collection);
}

//argument: CodeElement object of type class. This is the 'selected' list element
//return : A tuple of CodeElements type member variable and method.
//The member variables and methods of the selected class
auto LighthouseMain::secondBrowserProcessEvent(Lighthouse::CodeElement::CodeElement&& element)
->std::tuple<Lighthouse::CodeElement::CodeElement, Lighthouse::CodeElement::CodeElement>
{
	Lighthouse::CodeElement::CodeElement methodCollection;
	Lighthouse::CodeElement::CodeElement memberCollection;
	methodCollection.set__type(Lighthouse::CodeElement::CodeElement_ElementType_COLLECTION);
	memberCollection.set__type(Lighthouse::CodeElement::CodeElement_ElementType_COLLECTION);

	if (element._type() != Lighthouse::CodeElement::CodeElement_ElementType_CLASS)
		return std::make_tuple(exceptionHandler("Wrong input Type"), Lighthouse::CodeElement::CodeElement{});

	auto updatedElement = _dictionary->findElement(element);

	for (auto&& i : updatedElement._child()) // the input is a collection of sourcefiles
	{
		if (i._type() == Lighthouse::CodeElement::CodeElement_ElementType_METHOD)
		{
			auto ptr = methodCollection.add__child();
			*ptr = i;
		}
		else if (i._type() == Lighthouse::CodeElement::CodeElement_ElementType_MEMBER)
		{
			auto ptr = memberCollection.add__child();
			*ptr = i;
		}
		else
			return std::make_tuple(exceptionHandler("Wrong Child Element Type: should be a method or a member"), Lighthouse::CodeElement::CodeElement{});
	}

	return std::make_tuple(methodCollection, memberCollection);
}

// exception generator. Outputs an exceptiion type CodeElement object, using the input exceptionMessage
// the exception message is stored in the 'name' section
auto LighthouseMain::exceptionHandler(std::string exceptionMessage)
->Lighthouse::CodeElement::CodeElement
{
	Lighthouse::CodeElement::CodeElement exception;

	exception.set__type(Lighthouse::CodeElement::CodeElement_ElementType_EXCEPTION);
	exception.set__name(exceptionMessage);

	return exception;
}

/* currently unused code */
//auto LighthouseMain::thirdBrowserProcessEvent(Lighthouse::CodeElement::CodeElement element)
//{
//	return	
//}
//auto LighthouseMain::fourthBrowserProcessEvent(Lighthouse::CodeElement::CodeElement element)
//{
//	return 	
//}