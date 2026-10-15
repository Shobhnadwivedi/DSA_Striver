include<iostream>
#include<vector>
#include<stack>
using namespace std;



// STRUCTURE OF NODE
struct  TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;


    // Constructor:
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}

};




// RECURSIVE SOLUTION : 
class Solution {
public:
    void helper(TreeNode* node, int height){
        if(node->left == nullptr){
            
        }
    }
    
    int maxDepth(TreeNode* root) {
        
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
    Solution sol;
    

}