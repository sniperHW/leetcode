#include <iostream>
#include <vector>

using namespace std;


/*
Input: [1,8,6,2,5,4,8,3,7]
Output: 49
*/

class Solution {
public:

	int calMin(int a,int b) {
		return a > b ? b : a;
	}

	/*
	穷举：会超时,复杂度O(n^2)
	*/
    int maxAreaExhaustion(vector<int>& height) {
    	int max = 0;
    	int s = height.size();
    	for(int i = 0;i < s;i++){
    		for(int j = 1; j < s;j++){
    			int product = (j-i) * calMin(height[i],height[j]);
    			if(product > max){
    				max = product;
    			}
    		}
    	}
        return max;
    }

    int maxTowPointer(vector<int>&height) {
    	int max = 0;
    	int l = 0;
    	int r = height.size()-1;
    	while(l < r) {
    		int product = (r-l) * calMin(height[r],height[l]);
    		if(product > max) {
    			max = product;
    		}

    		if(height[r] < height[l]) {
    			r--;
    		} else {
    			l++;
    		}
    	};
    	return max;
    }


    int maxArea(vector<int>& height) {
    	int s = height.size();
    	if(s < 2){
    		return 0;
    	}
    	return maxTowPointer(height);
    	//return maxRecursive(height);
    }
};


int main() {
	Solution s;
	vector<int> v;


	v.push_back(1);
	v.push_back(8);
	v.push_back(6);
	v.push_back(2);
	v.push_back(5);
	v.push_back(4);
	v.push_back(8);	
	v.push_back(3);
	v.push_back(7);
	cout << s.maxArea(v) << endl;	
	return 0;
}

//[10,9,8,7,6,5,4,3,2,1]

//[2,1]  -> [3,2,1] -> [3,1]








