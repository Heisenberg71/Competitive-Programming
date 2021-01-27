ll eulerPhi(ll n)
{
    ll res = n;
    ll sqrtn = sqrt(n);
    for(ll i = 0; i <= sqrtn; i++){
        if(n%v[i] == 0){
            while(n%v[i] == 0)
                n /= v[i];
            sqrtn = sqrt(n);
            res /=  v[i];
            res *= v[i]-1;
        }
    }
    if(n != 1){
        res /= n;
        res *= n-1;
    }
    return res;
}
