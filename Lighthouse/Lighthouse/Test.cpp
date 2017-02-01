#include <gtest/gtest.h>
#include <memory>
#include "ProtobufFiles/LighthouseCodeElement.pb.h"
#include "ProtobufFiles/LighthouseState.pb.h"
#include "LighthouseInterface.h"

#ifdef __TEST__
struct LighthouseInterfaceTest : testing::Test
{
	std::unique_ptr<LighthouseInterface> _interface;

	LighthouseInterfaceTest()
	{
		_interface = std::make_unique<LighthouseInterface>();
	}
	~LighthouseInterfaceTest() = default;
};

namespace TestMessageInitializer
{
	auto initElement(Lighthouse::CodeElement::CodeElement&& _testCodeElement)
	{
		_testCodeElement = Lighthouse::CodeElement::CodeElement();
		_testCodeElement.set__name("name");
		_testCodeElement.set__type(Lighthouse::CodeElement::CodeElement_ElementType_CLASS);

		return _testCodeElement;
	}
	auto initState(Lighthouse::State::State&& _testState)
		->Lighthouse::State::State
	{
		_testState = Lighthouse::State::State();
		
		auto testBrowser = Lighthouse::State::State_Browser();
		

		testBrowser.set__buttonfirststate(true);
		testBrowser.set__buttonsecondstate(false);
		testBrowser.set__buttonthirdstate(true);

		for (auto it = 0; it != 5; ++it)
		{
			auto* _testElement = testBrowser.add__listelement();
			*_testElement = initElement(std::move(*_testElement));
		}
		
		_testState.set_allocated__first(&testBrowser);

		return _testState;
	}
}

TEST_F(LighthouseInterfaceTest, stateInitialization)
{
	auto emptyTestState = Lighthouse::State::State();
	auto initialState = TestMessageInitializer::initState(std::move(emptyTestState));

	_interface->setInitialState(initialState.SerializeAsString());

	auto result = _interface->_mainModule._previousState;
	
	EXPECT_EQ(initialState.SerializeAsString(), result.SerializeAsString());
}

TEST_F(LighthouseInterfaceTest, positionNeedingUpdate)
{
	auto emptyTestState = Lighthouse::State::State();
	auto initialState = TestMessageInitializer::initState(std::move(emptyTestState));

	_interface->setInitialState(initialState.SerializeAsString());

	auto emptyTestStateTwo = Lighthouse::State::State();
	auto initializedState = TestMessageInitializer::initState(std::move(emptyTestState));
	auto it = initializedState.mutable__first()->mutable__listelement()->begin();
	it->set__isselected(true);

	_interface->eventDataPush(initializedState.SerializeAsString());
	auto pos = _interface->getUpdatePosition();

	EXPECT_EQ(2, pos);
}
#endif