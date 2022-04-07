class Solution {
public:
    string simplifyPath(string path) {
        stack<string> stacks;
        string s="";
        for(int i=0;i<path.size();i++)
        {
            if(path[i]=='/')
            {
                if(s!="" && s!="." && s!="..")
                    stacks.push(s);
                else if(s==".." && !stacks.empty())
                    stacks.pop();
                s="";
            }
            else
            {
                s=s+path[i];
            }
        }
        if(s!="" && s!="." && s!="..")
            stacks.push(s);
        else if(s==".." && !stacks.empty())
            stacks.pop();
        s="";
        while(!stacks.empty())
        {
            s="/"+stacks.top()+s;
            stacks.pop();
        }
        if(s=="")
            s="/";
        return s;
        
    }
};
