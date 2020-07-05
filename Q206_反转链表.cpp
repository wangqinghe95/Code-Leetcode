/*
带有头节点
*/

void ReverseList(ListNode* pHead)
{
    if (pHead == NULL | pHead->next == NULL)
    {
        return pHead;
    }

    ListNode *p = pHead->next;
    ListNode *q = NULL;
    pHead->next = NULL;
    while (p != NULL)
    {
        q = p;
        p = p->next;
        q->next = pHead->next;
        pHead->next = q;
    }
}

/*不带有头节点*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* reverseList(struct ListNode* head){
    if (NULL == head || NULL == head->next)
    {
        return head;
    }

    struct ListNode* pre = NULL;
    struct ListNode* cur = head;
    struct ListNode* q ;
    
    while ( NULL != cur )
    {
        q = cur->next;
        cur->next = pre;
        pre = cur;
        cur = q;
    }

    return pre;

}

/*
递归反转
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* reverseList(struct ListNode* head){
    if ( NULL == head )
    {
        return NULL;
    }

    if ( NULL == head->next )
    {
        return head;
    }

    struct ListNode* newHead = reverseList(head->next);
    head->next->next = head;
    head->next = NULL;

    return newHead;
}



