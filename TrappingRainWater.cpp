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
    	int sum   = 0;
		int left  = -1;
		for(int j = 0;j < height.size(); j++) {
			if(height[j] > 0){
    			if(left == -1) {
    				left = j;//找到左边门板
    			} else {
					if(j - left > 0) {
						int v = min(height[left],height[j]);
						for(int k = left + 1; k < j; k++) {
							sum += (v - height[k]);
						}
						left = j; 
					}   				
    			}
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