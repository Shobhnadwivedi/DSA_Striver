#include<iostream>
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


// 1. RECURSIVE SOLUTION
class Solution{
public:
    void Preorder(TreeNode* root, vector<int>& arr){
        // Base Case
        if(root == nullptr){
            return;
        }

        // print/push back the root ka data into arr
        arr.push_back(root->val);

        // go to left subtree first
        Preorder(root->left , arr);

        // then go to right subtree
        Preorder(root->right, arr);

    }

    // Function to return the vector containing nodes in preorder traversal
    vector<int> givePreorderArray(TreeNode* root){
        // Create a vector to store values 
        vector<int> arr;

        // Call the recursive Preorder function
        Preorder(root, arr);
        
        return arr;
    }

};

// 2. ITERATIVE SOLUTION:

class Solution2 {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        stack<TreeNode* > stt;

        stt.push(root);

        while(!stt.empty()){
            int size = stt.size();

            TreeNode* curr = stt.top();
            stt.pop();
            ans.push_back(curr->val);
            if(curr->right != nullptr) stt.push(curr->right);
            if(curr->left != nullptr) stt.push(curr->left);
        }

        return ans;
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
    // vector to store ans:
    vector<int> res;

    res = sol.givePreorderArray(root);

    // print the result array
    for(int i =0; i< res.size(); i++){
        cout << res[i] << " ";
    }
}
