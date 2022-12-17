// class Solution {
// public:
//     int evalRPN(vector<string>& tokens) {
//         stack<int>st;
        
//         for(int i=0;i<tokens.size();i++)
//         {
//             if(tokens[i]!="+"&&tokens[i]!="-"&&tokens[i]!="*"&&tokens[i]!="/")
//             {
//                 int k=stoi(tokens[i]);
//                 st.push(k);
//             }
//             else
//             {
//                 int op2=st.top();
//                 st.pop();
//                 int op1=st.top();
//                 st.pop();
//                 switch(tokens[i][0])
//                 {
//                     case '+':
//                         st.push(op1+op2);
//                         break;
//                     case '-':
//                         st.push(op1-op2);
//                         break;
//                     case '*':
//                         st.push(op1*op2);
//                         break;
//                     case '/':
//                         st.push(op1/op2);
//                         break;
//                 }
//             }
//         }
//         return st.top();
//     }
// };


// class Solution {
// public:
//     int evalRPN(vector<string>& tokens) {
//         stack<int> s;
//         for(int i=0;i<tokens.size();i++){
//             if(tokens[i]=="+" || tokens[i]=="-" || tokens[i]=="*" || tokens[i]=="/"){
//                 int a = s.top();
//                 s.pop();
//                 int b = s.top();
//                 s.pop();
//                 int res;
//                 if(tokens[i] == "+"){
//                     s.push(a+b);
//                 }
//                 else if(tokens[i] == "-"){
//                     s.push(b-a);
//                 }
//                 else if(tokens[i] == "*"){
//                     s.push(a*b);
//                 }
//                 else if(tokens[i] == "/"){
//                     s.push(b/a);
//                 }
//             }
//             else
//                 s.push(stoi(tokens[i]));
//         }
//         return s.top();
//     }
// };


// Time Complexity : O(N)
// Space Complexity : O(1)
// class Solution{
//     public:
// int evalRPN(vector<string>& tokens) {
// 	int top = 0;
// 	for(auto& t : tokens) 
// 		if(t == "+" || t == "-" || t == "*" || t == "/") {
// 			int op1 = stoi(tokens[--top]); 
// 			int op2 = stoi(tokens[--top]); 
// 			if(t == "+") op1 = op2 + op1;
// 			if(t == "-") op1 = op2 - op1;
// 			if(t == "/") op1 = op2 / op1;
// 			if(t == "*") op1 = op2 * op1;   
// 			tokens[top++] = to_string(op1);
// 		}
// 		else tokens[top++] = t;
// 	return stoi(tokens[0]);
// }
// };


class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> stk;
        for(int i=0;i<tokens.size();i++)
        {
    if(tokens[i]!="+" && tokens[i]!="-" && tokens[i]!="/" && tokens[i]!="*")
    {
        stk.push(stoi(tokens[i]));
        continue;
    }
    else
    {
        long long ftop=stk.top();
        stk.pop();
        long long stop=stk.top();
        stk.pop();
        if(tokens[i]=="+")
        {
            stk.push(stop+ftop);
        }
        else if(tokens[i]=="-")
        {
            stk.push(stop-ftop);
        }
        else if(tokens[i]=="*")
        {
            stk.push(stop*ftop);
        }
        else
        {
            stk.push(stop/ftop);
        }


    }
        }
        return stk.top();

    }
};