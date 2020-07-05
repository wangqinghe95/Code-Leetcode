/*
剑指offer的一道题，深拷贝链表并且分离
*/

/**
 * Definition for a Node.
 * struct Node {
 *     int val;
 *     struct TreeNode *next;
 *     struct TreeNode *random;
 * };
 */

struct Node* copyRandomList(struct Node* head) {

    if (head == NULL)
    {
        return NULL;
    }

    struct Node* first = head;
    struct Node* second = head;
    struct Node* tmp ;

    while (NULL != first)
    {
        tmp = (struct Node*)malloc(sizeof (struct Node));
        tmp->val = first->val;
        tmp->random = first->random;
        tmp->next = first->next;

        first->next = tmp;
        first = tmp->next;
    }

    first = head;
    while(first != NULL)
    {
        second = first->next;
        if (NULL != second->random)
        {
            second->random = second->random->next;
        }
        first = second->next;
    }

    first = head;
    second = head->next;

    while( (NULL != first ) && ( NULL != first->next ) )
    {
        tmp = first->next;
        first->next = tmp->next;

        first = tmp->next;
        if ( NULL != tmp->next )
        {
            tmp->next = first->next;
        }
    }

    return second;

}