#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:


	vector<vector<int>> ret;

	bool combination(vector<int>& candidates, vector<int> &vv, int cur, int sum,int target) {
		int v = candidates[cur];
		int remian = target - sum;
		if(v > remian) {
			return false;
		} else {
			vv.push_back(v);
			if(remian == v) {
				ret.push_back(vv);
				vv.pop_back(); 
				return true;
			} else {
				bool ok = false;
				for(int i = cur + 1; i < candidates.size();i++) {
					if(candidates[i] + sum + v > target) {
						break;
					} else {
						if(combination(candidates,vv,i,sum + v,target)) {
							ok = true;
							int j = i + 1;
							for(; j < candidates.size();j++) {
								if(candidates[j] != candidates[i]) {
									break;
								}
							}
							i = j - 1;
						}
					}						
				}
				vv.pop_back();
				return ok;
			}
		}
	}

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
    	ret.clear();
    	sort(candidates.begin(),candidates.end());
    	for(int i = 0; i < candidates.size();i++) {
    		if(i > 0 && candidates[i] == candidates[i-1]) continue;
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
	vector<int> v{2,2,2};////{10,1,2,2,7,6,1,5};//1,1,2,5,6,7,10
	ret = s.combinationSum2(v,4);
	show(ret);

	/*vector<int> v1{2,3,5};
	ret = s.combinationSum(v1,8);
	show(ret);*/

	return 0;
}