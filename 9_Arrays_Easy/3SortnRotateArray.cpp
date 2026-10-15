/*                  LEETCODE = 1752      ->     Check if Array Is Sorted and Rotated

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
#include <algorithm>  // For sort function and min function
using namespace std;

//  MYYY Brute force method = T.C = O( n^2 )  S.C = O(n)
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



// 
class Solution2 {
public:
    bool check(vector<int>& nums) {
        int n = nums.size();

        // Construct the rotated array
        vector<int> checkSorted(n);

        // Iterate through all possible rotation offsets
        for (int rotationOffset = 0; rotationOffset < n; ++rotationOffset) {
            int currIndex = 0;
            for (int index = rotationOffset; index < n; ++index) {
                checkSorted[currIndex++] = nums[index];
            }
            for (int index = 0; index < rotationOffset; ++index) {
                checkSorted[currIndex++] = nums[index];
            }

            // Check if the constructed array is sorted
            bool isSorted = true;
            for (int index = 0; index < n - 1; ++index) {
                if (checkSorted[index] > checkSorted[index + 1]) {
                    isSorted = false;
                    break;
                }
            }

            // If sorted, return true
            if (isSorted) {
                return true;
            }
        }

        // If no rotation makes the array sorted, return false
        return false;
    }
};



// Another Brute force method = T.C = O( n^2 )  S.C = O(n)
class Solution3 {
public:
    bool check(vector<int>& nums) {
        int size = nums.size();

        // Create a sorted copy of the array
        vector<int> sortedNums = nums;
        sort(sortedNums.begin(), sortedNums.end());

        // Compare the original array with the sorted array, considering all
        // possible rotations
        for (int rotationOffset = 0; rotationOffset < size; ++rotationOffset) {
            bool isMatch = true;
            for (int index = 0; index < size; ++index) {
                if (nums[(rotationOffset + index) % size] !=
                    sortedNums[index]) {
                    isMatch = false;
                    break;
                }
            }
            if (isMatch) {
                return true;
            }
        }

        return false;
    }
};


// Another Brute force method = T.C = O( n^2 )  S.C = O(1)
class Solution4 {
public:
    bool check(vector<int>& nums) {
        int n = nums.size();
        


        for(int rotationOFFSET = 0 ; rotationOFFSET < n ; rotationOFFSET++){

            bool sorted = true;
            for( int i = rotationOFFSET ; i < (n + rotationOFFSET )-1   ; i++){
                if( nums[i% n] > nums[(i+1)%n] ){
                    sorted = false ;
                    break;
                } 
            }

            if(sorted){
                return true;
            }

        }
        
        return false;
    }
};


// OPTIMAL SOLUTION 
class Solution5 {
    public:
        bool check(vector<int>& nums) {

            int n = nums.size();
            int smallest = nums[0];
            int index = 0;
            for(int i=0; i<n ; i++){
                if(nums[i]< smallest){
                    index =i;
                    smallest = nums[i];
                }
            }

            // index is the position of smallest number in array
            // from that index till 
            int cnt=0;
            for(int i = index; i< (index+n) ; i++){
                if( nums[i%n] > nums[ (i+1) % n ] ){
                    cnt++;
                }
            }

            if(cnt>1){
                return false;
            }
            return true;
            

        }
};





int main(){
    vector<int> arr = {3,4,5,1,2};
    Solution1 sol ;
    cout<< sol.check(arr);
    

}

