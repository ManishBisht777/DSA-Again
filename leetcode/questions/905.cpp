vector<int> sortArrayByParity(vector<int> &A)
{
    int size = A.size();
    vector<int> res(size, 0);
    int start = 0, end = size - 1;
    for (int i = 0; i < size; i++)
    {
        if (A[i] % 2 == 1)
        {
            res[end--] = A[i];
        }
        else
        {
            res[start++] = A[i];
        }
    }
    return res;
}