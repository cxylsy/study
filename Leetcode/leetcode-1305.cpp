/*
1305. 两棵二叉搜索树中的所有元素
给你 root1 和 root2 这两棵二叉搜索树。请你返回一个列表，其中包含 两棵树 中的所有整数并按 升序 排序。
输入：root1 = [2,1,4], root2 = [1,0,3]
输出：[0,1,1,2,3,4]
   2           1          
1     4    0      3

思路：将两颗树的元素都放进vector容器中，再将vector容器进行排序

*/
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    void dfs(TreeNode* root, vector<int>& ans) {
        if(root == nullptr) {
            return ;
        }
        dfs(root->left, ans);
        ans.push_back(root->val);
        dfs(root->right, ans);
    }
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) { // sort 复杂度nlogn
        vector<int> ans;
        dfs(root1, ans);
        dfs(root2, ans);
        sort(ans.begin(), ans.end());
        return ans;
    }
    void inorder(TreeNode *node, vector<int> &res) {
        if (node) {
            inorder(node->left, res);
            res.push_back(node->val);
            inorder(node->right, res);
        }
    }

    vector<int> getAllElements1(TreeNode *root1, TreeNode *root2) {// 归并n+m
        vector<int> nums1, nums2;
        inorder(root1, nums1);
        inorder(root2, nums2);

        vector<int> merged;
        auto p1 = nums1.begin(), p2 = nums2.begin();
        while (true) {
            if (p1 == nums1.end()) {
                merged.insert(merged.end(), p2, nums2.end());
                break;
            }
            if (p2 == nums2.end()) {
                merged.insert(merged.end(), p1, nums1.end());
                break;
            }
            if (*p1 < *p2) {
                merged.push_back(*p1++);
            } else {
                merged.push_back(*p2++);
            }
        }
        return merged;
    }
};

int main() {
    vector<int> ans;
    Solution A;
    TreeNode* root1 = new TreeNode();
    root1->val = 2;
    root1->left = new TreeNode(1);
    root1->right = new TreeNode(4);

    TreeNode* root2 = new TreeNode();
    root2->val = 1;
    root2->left = new TreeNode(0);
    root2->right = new TreeNode(3);

    ans = A.getAllElements(root1, root2);
    for(int i = 0; i < ans.size(); i++) {
        if(i == ans.size() - 1) {
            cout << ans[i];
        } else {
            cout << ans[i] << " ";
        }
    }

    ans = A.getAllElements1(root1, root2);
    for(int i = 0; i < ans.size(); i++) {
        if(i == ans.size() - 1) {
            cout << ans[i];
        } else {
            cout << ans[i] << " ";
        }
    }
    return 0;
}