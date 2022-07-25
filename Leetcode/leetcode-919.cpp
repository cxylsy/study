/*
919. 完全二叉树插入器
完全二叉树 是每一层（除最后一层外）都是完全填充（即，节点数达到最大）的，并且所有的节点都尽可能地集中在左侧。

设计一种算法，将一个新节点插入到一个完整的二叉树中，并在插入后保持其完整。

实现 CBTInserter 类:

CBTInserter(TreeNode root) 使用头节点为 root 的给定树初始化该数据结构；
CBTInserter.insert(int v)  向树中插入一个值为 Node.val == val的新节点 TreeNode。使树保持完全二叉树的状态，并返回插入节点 TreeNode 的父节点的值；
CBTInserter.get_root() 将返回树的头节点。
 
输入
["CBTInserter", "insert", "insert", "get_root"]
[[[1, 2]], [3], [4], []]
输出
[null, 1, 2, [1, 2, 3, 4]]

解释
CBTInserter cBTInserter = new CBTInserter([1, 2]);
cBTInserter.insert(3);  // 返回 1
cBTInserter.insert(4);  // 返回 2
cBTInserter.get_root(); // 返回 [1, 2, 3, 4]

思路：对于完全二叉树而言，除了最后一层之外都是完全填充的，切最后一层的节点都在最左侧。那么只有倒数第二层（如果存在）
最右边的节点可以在添加子节点，其余节点都拥有了两个节点。因此我们把上述可以插入子节点的节点按照倒数第二层从左到右，
最有一层从左到右放进队列中（通过广度优先搜索完成）。然后判断插入的节点时，创造一个child的节点，使用队首节点指向child，
并将child push进队列，如果队首节点拥有两个子节点，进行pop操作。
*/



#include <bits/stdc++.h>
#include <iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
 
class CBTInserter {
public:
    CBTInserter(TreeNode* root) {
        node = root;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()) {
            TreeNode* tmp = q.front();
            q.pop();
            if(tmp->left) {
                q.push(tmp->left);
            }
            if(tmp->right) {
                q.push(tmp->right);
            }
            if(!(tmp->left && tmp->right)) {
                cal.push(tmp);
            }
        }
    }
    
    int insert(int val) {
        TreeNode* tmp = cal.front();
        if(!tmp->left) {
            tmp->left = new TreeNode(val);
            cal.push(tmp->left);
        } else if(!tmp->right) {
            tmp->right = new TreeNode(val);
            cal.push(tmp->right);
        }

        if(tmp->left && tmp->right) {
            cal.pop();
        }
        return tmp->val;
    }
    
    TreeNode* get_root() {
        return node;
    }
private:
    TreeNode* node;
    queue<TreeNode*> cal;
};

int main() {
    TreeNode* node = new TreeNode(1);
    node->left = new TreeNode(2);
    CBTInserter cb = CBTInserter(node);
    int ans = cb.insert(3);
    cout << ans << endl;
    ans = cb.insert(5);
    cout << ans << endl;
    TreeNode* tmp = cb.get_root();
    return 0;
}