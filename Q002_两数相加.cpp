//耗时过多

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){
    struct ListNode* res = (struct ListNode*)malloc(sizeof (struct ListNode));;
    struct ListNode* temp_node = res;;

    int carry = 0;
    //for (; l1 != NULL || l2 != NULL; l1 = l1->next, l2 = l2->next)
    
    do
    {
        int curr_value = 0;
        if (l1 != NULL)
        {
            curr_value += l1->val;
            l1 = l1->next;
        }
        if (l2 != NULL)
        {
            curr_value += l2->val;
            l2 = l2->next;
        }

        struct ListNode *cur_node = (struct ListNode*)malloc(sizeof(struct ListNode));
        cur_node->val = (curr_value + carry) % 10;
        cur_node->next = NULL;
        carry = (curr_value + carry) / 10;

        temp_node->next = cur_node;
        temp_node =  temp_node->next;        
    }while(l1 != NULL || l2 != NULL);

    if (carry != 0)
    {
        struct ListNode *cur_node = (struct ListNode*)malloc(sizeof(struct ListNode));
        cur_node->val = (carry);
        cur_node->next = NULL;
        temp_node->next = cur_node;
    }

    return (res->next);
}

//递归解法，耗时也挺多的
int carry = 0;
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){
    if (l1 == NULL && l2 == NULL && 0 == carry)
    {
        return NULL;
    }

    l1 = l1 != NULL ? (carry += l1->val, l1->next) : l1;
    l2 = l2 != NULL ? (carry += l2->val, l2->next) : l2;

    struct ListNode* cur_node = (struct ListNode*)malloc(sizeof(struct ListNode));
    cur_node->val = carry % 10;
    carry /= 10;
    cur_node->next = addTwoNumbers(l1, l2);
    return cur_node;
}

// C++
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *res = new ListNode(-1);
        ListNode *cur = res;
        int carry = 0;
        while(l1 || l2)
        {
            int value_1 = l1 ? l1->val : 0;
            int value_2 = l2 ? l2->val : 0;
            int sum = value_1 + value_2 + carry;
            carry = sum / 10;
            cur->next = new ListNode(sum % 10);
            cur = cur->next;

            if (l1)
            {
                l1 = l1->next;
            }
            if (l2)
            {
                l2 = l2->next;
            }
        }

        if (carry)
        {
            cur->next = new ListNode(carry);
        }

        return (res->next);
    }
};