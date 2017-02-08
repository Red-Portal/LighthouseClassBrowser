#include "LighthouseInterface.h"

bool LighthouseInterface::firstBrowserDataPush(std::string data)
{
	Lighthouse::CodeElement::CodeElement element;
	element.ParseFromString(data);

	auto result = _mainModule.firstBrowserProcessEvent(element);
	auto collection = std::get<0>(result);

	if (collection._type() == Lighthouse::CodeElement::CodeElement_ElementType_EXCEPTION)
		return false;
	else
	{
		_firstBrowserResult = collection.SerializeAsString();
		return true;
	}
}
std::string LighthouseInterface::firstBrowserDataPull()
{
	return _firstBrowserResult;
}
bool LighthouseInterface::secondBrowserDataPush(std::string data)
{
	Lighthouse::CodeElement::CodeElement element;
	element.ParseFromString(data);

	auto result = _mainModule.secondBrowserProcessEvent(std::move(element));
	auto first = std::get<0>(result);
	auto second = std::get<1>(result);

	if (first._type() == Lighthouse::CodeElement::CodeElement_ElementType_EXCEPTION)
		return false;
	else
	{
		_secondBrowserResult_first = first.SerializeAsString();
		_secondBrowserResult_second = second.SerializeAsString();
		return true;
	}
}
std::string LighthouseInterface::secondBrowserDataPull_first()
{
	return _secondBrowserResult_first;
}
std::string LighthouseInterface::secondBrowserDataPull_second()
{
	return _secondBrowserResult_second;
}
std::string LighthouseInterface::secondBrowserMovePositionPull()
{
	return _secondBrowserMovePostion;
}

////void LighthouseInterface::thirdBrowserDataPush(std::string data)
//{
//	Lighthouse::CodeElement::CodeElement element;
//	element.ParseFromString(data);
//
//	auto result = _mainModule.thirdBrowserProcessEvent(element);
//}
//std::string LighthouseInterface::thirdBrowserMovePositionPull()
//{
//	return _thirdBrowserMovePosition;
//}
////void LighthouseInterface::fourthBrowserDataPush(std::string data)
//{
//	Lighthouse::CodeElement::CodeElement element;
//	element.ParseFromString(data);
//
//	auto result = _mainModule.fourthBrowserProcessEvent(element);
//}
//std::string LighthouseInterface::fourthBrowserMovePositionPull()
//{
//	return _fourthBrowserMovePosition;
//}
