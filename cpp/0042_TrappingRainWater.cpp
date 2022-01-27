/*
(1)可以从左往右走，再从右往左走，第一遍存入当前位置左边的最大值，第二次遍历时找右边最大值，然后和左边最大值比较取其中的较小值，
然后跟当前值 A[i] 相比，如果大于当前值，则将差值存入结果
(2)左右指针，找到左右中最小的，如果较小值是 left 指向的值，则从左向右扫描，如果较小值是 right 指向的值，则从右向左扫描，若遇到的值比当较小值小，
则将差值存入结果，如遇到的值大，则重新确定新的窗口范围
(3)遍历高度，如果此时栈为空，或者当前高度小于等于栈顶高度，则把当前高度的坐标压入栈，注意这里不直接把高度压入栈，而是把坐标压入栈，
这样方便在后来算水平距离。当遇到比栈顶高度大的时候，就说明有可能会有坑存在，可以装雨水。此时栈里至少有一个高度，如果只有一个的话，
那么不能形成坑，直接跳过，如果多余一个的话，那么此时把栈顶元素取出来当作坑，新的栈顶元素就是左边界，当前高度是右边界，只要取二者较小的，
减去坑的高度，长度就是右边界坐标减去左边界坐标再减1，二者相乘就是盛水量啦
*/
class Solution {
public:
    int trap(vector<int>& height) {
        int left=0,right=height.size()-1;
        int res=0;
        while(left<right)
        {
            int low=min(height[left],height[right]);
            if (height[left] == low) {
                left++;
                while (left < right && height[left] < low) 
                {
                    res += low - height[left++];
                }
            } else 
            {
                right--;
                while (left < right && height[right] < low) 
                {
                    res += low - height[right--];
                }
            }

        }
        return res;
        
    }
};

class Solution {
public:
    int trap(vector<int>& height) {
        int l = 0, r = height.size() - 1, level = 0, res = 0;
        while (l < r) {
            int lower = height[(height[l] < height[r]) ? l++ : r--];
            level = max(level, lower);
            res += level - lower;
        }
        return res;
    }
};
class Solution {
public:
    int trap(vector<int>& height) {
        stack<int> st;
        int i = 0, res = 0, n = height.size();
        while (i < n) {
            if (st.empty() || height[i] <= height[st.top()]) {
                st.push(i++);
            } else {
                int t = st.top(); st.pop();
                if (st.empty()) continue;
                res += (min(height[i], height[st.top()]) - height[t]) * (i - st.top() - 1);
            }
        }
        return res;
    }
};
