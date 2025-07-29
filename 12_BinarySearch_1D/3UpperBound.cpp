#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


class Solution {
  public:
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
};


int main(){
    vector<int> arr = {1,2,2,4,4,7,8,9,9,9,11};
    Solution sol;

    int res = sol.upperBound(arr,4);
    cout<< res;
}