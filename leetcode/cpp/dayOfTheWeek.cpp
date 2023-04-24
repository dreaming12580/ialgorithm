#include <vector>
#include <string>

using namespace std;

class Solution {
	/** 1970 年 12 月 31 日 是 星期四
	 *  求输入的日期距离1970年12月31日的天数
	*/
public:
	string dayOfTheWeek(int day, int month, int year) {
		vector<string> week = {"Monday", "Tuesday", "Wednesday", 
"Thursday", "Friday", "Saturday", "Sunday"}
		vector<int> monthDays = {31, 28, 31, 30, 31, 30, 31, 31, 
30, 31, 30};
		/* 输入年份之前的年份的天数贡献 */
		int days = 365 * (year - 1971) + (year - 1970 - 1) / 4;
		days -= (year - 1900) / 400;
		/* 输入年份中， 输入月份之前的月份的天数贡献 */
		for (int i = 0; i < month - 1; ++i) {
			days += monthDays[i];
		}
		if ((year % 400 == 0 || (year % 4 == 0 && year % 100 != 0)) && month >= 3) {
			days += 1;
		}
		/* 输入月份中的天数贡献 */
		days += day;
		return week[(days + 3) % 7];
	}
};






