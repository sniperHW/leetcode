/*
Given a string s, find the longest palindromic substring in s. You may assume that the maximum length of s is 1000.

Example:

Input: "babad"

Output: "bab"

Note: "aba" is also a valid answer.
Example:

Input: "cbbd"

Output: "bb"
*/

#include <string>
#include <stdio.h>

using namespace std;

class Solution {
public:

	bool isPalindrome(const char *s,size_t len) {
		if(len == 0) {
			return false;
		}else if(len == 1){
			return true;
		}else{
			size_t end,i,j;
			end = len / 2;
			if(len % 2 != 0) {
				end++;
			}
			for(i = 0 , j = len-1 ; i < end; ++i,--j) {
				if(s[i] != s[j]) {
					return false;
				}
			}
			return true;
		}
	}

    string longestPalindrome(string s) {
    	if(s.size() <= 1) {
    		return s;
    	}
        const char *c_str_ptr = s.c_str();
        size_t s_len = s.size();
        if(isPalindrome(c_str_ptr,s_len)) {
        	return s;
        }

        const char *longestSub = s.c_str(); 
        size_t longest_sub_len = 1;
        for(size_t i = 0; i < s_len; ++i) {
        	if(s_len - i <= longest_sub_len) {
        		//后面的子串不可能比当前最长子串更长，不用继续检测
        		break;
        	}
        	for(size_t j = longest_sub_len + 1; j <= s_len-i; ++j) {
        		if(isPalindrome(&c_str_ptr[i],j)) {
        			longestSub = &c_str_ptr[i];
        			longest_sub_len = j;
        		}
        	}
        }
        return string(longestSub,longest_sub_len);
    }
};


int main() {

	Solution s;
	printf("%s\n",s.longestPalindrome("babad").c_str());
	printf("%s\n",s.longestPalindrome("babadada").c_str());
	return 0;
}