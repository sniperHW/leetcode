#include <iostream>
#include <vector>

using namespace std;

/*
Given a linked list, swap every two adjacent nodes and return its head.

You may not modify the values in the list's nodes, only nodes itself may be changed.

Example:

Given 1->2->3->4, you should return the list as 2->1->4->3.

*/

struct ListNode {
 int val;
 ListNode *next;
 ListNode(int x) : val(x), next(NULL) {}
};
 
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
    	if(NULL == head || NULL == head->next) return head;
       	ListNode *newHead = NULL;
       	for(ListNode *first = head,*tail = NULL; first ; first=first->next) {
       		if(first->next) {
       			if(!newHead) newHead = first->next;
       			if(tail) tail->next = first->next;       			       			
       			//swap
       			ListNode *next = first->next->next;
       			first->next->next = first;
       			first->next = next;

       			tail = first;
       		} else {
       			tail->next = first;
       		}
       	}
       	return newHead;
    }
};


ListNode *vtol(const std::vector<int> &v) {
	ListNode *head = NULL;
	ListNode *tail = NULL;
	for(std::vector<int>::const_iterator it = v.begin(); it != v.end(); it++) {
		ListNode *n = new ListNode(*it);
		//std::cout << *it << std::endl;
		if(!head){
			head = n;
		}
		if(tail){
			tail->next = n;
		}
		tail = n;
	}
	return head;
}

std::vector<int> ltov(ListNode *head) {
	std::vector<int> v;
	ListNode *cur = head;
	while(cur){
		v.push_back(cur->val);
		cur = cur->next;
	}
	return v;
}

void showv(const std::vector<int> &v) {
	for(std::vector<int>::const_iterator it = v.begin(); it != v.end(); it++) {
		std::cout << *it << ",";
	}
	std::cout << std::endl;
}

int main() {

	Solution s;

	std::vector<int> v{1,2,3,4,5,6,7,8};

	//showv(ltov(vtol(v)));

	ListNode *newL = s.swapPairs(vtol(v));

	showv(ltov(newL));

	return 0;
}