#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


// 1 APPROACH -> EXTRA SPACE 
class Solution {
public:
    void recursion(int i, int n, vector<int> ds, unordered_map<int,int>& mark, vector<vector<int>>& ans, vector<int>& nums) {
        if(i>=n){
            
            ans.push_back(ds);
            return;
        }
        
        for(int j =0 ; j<n; j++){
            if(mark.count(j) == 0 ){
                mark[j]++;
                ds.push_back(nums[j]) ;
                recursion(i+1, n, ds, mark, ans, nums);
                mark.erase(j);
                ds.pop_back();
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        int n = nums.size();

        vector<vector<int>> ans;
        vector<int> ds;
        unordered_map<int,int> mark;

        recursion(0, n, ds, mark, ans, nums);

        return ans;
        

    }
};


// 2 APPROACH -> NO EXTRA SPACE

class Solution2 {
public:
    void recursion(int i, vector<vector<int>>& ans, vector<int>& nums) {
        
        if(i >= nums.size()){
            ans.push_back(nums);
            return;
        }

        for(int j = i ; j < nums.size() ; j++){
            swap(nums[i], nums[j]);
            recursion(i+1, ans, nums);
            swap(nums[i], nums[j]);
        }
    }


    vector<vector<int>> permute2(vector<int>& nums) {
        int n = nums.size();

        vector<vector<int>> ans;

        recursion(0, ans, nums);

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
    Solution2 sol ;

    vector<vector<int>> res = sol.permute2( nums) ;

    for(int i=0 ; i< res.size(); i++){
        for(int j =0; j< res[i].size() ; j++){
            cout<< res[i][j] << " ";
        }
        cout<< endl; 

    }
}
