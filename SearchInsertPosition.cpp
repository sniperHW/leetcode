#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:

	//返回target应该插入的位置
	int binarySearch(int *a,size_t len,int target) {
		if(!a || len == 0) {
			return 0;
		}
		size_t b = 0;
		size_t e = len - 1;
		for( ; b <= e ; ) {
			size_t m = (e - b)/2 + b;
			if(a[m] == target) {
				if(m > b && a[m-1] == target) {
					for(size_t i = m-1; i >= b; i--){
						if(a[i] != target) {
							return i;
						}
					}
				}
				return m;
			} else if(a[m] > target) {
				if(m > 0){
					e = m - 1;
				}else{
					break;
				}
			} else {
				b = m + 1;
			}
		}
		return b;
	}

    int searchInsert(vector<int>& nums, int target) {
     	return binarySearch(&nums[0],nums.size(),target);   
    }
};


int main() {
	Solution s;
	vector<int> v{1};
	cout << s.searchInsert(v,1) << endl;

}