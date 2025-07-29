#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int l=0 , h=n-1;
        int minim= nums [(l+h)/2] ;

        while(l<=h){
            int mid = (l+h)/2 ;
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
        return minim ;
    }
};



// Thoda sa optimize aur kr skte h -  agar koi portion (low - mid - high ) dono side sorted h , mtlb that portion is fully sorted to 
// arr[low] will be minimum and break te loop.

class Solution2 {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int l=0 , h=n-1;
        int minim= nums [(l+h)/2] ;

        while(l<=h){
            int mid = (l+h)/2 ;

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
        return minim ;
    }
};



int main(){
    vector<int> arr = {18,11,13,15,17};
    Solution sol;
    int result = sol.findMin(arr);
    cout << result ;

}
