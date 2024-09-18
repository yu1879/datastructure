class Solution {
    stack<char> data;
public:
    bool isValid(string s) {
        for(char c:s){
            if(c=='(' || c=='[' || c=='{'){
                data.push(c);
                continue;
            }
            
            if((c==')' || c==']' || c=='}') && data.empty())
                return false;
            
            if(c==')'){
                if(data.top()=='('){
                    data.pop();
                }
                else{
                    return false;
                }
            }
            else if(c==']'){
                if(data.top()=='['){
                    data.pop();
                }
                else{
                    return false;
                }
            }
            else if(c=='}'){
                if(data.top()=='{'){
                    data.pop();
                }
                else{
                    return false;
                }
            }
        }
        if(data.empty())
            return true;
        else
            return false;
    }
};