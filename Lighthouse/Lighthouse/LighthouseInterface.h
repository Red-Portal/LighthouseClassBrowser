#ifndef __LIGHTHOUSEINTERFACE__
#define __LIGHTHOUSEINTERFACE__

#include "LighthouseMain.h"

class LighthouseInterface
{
private:
	LighthouseMain _mainModule;
public:
	LighthouseInterface();

	void setInitialState(std::string); //the absolute first state

	bool shouldMoveToPoint(); //If There is the need to Move to a certain point
	std::string getPointPosition(); //Get the coordination of that point

	void eventDataPush(std::string); //push the new app state, pull the changed data state
	int getUpdatePosition(); //Receive the positions that need a view update
	std::string eventDataPull(void);
};
#endif