class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> res(n,vector<int>(n,0));   
        if(n==0) return res;
        if(n==1){res[0][0]=1; return res;}
        
        
        int left=0,right=n-1,top=0,bottom=n-1,dir=0;
        int num=1;
        while(left<=right and top<=bottom){
            if(dir==0){
                for(int i=left;i<=right;i++){
                    res[top][i]=num++;
                }
                dir=1,top++;
            }
            else if(dir==1){
                for(int i=top;i<=bottom;i++){
                    res[i][right]=num++;
                }
                dir=2,right--;
            }
            else if(dir==2){
                for(int i=right;i>=left;i--){
                    res[bottom][i]=num++;
                }
                dir=3,bottom--;
            }
            else if(dir==3){
                for(int i=bottom;i>=top;i--){
                    res[i][left]=num++;
                }
                dir=0,left++;
            }
            
        }
        return res;
    }
};
