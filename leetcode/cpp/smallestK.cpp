#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
using namespace std;


class Solution {
    int partition(vector<int>& nums, int l, int r) {
        int pivot = nums[r];
        int i = l - 1;
        for (int j = l; j <= r - 1; ++j) {
            if (nums[j] <= pivot) {
                i = i + 1;
                swap(nums[i], nums[j]);
            }
        }
        swap(nums[i + 1], nums[r]);
        return i + 1;
    }

    // 基于随机的划分
    int randomized_partition(vector<int>& nums, int l, int r) {
        int i = rand() % (r - l + 1) + l;
        swap(nums[r], nums[i]);
        return partition(nums, l, r);
    }

    void randomized_selected(vector<int>& arr, int l, int r, int k) {
        if (l >= r) {
            return;
        }
        int pos = randomized_partition(arr, l, r);
        int num = pos - l + 1;
        if (k == num) {
            return;
        } else if (k < num) {
            randomized_selected(arr, l, pos - 1, k);
        } else {
            randomized_selected(arr, pos + 1, r, k - num);
        }
    }

public:
    vector<int> smallestK(vector<int>& arr, int k) {
        srand((unsigned)time(NULL));
        randomized_selected(arr, 0, (int)arr.size() - 1, k);
        vector<int> vec;
        for (int i = 0; i < k; ++i) {
            vec.push_back(arr[i]);
        }
        return vec;
    }
};

int main() {
	vector<int> vec = {-5,-1,-3,-9149,9,-30504,6,-8,5,-74,9256,-757,-61878,-4,8,470,5549,-774,-333,-314,590,294,-1842,-1,-28424,-7316,-43721,62039,-7760,983,-40,-888,17759,5480,6,7436,-3,-6232,-67,2058,93,51400,-42083,44,-1,-8541,55,-6,-61881,6867,230,-91,-9,335,-625,-92,80,500,2147,-8925,-52447,-9,-710,-386,-17008,7,-599,8493,6,451,8,-397,4111,54,-3843,4440,34,4,57762,2641,64449,15639,-14,30192,-7595,-41815,193,-6783,62,8793,-397,1,-403,-35,-500,20996,-1747,838,44848,-439,7406,84,-1240,1,8188,-7153,-31,-22040,-19,31,8288,-22814,5759,-5046,-3157,-3864,-4,4278,42,-15,5712,-167,21973,0,58,-37814,-53301,1,6555,883,8,-68,-943,-4,19,1,-6,-876,219,-57,46,0,-23,-38,15,-35,-8833,21,-2540,57314,6244,-8061,-1,3450,-299,-29,9103,-86,587,3,2,-75,210,-70,69,26,3,275,17,-70,24962,-2,9476,52106,153,-19415,-4751,-57846,-2,22750,79,-8677,1,-2,-819,94,-4,-229,-9304,-30,35,-5524,-25002,-11781,-754,-866,8,-4874,-49488,-4724,62413,674,32750,-462,580,-530,4630,2454,-435,377,9192,605,-66,266,533,-33843,789,720,-5,29986,-520,-9,-45,3,2,12,188,56,-8,-53777,-363,29620,-84,4,-90,-3,-38291,547,64,59633,-75,-42535,-2802,-35669,-622,-199,2348,-42473,3,8636,-8,-10053,3,-3960,8421,6,820,17699,1,-6052,5515,479,-7,3,-4811,-9,-4,-97,3,-733,-65,3937,2087,6786,-38910,3653,-3278,-97,-44741,8,51,-803,-636,-8027,-831,-7947,4307,-37,-67,62750,6112,-7,624,-24007,-7845,-582,864,-2,329,-324,12,-42245,-503,-4969,-156,280,-989,1710,-5334,264,-879,-1025,-38546,7537,-61,-30935,5,8,51556,-61,12174,-2559,-27,93,44953,-420,0,7934,-35440,0,-11,866,54776,55,697,-85,943,42975,306,43540,46266,8171,-5,-2,-9423,-35779,48,-1,877,-595,2,37302,-39,135,8215,55078,0,999,-18,9270,3,30,6861,22645,75,53862,-55,15878,-32258,37,-8,30,-2,-43,-2592,0,-9775,6,-84,-9283,10591,-73,-47819,5,-2408,0,625,-41131,740,81,-45104,13,46,9927,65,66,0,718,188,-52821,-638,-191,-37515,-6,7,20171,839,5218,-31646,34383,5217,-634,22,6,644,-42002,64185,315,895,-41,-61566,731,9,586,-532,55730,2,-19509,6056,2,-21780,-8640,-8,918,-5,-3783,-6,1,-9,-58,-9439,-9,-557,-676,659,-15,40,14840,-291,16273,-2811,3585,14786,-33509,-9364,-61887,-6,-82,-37043,3776,-3,-59909,17305,17310,345,-5,870,292,1042,-667,9,3380,52149,-2610,0,-873,1845,31,-10003,96,-5,4,7,-44407,-14615,-39092,-29084,-64468,40579,-34666,-1,17,-67,-12,6122,699,6402,2468,6066,-23,-44,800,4719,-14,-17,-26430,750,143,-1678,431,7855,96,0,48,29,64907,-394,4949,9618,-462,-65452,-14,-16,8,-275,-232,-25551,-745,-370,-7,-91,-9,-2833,4557,-2261,-42,17,31665,-49236,7,3268,-770,-7,24412,502,-19229,256,-6,1,22,-42,6691,43267,54646,605,61076,-2382,-141,-734,-155,-3104,-2,-173,6117,-66,33,-21792,-46,-9472,832,-529,42,19523,6,7,-6400,33164,81,0,-7686,-608,54,26676,-38,-7908,-596,183,28,867,113,0,-21,-9425,-47859,7,7294,-9462,30601,16368,50452,378,15911,58382,5,6,-717,501,1097,-254,-7220,-2517,-915,-2662,17876,923,-8704,-7,5,7,5390,-2726,571,409,-3199,21,-50057,9859,-4090,-90,-8493,-156,-15,54034,-4675,-6,1,-7,-57,45,-2,737,5695,9597,29715,59,-2,-30783,1381,84,30713,-818,-7,-72,-25864,9,57,1,-11322,52912,42156,952,-152,-17080,99,-79,-5,9247,-45476,-31519,-527,45151,-35568,14568,7725,51292,-30705,3,899,-4988,258,-63,7,79,0,9747,18560,-49712,-61306,-9,4,-1067,13235,-15052,-50,96,13775,-998,2,-41487,-1497,9,-51,97,2,6,4141,39877,-426,9,-4610,3,846,929,3971,135,408,48138,-850,-161,-7900,-3,-14,916,23,8221,-607,31690,-32,607,5729,5171,7009,-181,6555,13,-45,-24,-11,42756,5,-98,-4424,-44,13,4187,-7,-27394,-50361,20156,344,-33831,-3};
	int k = 257;
	Solution s;
	vector<int> ans = s.smallestK(vec, k);
	sort(ans.begin(), ans.end());
	cout << "ans:";
	for (auto item: ans) {

		cout << " " << item;
	}
	cout << endl;
}












