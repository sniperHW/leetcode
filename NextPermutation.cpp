
#include <iostream>
#include <vector>

using namespace std;

void showv(const std::vector<int> &v) {
	for(std::vector<int>::const_iterator it = v.begin(); it != v.end(); it++) {
		std::cout << *it << ",";
	}
	std::cout << std::endl;
}


/*

Input
[1,3,2]

Output
[3,1,2]

Expected
[2,1,3]



4 1 3 2   -> 4 2 1 3


1 [3 2] 


Input
[2,3,1]

Output
[1,2,3]

Expected
[3,1,2]



*/

class Solution {
public:

	bool nextP(vector<int>& nums,int b,int e) {
		if(e-b == 1) {
			if(nums[b] < nums[e]) {
				swap(nums[b],nums[e]);
				return true;
			} else {
				return false;
			}
		} else {
			bool ok = nextP(nums,b+1,e);
			if(ok) {
				return ok;
			} else {
				if(nums[b] >= nums[b+1]) {
					return false;
				} else {
					int idx = e;
					for( ; idx > b ; idx--) {
						if(nums[b] < nums[idx]){
							break;
						}						
					}
					swap(nums[b],nums[idx]);

					vector<int>::iterator it = nums.begin();
					for(int i = 0; i <= b; i++) {
						it++;
					}

					sort(it,nums.end());		
					return true;
				}
			}
		}
	}

    void nextPermutation(vector<int>& nums) {
        int len = nums.size();
        if(len == 0 || len == 1) {
        	return;
        }	

        if(!nextP(nums,0,len-1)) {
        	sort(nums.begin(),nums.end());
    	}
    }
};


int main() {

	Solution s;
	vector<int> v{2,2,7,5,4,3,2,2,1};
	//vector<int> v{1,3,2};  //->2 3 1  -> 2 1 3
	//vector<int> v{2,3,1}; //->3 2 1  -> 3 1 2
	s.nextPermutation(v);
	showv(v);

}