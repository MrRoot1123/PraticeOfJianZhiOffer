#include <iostream>
#include <vector>

using namespace std;

/*
输入一个整数数组，判断该数组是不是某二叉搜索树的后序遍历的结果。如果是则输出Yes,否则输出No。假设输入的数组的任意两个数字都互不相同。
*/

class Solution {
public:
    bool VerifySquenceOfBST(vector<int> sequence) {
        return bst(sequence, 0, sequence.size() - 1);
    }
private:
    bool bst(vector<int> seq, int begin, int end){
        // 边界条件
        if(seq.empty() || begin > end)
            return false;
        // 划分左右子树，并判断左右子树和根节点的关系
        int i = begin;
        for(; i < end; ++i)
            if(seq[i] > seq[end])
                break;
        int j = i;
        for(; j < end; ++j)
            if(seq[j] < seq[end])
                return false;
        // 判断左子树是不是二叉搜索树
        bool left = true;
        if(i > begin)
            left = bst(seq, begin, i - 1);
        // 判断右子树是不是二叉搜索树
        bool right = true;
        if(i < end - 1)
            right = bst(seq, i , end - 1);
        return left && right;
    }
};