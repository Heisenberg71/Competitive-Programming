#include<bits/stdc++.h>
#define ll long long int
using namespace std;

ll arr[100005];
ll cnt[100005];

int big_mod(ll base,ll power,ll mod)
{
    if(power==0) return 1;
    else if(power%2==1)
    {
        long long int p1=base%mod;
        long long int p2=(big_mod(base,power-1,mod))%mod;
        return (p1*p2)%mod;
    }
    else
    {
        long long int p1=(big_mod(base,power/2,mod))%mod;
        return (p1*p1)%mod;
    }
}

int main()
{
    ll n;
    cin>>n;

    memset(cnt,0,sizeof cnt);

    for(ll i=0; i<n; i++)
    {
        cin>>arr[i];
        ll x=arr[i];

        ll r=sqrt(x);

        for(ll j=1; j<=r; j++)
        {
            if(x%j==0)
            {
                ll d1=j;
                ll d2=x/j;

                if(d1==d2)
                {
                    ll k=arr[i]/d1;
                    if(k>=d1)
                    {
                        cnt[d1]++;
                    }
                }
                else
                {
                    ll k1=arr[i]/d1;
                    ll k2=arr[i]/d2;

                    if(k1>=d1)
                    {
                        cnt[d1]++;
                    }

                    if(k2>=d2)
                    {
                        cnt[d2]++;
                    }
                }
            }
        }
    }

    ll ans=0;

    for(ll i=0; i<n; i++)
    {
        ll x=arr[i];
        ll p=cnt[x];
        ll mod=1000000007;

        ll a=big_mod(2LL,p,mod)%mod;
        a--;

        ans=ans+a;

        ans=ans%mod;

    }

    cout<<ans<<endl;
}
