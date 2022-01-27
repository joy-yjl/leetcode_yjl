class Solution {
public:
    string multiply(string num1, string num2) {
        if (num1 == "0" || num2 == "0") return "0";
        int m=num1.size();
        int n=num2.size();
        vector<int> res_num(n+m);
        string res="";

        for(int i=m-1;i>=0;i--)
        {
            for(int j=n-1;j>=0;j--)
            {
                int val=(num1[i]-'0')*(num2[j]-'0');
                int p1=i+j,p2=i+j+1;
                int all=val+res_num[p2];
                res_num[p2]=all%10;
                res_num[p1]+=all/10;
            }
        }

        for(int i=0;i<res_num.size();i++)
        {
            if(res.empty() && res_num[i]==0)
                continue;
            res.push_back(res_num[i]+'0');
        }
        return res.empty()?"0":res;
        
    }
};
