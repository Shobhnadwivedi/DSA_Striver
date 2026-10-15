#include<iostream>
#include<vector>
#include<set>
using namespace std;



class Solution {
public:

    void recursion(int i, int n, vector<int> ds, vector<vector<int>>& ans, vector<int>& nums) {
        if(i>=n) {
            return;
        }

        for(int ind =i ; ind<n ; ind++){
            if(ind > i  && nums[ind-1] == nums[ind] ) continue;

            ds.push_back(nums[ind]);
            ans.push_back(ds);
            recursion(ind +1, n, ds, ans, nums);
            ds.pop_back();
            
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        int n = nums.size() ;

        vector<vector<int>> ans;
        vector<int> ds;

        sort(nums.begin(), nums.end());
        ans.push_back({});
        recursion(0 , n, ds, ans, nums );


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

    vector<vector<int>> res = sol.subsetsWithDup( nums) ;

    for(int i=0 ; i< res.size(); i++){
        for(int j =0; j< res[i].size() ; j++){
            cout<< res[i][j] << " ";
        }
        cout<< endl; 

    }
}
