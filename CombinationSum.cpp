/*
Given a set of candidate numbers (candidates) (without duplicates) and a target number (target), find all unique combinations in candidates where the candidate numbers sums to target.

The same repeated number may be chosen from candidates unlimited number of times.

Note:

    All numbers (including target) will be positive integers.
    The solution set must not contain duplicate combinations.

Example 1:

Input: candidates = [2,3,6,7], target = 7,
A solution set is:
[
  [7],
  [2,2,3]
]

Example 2:

Input: candidates = [2,3,5], target = 8,
A solution set is:
[
  [2,2,2,2],
  [2,3,3],
  [3,5]
]


Input: candidates = [2,3,5], target = 7,
A solution set is:
[
  [2,2,3],
  [2,5]
]

*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:


	vector<vector<int>> ret;

	void combination(vector<int>& candidates, vector<int> &vv, int cur, int sum,int target) {
		int v = candidates[cur];
		int remian = target - sum;
		if(v > remian) {
			return;
		} else {
			vv.push_back(v);
			if(remian == v) {
				ret.push_back(vv);
			} else {
				for(int i = cur; i < candidates.size();i++) {
					if(candidates[i] + sum + v > target) {
						break;
					} else {
						combination(candidates,vv,i,sum + v,target);
					}
				}
			}
			vv.pop_back();
		}
	}

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    	ret.clear();
    	sort(candidates.begin(),candidates.end());
    	for(int i = 0; i < candidates.size();i++) {
    		if(candidates[i] > target) break;
    		vector<int> vv;
    		combination(candidates,vv,i,0,target);
    	}
    	return ret;
    }
};

void show(vector<vector<int> > &v) {
	for(int i = 0; i < v.size(); i++) {
		for(int j = 0; j < v[i].size(); j++) {
			cout << v[i][j] << ",";
		}
		cout << endl;
	}
}

int main() {
	vector<vector<int> > ret;
	Solution s;
	vector<int> v{2,3,6,7};
	ret = s.combinationSum(v,7);
	show(ret);

	vector<int> v1{2,3,5};
	ret = s.combinationSum(v1,8);
	show(ret);

	return 0;
}