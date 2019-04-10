#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:

    int search(vector<int>& nums, int target) {
        if(nums.empty()) return -1;	
        if(nums.size() == 1 && nums[0] == target) return 0;
        int left = 0;
        int right = nums.size() - 1;
        while(left < right) {
        	if(nums[left] == target) return left;
        	if(nums[right] == target) return right;
        	if(right - left == 2 && nums[left+1] == target) return left+1;
        	right--;
        	left++;
        }
        return -1;
    }
};

int main() {
	Solution s;
	vector<int> v{2,0,1};

	cout << s.search(v,0) << endl;

}