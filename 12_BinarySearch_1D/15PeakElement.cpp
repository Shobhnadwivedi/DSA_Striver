#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

/*
A peak element is an element that is strictly greater than its neighbors.

Given a 0-indexed integer array nums, find a peak element, and return its index. If the array contains multiple peaks, return the index to any of the peaks.

You may imagine that nums[-1] = nums[n] = -∞. In other words, an element is always considered to be strictly greater than a neighbor that is outside the array.

You must write an algorithm that runs in O(log n) time.

Example 1:

Input: nums = [1,2,3,1]
Output: 2
Explanation: 3 is a peak element and your function should return the index number 2.
Example 2:

Input: nums = [1,2,1,3,5,6,4]
Output: 5
Explanation: Your function can return either index number 1 where the peak element is 2, or index number 5 where the peak element is 6.
 
*/


// this solution was when we assumed there is a single peak only.
//  But it also works for multiple peaks, as it returns the index of any peak element.

// striver ke solution me , jo maine else if mein || ke baad conditions lagai h , vo nhi thi.


class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        int l=1, h=n-2;
        int ans;
        // return the index of peak element 
        if(n==1){
            ans = 0 ;
        }
        else if(nums[0] > nums[1]){
            ans = 0 ;
        }
        else if(nums[n-1] > nums[n-2]){
            ans = n-1 ;
        }

        while(l<=h){
            int mid =(l+h)/2;

            if(nums[mid] > nums[mid -1] && nums[mid] > nums[mid+1]){
                ans = mid ;
                break;
            }
            else if(nums[mid-1]< nums[mid] || nums[mid] < nums[mid+1]){
                l = mid+1;

            }
            else if(nums[mid-1] > nums[mid] || nums[mid] > nums[mid+1]){
                h = mid-1;
            }
        }
        return ans ;
    }
};

// Solution that works for cases like [1,5,1,2,1] - 
// Only one change is made in the condition of the while loop.
// in this ex


int main(){
    vector<int> arr = {1,5,1,2,1};
    Solution sol;
    int result = sol.findPeakElement(arr);
    cout << result ;

}