#include <iostream>
#include <vector>

using namespace std;

/*
Given a linked list, reverse the nodes of a linked list k at a time and return its modified list.

k is a positive integer and is less than or equal to the length of the linked list. If the number of nodes is not a multiple of k then left-out nodes in the end should remain as it is.

Example:

Given this linked list: 1->2->3->4->5

For k = 2, you should return: 2->1->4->3->5

For k = 3, you should return: 3->2->1->4->5

Note:

    Only constant extra memory is allowed.
    You may not alter the values in the list's nodes, only nodes itself may be changed.


*/

struct ListNode {
 int val;
 ListNode *next;
 ListNode(int x) : val(x), next(NULL) {}
};
 
class Solution {
public:

	pair<ListNode*, ListNode*> reverse(ListNode* head,int i,int k) {
		if(!head) {
			return make_pair(nullptr,nullptr);
		}

		if(i == k) {
			return make_pair(head,head);
		} else {
			pair<ListNode*,ListNode*> t = reverse(head->next,i+1,k);
			if(!t.first && !t.second) {
				if(i == 1) return make_pair(head,nullptr);
				else return make_pair(nullptr,nullptr);
			}
			head->next = t.second->next;
			t.second->next = head;
			return make_pair(t.first,head);
		}
	}

    ListNode* reverseKGroup(ListNode* head, int k) {
    	if(!head || !head->next) return head;
    	ListNode *newHead = NULL;
    	ListNode *tail = NULL;
    	for( ; head ; ) {
    		pair<ListNode*,ListNode*> t = reverse(head,1,k);
    		if(!tail) {
    			newHead = t.first;
    		} else{
    			tail->next = t.first;
    		}
    		tail = t.second;
    		if(!tail) break;
    		else head = tail->next;
    	}
    	return newHead;
    }
};


ListNode *vtol(const std::vector<int> &v) {
	ListNode *head = NULL;
	ListNode *tail = NULL;
	for(std::vector<int>::const_iterator it = v.begin(); it != v.end(); it++) {
		ListNode *n = new ListNode(*it);
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

	std::vector<int> v{1,2,3,4,5};

	//showv(ltov(vtol(v)));

	ListNode *newL = s.reverseKGroup(vtol(v),3);

	showv(ltov(newL));

	return 0;
}