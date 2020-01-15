#include <iostream>

using namespace std;

struct RandomListNode {
    int label;
    struct RandomListNode *next, *random;
    RandomListNode(int x) :
            label(x), next(NULL), random(NULL) {
    }
};

class Solution {
public:
    RandomListNode* Clone(RandomListNode* pHead)
    {
        CloneNodes(pHead);
        ConnectRandomNodes(pHead);
        return ReconnectNodes(pHead);
    }
private:
    void CloneNodes(RandomListNode* pHead)
    {
        RandomListNode* pNode = pHead;
        while (pNode != nullptr)
        {
            RandomListNode* pCloned = new RandomListNode(pNode -> label);
            pCloned -> next = pNode -> next;
            pNode -> next = pCloned;
            pNode = pCloned -> next;
        }
    }
    void ConnectRandomNodes(RandomListNode* pHead)
    {
        RandomListNode* pNode = pHead;
        while (pNode != nullptr)
        {
            RandomListNode* pCloned = pNode -> next;
            if (pNode -> random != nullptr)
            {
                pCloned -> random = pNode -> random -> next;
            }
            pNode = pCloned -> next;
        }
    }
    RandomListNode* ReconnectNodes(RandomListNode* pHead)
    {
        RandomListNode* pNode = pHead;
        RandomListNode* pClonedHead = nullptr;
        RandomListNode* pClonedNode = nullptr;
        if (pNode != nullptr)
        {
            pClonedHead = pClonedNode = pNode -> next;
            pNode -> next = pClonedNode -> next;
            pNode = pNode -> next;
        }
        while (pNode != nullptr)
        {
            pClonedNode -> next = pNode -> next;
            pClonedNode = pClonedNode -> next;
            pNode -> next = pClonedNode -> next;
            pNode = pNode -> next;
        }
        return pClonedHead;
        
    }
};