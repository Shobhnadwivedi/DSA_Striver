#include <iostream>
#include <vector>
#include<set>
using namespace std;

// IT IS GIVEN THAT - elements in array are positive  thus once sum =0 , it can't increase.

class Solution {
public:

    void recursive( int i, set<vector<int>> &sett ,  vector<int>& candidates, vector<int> ds, int n, int target ){
        

        // Base case
        if( i >= n || target < 0){
            if( target == 0 ){
                sett.insert(ds);
                return ; 
            } 
            return;                

        }
        

        ds.push_back(candidates[i]);
        recursive(i, sett, candidates, ds, n, target -  candidates[i]);
        
        
        
        recursive(i+1, sett, candidates, ds, n , target -  candidates[i] );

        ds.pop_back();

        recursive(i+1, sett, candidates, ds, n, target);

        return;
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        
        int n = candidates.size();
 
        Solution sol;

        set<vector<int>> sett;
        vector<int> ds;
        sol.recursive(0, sett, candidates, ds, n, target);

        vector<vector<int>> ans( sett.begin(), sett.end());

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
    Solution sol ;

    vector<vector<int>> ans = sol.combinationSum(candidates, k) ;

    for(int i=0 ; i< ans.size(); i++){
        for(int j =0; j< ans[i].size() ; j++){
            cout<< ans[i][j] << " ";
        }
        cout<< endl; 

    }
    
}