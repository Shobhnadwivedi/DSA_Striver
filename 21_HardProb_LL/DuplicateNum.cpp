// YT Explaination video : https://youtu.be/hCIdhv7-5Ms?si=IMzsxMZX4MCUu18B
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

/*
Given an array of integers nums containing n + 1 integers where each integer is in the range [1, n] inclusive.
There is only one repeated number in nums, return this repeated number.
You must solve the problem without modifying the array nums and using only constant extra space.

 

Example 1:

Input: nums = [1,3,4,2,2]
Output: 2
Example 2:

Input: nums = [3,1,3,4,2]
Output: 3
Example 3:

Input: nums = [3,3,3,3,3]
Output: 3

*/


class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        
        int slow = 0,fast = 0;

        // very important to put slow 1 step and fast 2 steps ahead before the loop, 
        // vrna while(slow!=fast) wali condition starting me hi false ho jayegi and the loop will not run
        slow = nums[slow];
        fast = nums[nums[fast]];


        while( slow != fast){
            slow = nums[slow];
            fast = nums[nums[fast]];
        }

        // once slow==fast , means cycle detected, now find the duplicate number
        // find the entry point of the cycle

        slow= 0;    // fast is same 
        while(slow != fast){
            slow = nums[slow];
            fast = nums[fast];
        }

        return slow;
    }
};


int main(){

}