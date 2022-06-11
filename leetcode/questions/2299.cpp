bool strongPasswordCheckerII(string p)
{

    if (p.size() < 8)
        return false;

    bool upper = false, lower = false, digit = false, ch = false;
    for (int i = 0; i < p.size(); i++)
    {
        if (isupper(p[i]))
            upper = true;
        else if (islower(p[i]))
            lower = true;
        else if (isdigit(p[i]))
            digit = true;
        else if (!isupper(p[i]) && !islower(p[i]) && !isdigit(p[i]))
            ch = true;
        if ((i && p[i] == p[i - 1]))
            return false;
    }

    cout << upper << " " << lower << " " << digit << " " << ch << "\n";

    if (upper && lower && digit && ch)
        return true;
    return false;
}