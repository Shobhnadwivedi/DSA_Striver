#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
/*
You are given an array arr of positive integers. Your task is to find all the leaders in the array. 
An element is considered a leader if it is greater than or equal to all elements to its right. The rightmost element is always a leader.
mtlb uske right ke saarey elemnts must be smaller or equal to it .
Examples:

Input: arr = [16, 17, 4, 3, 5, 2]
Output: [17, 5, 2]
Explanation: Note that there is nothing greater on the right side of 17, 5 and, 2.
Input: arr = [10, 4, 2, 4, 1]
Output: [10, 4, 4, 1]
Explanation: Note that both of the 4s are in output, as to be a leader an equal element is also allowed on the right. side
*/


class Solution {
    // Function to find the leaders in the array.
  public:
    vector<int> leaders(vector<int>& arr) {
        int n = arr.size();
        vector<int> ans ;
        
        for(int i = 0;i<=n-2;i++){
            bool isgreater= false;
            for(int j=i+1; j<n; j++){
                
                if(arr[j]> arr[i]){
                    isgreater = true;
                    break;
                }
                
            }
            if(isgreater== false){
                    ans.push_back(arr[i]);
                }
        }
        ans.push_back(arr[n-1]);
        return ans;
        
    }
};


class Solution2 {
    // Function to find the leaders in the array.
  public:
    vector<int> leaders(vector<int>& arr) {
        int maxx = arr[arr.size()-1];
        vector<int> ans= {arr[arr.size()-1]};
        for(int i=arr.size()-2; i>=0;i--){
            if(arr[i]>= maxx){
                ans.push_back(arr[i]);
                maxx = max(maxx,arr[i]);
            }
            else{
                maxx = max(maxx,arr[i]);
            }
        }
        reverse(ans.begin(),ans.end());
        return ans;
        
        
    }
};


int main(){
    vector<int> arr= { 16, 17, 4, 3, 5, 2 };
    Solution2 sol;
    vector<int> res = sol.leaders(arr);
    for(int i=0; i< res.size(); i++){
        cout << res[i] << ' ';
    }
}