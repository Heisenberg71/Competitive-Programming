#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define LIM 1429436
using namespace std;

int arr[LIM], tree[4*LIM];
vector <int> ans;

void build(int st, int ed, int nd)
{
    if(st == ed){
        tree[nd] = arr[st];
        return;
    }

    int md = st + (ed - st)/2;
    build(st, md, nd + nd);
    build(md + 1, ed, nd + nd + 1);

    tree[nd] = tree[nd + nd] + tree[nd + nd + 1];
}

void update(int st, int ed, int nd, int pos, int val)
{
    if(pos < st || ed < pos) return;

    if(st == ed){
        tree[nd] = val;
        return;
    }

    int md = st + (ed - st)/2;
    update(st, md, nd + nd, pos, val);
    update(md + 1, ed, nd + nd + 1, pos, val);

    tree[nd] = tree[nd + nd] + tree[nd + nd + 1];
}

int query(int st, int ed, int nd, int gap)
{
    if(st == ed) return st;

    int md = st + (ed - st)/2;
    if(gap <= tree[nd + nd]) query(st, md, nd + nd, gap);
    else query(md + 1, ed, nd + nd + 1, gap - tree[nd + nd]);
}

void precal()
{
    for(int i = 1; i <= LIM; i += 2)
        arr[i] = 1;

    build(1, LIM, 1);

    for(int i = 2; i <= LIM; i++){
        if(tree[1] < i) break;
        int gap = query(1, LIM, 1, i);
//        cout << "gap: " << gap << endl;
        vector <int> kill;
        for(int j = gap; j <= LIM; j += gap){
            if(tree[1] < j) break;
            int pos = query(1, LIM, 1, j);
            kill.pb(pos);
        }
        for(int j = 0; j < kill.size(); j++)
            update(1, LIM, 1, kill[j], 0);
    }

//    for(int i = 1; i <= 10; i++)
//        cout << query(1, LIM, 1, i) << " ";
//    cout << endl;
}

int main()
{
    precal();

    int t, cas = 1, n;
    scanf("%d", &t);
    while(t--){
        scanf("%d", &n);
        printf("Case %d: %d\n", cas++, query(1, LIM, 1, n));
    }

    return 0;
}
