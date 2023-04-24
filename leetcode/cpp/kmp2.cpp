

class KMP {
public:
	// pi[i], 子串s[0...i]最长的相等的真前缀与真后缀的长度

	vector<int> prefix_function(string s) {
		int n = (int)s.length();
		vector<int> pi(n);
		for (int i = 1; i < n; ++i) {
			for (int j = i; j >= 0; --j) {
				if (s.substr(0, j) == s.substr(i - j + 1, j)) {
					pi[i] = j;
					break;
				}
			}
		}
		return pi;
	}

	vector<int> prefix_function2(string s) {
		int n = (int)s.length();
		vector<int> pi(n);
		for (int i = 1; i < n; ++i) {
			for (int j = pi[i - 1] + 1; j >= 0; --j) {
				if (s.substr(0, j) == s.substr(i - j + 1, j)) {
					pi[i] = j;
					break;
				}
			}
		}
		return pi;
	}

	vector<int> prefix_function3(string s) {
		int n = (int)s.length();
		vector<int> pi(n);
		for (int i = 1; i < n; ++i) {
			int j = pi[i - 1];
			while (j > 0 && s[i] != s[j]) {
				j = pi[j - 1];
			}
			if (s[i] == s[j]) {
				++j;
			}
			pi[i] = j;
		}
		return pi;
	}
};














