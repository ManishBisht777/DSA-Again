int maxArea(int h, int w, vector<int> &hc, vector<int> &vc)
{

    hc.push_back(h);
    vc.push_back(w);
    int mod = 1e9 + 7;

    sort(hc.begin(), hc.end());
    sort(vc.begin(), vc.end());

    int prev = 0;
    long int height = 0, width = 0;

    for (int i = 0; i < hc.size(); i++)
    {
        height = max(height, (long int)hc[i] - prev);
        prev = hc[i];
    }

    prev = 0;

    for (int i = 0; i < vc.size(); i++)
    {
        width = max(width, (long int)vc[i] - prev);
        prev = vc[i];
    }

    return (height * width) % mod;
}