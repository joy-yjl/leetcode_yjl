/*
使用栈
*/
class Solution {
public:
    bool isValid(string s) {
        unordered_map<char,char> dict{{'(',')'},{'{','}'},{'[',']'}};
        stack<char> m_stack;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='(' ||s[i]=='{'||s[i]=='[')
                m_stack.push(s[i]);
            else
            {
                if(m_stack.empty())
                    return false;
                char tmp=m_stack.top();
                m_stack.pop();
                if(dict[tmp]!=s[i])
                    return false;
            }

        }
        if(m_stack.empty())
            return true;

        return false;
        
    }
};
