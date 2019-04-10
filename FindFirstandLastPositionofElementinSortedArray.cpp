#include <iostream>
#include <vector>

using namespace std;

void showv(const std::vector<int> &v) {
	for(std::vector<int>::const_iterator it = v.begin(); it != v.end(); it++) {
		std::cout << *it << ",";
	}
	std::cout << std::endl;
}

class Solution {
public:

    int search(vector<int> &numbers,int begin,int end,int target){
    	for( ; begin <= end ; ) {
	     	int mid = begin + (end - begin)/2;
	    	int midval = numbers[mid];
	    	if(midval == target)
	    		return mid;
	    	else if(midval < target)
	    		begin = mid + 1;
	    	else
	    		end = mid - 1;   		
    	}
    	return -1;
    }	


    vector<int> searchRange(vector<int>& nums, int target) {

		if(nums.empty()) return vector<int>{-1,-1};
		int idx = search(nums,0,nums.size()-1,target);
		if(idx == -1) return vector<int>{-1,-1};

		int l;
		for(l = idx - 1; l > -1; l--) {
			if(nums[l] != target) break;
		}

		int r;
		for(r = idx + 1; r < nums.size(); r++) {
			if(nums[r] != target) break;
		}

		return vector<int>{l+1,r-1};
    }
};


int main() {

	Solution s;
	vector<int> v{5,7,7,8,10};

	showv(s.searchRange(v,8));

	return 0;
}