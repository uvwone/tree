#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

string a, b;
char c[1000];
map<char,int> bpos;

void preorder(int idx, char ch)
{
    if(c[idx] == 0)
    {
        c[idx] = ch;
        return;
    }

    if(bpos[ch] < bpos[c[idx]]) preorder(idx * 2, ch);
    else preorder(idx * 2 + 1, ch);
}

void postorder(int idx)
{
    if(a[idx] == 0) return;
    postorder(idx*2);
    postorder(idx*2+1);
    cout << c[idx];
}

int main()
{
    cin >> a >> b;
    for(int i = 0; i < a.size(); i++) bpos[a[i]] = i;
    for(int i = 0; i < b.size(); i++) preorder(1,b[i]);
    postorder(1);
    return 0;
}
