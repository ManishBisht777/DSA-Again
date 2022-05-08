string largestGoodInteger(string num)
{

    int cnt = 1;
    string maxnum;

    for (int i = 1; i < num.size(); i++)
    {
        if (num[i] == num[i - 1])
        {
            cnt++;
            if (cnt == 3)
            {
                cnt = 1;
                string num2;
                num2 = num[i];
                if (maxnum < num2)
                    maxnum = num[i];
            }
        }
        else
        {
            cnt = 1;
        }
    }

    string ans = "";
    ans += maxnum + maxnum + maxnum;
    return ans;
}