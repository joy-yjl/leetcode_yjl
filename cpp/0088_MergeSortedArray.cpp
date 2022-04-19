class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int right=m+n-1;
        int r1=m-1;
        for(int i=n-1;i>=0;i--)
        {
            while(r1>=0 && nums1[r1]>nums2[i])
            {
                nums1[right]=nums1[r1];
                r1--;
                right--;
            }
            nums1[right]=nums2[i];
            right--;

        }
    }
};
