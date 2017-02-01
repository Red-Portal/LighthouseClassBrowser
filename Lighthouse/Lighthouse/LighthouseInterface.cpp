#include "LighthouseInterface.h"

void LighthouseInterface::setInitialState(std::string initialStateData)
{
	Lighthouse::State::State initialState;
	initialState.ParseFromString(initialStateData);
	_mainModule = LighthouseMain(std::move(initialState));
}
void LighthouseInterface::eventDataPush(std::string serialData)
{
	Lighthouse::State::State newEventState;
	newEventState.ParseFromString(serialData);
	auto result = _mainModule.processEvent(std::move(newEventState));

	_updatePosition = std::get<0>(result);
	_newStateData = std::get<1>(result);
}
int LighthouseInterface::getUpdatePosition()
{
	return _updatePosition;
}
std::string LighthouseInterface::eventDataPull()
{
	return _newStateData;
}