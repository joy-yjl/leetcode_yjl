
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n=nums.size();
        for(int i=n-1;i>0;i--)
        {
            if(nums[i-1]<nums[i])
            {

                int index=findReplace(nums, i,n-1,nums[i-1]);
                int tmp=nums[index];
                nums[index]=nums[i-1];
                nums[i-1]=tmp;
                sort(nums,i,n-1);
                return;

            }

        }
        sort(nums,0,n-1);

    }
    void sort(vector<int> & nums,int left,int right)
    {
        while(right>left)
        {
            int tmp=nums[right];
            nums[right]=nums[left];
            nums[left]=tmp;
            right--;
            left++;
        }
    }

    int findReplace(vector<int> & nums,int left,int right,int num)
    {
        while(right>left)
        {
            int mid=left+(right-left)/2;
            if(nums[mid]>num)
            {
                left=mid+1;                
            }
            else
            {
                right=mid-1;
            }
        }
        if(nums[right]>num)
            return right;
        else
            return right-1;

    }

};
