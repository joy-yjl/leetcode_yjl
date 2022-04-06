class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> vec;
        int row=matrix.size();
        int column=matrix[0].size();
        if(row==0) return vec;
        int left=0,right=column-1,top=0,bottom=row-1,dir=0;
        while(left<=right and top<=bottom){
            if(dir==0){
                for(int i=left;i<=right;i++){
                    vec.push_back(matrix[top][i]);
                }
                dir=1,top++;
            }
            else if(dir==1){
                for(int i=top;i<=bottom;i++){
                    vec.push_back(matrix[i][right]);
                }
                dir=2,right--;
            }
            else if(dir==2){
                for(int i=right;i>=left;i--){
                    vec.push_back(matrix[bottom][i]);
                }
                dir=3,bottom--;
            }
            else if(dir==3){
                for(int i=bottom;i>=top;i--){
                    vec.push_back(matrix[i][left]);
                }
                dir=0,left++;
            }
            
        }
        return vec;
    }
};
