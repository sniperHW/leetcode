/*

Given an input string (s) and a pattern (p), implement wildcard pattern matching with support for '?' and '*'.

'?' Matches any single character.
'*' Matches any sequence of characters (including the empty sequence).

The matching should cover the entire input string (not partial).

*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:

	vector<vector<char> > memo;

	bool match(string &s,int sIdx,string &patten,int pIdx) {

		if(memo[sIdx][pIdx] != 0) return memo[sIdx][pIdx] == 1;

		if(pIdx >= patten.size()){
			bool ret = sIdx >= s.size();
			memo[sIdx][pIdx] = ret ? 1 : -1;
			return ret;
		}

		if(patten[pIdx] == '*') {
			if(pIdx == patten.size()-1 && sIdx == s.size() - 1){
				memo[sIdx][pIdx] = 1;
				return true;
			}
			for(int i = sIdx; i <= s.size(); i++) {
				if(this->match(s,i,patten,pIdx + 1)){
					memo[sIdx][pIdx] = 1;
					return true;
				}
			}
			memo[sIdx][pIdx] = -1;
			return false;
		} else {
			bool first_match = (!(sIdx >= s.size()) && (s[sIdx] == patten[pIdx] || patten[pIdx] == '?'));
			bool ret = first_match && this->match(s,sIdx+1,patten,pIdx+1); 			
			memo[sIdx][pIdx] = ret ? 1 : -1;
			return ret;
		}
	}


    bool isMatch(string s, string p) {
    	string pattern;
    	char last = '\0';
    	for(int i = 0; i < p.size();i++) {
    		char c = p[i];
    		if(c == '*') {
    			if(last != '*'){
    				pattern.push_back(c);
    			}
    		} else {
    			pattern.push_back(c);
    		}
    		last = c;
    	}

    	memo.reserve(s.size()+1);
    	for(int i = 0; i <= s.size();i++) {
    		memo.push_back(vector<char>(pattern.size()+1,0));
    	}
        return this->match(s,0,pattern,0);
    }
};


int main() {

	Solution s;

	{
		string ss = "abbabaaabbabbaababbabbbbbabbbabbbabaaaaababababbbabababaabbababaabbbbbbaaaabababbbaabbbbaabbbbababababbaabbaababaabbbababababbbbaaabbbbbabaaaabbababbbbaababaabbababbbbbababbbabaaaaaaaabbbbbaabaaababaaaabb";
		string p = "**aa*****ba*a*bb**aa*ab****a*aaaaaa***a*aaaa**bbabb*b*b**aaaaaaaaa*a********ba*bbb***a*ba*bb*bb**a*b*bb";
		cout << s.isMatch(ss,p) << endl;
	}
}