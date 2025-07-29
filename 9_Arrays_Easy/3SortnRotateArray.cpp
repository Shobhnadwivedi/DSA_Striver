/*                  LEETCODE = 1752
Given an array nums, return true if the array was originally sorted in non-decreasing order, then rotated some number of positions (including zero). Otherwise, return false.

There may be duplicates in the original array.

Note: An array A rotated by x positions results in an array B of the same length such that B[i] == A[(i+x) % A.length] for every valid index i.

 

Example 1:

Input: nums = [3,4,5,1,2]
Output: true
Explanation: [1,2,3,4,5] is the original sorted array.
You can rotate the array by x = 3 positions to begin on the element of value 3: [3,4,5,1,2].
*/


#include <iostream>
#include <vector>
#include <algorithm>  // For sort function
using namespace std;

//  Brute force method = T.C = O( )
class Solution1 {
    public:
        bool check(vector<int>& nums) {
            int n =nums.size();
            vector<int> newnum;
            for(int i=0;i<n;i++){
                newnum.push_back(nums[i]) ;
            }
            sort(newnum.begin(), newnum.end());
            int final_cnt =0;
            for(int k=0;k<n;k++){
                int cnt=0;
                for(int i=0;i<n;i++){
                    if( newnum[i] == nums[(i+k)%n]){
                            cnt+=1;
                    }
                }
                if(cnt == n){  final_cnt+=1; }
            }
    
            if(final_cnt>0){
                    return true;
            }
    
            else return false;
    }
};


class Solution1 {
    public:
        bool check(vector<int>& nums) {

        }
};


int main(){
    vector<int> arr = {3,4,5,1,2};
    Solution1 sol ;
    cout<< sol.check(arr);
    

}