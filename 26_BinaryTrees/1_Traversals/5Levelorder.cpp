#include<iostream>
#include<vector>
#include<stack>
using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};



// 1. Iterative Solution :







// 2. Recursive solution :
class Solution2{
public:
    void helper(TreeNode* node, int level, vector<vector<int>>& ans){
        if(node == nullptr){
            return;
        }

        if(level == ans.size()){
            ans.push_back(vector<int>());
        }

        ans[level].push_back(node->val);
        
        helper(node->left , level + 1, ans);
        helper(node->right , level + 1, ans);
    }

    vector<vector<int>> levelOrder(TreeNode* root){
        vector<vector<int>> res ;

        helper(root, 0, res);

        return res;
    }
};





/*
       1
     /   \
    2      3
   /  \
  4    5

*/
 

int main(){
    // Make a tree:
    TreeNode* root = new TreeNode(1);
    root->left  = new TreeNode(2);
    root->right  = new TreeNode(3);
    root -> left ->left = new TreeNode(4);
    root -> left -> right = new TreeNode(5);


    // Create objct
    Solution2 sol;
    // vector to store ans:
    vector<vector<int>> res;

    res = sol.levelOrder(root);

    // print the result array
    for(int i =0; i< res.size(); i++){
        for(int j =0; j< res[i].size(); j++){
            cout << res[i][j] << " ";
        }
    }
}
