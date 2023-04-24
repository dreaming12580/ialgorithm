#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
	string longestWord(vector<string>& words) {
		// 按照单词的长度升序排序， 如果长度相同则按照字典序降序排序。
		sort(words.begin(), words.end(), [](const string& a, const string& b) { 
			if (a.size() != b.size()) {
				return a.size() < b.size();
			} else {
				return a > b;
			}
		});

		string longest = "";
		unordered_set<string> cnt;
		cnt.emplace("");
		for (auto& word : words) {
			if (cnt.count(word.substr(0, word.size() - 1))) {
				cnt.emplace(word);
				longest = word;
			}
		}
		return longest;
	}
};












