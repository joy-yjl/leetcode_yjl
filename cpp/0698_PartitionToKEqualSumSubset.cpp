class Solution {
public:
    bool backtrack(vector<int>& nums,vector<int> &visited, int target, int curr_sum, int i, int k) {
        if (k == 1) 
            return true;
        if (i>=nums.size())
            return false;
        
        if (curr_sum == target) 
            return backtrack(nums, visited, target, 0, 0, k-1);
        
        for (int j = i; j < nums.size(); j++) {
            if (visited[j] || curr_sum + nums[j] > target) 
                continue;
            visited[j] = 1;
            if (backtrack(nums, visited, target, curr_sum + nums[j], j+1, k)) 
                return true;
            visited[j] = 0;
        }
        
        return false;
    }
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int sum=0;
        for(int i=0;i<nums.size();i++)
            sum+=nums[i];
        int ave=sum/k;
        if(nums.size() < k || sum%k)
            return false;
        vector<int>vis(nums.size(), 0);
        // sort(nums.begin(),nums.end(),greater<int>());
        return backtrack(nums, vis, sum / k, 0, 0, k);
        
    }
};
