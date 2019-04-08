/*

Given two integers dividend and divisor, divide two integers without using multiplication, division and mod operator.

Return the quotient after dividing dividend by divisor.

The integer division should truncate toward zero.

Example 1:

Input: dividend = 10, divisor = 3
Output: 3

Example 2:

Input: dividend = 7, divisor = -3
Output: -2

Note:

    Both dividend and divisor will be 32-bit signed integers.
    The divisor will never be 0.
    Assume we are dealing with an environment which could only store integers within the 32-bit 
    signed integer range: [−2^31,  2^31 − 1]. For the purpose of this problem, 
    assume that your function returns 2^31 − 1 when the division result overflows.
*/

#include <iostream>
#include <stdio.h>

using namespace std;


class Solution {
public:
    int divide(int dividend, int divisor);
};

// a / b
int Solution::divide(int a, int b) {
    // First, deal with bunch of special conditions
    if (a == b) {
        return 1;
    }
    if (b == 1) {
        return a;
    }
    if (a == 0 || b == INT_MIN) {
        return 0;
    }
    if (a == INT_MIN && b == -1) {
        return INT_MAX; // seems to be the only condition to max out...
    }
    
    // get sign 
    int sign = 1;
    if ((a >> 31) ^ (b >> 31)) {
        sign = -1;
    }
    // convert both to negative
    if (a > 0) a = -a;
    if (b > 0) b = -b;
    if (b < a) {
        return 0;
    }

    int res = 0;
    int sub = b;
    int cnt = 1;
    // you can use bit here, shift is the same as b * 2 or b + b
    while (true) {
        while (sub >= INT_MIN / 2 && a - (sub + sub) < 0) {
            sub += sub;
            cnt += cnt;
        }
        a -= sub;
        res += cnt;
        // re-init
        sub = b;
        cnt = 1;
        if (a > b) {
            break;
        }
    }
    return sign > 0 ? res : -res;
}



int main() {
	//printf("%x\n",-2147483648);
	Solution s;
	cout << s.divide(-2147483648,2) << endl;
	//cout << s.divide(2,3) << endl;
	//cout << s.divide(-2,3) << endl;
	//int a = -2147483647;
	//int b = a & 0x7FFFFFFF;
	//cout << b << endl;
}
