void segregateElements(int arr[], int n)
{
    // Your code goes here
    int low = 0;
    int high = n - 1;
    int ar[n];
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > 0)
        {
            ar[low++] = arr[i];
        }
        if (arr[n - i - 1] < 0)
        {
            ar[high--] = arr[n - i - 1];
        }
    }
    for (int i = 0; i < n; i++)
    {
        arr[i] = ar[i];
    }
}