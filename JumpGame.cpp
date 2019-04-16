#include <iostream>
#include <vector>

using namespace std;


/*

Given an array of non-negative integers, you are initially positioned at the first index of the array.

Each element in the array represents your maximum jump length at that position.

Determine if you are able to reach the last index.

Example 1:

Input: [2,3,1,1,4]
Output: true
Explanation: Jump 1 step from index 0 to 1, then 3 steps to the last index.

Example 2:

Input: [3,2,1,0,4]
Output: false
Explanation: You will always arrive at index 3 no matter what. Its maximum
             jump length is 0, which makes it impossible to reach the last index.

*/

class Solution {
public:

	int bfs(vector<int>& nums) {
		if(nums.size()<2)return 1;
		int level=0,currentMax=0,i=0,nextMax=0;
		while(currentMax-i+1>0){		//nodes count of current level>0
			level++;
			for(;i<=currentMax;i++){	//traverse current level , and update the max reach of next level
				nextMax=max<int>(nextMax,nums[i]+i);
				if(nextMax>=nums.size()-1)return level;   // if last element is in level+1,  then the min jump=level 
			}
			currentMax=nextMax;
		}
		return 0;
	}


    bool canJump(vector<int>& nums) {
        return bfs(nums) > 0;
    }
};

int main() {
	Solution s;
	vector<int> v{3,2,1,0,4};
	cout << s.bfs(v) << endl;

	return 0;
}