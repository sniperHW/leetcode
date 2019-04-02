#include <iostream>
#include <math.h>
using namespace std;



class Solution {
public:

	int getnum(int x) {
		if(x < 10){
			return 1;
		} else if(x < 100) {
			return 2;
		} else if(x < 1000) {
			return 3;
		} else if(x < 10000) {
			return 4;
		} else if(x < 100000) {
			return 5;
		} else if(x < 1000000) {
			return 6;
		} else if(x < 10000000) {
			return 7;
		} else if(x < 100000000) {
			return 8;
		} else if(x < 1000000000) {
			return 9;
		} else {
			return 10;
		}
	}

	int revert(int x) {
		if(x < 10) {
			return x;
		}
		int n = getnum(x);
		return revert(x/10) + (x%10)*pow(10,n-1);
	}

    bool isPalindrome(int x) {
    	if(x < 0) {
    		return false;
    	}
  		return x == revert(x);  
    }
};


int main() {

	Solution s;
	cout << s.revert(1212) << endl;


	return 0;
}
