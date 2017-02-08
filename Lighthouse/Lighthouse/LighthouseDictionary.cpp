#include "LighthouseDictionary.h"

auto& LighthouseDictionary::findElement(Lighthouse::CodeElement::CodeElement const& element)
{
	auto& key = element._name();

	std::lock_guard<std::mutex> guard(_lock);

	if (_elementsUnorderedMap.count(key) == 0)
		_elementsUnorderedMap[key] = element;
	else
		return _elementsUnorderedMap[key];
}
void LighthouseDictionary::setElement(Lighthouse::CodeElement::CodeElement const& element)
{
	std::lock_guard<std::mutex>	guard(_lock);
	_elementsUnorderedMap[element._name()] = element;
}
