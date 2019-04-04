#include <iostream>
#include <vector>

using namespace std;


/*
 Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

For example, given n = 3, a solution set is:

[
  "((()))",
  "(()())",
  "(())()",
  "()(())",
  "()()()"
]
*/

class Solution {
public:
	void generate(vector<string> &ret,string s,int i,int n,int t) {
		s.push_back('(');
		if(i == t) {
			ret.push_back(s + string(t-n,')'));
		} else {
			for(int j = i - n; j >= 0; j--){
				generate(ret,s + string(j,')'),i+1,j+n,t);
			}			
		}
	}

    vector<string> generateParenthesis(int n) {
   		vector<string> ret;
   		generate(ret,"",1,0,n);
   		return ret;
    }
};


int main() {
	Solution s;
	vector<string> ret = s.generateParenthesis(3);
		cout << "------------" <<endl;
	for(int i = 0; i < ret.size(); i++) {
		cout << ret[i] << endl;
	}

	//cout << s.generateParenthesis(3).size() << endl;

	return 0;
}