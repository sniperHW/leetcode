

/*
Determine if a 9x9 Sudoku board is valid. Only the filled cells need to be validated according to the following rules:

    Each row must contain the digits 1-9 without repetition.
    Each column must contain the digits 1-9 without repetition.
    Each of the 9 3x3 sub-boxes of the grid must contain the digits 1-9 without repetition.

*/

#include <iostream>
#include <vector>

using namespace std;


/*

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int row[9][9]={0},col[9][9]={0},box[9][9]={0};
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                if(board[i][j]!='.'){
                    int num=board[i][j]-'0'-1,k=i/3*3+j/3;
                    if(row[i][num]||col[num][j]||box[k][num])
                        return false;
                    row[i][num]=col[num][j]=box[k][num]=1;
                }
            }
        }
        return true;
    }
};


*/

class Solution {
public:

    bool isValidSudoku(vector<vector<char>>& board) {
    	//检查行
    	for(int i = 0;i < 9;i++) {
    		int flag = 0;
    		for(int j = 0; j < 9;j++) {
    			int v = board[i][j] - '0';
    			if(v >= 1 && v <= 9) {
    				if((flag & (1 << v)) != 0) return false;
    				flag = flag | (1 << v);
    			} else if(board[i][j] != '.') return false;
    		}
    	}


    	//检查列
    	for(int i = 0;i < 9;i++) {
    		int flag = 0;
    		for(int j = 0; j < 9;j++) {
    			int v = board[j][i] - '0';
    			if(v >= 1 && v <= 9) {
    				if((flag & (1 << v)) != 0) return false;
    				flag = flag | (1 << v);
    			} else if(board[j][i] != '.') return false;
    		}    			
    	}


    	//检查9个sub-box

    	for(int z = 0; z < 9; z = z + 3) {
	    	for(int j = 0; j < 3;j++) {
	    		int flag = 0;
		    	for(int i = z; i < z+3;i++){
		    		int b = j*3;
		    		int e = j*3+3; 
		    		for(int j = b; j < e;j++){
		    			int v = board[i][j] - '0';
		    			if(v >= 1 && v <= 9) {
		    				if((flag & (1 << v)) != 0) return false;
		    				flag = flag | (1 << v);
		    			} else if(board[i][j] != '.') return false;
		    		}
		    	}
	    	}
    	}
    	return true;   	
    }	
};


int main() {
	Solution s;

	vector<vector<char> > v1;
  	v1.push_back(vector<char>{'5','3','.','.','7','.','.','.','.'});
	v1.push_back(vector<char>{'6','.','.','1','9','5','.','.','.'});
	v1.push_back(vector<char>{'.','9','8','.','.','.','.','6','.'});
	v1.push_back(vector<char>{'8','.','.','.','6','.','.','.','3'});
	v1.push_back(vector<char>{'4','.','.','8','.','3','.','.','1'});
	v1.push_back(vector<char>{'7','.','.','.','2','.','.','.','6'});
	v1.push_back(vector<char>{'.','6','.','.','.','.','2','8','.'});
	v1.push_back(vector<char>{'.','.','.','4','1','9','.','.','5'});
	v1.push_back(vector<char>{'.','.','.','.','8','.','.','7','9'});

	vector<vector<char> > v2;
    v2.push_back(vector<char>{'8','3','.','.','7','.','.','.','.'});
	v2.push_back(vector<char>{'6','.','.','1','9','5','.','.','.'});
	v2.push_back(vector<char>{'.','9','8','.','.','.','.','6','.'});
	v2.push_back(vector<char>{'8','.','.','.','6','.','.','.','3'});
	v2.push_back(vector<char>{'4','.','.','8','.','3','.','.','1'});
	v2.push_back(vector<char>{'7','.','.','.','2','.','.','.','6'});
	v2.push_back(vector<char>{'.','6','.','.','.','.','2','8','.'});
	v2.push_back(vector<char>{'.','.','.','4','1','9','.','.','5'});
	v2.push_back(vector<char>{'.','.','.','.','8','.','.','7','9'});

	vector<vector<char> > v3;
	v3.push_back(vector<char>{'.','.','.','.','5','.','.','1','.'});
	v3.push_back(vector<char>{'.','4','.','3','.','.','.','.','.'});
	v3.push_back(vector<char>{'.','.','.','.','.','3','.','.','1'});
	v3.push_back(vector<char>{'8','.','.','.','.','.','.','2','.'});
	v3.push_back(vector<char>{'.','.','2','.','7','.','.','.','.'});
	v3.push_back(vector<char>{'.','1','5','.','.','.','.','.','.'});
	v3.push_back(vector<char>{'.','.','.','.','.','2','.','.','.'});
	v3.push_back(vector<char>{'.','2','.','9','.','.','.','.','.'});
	v3.push_back(vector<char>{'.','.','4','.','.','.','.','.','.'});


	//cout << s.isValidSudoku(v1) << endl;
	//cout << s.isValidSudoku(v2) << endl;
	cout << s.isValidSudoku(v3) << endl;
}


/*





*/