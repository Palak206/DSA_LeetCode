class Solution {
public:
    string convert(string s, int numRows) {
        string a[numRows];
        
        int i,j=0,pos=0;
        
        if(numRows == 1)
            return s;
        
      for(i=0;i<s.length();++i){
          
        a[pos]+=s[i];
          
          if(pos==0)
              j=0;
          else if(pos==numRows-1)
              j=1;
          if(j==0)
              ++pos;
          else 
              --pos;
      }  
      for(i=1;i<numRows;++i)
          a[0]+=a[i];
      return a[0];
    }
};