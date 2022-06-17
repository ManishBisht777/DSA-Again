string largestNumber(int n, int sum)
{
    // Your code here
    string ans = "";

    while (n--)
    {
        if (sum >= 9)
            ans += "9", sum -= 9;
        else if (sum > 0)
        {
            ans += to_string(sum);
            sum = 0;
        }
        else
        {
            ans += '0';
        }
    }

    if (sum != 0)
        return "-1";

    return ans;
}