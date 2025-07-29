#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


class Solution {
    //  same formula as of finding the index ,
    //  bas if not found wale case me pehle return -1 tha ->> when( low> high) 
    //  now return low if that happens kyunki wo index pr hi insert hoga number.


    
private:
    int helper(vector<int>& nums,int target, int low,int high){
        int mid= (low + high)/2;
        if(nums[mid]==target){
            return mid;
        }
        else if(low>high){
            return low ;
        }
        else if(nums[mid] > target){
            return helper(nums, target, low, mid-1);
        }
        else{
            return helper(nums,target, mid+1, high);
        }
    }

public:
    int searchInsert(vector<int>& nums, int target) {
        int n=nums.size();
        int low=0, high=n-1;
        return helper(nums,target, low, high);
    }
};


//  or copy the solution of the LOWER BOUND ( kyunki yahan the answer is lower bound only )

class Solution2{
public:
    int searchInsert(vector<int>& nums, int target, int low, int high){

    }
};


int main(){
    vector<int> arr = {1,2,2,4,7,8,9,11};
    Solution sol;

    int res = sol.searchInsert(arr,5);
    cout<< res;
}