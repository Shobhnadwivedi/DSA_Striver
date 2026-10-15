#include<iostream>
#include<vector>
using namespace std;


class Solution {
public:

    void recursion(int i, int n, vector<int>& ds, vector<vector<int>>& ans, vector<int> nums) {
        if(i>=n){
            return;
        }

        ds.push_back(nums[i]);
        
        ans.push_back(ds);
        
        for(int ind = i+1 ; ind < n ; ind++ ){
            recursion(ind , n, ds, ans, nums);
        }
        ds.pop_back();
        

    }


    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size() ;

        vector<vector<int>> ans;
        vector<int> ds;

        ans.push_back({});

        for(int ind = 0; ind<n ; ind++){
            recursion(ind, n, ds, ans, nums);
        }

        return ans;
        
    }
};



int main(){

    cout<< "Enter length of array: ";
    int n ;
    cin >> n;

    cout << "Enter array elements: ";
    vector<int> nums(n);

    for(int i=0; i<n; i++){
        cin >> nums[i];
    }
    

    vector<int> ds;
    int sum =0;
    Solution sol ;

    vector<vector<int>> res = sol.subsets( nums) ;

    for(int i=0 ; i< res.size(); i++){
        for(int j =0; j< res[i].size() ; j++){
            cout<< res[i][j] << " ";
        }
        cout<< endl; 

    }
}
