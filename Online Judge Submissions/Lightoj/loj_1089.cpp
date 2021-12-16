#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define ff first
#define ss second
#define pii pair<int, int>
#define LIM 150005
using namespace std;

int tree[4*LIM];
vector <pii> ranges;
map <int, int> mp;
vector <int> place, v;

void update(int st, int ed, int nd, int L, int R)
{
    if(ed < L || R < st) return;

    if(L <= st && ed <= R){
        tree[nd]++;
        return;
    }

    int md = st + (ed - st)/2;
    update(st, md, nd + nd, L, R);
    update(md + 1, ed, nd + nd + 1, L, R);
}

int query(int st, int ed, int nd, int idx)
{
    if(idx < st || ed < idx) return 0;
    if(st == ed) return tree[nd];

    int md = st + (ed - st)/2;
    return tree[nd] + query(st, md, nd + nd, idx) + query(md + 1, ed, nd + nd + 1, idx);
}

int findPos(int val)
{
    int lo = 0, hi = place.size() - 1, md;
    while(lo <= hi){
        md = lo + (hi - lo)/2;
        if(place[md] == val) return md;
        else if(place[md] < val) lo = md + 1;
        else hi = md - 1;
    }
}

void getVal(int n)
{
    if(mp[n] == 0){
        mp[n] = 1;
        place.pb(n);
    }
}

void reset(int tot)
{
    memset(tree, 0, sizeof tree);
    mp.clear();
    v.clear();
    ranges.clear();
    place.clear();
}

int main()
{
    int t, cas = 1, n, q;
    scanf("%d", &t);
    while(t--){
        scanf("%d %d", &n, &q);
        int tot = 2*n + q;
        for(int i = 0; i < n; i++){
            int L, R;
            scanf("%d %d", &L, &R);
            ranges.push_back({L, R});
            getVal(L), getVal(R);
        }
        while(q--){
            int pos;
            scanf("%d", &pos);
            v.pb(pos);
            getVal(pos);
        }
        place.pb(-1);
        sort(place.begin(), place.end());
        for(int i = 0; i < ranges.size(); i++){
            update(1, LIM, 1, findPos(ranges[i].ff), findPos(ranges[i].ss));
        }
        printf("Case %d:\n", cas++);
        for(int i = 0; i < v.size(); i++)
            printf("%d\n", query(1, LIM, 1, findPos(v[i])));

        reset(tot);
    }

    return 0;
}
