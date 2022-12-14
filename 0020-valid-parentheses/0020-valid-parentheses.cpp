class Solution {
public:
    bool isValid(string s) {
        stack<char>stk;
   
   for(int i=0;i<s.length();i++)
   {
      if(s[i]=='(')
	  {
	     stk.push(s[i]);	
	  }
	  else if(s[i]=='{')
	  {
	  	stk.push(s[i]);
	  }
	  else if(s[i]=='[')
	  {
	  	stk.push(s[i]);
	  }
	  else if(s[i]==')')
	  {
 	     if(!stk.empty() and stk.top()=='(')
 	     {
 	        stk.pop();	
	     }
	     else
	     {
	     	return false;
		 }
      }
	  else if(s[i]=='}')
	  {
	  	if(!stk.empty() and stk.top()=='{')
 	     {
 	        stk.pop();	
	     }
	     else
	     {
	     	return false;
		 }
	  }
	  else if(s[i]==']')
	  {
	  	if(!stk.empty() and stk.top()=='[')
 	     {
 	        stk.pop();	
	     }
	     else
	     {
	     	return false;
		 }
	  }	
   }        
   return stk.size()==0;
    }
};