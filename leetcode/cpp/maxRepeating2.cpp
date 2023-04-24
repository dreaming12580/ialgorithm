


class Solution {
public:
	int maxRepeating(string sequence, string word) {
		int n = sequence.size(), m = word.size();
		if (n < m) {
			return 0;
		}

		vector<int> fail(m, -1);
		for (int i = 1; i < m; ++i) {
			int j = fail[i - 1];
			while (j != -1 && word[j + 1] != word[i]) {
				j = fail[j];
			}
			if (word[j + 1] == word[i]) {
				fail[i] = j + 1;
			}
		}

		vector<int> f(n);
		int j = -1;
		for (int i = 0; i < n; ++i) {
			while (j != -1 && word[j + 1] != sequence[i]) {
				j = fail[j];
			}
			if (word[j + 1] == sequence[i]) {
				++j;
				if (j == m - 1) {
					f[i] = (i >= m ? f[i - m]: 0) + 1;
					j = fail[j];
				}
			}
		}
		return *max_element(f.begin(), f.end());
	}
};












