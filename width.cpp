#include <iostream>
#include <algorithm>
#include <vector>
#define NN 10000

using namespace std;

struct Node
{
    int par;
    int left,right;
} nd[NN];

int root,cnt=0;
int minD[NN], maxD[NN], maxdep = 0;

int GetRoot(int idx)
{
    if(nd[idx].par == 0) return idx;
    return GetRoot(nd[idx].par);
}

void inorder(int idx, int dep)
{
    if(nd[idx].left  != -1) inorder(nd[idx].left, dep+1);
    cnt++;
    minD[dep] = min(minD[dep],cnt);
    maxD[dep] = max(maxD[dep],cnt);
    maxdep = max(maxdep,dep);

    if(nd[idx].right != -1) inorder(nd[idx].right, dep+1);
}

int main()
{
    int n;  cin >> n;
    for(int i=1, a,b,c; i<=n; i++)
    {
        minD[i] = 1e9;
        cin >> a >> b >> c;
        nd[a].left = b;
        nd[a].right = c;
        if(b != -1) nd[b].par = a;
        if(c != -1) nd[c].par = a;
    }

    root = GetRoot(1);

    inorder(root, 1);

    int gab=0, dep;
    for(int i=1; i<=maxdep; i++)
    {
        if(gab < maxD[i]-minD[i]+1) {
        gab = maxD[i]-minD[i]+1;
        dep = i;
        }
    }
    cout << dep << ' ' << gab;
    return 0;
}
