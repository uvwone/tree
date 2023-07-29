#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int a[1000], maxdep=0, cnt=0;

void Action1()
{

}

void Action2()
{

}

void preorder(int idx, int dep)
{
    cin >> a[idx];
    if(a[idx] == -1) return;
    preorder(idx*2, dep+1);
    preorder(idx*2+1, dep+1);
}

void postorder(int idx, int dep)
{
    if(a[idx] == -1) return;
    postorder(idx*2, dep+1);
    postorder(idx*2+1, dep+1);
    maxdep = max(maxdep, dep);

    if(a[idx*2] != -1 && a[idx*2 + 1] != -1) cnt++;
    cout << cnt;
}

int main()
{
    preorder(1,1);
    postorder(1,1);
    return 0;
}
