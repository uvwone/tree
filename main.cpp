#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int A[100][100], Cnt[100], n;

int dy[4] = { 0, 1, 0, -1};
int dx[4] = { 1, 0, -1, 0};

bool safe(int y, int x)
{
    return (0<=y && y<n) && (0<=x && x<n);
}


void dfs(int y, int x, int danjiNo)
{
    Cnt[danjiNo] ++;
    A[y][x] = 0;

    for(int i=0,yy,xx; i<4; i++)
    {
        yy = y + dy[i];
        xx = x + dx[i];
        if(safe(yy,xx) && A[yy][xx] == 1) {
            dfs(yy,xx,danjiNo);
        }
    }
}


void dfs1(int y, int x, int danjiNo)
{
    if(A[y][x] != 1) return;

    Cnt[danjiNo] ++;
    A[y][x] = 0;

    if(x<n-1) dfs(y,x+1,danjiNo);
    if(y<n-1) dfs(y+1,x,danjiNo);
    if(x>0) dfs(y,x-1,danjiNo);
    if(y>0) dfs(y-1,x,danjiNo);
}

int main()
{

    cin >> n;
    int danjiCnt = 0;
    for(int y = 0; y<n; y++) for(int x = 0; x<n; x++) cin >> A[y][x];
    for(int y = 0; y<n; y++) for(int x = 0; x<n; x++) if(A[y][x] == 1)
    {
        dfs(y,x,danjiCnt++);
    }

    cout << danjiCnt << endl;
    sort(Cnt,Cnt+danjiCnt,greater<int>());
//    sort(&Cnt[0],&Cnt[danjiCnt],greater<int>());
    for(int i=0; i<danjiCnt; i++) cout << Cnt[i] << endl;

    return 0;
}
