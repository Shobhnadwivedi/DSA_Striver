#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
  public:
    int lowerBound(vector<int>& arr, int target) {
        int ans= arr.size();
        int l=0, h= arr.size()-1;
        while(l<=h){
            int mid = (l+h)/2 ;
           
            if(arr[mid]>= target){          // pehlr the code was incorrect kyunki when l=h=0 ho raha tha then m = 0 , fir uske baad h update hi nhi ho raha tha 
                ans = mid;                  //  incorrect code =  h = mid ;
                h = mid-1;                  //                    ans = mid;
            }
            else{
                l= mid+1;
            }
        }
        return ans; 
    }
};


int main(){
    vector<int> arr = {2,2,4,4,7,8,9,9,9,11};
    Solution sol;

    int res = sol.lowerBound(arr,1);
    cout<< res;
}