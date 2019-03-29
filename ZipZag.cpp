#include <iostream>
#include <stdio.h>

using namespace std;

/*
The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)

P   A   H   N
A P L S I I G
Y   I   R

And then read line by line: "PAHNAPLSIIGYIR"

Write the code that will take a string and make this conversion given a number of rows:

P     I    N
A   L S   I G
Y A   H R
P     I

PINALSIGYAHRPI


1 3 5 7
2 4 6 8

0 2 4 6 1 3 5 7
1 3 5 7 2 4 6 8


1,2,3,4,5,6,7,8,9,10,11,12,13,14

1   5   9     13
2 4 6 8 10 12 14
3   7   11    15


    4            2              4 

0 4 8 12 | 1 3 5 7 9  11 13 | 2 6 10 14
1 5 9 13 | 2 4 6 8 10 12 14 | 3 7 11 15


1     7        13
2   6 8     12 14
3 5   9  11    15
4     10       16


  6       4    2          2    4        6   

0 6 12 | 1 5 7 11 13 | 2 4 8 10 14  |3 9  15
1 7 13 | 2 6 8 12 14 | 3 5 9 11 15  |4 10 16



1       9           17
2     8 10       16 18
3   7   11    15    19
4 6     12 14       20
5       13          21

 
  8       6    2             4             2    6       8
0 8 16 | 1 7 9  15 17 | 2 6 10 14 18 | 3  5  11 13 19 | 4  12 20
1 9 17 | 2 8 10 16 18 | 3 7 11 15 19 | 4  6  12 14 20 | 5  13 21 
0 1 2    3 4 5  6  7    8 9 10 11 12   13 14 15 16 17   18 19 20



1          11        1 -> 11 = 10 -> 5*2   5               5 * 2                                      
2       10 12        2 -> 10 = 8 -> 4*2    10 -> 12 = 2 -> (5 - 4) * 2    4 = 5 - 1                   
3     9    13        3 -> 9  = 6 -> 3*2    9 -> 13 = 4 -> (5 - 3) * 2       3 = 5 - 2                 
4   8      14        4 -> 8  = 4 -> 2*2    8 -> 14 = 6 -> (5 - 2) * 2                                 
5 7        15        5 -> 7  = 2 -> 1*2    7 -> 15 = 8 -> (5 - 1) * 2                                 
6          16        6 -> 16 = 10 -> 5*2   5                                                            


*/

class Solution {
public:
    string convert(string s, int numRows) {

    	if(numRows == 1) {
    		return s;
    	}

        string ret(s.size(),0);
        int len = s.size();
        int j = 0;//当前处理第几行 
        int n = numRows - 1;
        int span = n;
        int step = 0;
        int flip = 0;
        int sIdx = 0;
        for(int i = 0; i < len; i++) {
        	sIdx += step;
        	if(sIdx < len) {
        		ret[i] = s[sIdx];
        		//更新step
        		if(flip == 0) {
        			step = span;// * 2;
        		} else {
        			step = (n - span * (span == n ? 0 : 1));// * 2;
        		}
        		step += step;
        		flip = ~flip;
        	} else {
        		//换行
        		i--;
        		j++;
        		step = flip = 0;
        		sIdx = j;
        		span = n - (j % n);
        	}
        }
        return ret;
    }
};


int main() {
	Solution s;
	string str("PAYPALISHIRING");
	cout << s.convert(str,4) << endl;

	//string s("hello");
	//printf("%c\n", s.at(0));
}