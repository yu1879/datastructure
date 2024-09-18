/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root) {
        int max = 0;
        calculate(root, max);
        return max;
    }
    int calculate(TreeNode* root, int &max){
        if(root == nullptr) return 0;
        
        // height of left subtree
        int max_left = calculate(root->left, max);
        // height of right subtree
        int max_right = calculate(root->right, max);
        
        // Compare max and max_left + max_right
        max = max>max_left+max_right?max:max_left+max_right;
        int max_height = max_left>max_right?max_left:max_right;
        
        // return the height of root
        return max_height + 1;
    }
};