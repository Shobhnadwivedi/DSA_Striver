#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// BRUTE FORCE SOLUTION = LINEAR SEARCH =    T.C = O( N )



// Using Lower Bound and Upper Bound    =  T.C = O(log n)
class Solution2{
private:
    int lowerBound(vector<int>& arr, int target) {
        int ans= arr.size();
        int l=0, h= arr.size()-1;
        while(l<=h){
            int mid = (l+h)/2 ;
            
            if(arr[mid]>= target){          
                ans = mid;                  
                h = mid-1;                 
            }
            else{
                l= mid+1;
            }
        }
        return ans; 
    }

    int upperBound(vector<int>& arr, int target) {
        int ans= arr.size();
        int l=0, h= arr.size()-1;
        while(l<=h){
            int mid = (l+h)/2 ;
           
            if(arr[mid]> target){           
                ans = mid;                  
                h = mid-1;                  
            }
            else{
                l= mid+1;
            }
        }
        return ans; 
    }

public: 
    vector<int> searchRange(vector<int>& nums, int target){
        
    }
};



// Using simple Binary search =    T.C = O(log n )
class Solution3 {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans= {-1,-1};
        int l=0, h= nums.size()-1;

        // for smallest 
        while(l<=h){
            int mid = (l+h)/2 ;
            if(nums[mid]< target){
                l= mid+1;
            }
            else if(nums[mid] > target){
                h=mid - 1;
            }
            else{
                ans[0]=mid;
                h=mid -1;
            }
        }

        // for largest occurrence 
        l=0, h= nums.size()-1;
        while(l<=h){
            int mid = (l+h)/2;
            if(nums[mid]< target){
                l= mid+1;
            }
            else if(nums[mid] > target){
                h=mid - 1;
            }
            else{
                ans[1]=mid;
                l = mid+1;
            }
        }
        return ans;

    }
};


class Solution{
public:
    vector<int> searchRange(vector<int>& nums, int target){
        int n = nums.size();
        vector<int> ans = [-1,-1];
        auto it1 = lower_bound(nums.begin(), nums.end(), target);
        int lb = it1 - nums.begin();

        auto it2 = upper_bound(nums.begin(), nums.end(), target);
        int ub = it2 - nums.begin();

        if( ub==n || lb != target){

        }

    }
};




int main(){
    vector<int> arr = {1,2,2,4,4,7,8,9,9,9,11};
    Solution2 sol;
    vector<int> result = sol.searchRange(arr, 9);
    for(int i =0; i< result.size(); i++){
        cout << result[i]<< " ";
    }

}