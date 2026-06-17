class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> s;
        for(int i=0;i<tokens.size();i++){
            string ch=tokens[i];
            if(ch=="+"|| ch=="-" || ch=="*"|| ch=="/"){
            int b=s.top();
            s.pop();
            int a=s.top();
            s.pop();
            if(ch=="+")
            s.push(a+b);
            else if(ch=="-")
            s.push(a-b);
            else if(ch=="*")
            s.push(a*b);
            else
            s.push(a/b);
            }
            else {
                s.push(stoi(ch));
            }

        }
        return s.top();
    }
};
