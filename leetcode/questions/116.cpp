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

// bfs approach

Node *connect(Node *root)
{
    if (!root)
        return root;
    queue<Node *> q;
    q.push(root);
    while (!q.empty())
    {
        int n = q.size();
        for (int i = 0; i < n; i++)
        {
            Node *x = q.front();
            q.pop();
            if (i != n - 1)
                x->next = q.front();
            if (x->left)
                q.push(x->left);
            if (x->right)
                q.push(x->right);
        }
    }
    return root;
}