
#include <stdio.h>
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
	//返回target应该插入的位置
	int binarySearch(int *a,size_t len,int target) {
		if(!a || len == 0) {
			return 0;
		}
		size_t b = 0;
		size_t e = len - 1;
		for( ; b <= e ; ) {
			size_t m = (e - b)/2 + b;
			if(a[m] == target) {
				if(m <= e && a[m+1] == target) {
					for(size_t i = m + 1; i<= e ;i++) {
						if(a[i] != target) {
							return i;
						}
					}
				}
				return m + 1;	
			} else if(a[m] > target) {
				if(m > 0){
					e = m - 1;
				}else{
					break;
				}
			} else {
				b = m + 1;
			}
		}
		return b;
	}

	double findMedianSortedArrays1(int *nums1,size_t len1,int *nums2,size_t len2,size_t need) {
        if(!nums1 || len1 == 0) {
            return nums2[need];
        }

        if(!nums2 || len2 == 0) {
            return nums1[need];
        }    	

        if(nums1[0] == nums2[0]) {
            if(need == 0 || need == 1){
                return nums1[0];
            } else{
                return findMedianSortedArrays1(&nums1[1],len1-1,&nums2[1],len2-1,need-2);
            }
        } else if(nums1[0] > nums2[0]) {
            int idx = binarySearch(nums1,len1,nums2[0]);
            if(idx == need){
                return nums2[0];
            } else if(need > idx) {
                return findMedianSortedArrays1(&nums1[idx],len1 - idx,&nums2[1],len2 - 1,need - idx - 1);
            } else {
                return findMedianSortedArrays1(NULL,0,nums2,len2,need);
            }
        } else {
            int idx = binarySearch(nums2,len2,nums1[0]);
            if(idx == need){
                return nums1[0];
            } else if(need > idx) {
                return findMedianSortedArrays1(&nums2[idx],len2 - idx,&nums1[1],len1 - 1,need - idx - 1);
            } else {
                return findMedianSortedArrays1(nums1,len1,NULL,0,need);
            }           
        }
	}

    double findMedianSortedArrays2(int *nums1,size_t len1,int *nums2,size_t len2,size_t need1,size_t need2) {
        return (findMedianSortedArrays1(nums1,len1,nums2,len2,need1) + findMedianSortedArrays1(nums1,len1,nums2,len2,need2))/2;        
    }

    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        size_t len = nums1.size() + nums2.size();
        int mod = len%2;
        int m = len/2;

        int *v1 = nums1.empty() ? NULL : &nums1[0];
        int *v2 = nums2.empty() ? NULL : &nums2[0];


        if(mod == 0) {
            return this->findMedianSortedArrays2(v1,nums1.size(),v2,nums2.size(),m-1,m);
        } else {
            return this->findMedianSortedArrays1(v1,nums1.size(),v2,nums2.size(),m);
        }
    }
};

int main(){
    Solution s;

    vector<int> v1;
    vector<int> v2;

    v1.push_back(4);
    v2.push_back(1);
    v2.push_back(2);
    v2.push_back(3);


    printf("%f\n",s.findMedianSortedArrays1(&v1[0],v1.size(),&v2[0],v2.size(),1));
}