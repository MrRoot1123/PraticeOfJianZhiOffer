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
    ListNode* ReverseList(ListNode* pHead) {
        vector<ListNode*> tmp;
        size_t len = 0;
        if (pHead == NULL) return NULL;
        ListNode* pp = pHead;
        tmp.push_back(pp);
        while(pp -> next){
            pp = pp -> next;
            tmp.push_back(pp);
        }
        len = tmp.size();
        ListNode* pNew = tmp[len-1];
        ListNode* pTmp = pNew;
        for (int i = 0; i < len-1; ++i){
            pTmp->next = tmp[len-2-i];
            pTmp = pTmp -> next;
        }
        pTmp -> next = NULL;
        return pNew;
    }
};