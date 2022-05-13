Node *connect(Node *root)
{

    if (!root)
        return NULL;

    Node *lvl = root;
    Node *curr = NULL;

    while (lvl->left)
    {
        curr = lvl;
        while (curr)
        {
            curr->left->next = curr->right;

            if (curr->next)
                curr->right->next = curr->next->left;

            curr = curr->next;
        }

        lvl = lvl->left;
    }

    return root;
}