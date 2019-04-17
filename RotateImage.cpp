#include <iostream>
#include <vector>

using namespace std;


/*
You are given an n x n 2D matrix representing an image.

Rotate the image by 90 degrees (clockwise).

Note:

You have to rotate the image in-place, which means you have to modify the input 2D matrix directly. 
DO NOT allocate another 2D matrix and do the rotation.

Example 1:

Given input matrix = 
[
  [1,2,3],
  [4,5,6],
  [7,8,9]
],


(1,1) (1,2) (1,3)
(2,1) (2,2) (2,3)
(3,1) (3,2) (3,3)


(3,1) ->(1,1) (2,1) ->(1,2) (1,1) -> (1,3)
(3,2) ->(2,1) (2,2) ->(2,2) (1,2) -> (2,3)
(3,3) ->(3,1) (2,3) ->(3,2) (1,3) -> (3,3)


(1,1) -> (1,3) ; (1,3) -> (3,3) ; (3,3) -> (3,1) ; (3,1) -> (1,1);
(1,2) -> (2,3) ; (2,3) -> (3,2) ; (3,2) -> (2,1) ; (2,1) -> (1,2);




newRow = col

newCol = n - row + 1 


rotate the input matrix in-place such that it becomes:
[
  [7,4,1],
  [8,5,2],
  [9,6,3]
]

Example 2:

Given input matrix =
[
  [ 5, 1, 9,11],
  [ 2, 4, 8,10],
  [13, 3, 6, 7],
  [15,14,12,16]
], 

//第一轮

15 1  9  5
2  4  8  10
13 3  6  7
16 14 12 11

//第二轮

15 13 9  5
2  4  8  1
12 3  6  7
16 14 10 11


//第三轮
15 13 2  5
14 4  8  1
12 3  6  9
16 7 10 11

//第四轮
[15,13, 2, 5],
[14, 3, 4, 1],
[12, 6, 8, 9],
[16, 7,10,11]



rotate the input matrix in-place such that it becomes:
[
  [15,13, 2, 5],
  [14, 3, 4, 1],
  [12, 6, 8, 9],
  [16, 7,10,11]
]


*/

class Solution {
public:

	void showMatrix(vector<vector<int>>& matrix) {
		for(int i = 0;i < matrix.size(); i++){
			for(int j = 0; j < matrix.size();j++) {
				cout << matrix[i][j] << " ";
			}
			cout << endl;
		}
		cout << "------------------------------" << endl;
	}


	void helper(vector<vector<int>>& matrix,int b) {
		if(matrix.size() - b == 1){
			return;
		} else {
			int s = matrix.size() - 2*b - 1;
			for(int i = 0; i < s;i++) {
				int initR = b;
				int initC = b + i;
				int rr    = initR;
				int cc    = initC;
				int save  = matrix[initR][initC];
				do{
					int newC = matrix.size() - rr - 1;
					int newR = cc;
					swap(save,matrix[newR][newC]);
					rr = newR;
					cc = newC;
				}while(!(rr == initR && cc == initC));
			}
			helper(matrix,b + 1);
		}
	}

	void rotate(vector<vector<int>>& matrix) {
		helper(matrix,0);
		showMatrix(matrix);
	}

};

int main() {
	Solution s;

/*	vector<vector<int> > matrix{
		vector<int>{1,2,3},
		vector<int>{4,5,6},
		vector<int>{7,8,9}
	};
*/

/*	vector<vector<int> > matrix{
		vector<int>{1, 2, 3,4},
		vector<int>{5, 6, 7,8},
		vector<int>{9, 10, 11, 12},
		vector<int>{13,14,15,16}
	};
*/
	vector<vector<int> > matrix{
		vector<int>{1, 2, 3,4,5},
		vector<int>{6, 7, 8,9,10},
		vector<int>{11, 12, 13, 14,15},
		vector<int>{16,17,18,19,20},
		vector<int>{21,22,23,24,25},
	};

/*	vector<vector<int> > matrix{
		vector<int>{5, 1, 9,11},
		vector<int>{2, 4, 8,10},
		vector<int>{13, 3, 6, 7},
		vector<int>{15,14,12,16}
	};
*/

	s.rotate(matrix);

	return 0;
}