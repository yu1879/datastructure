#include <iostream>
#include <fstream>
#include <vector>
#include <unordered_map>
#include <stdlib.h>
using namespace std;

int main()
{
    ifstream file("A-large-practice.in");
    ofstream ofile("Testoutput.txt");

    vector<int> data;
    unordered_map<int, int> number_index;

    if(file && ofile)
    {
        int dataCounts,totalPrice,stuffCounts;
        file >> dataCounts;
        for(int i=0;i<dataCounts;i++)
        {
            file >> totalPrice >> stuffCounts;

            data.resize(stuffCounts);

            for(int j=0;j<stuffCounts;j++){
                file >> data[j];
            }

            for(int j=0;j<stuffCounts;j++){
                // check if totalPrice-data[j] exist in this unordered_map
                auto iter = number_index.find(totalPrice-data[j]);
                if(iter != number_index.end()){
                    ofile << "Case #" << i+1 << ": " << number_index[totalPrice-data[j]] + 1 << " " << j + 1 << endl;
                    break;
                }
                number_index[data[j]] = j;
            }
            number_index.clear();
        }
    }
    else
        cout << "Open test data failed!" << endl;
    file.close();
    ofile.close();
    return 0;
}
