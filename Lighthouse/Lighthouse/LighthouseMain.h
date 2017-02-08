#ifndef __LIGHTHOUSEMAIN__
#define __LIGHTHOUSEMAIN__
#include "LighthouseTree.h"
#include "ProtobufFiles/LighthouseCodeElement.pb.h"
#include "ProtobufFiles/LighthouseState.pb.h"

class LighthouseMain
{
private:
	
public:
	explicit LighthouseMain() = default;

	auto firstBrowserProcessEvent(Lighthouse::CodeElement::CodeElement)->std::tuple<Lighthouse::CodeElement::CodeElement>;
	auto secondBrowserProcessEvent(Lighthouse::CodeElement::CodeElement)->std::tuple<Lighthouse::CodeElement::CodeElement, Lighthouse::CodeElement::CodeElement>;
	//auto thirdBrowserProcessEvent(Lighthouse::CodeElement::CodeElement);
	//auto fourthBrowserProcessEvent(Lighthouse::CodeElement::CodeElement);

	auto exceptionHandler(std::string)->Lighthouse::CodeElement::CodeElement;
};
#endif