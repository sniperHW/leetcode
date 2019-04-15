#include <iostream>
#include <vector>
//#include <list>

using namespace std;

class Solution {
public:
	/*
		123
		456

		738
	   615
	  492 
	  56088

	  738
	 6150
	49200

	*/

    string multiply(string num1, string num2) {
        if(num1 == "0" || num2 == "0") return string("0");
        vector<char> sum(num1.size(),0);
        int k = 0;
        for(int i = num2.size()-1; i >= 0; i--,k++){
        	char carry = 0;
        	char n2 = num2[i] - '0';
        	int tmp = k;
        	for(int j = num1.size()-1;j >= 0; j--,tmp++) {
        		char n1 = num1[j] - '0';
        		char n = n1 * n2 + sum[tmp] + carry;
        		carry = n/10;
        		n = n % 10;
        		sum[tmp] = n;
        	}
        	if(carry > 0) {
        		sum.push_back(carry);
        	} else if(i - 1 >= 0) {
        		sum.push_back(0);
        	}       		
        }

        string ret("");
        vector<char>::reverse_iterator itr = sum.rbegin();
        for(; itr != sum.rend(); itr++){
        	ret.push_back(*itr+'0');
        }
        return ret;
    }
};


int main() {

	Solution s;

	cout << s.multiply("2","3") << endl;

	//show(s.m("123","456"));

	return 0;
}