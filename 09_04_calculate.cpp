class Solution {
public:
    int calculate(string s) {
        stack<int> numbers;
        stack<int> signs; // +1:+ , -1:-
        long long int value = 0;
        int sign = +1; // +1:+ , -1:-
        long long int result = 0; // a + b + c
        // ((a + b) + c)
        
        for(char c:s){
            if(c <= '9' && c>= '0'){
                value = value * 10 + c - '0'; // '9' -> 9
            }
            else if(c == '('){
                numbers.push(result);
                signs.push(sign);
                value = result = 0;
                sign = 1;
            }
            else if(c == ')'){
                result += sign * value;
                result *= signs.top();
                signs.pop();
                result += numbers.top();
                numbers.pop();
                value = 0;
                sign = 1;
            }
            else if(c == '+'){
                // a + b + c
                result += sign * value;
                sign = 1;
                value = 0;
            }
            else if(c == '-'){
                // a + b + c
                result += sign * value;
                sign = -1;
                value = 0;
            }
        }
        if(value){
            // a + b + c
            result += sign * value;
        }
        return result;
    }
};