double MedianOfArrays(vector<int> &arr1, vector<int> &arr2)
{
    // Your code goes here
    vector<int> merge;

    int i = 0, j = 0;
    while (i < arr1.size() && j < arr2.size())
    {
        if (arr1[i] <= arr2[j])
            merge.push_back(arr1[i++]);
        else
            merge.push_back(arr2[j++]);
    }

    while (i < arr1.size())
        merge.push_back(arr1[i++]);
    while (j < arr2.size())
        merge.push_back(arr2[j++]);

    int n = merge.size();

    if (n % 2 != 0)
        return (double)merge[n / 2];
    return (double)(merge[n / 2] + merge[n / 2 - 1]) / 2;
}

// optimal sol

double MedianOfArrays(vector<int> &arr1, vector<int> &arr2)
{
    // Your code goes here
    int i = 0, j = 0;
    int m1 = -1, m2 = -1;
    int n = arr1.size();
    int m = arr2.size();

    for (int cnt = 0; cnt <= (m + n) / 2; cnt++)
    {
        m2 = m1;

        if (i != n && j != m)
        {
            m1 = (arr1[i] > arr2[j]) ? arr2[j++] : arr1[i++];
        }
        else if (i < n)
        {
            m1 = arr1[i++];
        }
        else
            m1 = arr2[j++];
    }

    if ((m + n) % 2 == 1)
        return m1;
    return (double)(m1 + m2) / 2;
}