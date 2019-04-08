#include <iostream>

using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
    	if(needle == "") return 0;
    	int len1 = haystack.size();
    	int len2 = needle.size();
    	for(int i = 0; i < len1; i++) {
    		if(len2 > len1 - i) {
    			cout << len2 << "," << len1 << "," << i << endl;
     			return -1;
    		}
    		int ret = i;
    		int j;
    		for(j = 0; j < len2; j++) {
    			if(haystack[i+j] != needle[j]) {
    				break;
    			}
    		}
    		if(j == len2) {
    			return ret;
    		}
    	}
    	return -1;	
    }
};



int main() {
	Solution s;
	std::cout << s.strStr("mississippi","mississippi") << std::endl; 

}