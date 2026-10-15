#include<iostream>
#include<vector>
using namespace std;


class Solution2 {
public:

    void recursion(int i, int n, vector<vector<int>> &ans, vector<int> &ds, vector<int> &candidates, int target) {
        
        
        if(target == 0 ){
            ans.push_back(ds);
            return;
        }


        for(int ind = i; ind < candidates.size() ; ind++){
            
            if(ind > i && candidates[ind-1] == candidates[ind] ) continue;

            if(candidates[ind] > target) break;            // 
            
            ds.push_back(candidates[ind]);
            recursion(ind +1 , n, ans,ds, candidates, target-candidates[ind]);
            ds.pop_back();
            

        }
    }


    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        int n = candidates.size();

        sort(candidates.begin(), candidates.end());

        vector<vector<int>> ans ;
        vector<int> ds;

        recursion(0, n, ans, ds, candidates, target );
        
        return ans;

    }
};



int main(){

    cout<< "Enter length of array: ";
    int n ;
    cin >> n;

    cout << "Enter array elements: ";
    vector<int> candidates(n);

    for(int i=0; i<n; i++){
        cin >> candidates[i];
    }
    cout<< "Enter target k : ";

    int k ;
    cin >> k;

    vector<int> ds;
    int sum =0;
    Solution2 sol ;

    vector<vector<int>> res = sol.combinationSum2(candidates, k) ;

    for(int i=0 ; i< res.size(); i++){
        for(int j =0; j< res[i].size() ; j++){
            cout<< res[i][j] << " ";
        }
        cout<< endl; 

    }
}
