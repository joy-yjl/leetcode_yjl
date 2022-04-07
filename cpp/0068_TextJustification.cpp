class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> res;
        int n=words.size();
        int left=0,right=0;
        int count=0;
        for(int i=0;i<n;i++)
        {
            int l=words[i].size();
            if(count+l>maxWidth)
            {
                string r="";
                int space=maxWidth-count+1+(right-left);
                int num=right-left;
                int low=0,heigh=0;;
                if(num==0)
                {
                    low=space;
                    r=r+words[left];
                    while(low)
                    {
                        r=r+" ";
                        low--;
                    }

                }
                else
                {
                    low=space/num;
                    heigh=space%num;

                    for(int j=left;j<right;j++,heigh--)
                    {
                        r=r+words[j];
                        int k=low;
                        if(heigh>0)
                            k=low+1;
                        while(k)
                        {
                            r=r+" ";
                            k--;
                        }

                    }
                    r=r+words[right];
                }
                left=right+1;
                res.push_back(r);
                count=0;
                
            }
            if(count+l<=maxWidth)
            {
                count+=(l+1);
                right=i;
            }
        }
        if(left<=right)
        {
            string r="";
            int space=maxWidth-count+1;
            
            for(int j=left;j<right;j++)
            {
                r=r+words[j];
                r=r+" ";
            }
            r=r+words[right];
            while(space)
            {
                r=r+" ";
                space--;
            }
            res.push_back(r);
            
        }
        return res;
        
    }
};
