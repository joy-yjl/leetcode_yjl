
class Solution {
public:

    string getPermutation(int n, int k) {
        vector<int> fact;
        fact.push_back(1);
        for(int i=1;i<10;i++)
        {
            fact.push_back(i*fact[i-1]);
        }
        
        vector<int> num(n);
        for(int i=0; i<n; i++)
            num[i] = i+1;
        
        
        string res = "";
        while(n > 0)
        {
            int tmp = (k - 1) / fact[n - 1];
            res += (num[tmp]+'0');
            num.erase(num.begin() + tmp);
            k = k - tmp * fact[n - 1];
            n--;
        }
        return res;
    }
};


class Solution {
public:
    int kk=-1;
    string res="";
    void helper(string &r, int n, int index,int k,vector<int> &visit)
    {
        if(index==r.size())
        {
            kk--;
            res=r;
            return;
            
        }
        if(kk==0)   
            return;
        for(int i=0;i<n;i++)
        {
            if(visit[i]==1)
                continue;
            r[index]=i+1+'0';
            visit[i]=1;
            helper(r,n,index+1,k,visit);
            visit[i]=0;
        }
            
        
    }
    string getPermutation(int n, int k) {
        kk=k;
        string r="";
        for(int i=0;i<n;i++)
            r+=".";
        
        vector<int> visit(n,0);
        for(int i=0;i<n;i++)
        {
            r[0]=i+1+'0';
            visit[i]=1;
            helper(r,n,1,k,visit);
            visit[i]=0;
        }
        return res;
        
    }
};
