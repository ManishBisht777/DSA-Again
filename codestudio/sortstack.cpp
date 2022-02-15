void insertSorted(stack<int> &stack, int num)
{
    if (stack.empty() || (!stack.empty() && stack.top() < num))
    {
        stack.push(num);
        return;
    }

    int x = stack.top();
    stack.pop();
    insertSorted(stack, num);

    stack.push(x);
}

void sortStack(stack<int> &stack)
{
    // Write your code here
    if (stack.empty())
        return;

    int num = stack.top();
    stack.pop();

    sortStack(stack);

    insertSorted(stack, num);
}