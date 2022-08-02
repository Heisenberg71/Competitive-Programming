#include <bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>

#define ll long long
#define ull unsigned long long
#define pb push_back
#define pii pair<int, int>
#define ff first
#define ss second
#define nl '\n'
#define mod 1000000007
#define inf 1000000009
#define MAXX 1000000000000015
#define LIM 1000006 /// changed
#define LIMM 100005
#define eps 1e-9
#define pi acos(-1)

#define left st, (st + en) / 2, nd + nd
#define right (st + en) / 2 + 1, en, nd + nd + 1

using namespace std;
//using namespace __gnu_pbds;

//#define ordered_set tree<pii, null_type,less<pii>, rb_tree_tag, tree_order_statistics_node_update>

void FAST_IO() { ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0); }

/**

Notes:


*/

int freq[LIM], fact[LIM], status[LIM], extra[LIMM];
int tree[4*LIMM];

vector <int> primeFactor[LIM], prime, hasFactor[LIM];
unordered_map <int, int> primeMap;

void findFact()
{
    for(int i = 2; i < LIM; i++){
        if(!status[i]){
            prime.pb(i);
            for(int j = i; j < LIM; j += i){
                fact[i] += freq[j];
                if(i != j) status[j] = 1;
                primeFactor[j].pb(i);

                int cnt = freq[j];
                while(cnt--) hasFactor[i].pb(j);
            }
        }
    }
    for(int i = 0; i < prime.size(); i++){
        primeMap[ prime[i] ] = i;
        extra[i] = fact[ prime[i] ];
    }
}

void build(int st, int en, int nd)
{
    if(st == en)
    {
        tree[nd] = extra[st];
        return;
    }
    build(left); /// left subtree
    build(right); /// right subtree
    tree[nd] = max(tree[nd + nd], tree[nd + nd + 1]);
}

int query(int st, int en, int nd, int L, int R)
{
    if(L <= st && en <= R) return tree[nd]; /// if the query segment is completely overlapping our tree segment/node.
    if(en < L || R < st) return -inf;
    return max(query(left, L, R), query(right, L, R));
}

void update(int st, int en, int nd, int idx, int v)
{
    if(en < idx || idx < st) return;
    if(st == en)
    {
        tree[nd] += v;
        return;
    }
    update(left, idx, v);
    update(right, idx, v);
    tree[nd] = max(tree[nd + nd], tree[nd + nd + 1]);
}

int findY(int st, int en, int nd, int L, int R, int val)
{
    if(st == en) return st;

    if(val == tree[nd + nd]) return findY(left, L, R, val);
    return findY(right, L, R, val);
}

int main()
{
    ///MUST READ THE POINTS BELOW BEFORE SUBMIT

    //FAST_IO();

    int n;

    cin >> n;
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        freq[x]++;
    }

    findFact();
    build(0, LIMM - 1, 1);

    int ans = 0, ansx = 2, ansy = 2;
    for(int k = 0; k < prime.size(); k++){

        int x = prime[k];
        for(int j = 0; j < hasFactor[x].size(); j++){
            int y = hasFactor[x][j];
            for(int i = 0; i < primeFactor[y].size(); i++){
                update(0, LIMM - 1, 1, primeMap[ primeFactor[y][i] ], -1);
            }
        }

        int value = query(0, LIMM - 1, 1, 0, LIMM - 1);
        if(ans < fact[x] + value){
            ans = fact[x] + value;
            ansx = x;
            ansy = prime[ findY(0, LIMM - 1, 1, 0, LIMM - 1, ans - fact[x]) ];
        }

        for(int j = 0; j < hasFactor[x].size(); j++){
            int y = hasFactor[x][j];
            for(int i = 0; i < primeFactor[y].size(); i++){
                update(0, LIMM - 1, 1, primeMap[ primeFactor[y][i] ], 1);
            }
        }

    }

    cout << n - ans << nl;
    if(ansy <= 1) ansy = 2;
    cout << ansx << " " << ansy << nl;

    return 0;
    ///MUST READ THE POINTS BELOW BEFORE SUBMIT
}
/**
    1. READ PROBLEM STATEMENT CAREFULLY.
    2. LOOK SPECIAL CASE (LIKE, N = 1).
    3. LOOK FOR OVERFLOW.
    4. LOOK FOR OUT OF BOUNDS.
    5. DO NOT STUCK WITH A SINGLE APPROACH.
    6. THINK OUT OF THE BOX.
**/
