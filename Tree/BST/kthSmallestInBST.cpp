#include<bits/stdc++.h>
using namespace std;

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
    void solve(TreeNode *node, int& i, int& ans, int k) {
        if(node==NULL) return;
        solve(node->left, i, ans, k);
        i++;
        if(i==k) {
            ans = node->val;
        }
        solve(node->right, i, ans, k);
    }
public:
    int kthSmallest(TreeNode* root, int k) {
        int ans = 1e9;
        int i = 0;
        solve(root, i, ans, k);
        return ans;
    }
};