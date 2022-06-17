// brute force

int minJumps(int arr[], int n)
{
    // Your code here

    int i = 0, j, ans = 0;
    while (i < n)
    {
        int maxi = 0;
        for (j = i + 1; j <= i + arr[i]; j++)
        {
            maxi = max(maxi, arr[i]);
        }

        i += maxi;
        ans++;
    }

    return ans;
}

// optimised

int minJumps(int arr[], int n)
{
    // Your code here

    int curr = 0, jumps = 0, maxi = 0;

    for (int i = 0; i < n - 1; i++)
    {
        maxi = max(maxi, arr[i] + i);
        if (i == curr)
        {
            jumps++;
            curr = maxi;
        }
    }

    if (curr < n - 1)
        return -1;

    return jumps;
}