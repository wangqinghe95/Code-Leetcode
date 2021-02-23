//思路就是使用分治法，求两个有序链表的合并

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* a, ListNode* b){
        if ((!a) || (!b)){
            return a ? a : b;
        }
        ListNode head, *tail = &head, *aPtr = a, *bPtr = b;
        while(aPtr && bPtr){
            if (aPtr->val > bPtr->val){
                tail->next = bPtr;
                bPtr = bPtr->next;
            }
            else{
                tail->next = aPtr;
                aPtr = aPtr->next;
            }
            tail = tail->next;
        }
        tail->next = (aPtr ? aPtr : bPtr);
        return head.next;
    }
    ListNode* merge(vector<ListNode*>& lists, int l, int r){
        if (l == r){
            return lists[l];
        }

        if (l > r){
            return nullptr;
        }

        int mid = (l + r) >> 1;
        return mergeTwoLists((merge(lists,l, mid)), merge(lists, mid+1, r));
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        return merge(lists, 0, lists.size() - 1);
    }
};