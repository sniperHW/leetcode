#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	/*
	*  1层层填水,会超时
    int trap(vector<int>& height) {
    	int max = -1;
    	int sum = 0;
    	for(int i = 1; max == -1 || i <= max; i++) {
    		int left = -1;
    		for(int j = 0;j < height.size(); j++) {
    			if(height[j] > 0){
	    			if(height[j] > max) max = height[j];
	    			if(left == -1) {
	    				if(height[j] >= i) left = j;
	    			} else {
	    				if(height[j] >= i) {
	    					if(j - left > 0) {
	    						for(int k = left + 1; k < j; k++) sum += 1;
	    					}
	    					left = j;
	    				}
	    			}
    			}
    		}
    		if(max <= 0) {
    			break;
    		}
    	}
    	return sum;
    }
    */

    int trap(vector<int>& height) {
    	if(height.empty()) return 0;
	    int sum = 0;
	    int max_left = 0;
	    int max_right = 0;
	    int left = 1;
	    int right = height.size() - 2; // 加右指针进去
	    for (int i = 1; i < height.size() - 1; i++) {
	        //从左到右更
	        if (height[left - 1] < height[right + 1]) {
	            max_left = max(max_left, height[left - 1]);
	            int min = max_left;
	            if (min > height[left]) {
	                sum = sum + (min - height[left]);
	            }
	            left++;
	        //从右到左更
	        } else {
	            max_right = max(max_right, height[right + 1]);
	            int min = max_right;
	            if (min > height[right]) {
	                sum = sum + (min - height[right]);
	            }
	            right--;
	        }
	    }
	    return sum;
    }

};


/*

	     1 1 1     1
     1     1
[0,1,0,2,1,0,1,3,2,1,2,1]


*/

int main() {
	Solution s;
	vector<int> v{0,1,0,2,1,0,1,3,2,1,2};
	//vector<int> v{2,0,1};
	cout << s.trap(v) << endl;
}