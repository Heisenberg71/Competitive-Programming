#include <bits/stdc++.h>
#define ll long long
#define LIM 100005
#define left st, (st + ed) / 2, nd + nd
#define right (st + ed) / 2 + 1, ed, nd + nd + 1
using namespace std;

ll arr[LIM], tree[4*LIM], lazy[4*LIM];

void build(ll st, ll ed, ll nd)
{
    if(st == ed)
    {
        tree[nd] = arr[st];
        return;
    }
    build(left); /// left subtree
    build(right); /// right subtree

    tree[nd] = tree[nd + nd] + tree[nd + nd + 1];
}

void update(ll st, ll ed, ll nd, ll L, ll R, ll val)
{
    if(lazy[nd] != 0){  /// IF ANY UPDATE IS PENDING
        tree[nd] += (ed - st + 1)*lazy[nd]; /// UDPATE THE TREE
        if(st != ed){
            lazy[nd + nd] += lazy[nd];  /// PROPAGATE PENDING UPDATES TO THE LEFT CHILD
            lazy[nd + nd + 1] += lazy[nd];  /// PROPAGATE PENDING UPDATES TO THE RIGHT CHILD
        }
        lazy[nd] = 0;   /// ALL PENDINGS ARE CLEAR
    }

    if(ed < L or R < st) return;    /// INVALID STATE

    if(L <= st and ed <= R){
        tree[nd] += (ed - st + 1)*val;  /// UPDATE THE RANGE WITH THE INSERTED VALUE 'val'
        if(st != ed){
            lazy[nd + nd] += val;   /// PROPAGATE PENDING UPDATES TO THE LEFT CHILD
            lazy[nd + nd + 1] += val;/// PROPAGATE PENDING UPDATES TO THE RIGHT CHILD
        }
        return;
    }
    update(left, L, R, val);    /// UPDATE LEFT CHILD
    update(right, L, R, val);   /// UPDATE RIGHT CHILD

    tree[nd] = tree[nd + nd] + tree[nd + nd + 1];   /// KEEP THE ANSWERS OF CHILDS IN PARANT NODE

}

ll query(ll st, ll ed, ll nd, ll L, ll R)
{
    if(ed < L or R < st) return 0;  /// INVALID STATE

    if(lazy[nd] != 0){  /// IF ANY UPDATE IS PENDING
        tree[nd] += (ed - st + 1)*lazy[nd]; /// UPDATE THE TREE
        if(st != ed){
            lazy[nd + nd] += lazy[nd];  /// PROPAGATE PENDING UPDATES TO THE LEFT CHILD
            lazy[nd + nd + 1] += lazy[nd]; /// PROPAGATE PENDING UPDATES TO THE RIGHT CHILD
        }
        lazy[nd] = 0;   /// ALL PENDINGS ARE CLEAR
    }

    if(L <= st and ed <= R){
        return tree[nd];    /// OVERLAPPED STATE
    }

    return query(left, L, R) + query(right, L, R);  /// KEEP THE ANSWERS OF CHILDS IN PARANT NODE
}
