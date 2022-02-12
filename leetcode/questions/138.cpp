Node *copyRandomList(Node *head)
{

    Node *temp = head;
    Node *copy = new Node(0);
    Node *temp2 = copy;
    while (temp)
    {
        temp2->next = new Node(temp->val);
        temp2 = temp2->next;
        temp = temp->next;
    }

    Node *original = head;
    Node *clone = copy->next;

    while (original && clone)
    {
        Node *next = original->next;
        original->next = clone;
        original = next;

        next = clone->next;
        clone->next = original;
        clone = next;
    }

    Node *curr = head;

    while (curr)
    {
        if (curr->next)
            curr->next->random = curr->random ? curr->random->next : curr->random;

        curr = curr->next->next;
    }

    original = head;
    clone = copy->next;

    while (original && clone)
    {
        original->next = clone->next;
        original = original->next;

        if (original)
        {
            clone->next = original->next;
        }
        clone = clone->next;
    }

    return copy->next;
}