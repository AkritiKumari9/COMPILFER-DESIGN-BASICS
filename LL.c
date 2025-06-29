#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *next;
};
struct Node *insert(struct Node *head, int val)
{
    struct Node *n = malloc(sizeof(struct Node)), *t = head;
    n->data = val;
    n->next = NULL;
    if (!head)
        return n;
    while (t->next)
        t = t->next;
    t->next = n;
    return head;
}
struct Node *delete(struct Node *head, int val)
{
    struct Node *t = head, *prev = NULL;
    while (t && t->data != val)
    {
        prev = t;
        t = t->next;
    }
    if (!t)
        return head;
    if (!prev)
        head = t->next;
    else
        prev->next = t->next;
    free(t);
    return head;
}
void traversal(struct Node *head)
{
    while (head)
    {
        printf("%d->", head->data);
        head = head->next;
    }
    printf("NULL\n");
}
int main()
{
    struct Node *head = NULL;

    head = insert(head, 7);
    head = insert(head, 5);
    head = insert(head, 2);
    printf("After insertion:\n");

    traversal(head); // 7->5->2->NULL

    head = delete(head, 5);
    printf("After deletion:\n");

    traversal(head); // 7->5->NULL
    return 0;
}
