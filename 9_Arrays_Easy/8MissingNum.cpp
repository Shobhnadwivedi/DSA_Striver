#include <iostream>
#include <vector>

using namespace std;



class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        vector<int> h_arr( n+1 ,0);
        for(int i =0 ; i< n;i++){
            h_arr[nums[i]]++ ; 
        }
        int miss;
        for(int k=0;k<h_arr.size();k++){ 
            if(h_arr[k]==0){
                miss= k;
            }
        }
        return miss;

    }
};





int main(){
    vector<int> nums = {3,0,5,1,2};
    Solution sol ;
    int res = sol.missingNumber(nums);
    cout<< res;
    
    

}