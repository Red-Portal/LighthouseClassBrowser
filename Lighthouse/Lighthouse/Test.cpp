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
	std::shared_ptr<LighthouseDictionary> _dictionary;
	LighthouseMain _mainModule;

	LighthouseMainTest() : _dictionary(std::make_shared<LighthouseDictionary>()), _mainModule(_dictionary)
	{
	}
};
struct LighthouseDictionaryTest: testing::Test
{
	LighthouseDictionary _dict;
};

auto parseFromString(std::string data)
->Lighthouse::CodeElement::CodeElement
{
	Lighthouse::CodeElement::CodeElement element;
	element.ParseFromString(data);

	return element;
}
auto generateTestElement(std::string id, Lighthouse::CodeElement::CodeElement_ElementType type)
->Lighthouse::CodeElement::CodeElement
{
	Lighthouse::CodeElement::CodeElement element;
	element.set__name(id);
	element.set__type(type);

	return element;
}
void makeCollection(Lighthouse::CodeElement::CodeElement& parent , Lighthouse::CodeElement::CodeElement const& child)
{
	auto* ptr = parent.add__child();
	*ptr = child;
}

TEST_F(LighthouseInterfaceTest, FirstBrowserPushPullTest)
{
	auto collection = generateTestElement("collection", Lighthouse::CodeElement::CodeElement_ElementType_COLLECTION);
	auto parent = generateTestElement("parent", Lighthouse::CodeElement::CodeElement_ElementType_TOP);
	auto child = generateTestElement("child", Lighthouse::CodeElement::CodeElement_ElementType_CLASS);

	makeCollection(parent, child);
	makeCollection(collection, parent);


	bool flag = _interface.firstBrowserDataPush(collection.SerializeAsString());

	EXPECT_TRUE(flag);

	auto resultBinary = _interface.firstBrowserDataPull();
	auto result = parseFromString(resultBinary)._child(0);
		
	EXPECT_EQ(result._name(), child._name());
}
TEST_F(LighthouseInterfaceTest, SecondBrowserPushPullTest)
{
	auto classElement = generateTestElement("class", Lighthouse::CodeElement::CodeElement_ElementType_CLASS);
	auto member = generateTestElement("member", Lighthouse::CodeElement::CodeElement_ElementType_MEMBER);
	auto method = generateTestElement("method", Lighthouse::CodeElement::CodeElement_ElementType_METHOD);

	makeCollection(classElement, member);
	makeCollection(classElement, method);

	auto flag = _interface.secondBrowserDataPush(classElement.SerializeAsString());

	EXPECT_TRUE(flag);

	auto first = _interface.secondBrowserDataPull_first();
	auto second = _interface.secondBrowserDataPull_second();

	auto resultFirst = parseFromString(first)._child(0);
	auto resultSecond = parseFromString(second)._child(0);

	EXPECT_EQ(resultFirst._name(), method._name());
	EXPECT_EQ(resultSecond._name(), member._name());
}
TEST_F(LighthouseMainTest, FirstBrowserProcessTest)
{
	auto collection = generateTestElement("collection", Lighthouse::CodeElement::CodeElement_ElementType_COLLECTION);
	auto parent = generateTestElement("parent", Lighthouse::CodeElement::CodeElement_ElementType_TOP);
	auto child = generateTestElement("child", Lighthouse::CodeElement::CodeElement_ElementType_CLASS);

	makeCollection(parent, child);
	makeCollection(collection, parent);

	auto result = _mainModule.firstBrowserProcessEvent(std::move(collection));
	auto first = std::get<0>(result)._child(0);

	EXPECT_EQ(first._name(), child._name());
}
TEST_F(LighthouseMainTest, SecondBrowserProcessTest)
{
	auto classElement = generateTestElement("class", Lighthouse::CodeElement::CodeElement_ElementType_CLASS);
	auto member = generateTestElement("member", Lighthouse::CodeElement::CodeElement_ElementType_MEMBER);
	auto method = generateTestElement("method", Lighthouse::CodeElement::CodeElement_ElementType_METHOD);

	makeCollection(classElement, member);
	makeCollection(classElement, method);

	auto result = _mainModule.secondBrowserProcessEvent(std::move(classElement));
	auto first = std::get<0>(result)._child(0);
	auto second = std::get<1>(result)._child(0);

	EXPECT_EQ(first._name(), method._name());
	EXPECT_EQ(second._name(), member._name());
}
TEST_F(LighthouseDictionaryTest, DictionarySetFindTest)
{
	auto element = generateTestElement("test", Lighthouse::CodeElement::CodeElement_ElementType_CLASS);

	_dict.setElement(element);
	auto result = _dict.findElement(element);

	EXPECT_EQ(result._name(), element._name());
}
TEST_F(LighthouseInterfaceTest, DictionarySetFindTest)
{
	auto element = generateTestElement("test", Lighthouse::CodeElement::CodeElement_ElementType_CLASS);
	_interface.updateElement_mtx(element.SerializeAsString());
	EXPECT_EQ(_interface._dictionary->_elementsUnorderedMap.size(), 1);
	
	auto secondElement = generateTestElement("secondTest", Lighthouse::CodeElement::CodeElement_ElementType_CLASS);
	auto parent = generateTestElement("parent", Lighthouse::CodeElement::CodeElement_ElementType_TOP);
	
	makeCollection(parent, secondElement);
	_interface.updateElement_mtx(parent.SerializeAsString());
	
	makeCollection(parent, element);
	auto result = _interface._dictionary->findElement(parent);

	EXPECT_EQ(result._child_size(), 1);
	EXPECT_EQ(parent._child_size(), 2);
}
#endif