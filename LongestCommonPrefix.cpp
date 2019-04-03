
#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
    	if(strs.empty()) {
    		return "";
    	}

    	string str = strs[0];

    	if(str.empty()) {
    		return "";
    	}

    	string ret;

    	for(int i = 0; i < str.size(); i++) {
    		char s = str[i];
    		for(int j = 1; j < strs.size(); j++) {
    			string &ss = strs[j];
    			if(ss.size() < i+1){
    				return ret;
    			}
    			if(ss[i] != s) {
    				return ret;
    			} 
    		}
    		ret.push_back(s);
    	}
    	return ret;
    }
};


int main() {

	Solution s;
	vector<string> v = {"flower","flow","flight"};
	cout << s.longestCommonPrefix(v) << endl;

	return 0;
}