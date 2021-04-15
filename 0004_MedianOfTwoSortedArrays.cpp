/*
二分法，但是分多不是数组，而是k，每次删除k/2个小数
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m=nums1.size();
        int n=nums2.size();
        int left=(m+n+1)/2;
        int right=(m+n+2)/2;
        return (getKth(nums1,0,m-1,nums2,0,n-1,left)+getKth(nums1,0,m-1,nums2,0,n-1,right))*0.5;
    }
    int getKth(vector<int>& nums1, int start1, int end1, vector<int>& nums2, int start2, int end2, int k)
    {
        int len1 = end1 - start1 + 1;
        int len2 = end2 - start2 + 1;
        if (len1 > len2) return getKth(nums2, start2, end2, nums1, start1, end1, k);
        if (len1 == 0) return nums2[start2 + k - 1];

        if (k == 1) return nums1[start1]<nums2[start2]?nums1[start1]:nums2[start2];   
        
        int min1=len1<(k/2)?len1:(k/2);
        int min2=len2<(k/2)?len2:(k/2);

        int i = start1 + min1 - 1;
        int j = start2 + min2 - 1;

        if (nums1[i] > nums2[j]) {
            return getKth(nums1, start1, end1, nums2, j + 1, end2, k - (j - start2 + 1));
        }
        else {
            return getKth(nums1, i + 1, end1, nums2, start2, end2, k - (i - start1 + 1));
        }
    }
    
};
*/
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m=nums1.size();
        int n=nums2.size();
        int k1=(m+n+1)/2;
        int k2=(m+n+2)/2;
        return (findK(nums1,0,nums2,0,k1)+findK(nums1,0,nums2,0,k2)) / 2.0;
        
    }
    int findK(vector<int>& nums1,int start1,vector<int>& nums2,int start2,int k)
    {
        if(start1>=nums1.size()) return nums2[start2+k-1];
        if(start2>=nums2.size()) return nums1[start1+k-1];
        if(k==1) return nums1[start1]>nums2[start2]?nums2[start2]:nums1[start1];

        if((start1+k/2)>nums1.size()) 
            return findK(nums1,start1,nums2,start2+k/2,k-k/2);
        if((start2+k/2)>nums2.size()) 
            return findK(nums1,start1+k/2,nums2,start2,k-k/2);

        if (nums1[start1+k/2-1]>nums2[start2+k/2-1]) 
            return findK(nums1,start1,nums2,start2+k/2,k-k/2);
        else 
            return findK(nums1,start1+k/2,nums2,start2,k-k/2);


    }

};

