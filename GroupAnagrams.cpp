#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;


/*
Given an array of strings, group anagrams together.

Example:

Input: ["eat", "tea", "tan", "ate", "nat", "bat"],
Output:
[
  ["ate","eat","tea"],
  ["nat","tan"],
  ["bat"]
]

Note:

    All inputs will be in lowercase.
    The order of your output does not matter.

*/

class Solution {
public:



    vector<vector<string> > groupAnagrams(vector<string>& strs) {
    	if(strs.empty()) return vector<vector<string> >();
        
        unordered_map<string,std::vector<string>*> m;

        vector<vector<string> > ret;
        ret.reserve(strs.size());

        for(int i = 0; i < strs.size();i++) {
        	string &s = strs[i];
        	string ss = s;
        	sort(ss.begin(),ss.end());
        	unordered_map<string,std::vector<string>*>::iterator it = m.find(ss);
        	if(it != m.end()) {
        		it->second->push_back(s);
        	} else {
        		ret.push_back(std::vector<string>{s});
        		m[ss] = &ret[ret.size()-1];
        	}
        }
        return ret;
    }
};



int main() {

	/*string s("cba");
	string ss = s;
	sort(ss.begin(),ss.end());
	cout << s << "," << ss << endl;*/

	vector<string> v{"eat","tea","tan","ate","nat","bat"};
	Solution s;
	s.groupAnagrams(v);

	return 0;
}