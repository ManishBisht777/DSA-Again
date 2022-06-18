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