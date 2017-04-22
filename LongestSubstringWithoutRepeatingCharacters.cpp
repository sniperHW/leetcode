/*
Given a string, find the length of the longest substring without repeating characters.

Examples:

Given "abcabcbb", the answer is "abc", which the length is 3.

Given "bbbbb", the answer is "b", with the length of 1.

Given "pwwkew", the answer is "wke", with the length of 3. Note that the answer must be a substring, "pwke" is a subsequence and not a substring.
*/

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int asii[256];
        int max = 0;
        int len = strlen(s.c_str());
        int begindex = 0;
        while(begindex < len){
        	const char *ptr = &(s.c_str()[begindex]);
        	int search_len = len - begindex;
        	int match_len = 0;
        	memset(asii,0,sizeof(asii));
        	for(int i =0; i < search_len; ++i){
        		int idx = (int)*ptr;
        		if(asii[idx])
        			break;
        		else{
        			ptr++;
        			asii[idx] = 1;
        			++match_len;
        		}
        	}
        	if(match_len > max)
        		max = match_len;
        	begindex++;
        }
        return max;
    }
};