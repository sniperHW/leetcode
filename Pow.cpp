#include <iostream>


using namespace std;

/*
Implement pow(x, n), which calculates x raised to the power n (xn).

Example 1:

Input: 2.00000, 10
Output: 1024.00000

Example 2:

Input: 2.10000, 3
Output: 9.26100

Example 3:

Input: 2.00000, -2
Output: 0.25000
Explanation: 2^-2 = 1/2^2 = 1/4 = 0.25

Note:

    -100.0 < x < 100.0
    n is a 32-bit signed integer, within the range [−2^31, 2^31 − 1]

	xxxx
	xxxx xxxx

*/

class Solution {
public:    
    double pow(double x,unsigned int n) {
		if(n == 1) return x;
		if(n == 2) return x*x;
		unsigned int c = 2;
		double product = x*x;
		for( ; ; ) {
			if(c * 2 > n){
				break;
			} else if(c * 2 == n) {
				return product*product;
			} else {
				product *= product;
				c *= 2;
			}
		}
		
		return product * pow(x,n-c);
		
    }

    double myPow(double x, int n) {
		if(n == 0) {
			return 1; 
		} else {
			if(n > 0) return pow(x,n);
			else {
				if(n == -2147483648) return 1/pow(x,2147483648);
				else return 1/pow(x,abs(n));
			}
		}    	
    }
};

int main() {

	Solution s;
	cout << s.myPow(1.0,-2147483648) << endl;
	//cout << s.myPow(2,6) << endl;
	return 0;
}