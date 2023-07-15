#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int a[10000];

void preorder(int idx)
{
    cin >> a[idx];
    if(a[idx] == -1) return;
    preorder(idx*2);
    preorder(idx*2+1);
}

void postorder(int idx)
{
    if(a[idx] == -1) return;
    postorder(idx*2);
    postorder(idx*2+1);
    cout << a[idx] <<' ';
}

int main()
{
    preorder(1);
    postorder(1);
    return 0;
}
