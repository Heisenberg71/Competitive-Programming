#define ll long long  /// MACRO NEEDED
#define LIM 10005     /// MACRO NEEDED
#define mod 100000007 /// MACRO NEEDED
#define pb push_back  /// MACRO NEEDED
#define ff first      /// MACRO NEEDED
#define ss second     /// MACRO NEEDED

bool status[LIM]; /// NEED A GLOBAL ARRAY
vector <int> prime;
vector <pair<int,int> > prime_pow;

void make_prime(int N)
{
    int i, j, sqrtN;
    status[0] = 1, status[1] = 1;
    sqrtN = int( sqrt((double) N )) + 1; /// have to check primes up to (sqrt(N))
    for(i = 4; i <= N; i+=2) status[i] = 1;
    for(i = 3; i <= sqrtN; i+= 2){  /// so, i is a prime, so, discard all the multiples
        if(status[i] == 0){
            for(j = i*i; j <= N; j+=i+i) /// j = i * i, because it's the first number to be colored
                status[j] = 1;
        }
    }
    for(i = 0; i < LIM; i++) if(status[i] == 0) prime.pb(i);
    //for(i = 0; i < 10000005; i++) cout << v[i] << endl;
}

void factor(int n)
{
    for(int i = 0; i < prime.size() && prime[i]*prime[i] <= n; i++){
        int cnt = 0;
        while(n%prime[i] == 0){
            n /= prime[i];
            cnt++;
        }
        if(cnt) prime_pow.pb({prime[i], cnt*m});
    }
    if(n != 1) prime_pow.pb({n, 1*m});
}
