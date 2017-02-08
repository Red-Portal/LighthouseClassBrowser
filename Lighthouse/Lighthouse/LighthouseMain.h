/*
==========================================================================
Copyright 2017 Red - Portal, jzi040941

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

http ://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.
==========================================================================
*/

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