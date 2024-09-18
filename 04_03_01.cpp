#include <iostream>
#include <time.h>

using namespace std;

int main() {
    clock_t s,f;
    const int n = 600;
    auto arr_3d = new int[n][n][n];
    int counts = 0;

    s = clock();
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            for(int k=0;k<n;k++){
                arr_3d[i][j][k] = counts;
                counts++;
            }
        }
    }
    f = clock();
    cout << "Time consumed:" << (f-s)/(double)CLOCKS_PER_SEC << "s" <<endl;

    s = clock();
    counts = 0;
    int *p = (int*) arr_3d;
    for(int i=0;i<n*n*n;i++){
        *p = counts;
        counts++;
    }
    f = clock();
    cout << "Time consumed:" << (f-s)/(double)CLOCKS_PER_SEC << "s" <<endl;

    return 0;
}
