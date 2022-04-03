int convertTime(string current, string correct)
{

    int t1 = ((current[0] - '0') * 10 + current[1] - '0') * 60 + (current[3] - '0') * 10 + current[4] - '0';

    int t2 = ((correct[0] - '0') * 10 + correct[1] - '0') * 60 + (correct[3] - '0') * 10 + correct[4] - '0';

    int diff = t2 - t1;
    int op = 0;

    op += diff / 60;
    diff = diff % 60;

    cout << op << " ";

    op += diff / 15;
    diff = diff % 15;
    cout << op << " ";

    op += diff / 5;
    diff = diff % 5;
    cout << op << " ";

    op += diff / 1;
    diff = diff % 1;
    cout << op << " ";

    return op;
}