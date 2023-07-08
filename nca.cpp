#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct NODE
{
    int par;
    vector<int> cld;

    int no,dep,wei;
};

NODE nd[1000];
int x,y;


void dfs(int p, int dep)
{
    nd[p].dep = dep;
    for(auto q : nd[p].cld)
    {
        dfs(q,dep+1);
    }
}

int find_root(int me)
{
    if(nd[me].par == 0) return me;
    return find_root(nd[me].par);
}

int nca()
{
    if(nd[x].dep < nd[y].dep) swap(x,y);
    while(nd[x].dep != nd[y].dep) x = nd[x].par;
    while(x != y) x = nd[x].par, y = nd[y].par;
    return x;
}

int main()
{
    int d;
    cin >> d;
    for(int i = 1, a,b; i < d; i++)
    {
        cin >> a >> b;
        nd[a].cld.push_back(b);
        nd[b].par = a;
    }
    cin >> x >> y;

    int root = find_root(x);
    dfs(root,0);
    cout << nca();

    return 0;
}
