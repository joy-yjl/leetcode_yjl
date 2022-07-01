class Solution {
public:
    int numberOfMatches(int n) {
        return n-1;
    }
};

class Solution {
public:
    int numberOfMatches(int n) {
        int res=0;
        while(n>1)
        {      
            res+=n/2;
            n-=n/2;
        }
        return res;
        
        
    }
};
