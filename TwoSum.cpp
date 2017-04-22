/*
Given an array of integers, return indices of the two numbers such that they add up to a specific target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

Example:
Given nums = [2, 7, 11, 15], target = 9,

Because nums[0] + nums[1] = 2 + 7 = 9,
return [0, 1].
*/

class Solution {
public:

    int search(vector<pair<int,int> > &numbers,int begin,int end,int target){
    	if(begin > end) return -1;
    	int mid = begin + (end - begin)/2;
    	int midval = numbers[mid].first;
    	if(midval == target)
    		return mid;
    	else if(midval < target)
    		return search(numbers,mid+1,end,target);
    	else
    		return search(numbers,begin,mid-1,target);
    }

    static bool myfunction (pair<int,int> i,pair<int,int> j) { 
    	return i.first < j.first; 
    }

   vector<int> twoSum(vector<int> &numbers, int target) {
     	vector<pair<int,int> > mynumbers;
     	int size = numbers.size();
     	for(int i = 0; i < size; ++i){
     		mynumbers.push_back(make_pair(numbers[i],i+1));
     	}
     	sort(mynumbers.begin(),mynumbers.end(),myfunction);
     	vector<int> ret;
     	for(int i = 0; i < size; ++i){
     		int value = mynumbers[i].first;
     		int remain = target - value;
     		int j = search(mynumbers,i+1,size-1,remain);
     		if(j > 0){
     			if(mynumbers[i].second < mynumbers[j].second){
      				ret.push_back(mynumbers[i].second);
     				ret.push_back(mynumbers[j].second);
     			}else{
      				ret.push_back(mynumbers[j].second);
     				ret.push_back(mynumbers[i].second);
     			}
     			break;    			
     		}
     	}
     	return ret;
    }
};