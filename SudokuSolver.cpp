
#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:

    bool fill(vector<vector<char>>& board,int row[9],int col[9],int sub[9]) {
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
    		row[i] = flag;
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
    		col[i] = flag;    			
    	}


    	//检查9个sub-box
    	int s = 0;
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
		    	sub[s++] = flag;
	    	}
    	}
    	return true;   	
    }

    int getsub(int i,int j) {
    	static int s[9][9] = {
    		{0,0,0,1,1,1,2,2,2},
    		{0,0,0,1,1,1,2,2,2},
    		{0,0,0,1,1,1,2,2,2},
    		{3,3,3,4,4,4,5,5,5},
    		{3,3,3,4,4,4,5,5,5},
    		{3,3,3,4,4,4,5,5,5},
    		{6,6,6,7,7,7,8,8,8},
    		{6,6,6,7,7,7,8,8,8},
    		{6,6,6,7,7,7,8,8,8},
    	};
    	return s[i][j];
    }

    void next(int &i,int &j) {
    	if((i = (++i % 9)) == 0) j++;
    }

    bool solve(vector<vector<char>>& board,int i,int j,int row[9],int col[9],int sub[9]) {
    	if(board[i][j] == '.') {
    		int nexti = i;
    		int nextj = j;
    		next(nexti,nextj);
	    	for(int c = 1; c <= 9; c++) {
	    		//跳过所有不能选的数字
	    		if((row[i] & (1 << c)) != 0) continue;
	    		if((col[j] & (1 << c)) != 0) continue;
	    		int s = getsub(i,j);
	    		if((sub[s] & (1 << c)) != 0) continue;


	    		board[i][j] = c + '0';

	    		if(i == 8 && j == 8) {
	    			return true;
	    		}

	    		int oldrow = row[i];
	    		int oldcol = col[j];
	    		int oldsub = sub[s];
	    		
	    		row[i] = row[i] | (1 << c);
	    		col[j] = col[j] | (1 << c);
	    		sub[s] = sub[s] | (1 << c);

	    		if(solve(board,nexti,nextj,row,col,sub)) {
	    			return true;
	    		} else {
	    			board[i][j] = '.';
	    			row[i] = oldrow;
	    			col[j] = oldcol;
	    			sub[s] = oldsub;	    			
	    		}
	    	}
	    	return false;

    	} else {
	    	if(i == 8 && j == 8) {
	    		return true;
	    	}
    		next(i,j);
    		return solve(board,i,j,row,col,sub);
    	}
    }


    void solveSudoku(vector<vector<char>>& board) {
		int row[9]={0};int col[9]={0};int sub[9]={0};
		if(!fill(board,row,col,sub)) {
			return;
		}
		
		solve(board,0,0,row,col,sub);   	
    }
};

void show(vector<vector<char> >&board) {
	for(int i = 0; i < 9; i ++) {
		cout << board[i][0] << " " << board[i][1] << " " << board[i][2] << " " << board[i][3] << " " << board[i][4] << " ";
		cout << board[i][5] << " " << board[i][6] << " " << board[i][7] << " " << board[i][8] << endl;
	}
}

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

	s.solveSudoku(v1);

	show(v1);

}