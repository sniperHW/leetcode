
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

    double Min(int *nums1,size_t len1,int i,int *nums2,size_t len2,int j) {
        if(len1 - 1 < i) {
            return nums2[j];
        }

        if(len2 - 1 < j) {
            return nums1[i];
        }

        return min(nums1[i],nums2[j]);
    }

	double findKOfTwoSortedArrays(int *nums1,size_t len1,int *nums2,size_t len2,size_t k,bool k1) {
        if(!nums1 || len1 == 0) {
            if(k1){
                return ((double)nums2[k] + (double)nums2[k+1])/2;
            } else {
                return nums2[k];
            }
        }

        if(!nums2 || len2 == 0) {
            if(k1){
                return ((double)nums1[k] + (double)nums1[k+1])/2;
            } else {
                 return nums1[k];               
            }
        }    	

        if(nums1[0] == nums2[0]) {
            if(k == 0 || k == 1){
                if(!k1 || k == 0){
                    return nums1[0];
                } else {
                    return ((double)nums1[0] + (double)Min(nums1,len1,1,nums2,len2,1))/2;
                }
            } else{
                return findKOfTwoSortedArrays(&nums1[1],len1-1,&nums2[1],len2-1,k-2,k1);
            }
        } else if(nums1[0] > nums2[0]) {
            int idx = binarySearch(nums1,len1,nums2[0]);
            if(idx == k){
                if(k1){
                    return ((double)nums2[0] + (double)Min(nums2,len2,1,nums1,len1,idx))/2;
                } else {
                    return nums2[0];
                }
            } else if(k > idx) {
                return findKOfTwoSortedArrays(&nums1[idx],len1 - idx,&nums2[1],len2 - 1,k - idx - 1,k1);
            } else {
                return findKOfTwoSortedArrays(NULL,0,nums2,len2,k,k1);
            }
        } else {
            int idx = binarySearch(nums2,len2,nums1[0]);
            if(idx == k){
                if(k1) {
                    return ((double)nums1[0] + (double)Min(nums1,len1,1,nums2,len2,idx))/2;
                } else {
                    return nums1[0];
                }
            } else if(k > idx) {
                return findKOfTwoSortedArrays(&nums1[1],len1 - 1,&nums2[idx],len2 - idx,k - idx - 1,k1);
            } else {
                return findKOfTwoSortedArrays(nums1,len1,NULL,0,k,k1);
            }           
        }
	}

    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        size_t len = nums1.size() + nums2.size();
        size_t mod = len%2;
        size_t m = len/2;

        int *v1 = nums1.empty() ? NULL : &nums1[0];
        int *v2 = nums2.empty() ? NULL : &nums2[0];

        if(mod == 0) {
            return findKOfTwoSortedArrays(v1,nums1.size(),v2,nums2.size(),m-1,true);
        } else {
            return findKOfTwoSortedArrays(v1,nums1.size(),v2,nums2.size(),m,false);
        }
    }
};

int main(){
    Solution s;

    vector<int> v1;
    vector<int> v2;

    v1.push_back(1);
    //v1.push_back(3);
    v2.push_back(1);
    //v2.push_back(3);


    printf("%f\n",s.findMedianSortedArrays(v1,v2));

    //printf("%f\n",s.findKOfTwoSortedArrays(&v1[0],v1.size(),&v2[0],v2.size(),1,false));
}