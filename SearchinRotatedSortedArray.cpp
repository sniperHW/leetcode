#include <iostream>
#include <vector>

using namespace std;


/*
Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.

(i.e., [0,1,2,4,5,6,7] might become [4,5,6,7,0,1,2]).

You are given a target value to search. If found in the array return its index, otherwise return -1.

You may assume no duplicate exists in the array.

Your algorithm's runtime complexity must be in the order of O(log n).

Example 1:

Input: nums = [4,5,6,7,0,1,2], target = 0

7 0 1 2 3 4 5 6

1 2 3 4 5 6 7 0

Output: 4

Example 2:

Input: nums = [4,5,6,7,0,1,2], target = 3
Output: -1


*/

/*
class Solution {
public:
    int search(vector<int>& nums, int target) {
        if(nums.size()==0) return -1;
        
        int start=0,end=nums.size()-1;
        
        while(start+1<end){
            int mid=start+(end-start)/2;
            
            if(target==nums[mid]) return mid;
            if(nums[mid]>nums[start]){
                if(nums[start]<=target && target<=nums[mid]){
                    end=mid;
                }else{
                    start=mid;
                }
            }
            if(nums[mid]<nums[start]){
                if(nums[mid]<=target && target<=nums[end]){
                    start=mid;
                }else{
                    end=mid;
                }
            }
        }
        if(nums[start]==target) return start;
        else if(nums[end]==target) return end;
        else return -1;
    }
};

*/


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