#include <bits/stdc++.h>
using namespace std;

// structure for storing a cell's data
struct cell {
    int x, y;
    int dis;
    cell() {}
    cell(int x, int y, int dis) : x(x), y(y), dis(dis) {

    }

};


// Function to check if x,y are inside the Board
bool isInside(int x, int y, int N)
{
    if (x >= 1 && x <= N && y >= 1 && y <= N)
        return true;
    return false;
}


// Function to find minimum step to reach target position
int minStepToReachTarget(int knightPos[], int targetPos[], int N){

    // x and y direction, where a knight can move
    int dx[] = { -2, -1, 1, 2, -2, -1, 1, 2 };
    int dy[] = { -1, -2, -2, -1, 1, 2, 2, 1 };

    // queue for storing states of knight in board
    queue<cell> q;

    // push starting position of knight with 0 distance
    q.push(cell(knightPos[0], knightPos[1], 0));

    cell t;
    int x, y;
    bool visit[N + 1][N + 1];

    // make all cell unvisited
    for (int i = 1; i <= N; i++){
        for (int j = 1; j <= N; j++){
            visit[i][j] = false;
        }
    }

    // visit starting state
    visit[knightPos[0]][knightPos[1]] = true;

    // loop untill we have one element in queue
    while (!q.empty()) {
        t = q.front();
        q.pop();

        // if current cell is equal to target cell return its distance
        if (t.x == targetPos[0] && t.y == targetPos[1])
            return t.dis;



        // loop for all reachable states
        for (int i = 0; i < 8; i++) {
            x = t.x + dx[i];
            y = t.y + dy[i];

            // If reachable state is not visited yet push that state into queue
            if (isInside(x, y, N) && !visit[x][y]) {
                visit[x][y] = true;
                q.push(cell(x, y, t.dis + 1));

            }

        }

    }   // while loop ends


}




int main()
{
    int N ,s1,s2,t1,t2;
    cout<< "Enter board size"<<endl;
    cin>> N;
    cin>>s1>>s2>>t1>>t2;
    int knightPos[] = {s1,s2};
    int targetPos[] = {t1,t2};
    cout << minStepToReachTarget(knightPos, targetPos, N);
    return 0;
}
