#include <iostream>
#include <vector>

using namespace std;


/*

Given an unsorted integer array, find the smallest missing positive integer.

Example 1:

Input: [1,2,0]
Output: 3

Example 2:

Input: [3,4,-1,1]
Output: 2


Input: [3,4,2,-1,1]

Example 3:

Input: [7,8,9,11,12]
Output: 1

Note:

Your algorithm should run in O(n) time and uses constant extra space.


*/


class Solution {
public:

	void swap(vector<int>& nums, int i, int j) {
	    int temp = nums[i];
	    nums[i] = nums[j];
	    nums[j] = temp;
	}

    int firstMissingPositive(vector<int>& nums) {
    	if(nums.empty()) return 1;
    	int n = nums.size();
    	for(int i = 0; i < n;i++) {
    		while(nums[i] > 0 && nums[i] <= n && nums[i] != nums[nums[i]-1]) {
    			swap(nums, i,nums[i] - 1);
    		}
    	}
	    for (int i = 0; i < n; i++) {
	        if (nums[i] != i + 1) {
	            return i + 1;
	        }
	    }

   		return n + 1;
    }
};


int main() {
	return 0;
}