/*
输入一棵二叉搜索树，将该二叉搜索树转换成一个排序的双向链表。要求不能创建任何新的结点，只能调整树中结点指针的指向。
*/
#include <iostream>
#include <queue>
using namespace std;

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
    TreeNode* Convert(TreeNode* pRootOfTree)
    {
        if (pRootOfTree == nullptr) return nullptr;
        dfs(pRootOfTree);
        TreeNode* pNew = queueNode.front();
        TreeNode* pNode = pNew;
        queueNode.pop();
        while (!queueNode.empty())
        {
            TreeNode* pTmp;
            pTmp = queueNode.front();
            pNode -> right = pTmp;
            pTmp -> left = pNode;
            pNode = pTmp;
            queueNode.pop();
        }
        return pNew;
    }
private:
    void dfs(TreeNode* pRootOfTree)
    {
        if (pRootOfTree == nullptr) return;
        if (pRootOfTree -> left != nullptr)
        {
            dfs(pRootOfTree -> left);
        }
        queueNode.push(pRootOfTree);
        if (pRootOfTree -> right != nullptr)
        {
            dfs(pRootOfTree -> right);
        }
    }
    queue<TreeNode*> queueNode;
};