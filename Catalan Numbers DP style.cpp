#define ll long long               /// MACROS NEEDED
#define LIM 1005                   /// MACROS NEEDED
#define mod 1000000007             /// MACROS NEEDED

ll catalan[LIM];
void cata()
{
    catalan[0] = 1, catalan[1] = 1;  /// Two Base Cases
    for(ll i = 2; i <= LIM; i++){
        ll sum = 0;
        for(ll j = 0; j < i; j++){
            sum += (catalan[j]*catalan[i-j-1])%mod;  /// As, catalan[i] = sum_of(catalan[j]*catalan[i-j-1])
            sum %= mod;  /// Answer with mod 1e9+7
        }
        catalan[i] = sum;
    }
}
