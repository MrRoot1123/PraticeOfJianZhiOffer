/*
输入一棵二叉搜索树，将该二叉搜索树转换成一个排序的双向链表。要求不能创建任何新的结点，只能调整树中结点指针的指向。
*/
#include <iostream>

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
        
    }
private:
    void dfs(TreeNode* pRootOfTree)
    {
        if (pRootOfTree -> left != nullptr)
        {
            dfs(pRootOfTree -> left);
        }
        else
        {
            
        }
        
    }
    TreeNode* pHead;
    TreeNode* pNode;
};