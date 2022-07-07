class Solution {
public:
    string reverseWords(string s) {
        int n=s.size();
        int left=0,right=0;
        // while(right>left)
        // {
        //     swap(s[left],s[right]);
        //     left++;
        //     right--;
        // }
        for(int i=0;i<n;i++)
        {
            left=i,right=i;;
            while(right<n && s[i]!=' ')
            {
                right++;
                i++;
            }
            right=right-1;
            while(right>left)
            {
                swap(s[left],s[right]);
                left++;
                right--;
            }
        }
        return s;
        
    }
};
