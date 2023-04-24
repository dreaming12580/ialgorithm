
#include <unordered_map>
#include <set>
#include <vector>


using namespace std;



class MovieRentingSystem {
private:
	static constexpr auto pairHash = [fn = hash<int>()](const pair<int, int>& o) {
		return (fn(o.first) << 16) ^ fn(o.second);
	};

	// map < pair<shop, movie>, price> 
	unordered_map<pair<int, int>, int, decltype(pairHash)> t_price{0, pairHash};

	// map <movie, set <price, shop> >
	unordered_map<int, set<pair<int, int>>> t_valid;

	// set <price, shop, movie> 
	set<tuple<int, int, int>> t_rent;

public:
	// entries 中的 (shop, movie, price)
	MovieRentingSystem(int n, vector<vector<int>>& entries) {
		for (const auto& entry : entries) {
			t_price[{entry[0], entry[1]}] = entry[2];
			t_valid[entry[1]].insert({entry[2], entry[0]});
		}
	}

	vector<int> search(int movie) {
		if (!t_valid.count(movie)) {
			return {};
		}
		vector<int> ret;
		auto it = t_valid[movie].begin();
		for (int i = 0; i < 5 && it != t_valid[movie].end(); ++i, ++it) {
			ret.push_back(it->second);
		}
		return ret;
	}

	void rent(int shop, int movie) {
		int price = t_price[{shop, movie}];
		t_valid[movie].erase({price, shop});
		t_rent.emplace(price, shop, movie);
	}

	void drop(int shop, int movie) {
		int price = t_price[{shop, movie}];
		t_valid[movie].emplace(price, shop);
		t_rent.erase({price, shop, movie});
	}

	vector<vector<int>> report() {
		vector<vector<int>> ret;
		auto it = t_rent.begin();
		for (int i = 0; i < 5 && it != t_rent.end(); ++i, ++it) {
			ret.emplace_back(initializer_list<int>{get<1>(*it), get<2>(*it)});
		}
		return ret;
	}




};




















