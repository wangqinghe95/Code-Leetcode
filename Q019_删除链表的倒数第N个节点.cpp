/*
运行失败
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* removeNthFromEnd(struct ListNode* head, int n){
    struct ListNode* first = head;
    struct ListNode* second = head;
    
    int first_step = n + 1;
    while(first_step--)
    {
        first = first->next;
    }

    //first = first->next;
    while(first != NULL)
    {
        first = first->next;
        second = second->next;
    }

    struct ListNode* temp = second->next;
    second->next = temp->next;
    free(temp);

    return head;
}

/*运行成功*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* removeNthFromEnd(struct ListNode* head, int n){
    struct ListNode* first = head;
    struct ListNode* second = head;
    
    int first_step = n;
    while(first_step-- && first)
    {
        first = first->next;
    }

    if (first_step > 0)
    {
        return NULL;
    }
    if (!first)
    {
        return second->next;
    }

    first = first->next;
    while(first != NULL)
    {
        first = first->next;
        second = second->next;
    }

    second->next  = second->next->next;

    return head;
}



---
/*运行成功*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* removeNthFromEnd(struct ListNode* head, int n){
    struct ListNode* first = head;
    struct ListNode* second = head;
    
    while (first)
    {
        if (n < 0)
        {
            second = second->next;
        }

        n--;

        first = first->next;
    }

    if (0 == n)
    {
        return head->next;
    }
    second->next = second->next->next;
    return head;
}