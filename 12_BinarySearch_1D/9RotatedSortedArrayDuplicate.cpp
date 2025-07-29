#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int n = nums.size();
        int l =0, h= n-1;
        bool isthere = false;
        while(l<=h){
            int mid = (l+h)/2;

            if(nums[mid]== target){
                isthere = true ;
            }
            

            if(nums[l]==nums[mid] && nums[mid] ==nums[h]){
                l++;
                h--;
                continue;  // this is important kyunki we cant use while here, lekin ye condition baar baar check krwani h.  while lagaeyenge to neche wala else if will give error, kyunki else if se pehle if hona jaruri h
            }
                
            else if(nums[l]<= nums[mid]){     
                if(nums[l]<= target  && target <= nums[mid] ){
                    h= mid-1;
                }
                else{
                    l = mid+1;
                }
            }
            else{
                if(nums[mid]<= target && target <= nums[h]){
                    l= mid+1;
                }
                else{
                    h = mid-1;
                }

            }
            
            
        }
        return  isthere ;
    }
    
};


int main(){
    vector<int> arr = {1,0,1,1,1};
    Solution sol;
    bool result = sol.search(arr, 0);
    cout << result ;

}