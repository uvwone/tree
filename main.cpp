#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> cld[100];
int vis[100] = {};
int ans=0;

void dfs(int p)
{
    if(vis[p] == 1) return;
    if(p != 1) ans++; //, cout << p << ' ';
    vis[p] = 1;

    for(int q : cld[p])
    {
        cld[q].erase(find(cld[q].begin(),cld[q].end(),p));
        dfs(q);
    }
}


int main()
{
    int n, m; cin >> n >> m;

    for(int a,b; m--;)
    {
        cin >> a >> b;
        cld[a].push_back(b);
        cld[b].push_back(a);
    }
    dfs(1);

    cout << ans;
    return 0;
}
