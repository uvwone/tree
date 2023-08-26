#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int A[100][100], Cnt[100], N, M;
pair<int,int> S,G;

int dy[4] = { 0, 1, 0, -1};
int dx[4] = { 1, 0, -1, 0};

bool safe(int y, int x)
{
    return (0<=y && y<M) && (0<=x && x<N);
}


void prt()
{
    cout <<endl;
    for(int y=0; y<N; y++) {
        for(int x=0; x<M; x++){
            printf("%3d",A[y][x]);
        }
        cout <<endl;
    }
}


void dfs(int y, int x, int num)
{
    A[y][x] = num;

    prt();
    if(y == G.first && x == G.second) return;

    for(int i=0,yy,xx; i<4; i++)
    {
        yy = y + dy[i];
        xx = x + dx[i];
        if(safe(yy,xx) && (A[yy][xx] == 0 || A[yy][xx] > num+1)) {
            dfs(yy,xx,num+1);
        }
    }
}


void dfs1(int y, int x, int danjiNo)
{
    if(A[y][x] != 0) return;

    Cnt[danjiNo] ++;
    A[y][x] = 1;

    if(x<N-1) dfs(y,x+1,danjiNo);
    if(y<M-1) dfs(y+1,x,danjiNo);
    if(x>0) dfs(y,x-1,danjiNo);
    if(y>0) dfs(y-1,x,danjiNo);
}

int main()
{

    cin >> N >> M;
    S = {N-1,0}, G={0,M-1};
    string s;

    for(int y = 0; y<N; y++) {
        cin >> s;
        for(int x = 0; x<M; x++) if(s[x] == '1') A[y][x] = -1;
    }

    prt();
    dfs(S.first,S.second,1);

    cout << A[G.first][G.second] << endl;
    return 0;
}
