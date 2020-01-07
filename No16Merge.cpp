/*
struct ListNode {
int val;
struct ListNode *next;
ListNode(int x) :
val(x), next(NULL) {
}
};*/
class Solution {
public:
    ListNode* Merge(ListNode* pHead1, ListNode* pHead2)
    {
        if (pHead1 == NULL && pHead2 == NULL) return NULL;
        ListNode* pNew;
        if (pHead1 != NULL && pHead2 != NULL)
        {
            if ( pHead1 -> val <= pHead2 -> val){
                pNew = pHead1;
                pHead1 = pHead1 -> next;
            }
            else
            {
                pNew = pHead2;
                pHead2 = pHead2 -> next;
            }
        }
        else if (pHead1 == NULL){
            pNew = pHead2;
            pHead2 = pHead2 -> next;
        }
        else
        {
            pNew = pHead1;
            pHead1 = pHead1 -> next;
        }
        ListNode* pTmp = pNew;
        while (pHead1 != NULL || pHead2 != NULL)
        {
            if (pHead1 != NULL && pHead2 != NULL)
            {
                if (pHead1 -> val <= pHead2 -> val){
                    pTmp -> next = pHead1;
                    pTmp = pTmp -> next;
                    pHead1 = pHead1 -> next;
                }
                else
                {
                    pTmp -> next = pHead2;
                    pTmp = pTmp -> next;
                    pHead2 = pHead2 -> next;
                }
            }
            else if (pHead1 == NULL){
                pTmp -> next = pHead2;
                pTmp = pTmp -> next;
                pHead2 = pHead2 -> next;
            }
            else
            {
                pTmp -> next = pHead1;
                pTmp = pTmp -> next;
                pHead1 = pHead1 -> next;
            }
        }
        pTmp -> next = NULL;
        return pNew;
    }
};