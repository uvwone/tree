#include <iostream>
#include <algorithm>
#include <set>
#include <stdio.h>

using namespace std;

set<int> cld[100];
int vis[100] = {};

void dfs(int p)
{
    if(vis[p] == 1) return;
    cout << p << ' ';
    vis[p] = 1;

    for(int q : cld[p])
    {
        dfs(q);
    }
}

int main()
{
//    freopen("a.txt","r",stdin);
    int n,s; cin >> n >> s;
    for(int a,b; cin >> a >> b;)
    {
        cld[a].insert(b);
        cld[b].insert(a);
    }

    dfs(s);

    return 0;
}
