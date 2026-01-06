#include<bits/stdc++.h>
using namespace std;

//Brute Force

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
    void helper(TreeNode *node, vector<int>& inorder) {
        if(node==NULL) return;
        helper(node->left, inorder);
        inorder.push_back(node->val);
        helper(node->right, inorder);
        return;
    }
public:
    bool isValidBST(TreeNode* root) {
        if(root==NULL) return true;
        vector<int> inorder;
        helper(root, inorder);
        bool flag = true;
        for(int i=1; i<inorder.size(); i++) {
            if(inorder[i] <= inorder[i-1]) {
                flag = false;
                break;
            }
        }
        return flag;
    }
};

//Optimal

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
    bool check(TreeNode *node, long long min, long long max) {
        if(node==NULL) return true;
        if(node->val > min && node->val < max) {
            return check(node->left, min, node->val) && check(node->right, node->val, max);
        }
        return false;
    }
public:
    bool isValidBST(TreeNode* root) {
        if(root==NULL) return true;
        return check(root, LLONG_MIN, LLONG_MAX);
    }
};