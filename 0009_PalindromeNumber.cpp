/*
 简单反转一下
 */
/*
class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0)
            return false;
        if(x<10)
            return true;
        int x2=x;
        long long int verse=0;
        while(x2)
        {
            int tmp=x2%10;
            verse=verse*10+tmp;
            x2=x2/10;
        }
        if(x==verse)
            return true;
        return false;
        
    }
};
*/
/*
 翻一半
 */
class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0 || (x % 10 == 0 && x != 0))
            return false;
        if(x<10)
            return true;
        
        int verse=0;
        while(x>verse)
        {
            verse=verse*10+x%10;
            x=x/10;
        }
        if(x==verse || x== (verse/10))
            return true;
        return false;
        
    }
};
