/*
输入一棵二叉树，求该树的深度。从根结点到叶结点依次经过的结点（含根、叶结点）形成树的一条路径，最长路径的长度为树的深度。
*/
#include <iostream>
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};
class Solution {
public:
    int TreeDepth(TreeNode* pRoot)
    {
        int max_depth = 0, cur_dep = 0;
        if (pRoot == nullptr)
            return max_depth;
        ++cur_dep;
        ++max_depth;
        dfs(pRoot, max_depth, cur_dep);
        return max_depth;
    }
private:
    void dfs(TreeNode* pRoot, int &max_depth, int &cur_dep)
    {
        max_depth = max_depth < cur_dep ? cur_dep : max_depth;
        int tmp = cur_dep;
        if (pRoot == nullptr)
            return;
        if (pRoot -> left != nullptr)
        {
            ++cur_dep;
            dfs(pRoot->left, max_depth, cur_dep);
        }
        cur_dep = tmp;
        if (pRoot->right != nullptr)
        {
            ++cur_dep;
            dfs(pRoot->right, max_depth, cur_dep);
        }
        return;
    }
};

// 别人的答案 学习下
class Solution2 {
public:
    int TreeDepth(TreeNode* pRoot){
        if(!pRoot) return 0 ;
            return max(1+TreeDepth(pRoot->left), 1+TreeDepth(pRoot->right));
    }
};