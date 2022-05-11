void helper(vector<string> vowel ,vector<string> &temp, int idx, int &cnt, int n)
    {
        if(temp.size()==n)
        {
            cnt++;
            return;
        }
        
        for(int i=idx; i<vowel.size();i++)
        {
            temp.push_back(vowel[i]);
            
            helper(vowel,temp,i,cnt,n);
            
            temp.pop_back();
        }
    }
    
    int countVowelStrings(int n) {
        vector<string> vowel={"a","e","i","o","u"};
        vector<string> temp;
        int cnt=0;
        
        helper(vowel,temp,0,cnt,n);
        
        return cnt;
    }