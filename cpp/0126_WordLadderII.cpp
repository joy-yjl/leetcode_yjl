class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        vector<vector<string>> res;
        unordered_set<string> dict(wordList.begin(), wordList.end());
        vector<string> p{beginWord};
        queue<vector<string>> paths;
        paths.push(p);
        int level = 1, minLevel = INT_MAX;
        unordered_set<string> words;
        while (!paths.empty()) 
        {
            vector<string> cur=paths.front();
            paths.pop();

            if (cur.size() > level) {
                for (string w : words) dict.erase(w);
                words.clear();
                level = cur.size();
                if (level > minLevel) break;
            }

            string last=cur.back();
            for (int i = 0; i < last.size(); ++i) 
            {
                string newLast = last;
                for (char ch = 'a'; ch <= 'z'; ++ch) 
                {
                    newLast[i]=ch;
                    if(!dict.count(newLast)) continue;
                    words.insert(newLast);
                    vector<string> newpath=cur;
                    newpath.push_back(newLast);
                    if(newLast==endWord)
                    {
                        res.push_back(newpath);
                        minLevel=newpath.size();
                    }
                    else
                        paths.push(newpath);
                }
            }

        }
        return res;
    }
};


