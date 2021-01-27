bool status[LIM+5];
ll nod[LIM+5];
void NOD()
{
    ll i, j, tem, cnt;
    for(i = 0; i <= LIM; i++)
        nod[i] = 1;
    for(i = 4; i <= LIM; i+=2){
        status[i] = 1;
        tem = i;
        cnt = 0;
        while(tem%2 == 0){
            tem /= 2;
            cnt++;
        }
        nod[i] *= (cnt+1);
    }
    for(i = 3; i <= LIM; i+=2){
        if(status[i] == 0){
            for(j = i+i; j <= LIM; j += i){
                status[j] = 1;
                tem = j;
                cnt = 0;
                while(tem%i == 0){
                    tem /= i;
                    cnt++;
                }
                nod[j] *= (cnt+1);
            }
        }
    }
    nod[0] = 0, nod[1] = 1;
}
