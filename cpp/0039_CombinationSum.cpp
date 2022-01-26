/*
回溯法
好好学习一下 
很重要
*/



class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> tmp;
        sort(candidates.begin(),candidates.end());

        helper(candidates,target,0,tmp,res);
        
        return res;
        
    }
    void helper(vector<int>& cand, int target,int index,vector<int>& tmp,vector<vector<int>>& res)
    {
        if(index>=cand.size() || target-cand[index]<0) return ;
        tmp.push_back(cand[index]);
        if(target-cand[index]==0)
        {
            res.push_back(tmp);
            tmp.pop_back();
            return ;
        }
        helper(cand,target-cand[index],index,tmp,res);
        tmp.pop_back();
        helper(cand,target,index+1,tmp,res);
        return ;


    }
};
