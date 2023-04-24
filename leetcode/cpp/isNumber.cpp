














class Solution {
public:
	enum State {
		STATE_INITIAL, 
		STATE_INT_SIGN,					// 数字符号
		STATE_INTEGER,					// 整数数字
		STATE_POINT,					// 前面有整数的标点符号
		STATE_POINT_WITHOUT_INT,		// 前面没有整数的标点符号
		STATE_FRACTION,					// 小数部分
		STATE_EXP,						// 指数标注
		STATE_EXP_SIGN,					// 指数符号
		STATE_EXP_NUMBER,				// 指数数字
		STATE_END
	};

	enum CharType {
		CHAR_NUMBER,
		CHAR_EXP,
		CHAR_POINT,
		CHAR_SIGN,
		CHAR_ILLEGAL,
	}

	CharType toCharType(char ch) {
		if (ch >= '0' && ch <= '9') {
			return CHAR_NUMBER;
		} else if (ch == 'e' || ch == 'E') {
			return CHAR_EXP;
		} else if (ch == '.') {
			return CHAR_POINT;
		} else if (ch == '+' || ch == '-') {
			return CHAR_SIGN;
		} else {
			return CHAR_ILLEGAL;
		}
	}

	bool isNumber(string s) {
		unordered_map<State, unordered_map<CharType, State>> transfer{
			{
				STATE_INITIAL, {
					{CHAR_NUMBER, STATE_INTEGER},
					{CHAR_POINT, STATE_POINT_WITHOUT_INT},
					{CHAR_SIGN, STATE_INT_SIGN}
				}
			}, {
				STATE_INT_SIGN, {
					{CHAR_NUMBER, STATE_INTEGER},
					{CHAR_POINT, STATE_POINT_WITHOUT_INT}
				}
      }, {
				STATE_INTEGER, {
					{CHAR_NUMBER, STATE_INTEGER},
					{CHAR_EXP, STATE_EXP},
					{CHAR_POINT, STATE_POINT}
				}
			}, {
				STATE_POINT, {
					{CHAR_NUMBER, STATE_FRACTION},
					{CHAR_EXP, STATE_EXP}
				}
			}, {
				STATE_POINT_WITHOUT_INT, {
					{CHAR_NUMBER, STATE_FRACTION}
				}
			}, {
				STATE_FRACTION, {
					{CHAR_NUMBER, STATE_FRACTION},
					{CHAR_EXP, STATE_EXP}
				}
			}, {
				STATE_EXP, {
					{CHAR_NUMBER, STATE_EXP_NUMBER},
					{CHAR_SIGN, STATE_EXP_SIGN},
				}
			}, {
				STATE_EXP_SIGN, {
					{CHAR_NUMBER, STATE_EXP_NUMBER}
				}
			}, {
				STATE_EXP_NUMBER, {
					{CHAR_NUMBER, STATE_EXP_NUMBER}
				}
			}
		};

		int len = s.length();
		State st = STATE_INITIAL;

		for (int i = 0; i < len; ++i) {
			CharType type = toCharType(s[i]);
			if (transfer[st].find(type) == transfer[st].end()) {
				return false;
			} else {
				st = transfer[st][type];
			}
		}
		return st == STATE_INTEGER || st == STATE_POINT || 
				st == STATE_FRACTION || st == STATE_EXP_NUMBER ||
				st == STATE_END;
	}
};











