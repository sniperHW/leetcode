
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:

	std::pair<ListNode*,int> remove(ListNode *head,int n) {
		if(!head->next){
			int i = 1;
			if(i == n) {
				return std::make_pair(nullptr,0);
			} else {
				return std::make_pair(head,i);
			}
		} else {
			std::pair<ListNode*,int> next = remove(head->next,n);
			if(0 == next.second) {
				head->next = next.first;
				return std::make_pair(head,0);
			} else {
				int i = next.second + 1;
				if(i == n) {
					head->next = NULL;
					return std::make_pair(next.first,0);
				} else {
					return std::make_pair(head,i);
				}				
			}
		}
	}

    ListNode* removeNthFromEnd(ListNode* head, int n) {
    	if(!head || n <= 0) return NULL;
    	return remove(head,n).first;
    }
};


ListNode *vtol(const std::vector<int> &v) {
	ListNode *head = NULL;
	ListNode *tail = NULL;
	for(std::vector<int>::const_iterator it = v.begin(); it != v.end(); it++) {
		ListNode *n = new ListNode(*it);
		std::cout << *it << std::endl;
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

	ListNode *newL = s.removeNthFromEnd(vtol(v),2);

	showv(ltov(newL));

	return 0;
}