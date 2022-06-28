class Solution {
public:
    int minDeletions(string s) {
        sort(s.begin(),s.end());
        unordered_map<int,int> dict;
        char before=s[0];
        int res=0;
        for(int i=0;i<s.size();)
        {
            int num=0;
            while(s[i]==before)
            {
                i++;
                num++;
            }
            before=s[i];
            // cout<<num<<" "<<before<<endl;
            if(dict.count(num)==0)
                dict[num]=0;
            else
            {
                while(dict.count(num)==1 && num>0)
                {
                    res++;
                    num--;
                                       
                }
                dict[num]=1;
            }
            
        }
        return res;
        
        
    }
};
