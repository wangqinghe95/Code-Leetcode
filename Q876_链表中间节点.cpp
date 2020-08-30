/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

/*
方法一、数组存储
时间复杂度：O（n）
空间复杂度：O（n）
*/
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        vector<ListNode*> vecList = {head};
        while(vecList.back()->next != NULL)
        {
            vecList.push_back(vecList.back()->next);
        }
        return vecList[vecList.size() / 2];
    }
};

/*
方法二、单指针法
时间复杂度：O（n）
空间复杂度：O（1）
*/

class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        int n = 0;
        ListNode *cur = head;
        while (cur != NULL)
        {
            ++n;
            cur = cur->next;
        }

        int k = 0;
        cur = head;
        while(k < n / 2)
        {
            ++k;
            cur = cur->next;
        }

        return cur;
    }
};

/*
方法二、快慢指针法
时间复杂度：O（n）
空间复杂度：O（1）
*/

class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast != NULL && fast->next != NULL)
        {
            slow = slow->next;
            fast =  fast->next->next;
        }

        return slow;
    }
};