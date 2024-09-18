#include <iostream>

using namespace std;

unsigned char data[20][20];
unsigned char max_value[20];

int main() {
    int N,M;
    cin >> N >> M;

    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            int tmp;
            cin >> tmp;
            data[i][j] = tmp-1;
        }
    }

    int sum_max = 0;

    for(int i=0;i<N;i++){
        int max_int = data[i][0];
        for(int j=1;j<M;j++){
            max_int = max_int>data[i][j]?max_int:data[i][j];
        }
        sum_max += max_int+1;
        max_value[i] = max_int;
    }

    cout << sum_max << endl;
    int counts_max_divided = 0;
    for(int i=0;i<N;i++){
        if(sum_max%(max_value[i]+1)==0){
            cout << max_value[i]+1 << " ";
            counts_max_divided++;
        }
        else if(i == N-1 && counts_max_divided==0)
            cout << -1;
    }


    return 0;
}
