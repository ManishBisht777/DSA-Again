// koko eating bananas

int minEatingSpeed(vector<int> &piles, int h)
{
    int st, end, mid;
    st = 1;
    int n = piles.size();

    int count;

    for (int i = 0; i < n; i++)
    {
        end = max(piles[i], end);
    }

    while (st < end)
    {
        mid = st + (end - st) / 2;
        count = 0;

        for (int i = 0; i < n; i++)
        {
            count += (piles[i] + mid - 1) / mid;
        }

        if (count > h)
            st = mid + 1;
        else
            end = mid;
    }

    return st;
}