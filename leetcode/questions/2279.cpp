int maximumBags(vector<int> &capacity, vector<int> &rocks, int additionalRocks)
{
    for (int i = 0; i < rocks.size(); i++)
    {
        rocks[i] -= capacity[i];
    }

    sort(rocks.begin(), rocks.end());

    int i = rocks.size() - 1;
    while (additionalRocks > 0 && i >= 0)
    {
        if (additionalRocks >= abs(rocks[i]))
        {
            additionalRocks += rocks[i];
            rocks[i] = 0;
        }
        i--;
    }

    i = 0;
    int count = 0;
    for (i = 0; i < rocks.size(); i++)
    {
        if (rocks[i] == 0)
            count++;
    }

    return count;
}