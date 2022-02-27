class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        
        int count=0;
        int tcount=0;
        int m=words.size();
        
        for(int i=0; i<m ;i++)
        {
            tcount=0;
            if(words[i].size() >=pref.size())
            {
                for(int j=0; j<pref.size();j++)
                {
                    cout<<words[i][j]<<" ";
                    cout<<pref[j]<<"\n";
                    if(words[i][j]==pref[j]) tcount++;
                }
            }
            if(tcount==pref.size()) count++;
            cout<<count<<" count";
        }
        
        return count;
    }
};