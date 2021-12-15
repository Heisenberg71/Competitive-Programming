#include <bits/stdc++.h>
#define ll long long
#define LIM 150005
using namespace std;

int n, arr[LIM + 5], tree[4*LIM + 5];

void build(int st, int ed, int nd)
{
    if(st == ed){
        if(arr[st]) tree[nd] = 1;
        else tree[nd] = 0;
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
        //cout << "pos: " << pos << endl;
        if(arr[pos]) tree[nd] = 1;
        else tree[nd] = 0;
        return;
    }

    int md = st + (ed - st)/2;
    update(st, md, nd + nd, pos, val);
    update(md + 1, ed, nd + nd + 1, pos, val);

    tree[nd] = tree[nd + nd] + tree[nd + nd + 1];
}

int query(int st, int ed, int nd, int L, int R)
{
    if(ed < L || R < st) return 0;

    if(L <= st && ed <= R) return tree[nd];

    int md = st + (ed - st)/2;
    int Left = query(st, md, nd + nd, L, R);
    int Right = query(md + 1, ed, nd + nd + 1, L, R);
    return Left + Right;
}

int bs(int val)
{
    int lo = 1, hi = LIM, md, ans = -1;
    while(lo <= hi){
        md = lo + (hi - lo)/2;
        int prefix = query(1, LIM, 1, 1, md);
        if(prefix >= val){
            ans = md;
            hi = md - 1;
        }
        else lo = md + 1;
    }
    return ans;
}

int main()
{
    int t, cas = 1, q;
    scanf("%d", &t);
    while(t--){
        scanf("%d %d", &n, &q);
        int tot = n + q;
        for(int i = 1; i <= n; i++)
            scanf("%d", &arr[i]);
        build(1, LIM, 1);
        //cout << "query: " << query(1, LIM, 1, 1, n) << endl;
        printf("Case %d:\n", cas++);
        int last = n;
        while(q--){
            char ch;
            int val;
            scanf(" %c %d", &ch, &val);
            if(ch == 'a'){
                last++;
                arr[last] = val;
                update(1, LIM, 1, last, val);
                //cout << arr[last] << endl;
            }
            else{
                int idx = bs(val);
                if(idx == -1) printf("none\n");
                else{
                    printf("%d\n", arr[idx]);
                    //cout << idx << endl;
                    arr[idx] = 0;
                    update(1, LIM, 1, idx, 0);
                }
            }
            //cout << "query: " << query(1, LIM, 1, 1, 5) << endl;
        }

        for(int i = 0; i <= tot; i++)
            arr[i] = 0;
        for(int i = 0; i <= 4*tot + 5; i++)
            tree[i] = 0;
    }

    return 0;
}
