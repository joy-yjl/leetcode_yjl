class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        int res=0;
        unordered_set<string> words(wordList.begin(),wordList.end());
        if(!words.count(endWord))
            return res;
        queue<string> q;
        q.push(beginWord);
        res++;
        if(words.count(beginWord))
            words.erase(beginWord);

        while(!q.empty())
        {
            int n=q.size();
            for(int i=0;i<n;i++)
            {
                string last=q.front();
                q.pop();

                for(int j=0;j<last.size();j++)
                {
                    string newlast=last;
                    for (char ch = 'a'; ch <= 'z'; ++ch) 
                    {
                        newlast[j]=ch;
                        if(newlast==endWord)
                            return res+1;
                        if(words.count(newlast))
                        {
                            q.push(newlast);
                            words.erase(newlast);
                        }

                    }
                }
            }
            res++;
        }
        return 0;
        
    }
};
