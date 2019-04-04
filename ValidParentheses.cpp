#include <iostream>
#include <list>

using namespace std;

/*

Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

An input string is valid if:

    Open brackets must be closed by the same type of brackets.
    Open brackets must be closed in the correct order.

Note that an empty string is also considered valid.

Example 1:

Input: "()"
Output: true

Example 2:

Input: "()[]{}"
Output: true

Example 3:

Input: "(]"
Output: false

Example 4:

Input: "([)]"
Output: false

Example 5:

Input: "{[]}"
Output: true


*/

class Solution {
public:

	bool check(list<char> &stack , char c) {
		if(stack.empty()){
			if(c == '}' || c == ']' || c == ')'){
				return false;
			} else {
				stack.push_front(c);
				return true;
			}
		} else {
			char top = stack.front();
			switch(top){
				case '{':{
					if(c == '}'){
						stack.pop_front();
						return true;
					}
				}
				break;
				case '[':{
					if(c == ']'){
						stack.pop_front();
						return true;
					}
				}
				break;
				case '(':{
					if(c == ')'){
						stack.pop_front();
						return true;
					}
				}
				break;
				default:
					return false;
					break;
			}

			if(c == ']' || c == '}' || c == ')') {
				return false;
			} else {
				stack.push_front(c);
				return true;
			}
		}
	}

    bool isValid(string s) {
    	if(s.empty()) return true;
        list<char> stack;
        for(int i = 0; i < s.size(); i++) {
        	if(!check(stack,s[i])){
        		return false;
        	}
        }
        return stack.empty();
    }
};


int main() {

	Solution s;

	cout << s.isValid("()") << endl;
	cout << s.isValid("()[]{}") << endl;
	cout << s.isValid("(]") << endl;
	cout << s.isValid("([)]") << endl;
	cout << s.isValid("{[]}") << endl;
	return 0;
}