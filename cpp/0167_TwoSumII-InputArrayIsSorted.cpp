class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int n=numbers.size();
        int left=0,right=n-1;
        vector<int> res;
        while(right>left)
        {
            int sum=numbers[left]+numbers[right];
            if(sum>target)
                right--;
            else if(sum<target)
                left++;
            else
            {
                res.push_back(left+1);
                res.push_back(right+1);
                return res;
            }

        }
        return res;
        
    }
};
