#include <iostream>

using namespace std;

int n,A[100][100], DanjiCnt[100];

void dfs(int x, int y, int no)
{
    if(A[y][x] != 1) return;

    DanjiCnt[no]++;
    A[y][x] = 0;

    dfs(x+1,y);
    dfs(x,y+1);
    dfs(x-1,y);
    dfs(x+1,y-1);
}


int main()
{
    cin >> n;
    int cnt=0;
    for(int y=1; y<=n; y++)for(int x=1; x<=n; x++) cin >> A[y][x];
    for(int y=1; y<=n; y++)for(int x=1; x<=n; x++)
    {
        if(A[y][x] == 1)  dfs(x,y,cnt++);
    }
    return 0;
}
