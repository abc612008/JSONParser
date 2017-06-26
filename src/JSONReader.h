#pragma once
#include "basedef.h"
#include "JSONObject.h"
#include <memory>
#include <cwctype>
#include <tuple>

namespace JSON{
class JSONReader {
public:
	static std::unique_ptr<Element> parse(string jsonStr) {
		JSONReader reader(jsonStr);
		return std::move(reader.doParse());
	}

private:
	JSONReader(string jsonStr) : mJsonStr(jsonStr) {}
	~JSONReader() = default;

	std::unique_ptr<Element> doParse() {
		for (;;) {
			switch (tokenNow) {
			case TOKEN_OBJECT_BEGIN:

			}
			mPosition++;
		}
	}

	enum class Token {
		ObjectBegin,
		ObjectEnd,
		ObjectColon,
		String,
		Comma,
		Number,
	};

	union Data {
		Data() = default;
		Data(const Data&) = default;
		NumberType number;
		std::string_view string;
	};

	std::tuple<Token, Data> readNextToken() {
		for (;;) {
			jchar charNow = mJsonStr[mPosition];
			mPosition++;
			switch (charNow) {
			case ' ':
				continue;
			case '{':
				return { Token::ObjectBegin ,{} };
			case '}':
				return { Token::ObjectEnd ,{} };
			case ':':
				return { Token::ObjectColon ,{} };
			case ',':
				return { Token::Comma ,{} };
			case '\'':
			case '"':
				
			}
			if (std::iswdigit(charNow) || charNow == '-') {
				NumberType number = charNow=='-'?-1:charNow-'0';
				mPosition++;
				while ((std::iswdigit(mJsonStr[mPosition]))) {
					number = number * 10 + (mJsonStr[mPosition] - '0');
					mPosition++;
				}
				return { Token::Number, {number} };
			}
		}
	}

	string mJsonStr;
	uint32 mPosition = 0;
};
}
