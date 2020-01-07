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
    ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
        if (k <= 0 || pListHead == NULL) return NULL;
        size_t ListLen = 1;
        ListNode* l = pListHead;
        while (l -> next){
            l = l -> next;
            ++ListLen;
        }
        if (k > ListLen) return NULL;
        size_t order = ListLen - k;
        l = pListHead;
        for (int i = 0; i < order; ++i){
            l = l -> next;
        }
        return l;
    }
};