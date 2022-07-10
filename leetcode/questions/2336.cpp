class SmallestInfiniteSet
{
public:
    priority_queue<int, vector<int>, greater<int>> pq;
    map<int, int> mp;

    SmallestInfiniteSet()
    {
        for (int i = 1; i <= 1000; i++)
        {
            pq.push(i);
            mp[i]++;
        }
    }

    int popSmallest()
    {

        int temp = pq.top();
        pq.pop();
        mp.erase(temp);
        return temp;
    }

    void addBack(int num)
    {
        if (mp.find(num) == mp.end())
        {
            mp[num]++;
            pq.push(num);
        }
    }
};
