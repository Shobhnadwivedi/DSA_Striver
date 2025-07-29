
//   MOST USEFUL COMMENT ON LEETCODE  ( MUST READ )=    https://leetcode.com/problems/find-the-smallest-divisor-given-a-threshold/solutions/777019/python-clear-explanation-powerful-ultimate-binary-search-template-solved-many-problems


/*                    BINARY SEARCH 
Binary search is an efficient algorithm for finding a target value in a sorted array by repeatedly dividing the search interval in half. 
It compares the target value with the middle element of the array and eliminates half of the remaining elements based on whether the target is less than or greater than the middle element.

*/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution{
public:
    int BinarySearch(vector<int>& nums,int target){
        int n= nums.size();
        int low=0, high=n-1;

        while(high>=low){
            int mid= (low+high)/2;

            if(nums[mid]== target){
                return mid;
            }
            else if(nums[mid] > target){
                high = mid-1;
            }
            else{
                low=mid+1;
            }
            
        }
        
        return -1;
        
    }
};


class Solution2{
private:
    int helper(vector<int>& nums,int target, int low,int high){
        int mid= (low + high)/2;
        if(nums[mid]==target){
            return mid;
        }
        else if(low>high){
            return -1;
        }
        else if(nums[mid] > target){
            return helper(nums, target, low, mid-1);
        }
        else{
            return helper(nums,target, mid+1, high);
        }
    }

public:
    int BinarySearch(vector<int>& nums,int target){
        int n=nums.size();
        int low=0, high=n-1;
        return helper(nums,target, low, high);
    
    }
};



int main(){
    vector<int> nums = {3,4,6,7,9,12,16,19};
    Solution2 sol;
    int res = sol.BinarySearch(nums, 12);
    cout<< res;
}