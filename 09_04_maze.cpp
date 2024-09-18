#include <iostream>
#include <stack>
#include <vector>

using namespace std;

/*
struct pair{
    first,
    second
};
*/

int main () {
    int MAZE[10][12]={
        {1,1,1,1,1,1,1,1,1,1,1,1},
        {1,0,0,0,1,1,1,1,1,1,1,1},
        {1,1,1,0,1,1,0,0,0,0,1,1},
        {1,1,1,0,1,1,0,1,1,0,1,1},
        {1,1,1,0,1,0,0,1,1,0,1,1},
        {1,1,1,0,1,1,0,1,1,0,1,1},
        {1,1,1,0,0,0,0,1,1,0,1,1},
        {1,1,1,1,1,1,0,1,1,0,1,1},
        {1,1,0,0,0,0,0,0,1,0,0,1},
        {1,1,1,1,1,1,1,1,1,1,1,1}
    };

    vector<vector<bool>> visited(10, vector<bool>(12, false));
    stack<pair<int, int>> path;

    path.push(make_pair(1,1));
    visited[1][1] = true;

    while(!path.empty()){
        pair<int, int> current = path.top();
        int x = current.first;
        int y = current.second;
        if(x == 8 && y == 10)
            break;
        if(visited[x+1][y]==false && MAZE[x+1][y]==0){
            // bottom
            path.push(make_pair(x+1,y));
            visited[x+1][y] = true;
        }
        else if(visited[x-1][y]==false && MAZE[x-1][y]==0){
            // up
            path.push(make_pair(x-1,y));
            visited[x-1][y] = true;
        }
        else if(visited[x][y+1]==false && MAZE[x][y+1]==0){
            // right
            path.push(make_pair(x,y+1));
            visited[x][y+1] = true;
        }
        else if(visited[x][y-1]==false && MAZE[x][y-1]==0){
            // left
            path.push(make_pair(x,y-1));
            visited[x][y-1] = true;
        }
        else{
            // No available direction :(
            path.pop();
        }
    }

    while(!path.empty()){
        pair<int, int> current = path.top();
        int x = current.first;
        int y = current.second;
        MAZE[x][y] = 2;
        path.pop();
    }

    for(int i=0;i<10;i++){
        for(int j=0;j<12;j++){
            cout << MAZE[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}

