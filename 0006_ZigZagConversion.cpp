/*
单纯的找规律
*/

class Solution {
public:
    string convert(string s, int numRows) {
       int n=s.size();
       if (numRows<=1) return s;
       int group=(numRows-1)*2;
       string res="";
       for(int i=0;i<numRows;i++)
       {
           for(int j=i;j<n;j=j+group)
           {
               res+=s[j];
               int pos=j+group-i*2;
               if(i!=0 && i!=numRows-1 && pos<n )
               {
                   res+=s[pos];
               }

           }

       }
        return res;

    }
};