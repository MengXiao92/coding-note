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
        vector<int> temp;
        vector<int> result;
        while(head != NULL){
            temp.push_back(head->val);
            head = head->next;
        }
        int size = temp.size();
        for(int i = 0; i < size; i++){
            result.push_back(temp[size - 1 - i]);
        }
        return result;
    }
};
