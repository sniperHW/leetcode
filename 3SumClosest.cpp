#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:

    int threeSumClosest(vector<int>& nums, int target) {
        int size = nums.size();
        if(size < 3) {
        	return 0;
        } else if(size == 3) {
        	return nums[0] + nums[1] + nums[2];
        }
        sort(nums.begin(),nums.end());

        int closest = 0;
        int minAbs = 0x7FFFFFFF;

        for(int i = 0; i < size - 1; i++) {
        	int n1 = nums[i];
        	int j = i + 1;
        	int k = size - 1;
        	while(j < k) {
        		int n2 = nums[j];
        		int n3 = nums[k];
        		int s  = target - (n1 + n2 + n3); 
        		if(abs(s) < minAbs){
        			minAbs = abs(s);
        			closest = (n1 + n2 + n3);
        		}	

        		if(s == 0) {
        			return closest;
        		} else if(s < 0){
        			k--;
        		} else {
        			j++;
        		}
        	}
        }
        return closest;
    }
};

int main() {

	Solution s;

	vector<int> v{1,1,1,2};

	//vector<int> v{-4,-1,1,3};

	//vector<int> v{-4,-1,1,2};

	cout << s.threeSumClosest(v,1) << endl;

	return 0;
}