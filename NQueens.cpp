
#include <iostream>
#include <vector>

using namespace std;


/*
 *  皇后不能在同一行，同一列，同一斜线上
 */

class Solution {
public:

	//检查列
	bool checkCol(vector<string> &board,int c) {
		for(int i = 0;i < board.size(); i++) {
			if(board[i][c] == 'Q') return false;
		}
		return true;
	}

	//检查对角线
	bool checkCross(vector<string> &board,int r,int c) {
		int cc = c;
		int rr = r;
		for(; rr < board.size() && cc < board.size() ;) {
			if(board[rr][cc] == 'Q') return false;
			rr++;
			cc++;
		}

		cc = c-1;
		rr = r-1;
		for(; rr >= 0 && cc >= 0;) {
			if(board[rr][cc] == 'Q') return false;
			rr--;
			cc--;
		}		

		cc = c+1;
		rr = r-1;
		for(; rr >= 0 && cc < board.size();) {
			if(board[rr][cc] == 'Q') return false;
			rr--;
			cc++;
		}

		cc = c-1;
		rr = r+1;
		for(; cc >= 0 && rr < board.size();) {
			if(board[rr][cc] == 'Q') return false;
			rr--;
			cc++;
		}

		return true;

	}

	void backtrace(vector<vector<string>> &ret,vector<string> &board,int n,int c) {
		for(int i = 0; i < board.size(); i++) {
			if(i != c) {
				if(checkCol(board,i) && checkCross(board,n,i)) {
					string &s = board[n];
					s[i] = 'Q';
					if(n + 1 == board.size()) {
						ret.push_back(board);
					} else {
						backtrace(ret,board,n+1,i);
					}
					s[i] = '.';
					if(n + 1 == board.size()){
						break;
					}
				}
			}
		}
	}

    vector<vector<string>> solveNQueens(int n) {
    	vector<vector<string>> ret;

		string s(n,'.');
		vector<string> board(n,s);

		backtrace(ret,board,0,-1);
		return ret;
 	
    }
};

void show(const vector<vector<string>> &ret) {
	for(int i = 0; i < ret.size(); i++) {
		for(int j = 0; j < ret[i].size(); j++) {
			cout << ret[i][j] << endl;
		}
		cout << "---------------------------" << endl;
	}

}


int main() {
	
	/*string s(8,'.');
	s[1] = 'Q';

	cout << s << endl;*/

	vector<string> board{
		string("...."),
		string("..Q."),
		string("...."),
		string("...."),
	};

	Solution s;

	show(s.solveNQueens(3));

	//cout << s.checkCross(board,0,1) << endl;




	return 0;
}