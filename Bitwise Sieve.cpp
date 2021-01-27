int status[LIM/32+5];
vector <int> v;
bool check(int n, int pos){ return (bool)(n & (1<<pos));}
int mark(int n, int pos){ return n = (n | (1<<pos));}
void make_prime()
{
    int i, j, sq;
    sq = sqrt(LIM);
    for(i = 3; i <= sq; i+=2){
        if(check(status[i/32],i%32) == 0){
            for(j = i*i; j <= LIM; j += i+i){
                status[j/32] = mark(status[j/32],j%32);
            }
        }
    }
    v.pb(2);
    for(i = 3; i <=LIM; i+=2){
             if(check(status[i/32],i%32) == 0)
            v.pb(i);
    }
}
