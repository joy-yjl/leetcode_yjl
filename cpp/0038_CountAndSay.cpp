class Solution {
public:
    string countAndSay(int n) {
        if(n==1)
            return "1";
        string pre = countAndSay(n - 1);
        string res="";
        for(int i = 0; i < pre.size(); i++)
        {
            int count = 1;
            while(i+1 < pre.size() && pre[i] == pre[i+1]){
                i++;
                count++;
            }
            res+=(to_string(count)+pre[i]);
           
        }
        return res;

    }
    
};
