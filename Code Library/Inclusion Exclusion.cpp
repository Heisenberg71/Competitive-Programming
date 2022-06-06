ll inclusionExclusion(ll n)
{
    ll ans = 0;
    for(ll i = 1; i < (1LL << prime.size()); i++){
        if(__builtin_popcountll(i)%2){
            ll val = 1;
            for(ll pos = 0; pos < prime.size(); pos++){
                if((i&(1LL << pos))) val *= prime[pos];
            }
            ans += n/val;
        }
        else{
            ll val = 1;
            for(ll pos = 0; pos < prime.size(); pos++){
                if((i&(1LL << pos))) val *= prime[pos];
            }
            ans -= n/val;
        }
    }
    return n - ans;
}
