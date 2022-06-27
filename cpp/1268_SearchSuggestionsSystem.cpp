class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        vector<vector<string>> res;
        int n=searchWord.size();
        sort(products.begin(),products.end());
        int left=0,right=products.size()-1;
        for(int i =0;i<n;i++)
        {
            vector<string> r;
            int j;
            for(j=left;j<=right;j++)
            {
                if(products[j][i]==searchWord[i])
                {
                    left=j;
                    for(int k=j;k<=right;k++)
                    {
                        if(products[k][i]!=searchWord[i])
                        {
                            right=k-1;
                            break;
                        }
                    }
                    break;
                }

            }
            if(j>right)
            {
                left=right+1;
            }
            else
            {
                for(j=0;j<3 && left+j<=right;j++)
                    r.push_back(products[left+j]);
            }

            res.push_back(r);

        }
        return res;
        
    }
};


class Solution {
public:
    int findleft(vector<string>& products,string& searchWord,int index,int left,int right)
    {
        int rightc=right;
        while(left<=right)
        {
            int mid=left+(right-left)/2;
            if(products[mid][index]>=searchWord[index])
            {
                right=mid-1;
            }
            else
            {
                left=mid+1;
            }

        }
        if(left<=rightc &&products[left][index]==searchWord[index])
            return left;
        else
            return -1;

    }
    int findright(vector<string>& products,string& searchWord,int index,int left,int right)
    {
        int leftc=left;
        while(left<=right)
        {
            int mid=left+(right-left)/2;
            if(products[mid][index]<=searchWord[index])
            {
                left=mid+1;
                
            }
            else
            {
                right=mid-1;
            }

        }
        if(right>=leftc && products[right][index]==searchWord[index])
            return right;
        else
            return -1;

    }

    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        vector<vector<string>> res;
        int n=searchWord.size();
        sort(products.begin(),products.end());
        int left=0,right=products.size()-1;
        for(int i =0;i<n;i++)
        {
            vector<string> r;
            left=findleft(products,searchWord,i,left,right);
            if(left==-1)
            {
                for(int j=i;j<n;j++)
                    res.push_back(r);
                return res;
            }
            right=findright(products,searchWord,i,left,right);
            for(int j=0;j<3 && left+j<=right;j++)
                r.push_back(products[left+j]);

            res.push_back(r);

        }
        return res;
        
    }
};
