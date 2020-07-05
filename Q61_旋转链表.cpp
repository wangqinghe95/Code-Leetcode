/*
思路：
找到第 k%len个节点，将该节点作为链表的头节点，再把链表的最后一个节点连接到最表头
这样就可以达到了旋转k个节点的效果
*/

//时间效率不是太高

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* rotateRight(struct ListNode* head, int k){
    struct ListNode *first = head;
    struct ListNode *second = head;

    if (NULL == head)
    {
        return NULL;
    }

    int len_list = 0;
    while (first != NULL)
    {
        len_list++;
        first = first->next;
    }

    int last_k = k % len_list;
    first = head;

    for (int i = 0; first != NULL && i < (last_k); ++i)
    {
        first = first->next;
    }

    while(first->next != NULL)
    {
        first = first->next;
        second = second->next;
    }

    first->next = head;
    head = second->next;
    second->next = NULL;

    return head;
}