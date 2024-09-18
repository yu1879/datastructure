#include <iostream>

using namespace std;

int main() {
    int data[3][3][3];

    int *p = (int *) data;

    for(int i=0;i<27;i++){
        *(p+i) = i+1;
        // p[i]
    }

    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            for(int k=0;k<3;k++){
                cout << data[i][j][k] << " ";
            }
        }
    }

    return 0;
}
