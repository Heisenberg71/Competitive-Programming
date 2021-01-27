ll ncr[1005][1005];
void precal()
{
    ll i, j;
    for(i = 0; i < 1005; i++)
        ncr[i][0] = 1;
    for(i = 1; i < 1005; i++)
            for(j = 1; j < 1005; j++)
              ncr[i][j] = (ncr[i-1][j]+ncr[i-1][j-1])%mod;
}
