#include "LighthouseMain.h"
#include <functional>

LighthouseMain::LighthouseMain(Lighthouse::State::State&& initialState)
	: _previousState{std::move(initialState)}
{}
inline int LighthouseMain::findSelected(Lighthouse::State::State::Browser const& browser) const
{
	int index = 0;
	for(auto it : browser._listelement())
	{
		++index;
		if (it._isselected())
			return index;
	}

	return -1;
}
inline bool LighthouseMain::isStateUnchanged(Lighthouse::State::State::Browser const& current,
	Lighthouse::State::State::Browser const& previous, int index) const
{
	bool currentState = current._listelement(index)._isselected();
	bool previousState = previous._listelement(index)._isselected();
	
	return currentState == previousState;
}
auto LighthouseMain::processEvent(Lighthouse::State::State&& eventState) 
-> std::tuple<int, std::string>		
{ 
	int indexSecond = findSelected(eventState._second());
	int indexThird = findSelected(eventState._third());
	int indexFourth = findSelected(eventState._fourth());

	if (indexSecond > 0)
		if (!isStateUnchanged(eventState._second(), _previousState._second(), indexSecond))

	if(indexSecond > 0)
		if(!isStateUnchanged(eventState._third(), _previousState._third(), indexThird))
	
	if(indexFourth > 0)
		if(!isStateUnchanged(eventState._fourth(), _previousState._fourth(), indexFourth))



	return std::make_tuple(int{}, std::string(""));
}