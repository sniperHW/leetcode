/*
You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8
*/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
*/
class Solution {
public:
    void fetch(ListNode *n,vector<int> &num){
    	if(!n){
    		return;
    	}else{
       		num.push_back(n->val); 		
    		fetch(n->next,num);
    	}
    }

    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
    	vector<int> num1,num2;
    	fetch(l1,num1);
    	fetch(l2,num2); 	
		vector<int> *op1,*op2;
		if(num1.size() > num2.size()){
			op1 = &num1;
			op2 = &num2;
		}else{
			op1 = &num2;
			op2 = &num1;		
		}

		int size1 = op1->size();
		int size2 = op2->size();
		int carry = 0;
		for(int i = 0; i < size1; ++i){
			int tmp = 0;
			if(i < size2) tmp = (*op2)[i];
			(*op1)[i] += (tmp + carry);
			if((*op1)[i] >= 10){
				(*op1)[i] %= 10;
				carry = 1;
			}else{
				carry = 0;
			}
		}
		if(carry){
			op1->push_back(1);
		}		
		int size = op1->size();
		ListNode *head = NULL;
		ListNode *pre = NULL;
		for(int i = 0; i < size ; ++i){
			ListNode *tmp = new ListNode((*op1)[i]);
			if(!head){
				head = pre = tmp;
			}else{
				pre->next = tmp;
				pre = tmp;
			}
		}
		return head;
    }
};