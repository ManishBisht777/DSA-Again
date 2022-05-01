bool backspaceCompare(string s, string t) {
        
        int sp=0,tp=0;
        
        for(int i=0; i<s.size() ;i++)
        {
            if(s[i]=='#')
            {
                sp--;
                sp=max(0,sp);
            }
            else   
            {
                s[sp]=s[i];
                sp++;
            }
        }
        
        
        for(int i=0; i<t.size();i++)
        {
            if(t[i]=='#')
            {
                tp--;
                tp=max(0,tp);
            }
            else
            {
                t[tp]=t[i];
                tp++;
            }
        }
        
        if(sp!=tp) return false;
        else
        {
            for(int i=0; i<sp;i++)
            {
                if(s[i]!=t[i]) return false;
            }       
            return true;
        }
        
    }