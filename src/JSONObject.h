#pragma once
#include "basedef.h"
#include "Element.h"
#include <unordered_map>
namespace JSON{
class JSONObject : public Element {
public:


private:
	using KeyType = string;
	using ValueType = Element;
	using DataType = std::unordered_map<KeyType, ValueType>;
	DataType mData;
};
}
