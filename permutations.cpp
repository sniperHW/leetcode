
/*
*  leetcode Permutations II and Permutations
*
*/


#include <stdio.h>
#include <vector>
#include <set>
#include <list>
using namespace std;

struct procedure {
	size_t pos;
	vector<int> nums;
	vector<vector<int> > vv;
	set<int>    unique;
	procedure *parent;
	int        prefix;
	procedure(size_t pos,const vector<int>& nums,int prefix = 0,procedure *parent = NULL):pos(pos),nums(nums),parent(parent),prefix(prefix){
	}
};

//Permutations

//递归
vector<vector<int> > permute(vector<int>& nums) {
	vector<vector<int> > v;
	if(nums.size() == 1) {
		v.push_back(nums);
	}else {
		size_t size = nums.size();
		for(size_t i = 0; i < size; ++i) {
			swap(nums[0],nums[i]);
			vector<int> vv;
			for(size_t j = 1; j < size; ++j) {
				vv.push_back(nums[j]);
			}
			vector<vector<int> > ret = permute(vv);
			for(size_t j = 0; j < ret.size(); ++j) {
				ret[j].push_back(nums[0]);
				v.push_back(ret[j]);
			}
			swap(nums[0],nums[i]);
		}
	}
	return v;
}

vector<vector<int> > permuteNoRecursion(vector<int>& nums) {
	vector<vector<int> > v;
	list<procedure> stack;
	stack.push_back(procedure(0,nums));
	while(!stack.empty()) {
		procedure &top = stack.back();
		size_t num_size = top.nums.size();
		if(top.pos == num_size) {
			if(NULL == top.parent){
				size_t v_size = top.vv.size();
				for(size_t j = 0; j < v_size; ++j) {
					v.push_back(top.vv[j]);
				}
			}else if(top.vv.empty()) {
				top.parent->vv.push_back(vector<int>(1,top.prefix));
			}else {
				size_t v_size = top.vv.size();
				for(size_t j = 0; j < v_size; ++j) {
					top.vv[j].push_back(top.prefix);
					top.parent->vv.push_back(top.vv[j]);
				}
			}
			stack.pop_back();
		}else {
			swap(top.nums[0],top.nums[top.pos]);
			stack.push_back(procedure(0,vector<int>(++top.nums.begin(),top.nums.end()),top.nums[0],&top));
			swap(top.nums[0],top.nums[top.pos]);
			++top.pos;
		}
	}

	return v;
}

//Permutations II

/*
Given a collection of numbers that might contain duplicates, return all possible unique permutations.

For example,
[1,1,2] have the following unique permutations:
[
  [1,1,2],
  [1,2,1],
  [2,1,1]
]
*/

vector<vector<int> > permuteUnique(vector<int>& nums) {
	vector<vector<int> > v;
	if(nums.size() == 1) {
		v.push_back(nums);
	}else {
		size_t size = nums.size();
		set<int> unique;
		for(size_t i = 0; i < size; ++i) {
			if(!((i != 0 && nums[i] == nums[0]) || unique.find(nums[i]) != unique.end())) {
				unique.insert(nums[i]);
				swap(nums[0],nums[i]);
				vector<int> vv;
				for(size_t j = 1; j < size; ++j) {
					vv.push_back(nums[j]);
				}
				vector<vector<int> > ret = permuteUnique(vv);
				size_t s = ret.size();
				for(size_t j = 0; j < s; ++j) {
					ret[j].push_back(nums[0]);
					v.push_back(ret[j]);
				}
				swap(nums[0],nums[i]);
			}
		}
	}
	return v;
}

vector<vector<int> > permuteUniqueNoRecursion(vector<int>& nums) {
	vector<vector<int> > v;
	list<procedure> stack;
	stack.push_back(procedure(0,nums));
	while(!stack.empty()) {
		procedure &top = stack.back();
		size_t num_size = top.nums.size();
		if(top.pos == num_size) {
			if(NULL == top.parent){
				size_t v_size = top.vv.size();
				for(size_t j = 0; j < v_size; ++j) {
					v.push_back(top.vv[j]);
				}
			}else if(top.vv.empty()) {
				top.parent->vv.push_back(vector<int>(1,top.prefix));
			}else {
				size_t v_size = top.vv.size();
				for(size_t j = 0; j < v_size; ++j) {
					top.vv[j].push_back(top.prefix);
					top.parent->vv.push_back(top.vv[j]);
				}
			}
			stack.pop_back();
		}else {
			if((top.pos == 0 || top.nums[0] != top.nums[top.pos]) && top.unique.find(top.nums[top.pos]) == top.unique.end()){
				top.unique.insert(top.nums[top.pos]);			
				swap(top.nums[0],top.nums[top.pos]);
				stack.push_back(procedure(0,vector<int>(++top.nums.begin(),top.nums.end()),top.nums[0],&top));
				swap(top.nums[0],top.nums[top.pos]);
			}
			++top.pos;
		}
	}

	return v;
}

void testPermutations() {

	printf("testPermutations\n");

	vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	vector<vector<int> > ret = permuteNoRecursion(v);

	for(size_t j = 0; j < ret.size(); ++j) {
		for(size_t k = 0; k < ret[j].size(); ++k) {
			printf("%d ",ret[j][k]);
		}
		printf("\n");
	}	
}

void testPermutationsII() {
	printf("testPermutationsII\n");	
	vector<int> v;
	v.push_back(3);
	v.push_back(0);
	v.push_back(3);
	vector<vector<int> > ret = permuteUniqueNoRecursion(v);

	for(size_t j = 0; j < ret.size(); ++j) {
		for(size_t k = 0; k < ret[j].size(); ++k) {
			printf("%d ",ret[j][k]);
		}
		printf("\n");
	}	
}

int main() {
	testPermutations();
	testPermutationsII();
	return 0;
}

