
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define ll long long
#define ull unsigned long long
#define pb push_back
#define pii pair<int, int>
#define pll pair<ll, ll>
#define ff first
#define ss second
#define nl '\n'
#define mod 1000000007
#define inf 1000000009
#define MAXX 1000000000000015
#define LIM 1000006 /// changed
#define eps 1e-9
#define pi acos(-1)

using namespace std;
using namespace __gnu_pbds;

#define ordered_set tree<int, null_type,less<int>, rb_tree_tag, tree_order_statistics_node_update>

void FAST_IO() { ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0); }

/**

Notes:


*/

//bool inside(int x, int y, int h, int w)
//{
//    if(x >= 0 && x < h && y >= 0 && y < w && grid[x][y] != '#') return 1;
//    return 0;
//}

vector <pii> v;
string str;
int ans, vis[LIM];
int h, w;

int findLeft(int idx)
{
    //cout << idx << nl;
    if(idx == 0 || v[idx - 1].ff != v[idx].ff) return -1;
    return idx - 1;
}

int findRight(int idx)
{
    if(idx + 1 == v.size() || v[idx + 1].ff != v[idx].ff) return -1;
    return idx + 1;
}

int findUp(int idx)
{
    if(idx - w < 0) return -1;
    return idx - w;
}

int findDown(int idx)
{
    if(idx + w >= v.size()) return -1;
    return idx + w;
}

void dfs(int idx, int par)
{
    if(vis[idx] == 2) return;
    if(vis[idx] == 1){
        if(str[idx] == 'S') ans = 1;
        return;
    }

    //cout << v[idx].ff << " " << v[idx].ss << nl;

    vis[idx] = 1;
    for(int i = 0; i < 4; i++){
        int Left = findLeft(idx);
        //cout << "K" << Left << nl;
        int Right = findRight(idx);
        int Up = findUp(idx);
        int Down = findDown(idx);

        if(Left != par && Left != -1 && str[Left] != '#') dfs(Left, idx);
        if(Right != par && Right != -1  && str[Right] != '#') dfs(Right, idx);
        if(Up != par && Up != -1  && str[Up] != '#') dfs(Up, idx);
        if(Down != par && Down != -1  && str[Down] != '#') dfs(Down, idx);

//        if(Left != -1 && vis[Left] == 1 && str[Left] == 'S') ans = 1;
//        if(Right != -1 && vis[Right] == 1 && str[Right] == 'S') ans = 1;
//        if(Up != -1 && vis[Up] == 1 && str[Up] == 'S') ans = 1;
//        if(Down != -1 && vis[Down] == 1 && str[Down] == 'S') ans = 1;
    }

    vis[idx] = 2;
}

int main()
{
    ///MUST READ THE POINTS BELOW BEFORE SUBMIT

    FAST_IO();

    cin >> h >> w;

    int vis[h + 5][w + 5];
    char grid[h + 5][w + 5];

    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++){
            char ch;
            cin >> ch;
            str += ch;
            v.pb({i, j});
        }
    }
    //cout << str << nl;

    ans = 0;
    for(int i = 0; i < w*h; i++){
        if(str[i] == 'S'){
            dfs(i, -1);
        }
    }

    if(ans) cout << "Yes" << nl;
    else cout << "No" << nl;

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
