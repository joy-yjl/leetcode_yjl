class Solution {
public:
    string minWindow(string s, string t) {
        int n=s.size();
        int m=t.size();
        if(n==0 || m==0 )
            return "";
        
        unordered_map<char,int> dict;
        for(int i=0;i<m;i++)
            dict[t[i]]++;
        
        int required=dict.size();
        
        int left=0,right=0;
        int formed=0;
        
        unordered_map<char,int> dict2;
        vector<int> ans{-1,0,0};
        
        while(right<n)
        {
            dict2[s[right]]++;
            
            if(dict.count(s[right]) && dict2[s[right]]==dict[s[right]])
            {
                formed++;
            }
            
            while(left<=right && formed==required)
            {
                char ch=s[left];
                if (ans[0] == -1 || right - left + 1 < ans[0]) 
                {
                  ans[0] = right - left + 1;
                  ans[1] = left;
                  ans[2] = right;
                }
                dict2[s[left]]--;
                if(dict.count(s[left]) && dict2[s[left]]<dict[s[left]])
                    formed--;
                left++;
                
            }
            right++;
        }
        return ans[0]==-1?"": s.substr(ans[1],ans[0]);
        
        
    }
};
