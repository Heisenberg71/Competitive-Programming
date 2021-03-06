ll dp[15][5][5][5], dp2[15][5][5];
ll f2(ll pos, ll issmall, ll num)
{
    if(pos == s[num].size()) return 1;
    if(dp2[pos][issmall][num] != -1) return dp2[pos][issmall][num];
    ll lo = 0, hi = s[num][pos]-'0', sum = 0;
    if(issmall) hi = 9;
    for(; lo <= hi; lo++){
        sum += f2(pos+1,issmall | (lo<hi), num);
    }
    return dp2[pos][issmall][num] = sum;
}
ll f(ll pos, ll issmall, ll hasstarted, ll num)
{
    if(pos == s[num].size()) return 0;
    if(dp[pos][issmall][hasstarted][num] != -1) return dp[pos][issmall][hasstarted][num];
    ll lo = 0, hi = s[num][pos]-'0', sum = 0;
    if(issmall) hi = 9;
    for(; lo <= hi; lo++){
        ll tem = f(pos+1, issmall | (lo<hi), hasstarted | (lo != 0), num);
        if(hasstarted and lo == 0) tem += f2(pos+1,issmall | (lo<hi),num);
        sum += tem;
    }
    return dp[pos][issmall][hasstarted][num] = sum;
}
