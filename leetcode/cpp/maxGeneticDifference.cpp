#include <vector>
#include <iostream>


using namespace std;

struct Node {
	int index[2] = {-1, -1};
	int cnt = 0;
};

Node node[100000 * 18];
int top;

void insert(int root, int val, int depth) {
	node[root].cnt++;
	if (depth == 0) {
		return;
	}
	int ind = ((val & depth) ? 1 : 0);
	if (node[root].index[ind] == -1) {
		node[top] = Node();
		node[root].index[ind] = top++;
	}
	insert(node[root].index[ind], val, depth >> 1);
}

void erase(int root, int val, int depth) {
	node[root].cnt--;
	if (depth == 0) {
		return;
	}	
	int ind = ((val & depth) ? 1 : 0);
	erase(node[root].index[ind], val, depth>>1);
}

void match(int root, int val, int depth, int& anw) {
	if  (depth == 0) {
		return;
	}
	int ind = ((val & depth) ? 1 : 0);
	int other = ind ^ 1;
	if (node[root].index[other] != -1 && node[node[root].index[other]].cnt > 0) {
		anw |= depth;
		match(node[root].index[other], val, depth>>1, anw);
	} else if (node[root].index[ind] != -1 && node[node[root].index[ind]].cnt > 0) {
		match(node[root].index[ind], val, depth>>1, anw);
	}
}




vector<int> edge[100000];
vector<pair<int, int>> query[100000];

class Solution {
public:
	void dfs(int r, vector<int>& anw) {
		insert(0, r, 1 << 17);
		for (const auto& q : query[r]) {
			match(0, q.first, 1<<17, anw[q.second]);
		}
		for (int next : edge[r]) {
			dfs(next, anw);
		}
		erase(0, r, 1<<17);
	}


	vector<int> maxGeneticDifference(vector<int>& parents, vector<vector<int>>& queries) {
		node[top++] = Node();
		node[0].cnt = 1;

		int rroot = 0;
		for (int i = 0; i < parents.size(); i++) {
			query[i].resize(0);
			edge[i].resize(0);
		}

		for (int i = 0; i < parents.size(); i++) {
			int p = parents[i];
			if (p == -1) {
				rroot = i;
			} else {
				edge[p].push_back(i);
			}
		}

		for (int i = 0; i < queries.size(); i++) {
			query[queries[i][0]].push_back(make_pair(queries[i][1], i));
		}

		vector<int> anw(queries.size(), 0);
		dfs(rroot, anw);
		return anw;
	}







};









