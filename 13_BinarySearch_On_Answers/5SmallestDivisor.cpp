#include<iostream>
#include<cmath>
#include<vector>
#include<algorithm> 
using namespace std;

class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int n= nums.size();
        int l =1, h = *max_element(nums.begin(), nums.end()); 

        while(l<=h){
            long long mid = l + (h-l)/2 ; // Calculate mid to avoid overflow
            double val = 0;
            for(int i=0;i<n;i++){
                val += ( nums[i] + mid -1 )/ mid ;                     // safer than ceil((double)nums[i]/mid)
            }

            if(val <= threshold){
                h = mid-1;
            }
            else{
                l = mid+1;
            }
        }
        return l ;  // or ( h + 1 )
    }
};

int main(){
    Solution sol;

    vector<int> nums1 = {1,2,5,9}; 

    cout<< sol.smallestDivisor(nums1, 6) << endl; 

    vector<int> nums2 = {44,22,33,11,1}; 
    cout<< sol.smallestDivisor(nums2, 5) << endl;


}