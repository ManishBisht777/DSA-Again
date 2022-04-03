vector<vector<int>> findWinners(vector<vector<int>> &mat)
{

    map<int, int> win;
    map<int, int> lose;

    for (int i = 0; i < mat.size(); i++)
    {
        win[mat[i][0]]++;
        lose[mat[i][1]]++;
    }

    vector<vector<int>> res;
    vector<int> cnt;
    for (auto i : win)
        if (lose.find(i.first) == lose.end())
            cnt.push_back(i.first);

    res.push_back(cnt);
    cnt.clear();
    for (auto i : lose)
        if (i.second == 1)
            cnt.push_back(i.first);

    res.push_back(cnt);
    return res;
}