#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


class Solution {
  public:
    int countFreq(vector<int>& arr, int target) {
        int n = arr.size();
        
        auto it1 = lower_bound(arr.begin(), arr.end(), target);
        int lb = it1 - arr.begin();

        auto it2 = upper_bound(arr.begin(), arr.end(), target);
        int ub = it2 - arr.begin();

        if( (arr[lb] != target)  ||  (lb== n)){
            return 0;
        }
        else{
            return ub -lb;
        }
        
    }
};

class Solution2{
private:
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
    int countFreq(vector<int>& arr , int target){
        int n = arr.size();
        int lb = lowerBound(arr, target);
        int ub = upperBound(arr, target);
        if((lb == n) || (arr[lb] != target)){
            return 0;
        }
        else{
            return ub - lb;
        }

    }
};

int main(){
    vector<int> arr = {1,2,2,4,4,7,8,9,9,9,11};
    Solution sol;
    int result = sol.countFreq(arr, 9);
    cout << result ;

}