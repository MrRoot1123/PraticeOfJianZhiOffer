#include <iostream>
#include <vector>
#include <queue>

/*
从上往下打印出二叉树的每个节点，同层节点从左至右打印。
*/

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
    vector<int> PrintFromTopToBottom(TreeNode* root) {
        queue<TreeNode*> tmp;
        vector<int> result;
        if (root != nullptr)
            tmp.push(root);
        while (!tmp.empty())
        {
            TreeNode* tmpTree = tmp.front();
            tmp.pop();
            if (tmpTree -> left != nullptr)
                tmp.push(tmpTree -> left);
            if (tmpTree -> right != nullptr)
                tmp.push(tmpTree -> right);
            result.push_back(tmpTree -> val);
        }
        return result;
    }
};