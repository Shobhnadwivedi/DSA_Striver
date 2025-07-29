#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int l =0, h= n-1;
        int minim = INT_MAX;

        while(l<=h){
            int mid = (l+h)/2;
            
            // Always update minim first
            minim = min(minim, nums[mid]);

            if(nums[l]==nums[mid] && nums[mid] ==nums[h]){
                l++;
                h--;
                continue;  // this is important kyunki we cant use while here, lekin ye condition baar baar check krwani h.  while lagaeyenge to neche wala else if will give error, kyunki else if se pehle if hona jaruri h
            }
                
            if(nums[l]<= nums[h]){
                minim = min( minim, nums[l]);
                break;
            }
            // if left is sorted sbse chota hoga nums[low]
            if(nums[l]<= nums[mid]){
                minim = min( minim, nums[l]);
                l= mid+1;
            }
            else{
                minim = min(minim , nums[mid]);
                h = mid -1;

            }
            
            
        }
        return  minim ;
    }
    
};


int main(){
    vector<int> arr = {1};
    Solution sol;
    bool result = sol.findMin(arr);
    cout << result ;

}