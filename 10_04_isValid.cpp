#include <iostream>
#include <deque>

using namespace std;

bool isValid(string str){
    deque<char> data;
    for(char c:str){
        if(c =='(' || c=='[' || c=='{'){
            data.push_back(c);
            continue;
        }
        if((c==')' || c==']' || c=='}') && data.empty()){
            return false;
        }
        if(c==')'){
            if(data.back()=='('){
                data.pop_back();
            }
            else{
                return false;
            }
        }
        else if(c==']'){
            if(data.back()=='['){
                data.pop_back();
            }
            else{
                return false;
            }
        }
        else if(c=='}'){
            if(data.back()=='{'){
                data.pop_back();
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

int main()
{
    string str = "{[a+b+(s+f)-d]+2}";

    if(isValid(str))
        cout << "Valid!" << endl;
    else
        cout << "Not valid!" << endl;

    return 0;
}
