#include<iostream>
#include<queue>
#include<utility>

using namespace std;
#define FOR(i,a) for(int i = 0; i < a; i++)
int n, m, r ,c;
int maze[1005][1005];
bool visited[1005][1005];

bool intoMaze(int x, int y){
    return (x >= 0 && x < n && y >= 0 && y < m && maze[x][y] == 0);
}

int shortestPath(int sX, int sY){
    queue<pair<int,int>> qe;
    int dx[4] = {1,0,-1,0}, dy[4] = {0,-1,0,1};
    
    qe.push(make_pair(sX,sY));
    visited[sX][sY] = true;
    int countStep = 0;
    while(!qe.empty()){
        int size = qe.size();
        FOR(i,size){
            int x = qe.front().first;
            int y = qe.front().second;
            
            qe.pop();
            if(x == 0 || x == n-1 || y == 0 || y == m-1){
                return countStep + 1; // Thêm 1 vào countStep trước khi trả về
            }
            FOR(i,4){
                int dX = x + dx[i];
                int dY = y + dy[i];
                if(!visited[dX][dY] && intoMaze(dX,dY)){
                    visited[dX][dY] = true;
                    qe.push(make_pair(dX,dY));
                }
            }
        }
        countStep++;
    }
	return -1;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n >> m >> r >> c;
    FOR(i,n){
        FOR(j,m){
            cin >> maze[i][j];
        }
    }
    int res = shortestPath(r-1,c-1);
    cout << res << endl;
    return 0;
}
