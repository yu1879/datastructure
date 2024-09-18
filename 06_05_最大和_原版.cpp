#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N,M;
    cin >> N >> M;
    vector< vector<int> > data(N);

    for(int i=0;i<N;i++)
        data[i].resize(M);

    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            cin >> data[i][j];
        }
    }

    vector<int> max_value(N);
    int sum_max = 0;

    for(int i=0;i<N;i++){
        int max_int = data[i][0];
        for(int j=1;j<M;j++){
            max_int = max_int>data[i][j]?max_int:data[i][j];
        }
        sum_max += max_int;
        max_value[i] = max_int;
    }

    cout << sum_max << endl;
    int counts_max_divided = 0;
    for(int i=0;i<N;i++){
        if(sum_max%max_value[i]==0){
            cout << max_value[i] << " ";
            counts_max_divided++;
        }
        else if(i == N-1 && counts_max_divided==0)
            cout << -1;
    }


    return 0;
}
