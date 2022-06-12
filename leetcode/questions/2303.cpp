double calculateTax(vector<vector<int>> &brackets, int income)
{

    double tax = 0.0;

    int rem = income;

    int prev = 0;
    int curramount = 0;

    for (auto it : brackets)
    {
        curramount = it[0] - prev;
        if (rem <= 0)
            break;
        if (curramount > rem)
            curramount = rem;

        tax += (curramount * it[1]) / 100.0;

        rem -= curramount;
        cout << curramount << " " << tax << " " << rem << " ";
        prev = it[0];
    }

    return tax;
}