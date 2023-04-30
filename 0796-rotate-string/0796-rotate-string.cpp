class Solution {
public:
    bool rotateString(string s, string goal) {
        int n = s.length();
        int i=0;
        bool ans=false;
        char temp=' ';
        if(s==goal)
        return true;

        for(i=1;i<n;i++)
        {
            temp=s[0];
            s=s.substr(1,n)+temp;
            if(s==goal)
            {
            ans=true;
            break;
            }
        }
        return ans;
    }
};