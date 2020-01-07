/**
*  struct ListNode {
*        int val;
*        struct ListNode *next;
*        ListNode(int x) :
*              val(x), next(NULL) {
*        }
*  };
*/
class Solution {
public:
    vector<int> printListFromTailToHead(ListNode* head) {
        vector<int> tmp;
        ListNode* pp = head;
        if (pp == NULL) return tmp;
        while(pp != NULL){
            tmp.push_back(pp->val);
            pp = pp->next;
        }
        vector<int> result;
        for (int i = tmp.size(); i > 0; --i){
            result.push_back(tmp[i-1]);
        }
        return result;
    }
};