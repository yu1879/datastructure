#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(pair<int,int> a,pair<int,int> b){
    return a.first*b.second < a.second*b.first;
}

int main()
{
    int n;
    vector<pair<int,int>> object;
    long long int sum = 0;
    long long int total_cost = 0;

    cin >> n;
    object.resize(n);
    for(int i=0;i<n;i++){
        // weight
        cin >> object[i].first;
    }
    for(int i=0;i<n;i++){
        // frequency
        cin >> object[i].second;
    }
    sort(object.begin(),object.end(),compare);
    for(int i=0;i<n-1;i++){
        sum += object[i].first;
        total_cost += sum*object[i+1].second;
    }
    cout << total_cost << endl;

    return 0;
}
