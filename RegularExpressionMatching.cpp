#include <iostream>
#include <vector>
using namespace std;

/*


如果ss中可以存在*,.等符号，只有注释的代码才能处理

string ss = "a*";
string p = "a*a*";



class Solution {
public:

	struct c {
		char character;
		char next;
		c(char character,char next = '\0'):character(character),next(next){

		}

		friend ostream & operator<<(ostream &out, c &obj);

	};

	void buildP(string p,vector<c> &cp) {
		if(p.empty()){
			return;
		}
		size_t len = p.size();
		for(size_t i = 0; i < len; i++) {
			char character = p[i];
			char next = i + 1 < len ? p[i+1] : '\0';
			cp.push_back(c(character,next));
		}

	}


	bool match(string &s,int sIdx,vector<c> &cp,int cpIdx) {
		if(sIdx >= s.size() && cpIdx >= cp.size()){
			return true;
		} else {

			if(sIdx >= s.size() +1) {
				return false;
			}

			if(cpIdx >= cp.size()) {
				return false;
			}

			char c = '\0';

			if(sIdx < s.size()) {
				c = s[sIdx];
			}

			if(cp[cpIdx].next == '*') {
				bool ok = false;
				if(cp[cpIdx].character == '.' || c == cp[cpIdx].character){
					do {
						
						if(ok = this->match(s,sIdx,cp,cpIdx+1),ok){
							break;
						}

						if(ok = this->match(s,sIdx,cp,cpIdx+2),ok){
							break;
						}

						if(ok = this->match(s,sIdx+1,cp,cpIdx+1),ok){
							break;
						}

						if(ok = this->match(s,sIdx+1,cp,cpIdx+2),ok){
							break;
						}

						if(ok = this->match(s,sIdx+1,cp,cpIdx),ok){
							break;
						}					

					} while(0);
				} else {
					ok = this->match(s,sIdx,cp,cpIdx+2);
				}

				return ok;
			} else {
				if(c == cp[cpIdx].character) {
					//严格字符匹配，不存在分支
					return this->match(s,sIdx+1,cp,cpIdx+1);					
				}

				if(c != '\0' && cp[cpIdx].character == '.') {
					return this->match(s,sIdx+1,cp,cpIdx+1);
				}

				return false;
			}
		}
	}

    bool isMatch(string s, string p) {
        vector<c> cp;
        this->buildP(p,cp);
        return this->match(s,0,cp,0);
    }
};
*/

class Solution {
public:

	bool match(string &s,int sIdx,string &patten,int pIdx) {
		if(pIdx >= patten.size()) return sIdx >= s.size();
		bool first_match = (!(sIdx >= s.size()) && (s[sIdx] == patten[pIdx] || patten[pIdx] == '.')); 
		if(pIdx + 1 < patten.size() && patten[pIdx+1] == '*') {
			return this->match(s,sIdx,patten,pIdx + 2) || (first_match && this->match(s,sIdx+1,patten,pIdx));

		} else {
			return first_match && this->match(s,sIdx+1,patten,pIdx+1);
		}
	}


    bool isMatch(string s, string p) {
        return this->match(s,0,p,0);
    }
};


int main() {

	Solution s;

	/*{
		string ss = "aa";
		string p = "a*";

		cout << s.isMatch(ss,p) << endl;
	}

*/

/*	{
		string ss = "aaaaaaaaaaaaab";
		string p = "a*a*a*a*a*a*a*a*a*a*c";
		cout << s.isMatch(ss,p) << endl;
	}
*/

	{
		string ss = "a*";
		string p = "a*a*";
		cout << s.isMatch(ss,p) << endl;
	}	
}
