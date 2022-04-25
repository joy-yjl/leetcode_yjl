class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> res(rowIndex+1,1);
        long tmp=1;
        for(int i=1,up=rowIndex,down=1;i<rowIndex;i++,up--,down++)
        {
            tmp=tmp*up/down;
            res[i]=tmp;
        }
        return res;
    }
};
