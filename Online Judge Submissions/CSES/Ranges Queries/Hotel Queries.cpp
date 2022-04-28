#include <bits/stdc++.h>
using namespace std;
#define MAX 200005
#define left st, (st + en) / 2, nd + nd
#define right (st + en) / 2 + 1, en, nd + nd + 1
#define nl "\n"
int tree[4 * MAX + 5];
int n, arr[MAX + 5];

void build(int st, int en, int nd)
{
    if(st == en)
    {
        tree[nd] = arr[st];
        return;
    }
    build(left); /// left subtree
    build(right); /// right subtree
    tree[nd] = max(tree[nd + nd], tree[nd + nd + 1]);
}

int query(int st, int ed, int nd, int v)
{
    if(tree[nd] < v) return -1;

    if(st == ed){
        tree[nd] -= v;
        return st;
    }

    int md = st + (ed - st)/2, ret;
    if(tree[nd + nd] >= v) ret = query(st, md, nd + nd, v);
    else ret = query(md + 1, ed, nd + nd + 1, v);

    tree[nd] = max(tree[nd + nd], tree[nd + nd + 1]);

    return ret;
}

int main()
{
    int m;

    cin >> n >> m;
    for(int i = 0; i < n; i++)
        cin >> arr[i];

    build(0, n - 1, 1);

    for(int i = 0; i < m; i++){
        int x;
        cin >> x;
        int idx = query(0, n - 1, 1, x);
        cout << idx + 1 << " ";
    }
    cout << nl;

    return 0;
}
