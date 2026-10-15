#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;



class Solution {
public:

    void recursion(int n, int cntOpen, int cntClose, string  st , vector<string>& ans ) {
        if (st.length() == 2 * n) {
            ans.push_back(st);
            return;
        }
        if (cntOpen < n) recursion(n, cntOpen + 1, cntClose, st + '(' , ans);
        if (cntClose < cntOpen) recursion(n, cntOpen, cntClose + 1, st + ')', ans);
    }

    vector<string> generateParenthesis(int n) {
        // to generate valide paranthesis ... when we want to add any closing bracket -->> No. of open > No. of close  &&  no. of open < n

        // when adding opening bracket -->> No. of open brackets < n
        vector<string> ans;


        recursion(n,0,0, "", ans);
        return ans;
        
        
    }
    
};


int main(){

    int n ;
    cout << "Enter n :" ;
    cin >> n;


    Solution sol;
    vector<string> ans;
    
    ans = sol.generateParenthesis(n);

    for(int i=0; i< ans.size() ; i++){
        for(int j =0 ; j< ans[i].size(); j++){
            cout << ans[i][j];
        }
    }
}