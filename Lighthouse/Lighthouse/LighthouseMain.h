#ifndef __LIGHTHOUSEMAIN__
#define __LIGHTHOUSEMAIN__
#include "LighthouseTree.h"
#include "ProtobufFiles/LighthouseCodeElement.pb.h"
#include "ProtobufFiles/LighthouseState.pb.h"

class LighthouseMain
{
private:
	Lighthouse::State::State _previousState;
	LighthouseTree _sourceTree;
	
	inline int findSelected(Lighthouse::State::State::Browser const&) const; //this returns the index of a 'isSelected -> true'
	inline bool isStateUnchanged(Lighthouse::State::State::Browser const&, Lighthouse::State::State::Browser const&, int) const; // is the selected item a 'newly selected item'?
public:
	explicit LighthouseMain(Lighthouse::State::State&&); //should be initialized with 'initialState' message
	explicit LighthouseMain() = default;

	auto processEvent(Lighthouse::State::State&&)->std::tuple<int, std::string>;
	std::string getMovePosition();
};
#endif