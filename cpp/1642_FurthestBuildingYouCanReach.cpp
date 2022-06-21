class Solution {
public:
    int helper(vector<int>& heights,int index, int bricks,int ladders)
    {
        if(bricks<0 || ladders<0)
        {
            return index-1;
        }
        while(index<heights.size()-1 && heights[index]>=heights[index+1])
            index++;
        if(index==heights.size()-1)
            return index;
        else
        {
            int tmp=heights[index+1]-heights[index];
            return max(helper(heights,index+1,bricks-tmp,ladders),helper(heights,index+1,bricks,ladders-1));
        }
    }
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        return helper(heights,0,bricks,ladders);
    }
};

class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        priority_queue<int> maxB;
        int index=0, diff =0; 
        for(index=0; index<heights.size()-1; index++){ 
            diff = heights[index+1]-heights[index];
            if(diff <= 0){
                continue;
            }
            bricks -= diff; 
            maxB.push(diff); 
            if(bricks < 0){
                bricks += maxB.top(); 
                maxB.pop(); 
                ladders--; 
            }
            if(ladders < 0) break;
        }
        return index;
    }
};
