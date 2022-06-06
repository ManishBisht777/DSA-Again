int distance(ListNode *head)
{
    int dist = 0;
    ListNode *l1 = head;

    while (l1)
    {
        dist++;
        l1 = l1->next;
    }

    return dist;
}

ListNode *getIntersectionNode(ListNode *head1, ListNode *head2)
{

    int d1 = distance(head1);
    int d2 = distance(head2);

    int d = abs(d2 - d1);

    if (d2 > d1)
    {
        while (d--)
            head2 = head2->next;
    }
    else
        while (d--)
            head1 = head1->next;

    while (head1 || head2)
    {
        if (head1 == head2)
            return head1;

        head1 = head1->next;
        head2 = head2->next;
    }

    return NULL;
}