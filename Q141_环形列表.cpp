/*哈希表
思路--通过检查一个点是否此前被访问过来判断链表是否为环形链表-哈希表方式存储
方法--遍历所有节点存储每个结点的引用或者内存地址
*/


时间复杂度 O(n)
空间复杂度 O(n)

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {

        set<ListNode *> nodesSeen;
        while ( head != NULL )
        {
            if (nodesSeen.count(head))
            {
                return true;
            }
            else
            {
                nodesSeen.insert(head);
            }
            head = head->next;
        }
        return false;
    }
};

/* 双指针

*/

class Solution {
public:
    bool hasCycle(ListNode *head) {
        if (head == NULL || head->next == NULL)
        {
            return false;
        }

        ListNode* slow = head;
        ListNode* fast = head->next;
        while (slow != fast)
        {
            if (fast == NULL || fast->next == NULL)
            {
                return false;
            }
            slow = slow->next;
            fast = fast->next->next;
        }
        return true;
    }
};

