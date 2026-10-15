// OPTIMAL - In this approach, we will first sort the array and will try to choose the numbers in a greedy way.
//  We will keep a left pointer at the first index and a right pointer at the last index. Now until left < right, we will check the sum of arr[left] and arr[right]. Now if the sum < target, we need bigger numbers and so we will increment the left pointer. But if sum > target, we need to consider lesser numbers and so we will decrement the right pointer.

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution2 {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> mpp;

        for(int i=0; i< nums.size(); i++){
            if(mpp.find(target - nums[i]) != mpp.end()){
                return {i, mpp[target - nums[i]] };
            }
            mpp[nums[i]] = i;

        }

        return {};
    }    
};


class Solution3 {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        sort (nums.begin(), nums.end());

        int l=0, r = nums.size()-1;

        while(l<r){
            if(nums[l] + nums[r] == target){
                return {l, r};
            }
            else if( nums[l] + nums[r] < target ){
                l++;
            }
            else{
                r--;
            }
        }
        return {};
    }    
};