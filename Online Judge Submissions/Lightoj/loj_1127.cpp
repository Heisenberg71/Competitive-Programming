#include <bits/stdc++.h>
#define ll long long
#define pb push_back
using namespace std;

ll n, capa;
vector <ll> arr, brr, ans, ans2;

bool check(ll mask, ll pos) { return mask & (1 << pos); }

ll bs(ll val)
{
    ll lo = 0, hi = ans2.size() - 1, md, ans = ans2.size();
    while(lo <= hi){
        md = lo + (hi - lo) / 2;
        if(ans2[md] <= val){
            lo = md + 1;
        }
        else{
            ans = md;
            hi = md - 1;
        }
    }
    return ans;
}

ll f()
{
    ll mask, pos, i;
    for(mask = 0; mask < (1 << arr.size()); mask++){
        ll res = 0;
        for(pos = 0; pos < arr.size(); pos++){
            if(check(mask, pos))
                res += arr[pos];
        }
        ans.pb(res);
    }
    for(mask = 0; mask < (1 << brr.size()); mask++){
        ll res = 0;
        for(pos = 0; pos < brr.size(); pos++){
            if(check(mask, pos))
                res += brr[pos];
        }
        ans2.pb(res);
    }
    sort(ans2.begin(), ans2.end());

//    cout << "ans" << endl;
//    for(i = 0; i < ans.size(); i++)
//        cout << ans[i] << " ";
//    cout << endl;
//
//    cout << "ans2" << endl;
//    for(i = 0; i < ans2.size(); i++)
//        cout << ans2[i] << " ";
//    cout << endl;

    ll cnt = 0;
    for(i = 0; i < ans.size(); i++)
        cnt += bs(capa - ans[i]);

    return cnt;
}

int main()
{
    ll t, cas = 1, i, x;
    cin >> t;
    while(t--){
        cin >> n >> capa;
        for(i = 0; i < n; i++){
            cin >> x;
            if(i%2) arr.pb(x);
            else brr.pb(x);
        }
        printf("Case %lld: %lld\n",cas++, f());

        arr.clear(), brr.clear(), ans.clear(), ans2.clear();
    }
    return 0;
}
