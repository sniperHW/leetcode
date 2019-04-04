#include <iostream>
#include <vector>


using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
 		int size = nums.size();
 		for(int i = 0; i < size; ) {
 			if(nums[i] == val) {
 				//swap to end
 				swap(nums[i],nums[size-1]);
 				size--;
 			} else {
 				i++;
 			}
 		}
 		return size;	
    }
};

void showv(const std::vector<int> &v,int n) {
	/*for(std::vector<int>::const_iterator it = v.begin(); it != v.end(); it++) {
		std::cout << *it << ",";
	}*/
	for(int i = 0; i < n; i++) {
		std::cout << v[i] << ",";
	}
	std::cout << std::endl;
}

int main() {

	Solution s;
	vector<int> v{0,1,2,2,3,0,4,2};
	int n = s.removeElement(v,2);
	showv(v,n);
	return 0;
}