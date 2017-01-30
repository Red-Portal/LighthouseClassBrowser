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

	bool compareStates();
public:
	explicit LighthouseMain(); //should be initialized with 'initialState' message

	void processEvents();
};
#endif