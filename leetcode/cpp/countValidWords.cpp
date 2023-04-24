
#include <string>



using namespace std;


class Solution {


	enum State {
		STATE_BEGIN,
		STATE_LETTER,
		STATE_HYPHEN,
		STATE_END,
	};

	enum CharType {
		CHAR_LETTER,
		CHAR_NUMBER,
		CHAR_HYPHEN,
		CHAR_POINT,
		CHAR_SPACE,
		CHAR_END,
		CHAR_ILLEGAL,
	};

	CharType toCharType(char ch) {
		if (ch >= '0' && ch <= '9') {
			return CHAR_NUMBER;
		} else if (ch >= 'a' && ch <= 'z') {
			return CHAR_LETTER;
		} else if (ch == '-') {
			return CHAR_HYPHEN;
		} else if (ch == '!' || ch == '.' || ch == ',') {
			return CHAR_POINT;
		} else if (ch == ' ') {
			return CHAR_SPACE;
		} else {
			return CHAR_ILLEGAL;
		}
	}

	unordered_map<State, unordered_map<CharType, State>> transfer{
		STATE_BEGIN, {
			{CHAR_LETTER, STATE_LETTER},
			{CHAR_POINT, STATE_POINT},
		},
		STATE_LETTER, {
			{CHAR_LETTER, STATE_LETTER},
			{CHAR_END, STATE_END},
		},
		STATE_POINT, {
			{CHAR_SPACE, STATE_END},
			{CHAR_END, STATE_END},
		},

		STATE_HYPHEN, {
			{CHAR_LETTER, STATE_LETTER},
		},
	};



public:
	int countValidWords(string sentence) {
		int len = sentence.length();
		State st = STATE_BEGIN;

		for (int i = 0; i < len; ++i) {
			CharType type = toCharType(sentence[i]);
			if (transfer[st].find(type) == transfer[st].end()) {
				return false;
			} else {
				st = transfer[st][type];
			}
		}
		if (transfer[st].find(STATE_END) == transfer[st].end()) {
			return false;
		}
		return true;
	}
}
















