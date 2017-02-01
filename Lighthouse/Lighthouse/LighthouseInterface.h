#ifndef __LIGHTHOUSEINTERFACE__
#define __LIGHTHOUSEINTERFACE__

#include "LighthouseMain.h"

class LighthouseInterface
{
private:
	LighthouseMain _mainModule;
	int _updatePosition;
	std::string _newStateData;

public:
	LighthouseInterface() = default;

	void setInitialState(std::string); //the absolute first state

	void eventDataPush(std::string); //push the new app state, pull the changed data state
	int getUpdatePosition(); //Receive the positions that need a view update
	std::string eventDataPull(void);
};
#endif