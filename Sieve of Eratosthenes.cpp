bool status[10000005]; /// NEED A GLOBAL ARRAY
vector <int> v;
void make_primes(int N)
{
    int i, j, sqrtN;
    status[0] = 1, status[1] = 1;
    sqrtN = int( sqrt((double) N )); /// have to check primes up to (sqrt(N))
    for(i = 4; i <= N; i+=2) status[i] = 1;
    for(i = 3; i <= sqrtN; i+= 2){  /// so, i is a prime, so, discard all the multiples
        if(status[i] == 0){
            for(j = i*i; j <= N; j+=i+i) /// j = i * i, because it's the first number to be colored
                status[j] = 1;
        }
    }
    for(i = 0; i < 10000005; i++) if(status[i] == 0) v.pb(i);
    //for(i = 0; i < 10000005; i++) cout << v[i] << endl;
}
