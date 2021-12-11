void sg_sieve(ll m, ll n)
{
    ll i;
    memset(status2,0,sizeof status2);
    for(i = 0; v[i]*v[i] <= n; i++){
        ll tem = (m+v[i]-1)/v[i];
        ll sg = tem*v[i];
        if(sg == v[i]) sg += v[i];
        for(ll st = sg; st <= n; st += v[i]){
            status2[st-m+1] = 1;
        }
    }
    for(i = m ; i <= n; i++){
        if(status2[i-m+1] == 0 and i != 1) cout << i << endl;
    }
    cout << endl;
}
