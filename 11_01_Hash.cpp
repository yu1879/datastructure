#include <iostream>
#include <math.h>

using namespace std;

int Hash_Func_Div(string input, int m){
    long long int sum = 0;
    for(char c:input){
        sum += c;
    }
    return sum % m;
}

int Hash_Func_Mul(string input, int m){
    long long int sum = 0;
    double c = (sqrt(5)-1)/2.0;
    int tmp = 1;
    for(char c:input){
        sum += tmp * c;
        tmp *= 256;
    }
    // get fraction of c*sum
    double frac = c*sum - (int) (c*sum);
    int index = frac * m;
    return index;
}

int main()
{
    string str;
    cout << "Please enter a str:" << endl;
    cin >> str;

    cout << "Index:" << Hash_Func_Div(str, 8) << endl;
    cout << "Index:" << Hash_Func_Mul(str, 8) << endl;

    return 0;
}
