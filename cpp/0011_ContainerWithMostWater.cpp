/*
从两边往中间找，从短边移动
*/class Solution {
public:
    int maxArea(vector<int>& height) {
    	int res=0;
    	int i=0,j=height.size()-1;
    	while(j>i)
    	{
            int tmp=(right-left)*(height[left]>height[right]?height[right]:height[left]);
            if(tmp>res)
            	res=tmp;
            height[i]<height[j]?i++:j--;
        }
        return res;
        
    }
};
