class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<vector<int>> s;
        int n=heights.size();
        int res=0;

        int i=0;
        while(i<n || !s.empty())
        {
            if(i<n &&(s.empty() || heights[i]>=heights[s.top()[1]]))
            {
                s.push({i,i});
                i++;
            }
            else
            {
                vector<int> left=s.top(),right=s.top();
                while(!s.empty() && (i==n || heights[s.top()[1]]>heights[i]))
                {
                    left=s.top();
                    res=max( heights[left[1]]*(right[1]-left[0]+1) , res);
                    s.pop();
                }
                if(i<n)
                {
                    s.push({left[0],i});
                    i++;
                }
            }
        }
        return res;
        
    }
};

class Solution {
public:
    int largestRectangleArea(vector<int>& heights)
    { 
        stack<int> st;
        int ans=0;
        heights.push_back(0);
        
        for(int i=0;i<heights.size();i++)
        {
            while(!st.empty() && heights[st.top()]>heights[i]){
                int top=heights[st.top()];
                st.pop();
                int ran=st.empty()?-1:st.top();
                ans=max(ans,top*(i-ran-1));
            }
            st.push(i);
        }
        return ans;
    }
};
