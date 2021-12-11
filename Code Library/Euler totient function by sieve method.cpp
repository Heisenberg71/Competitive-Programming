#define MAX 10000000

unsigned long long phi[MAX + 7];

/**
* It took 0.902 secs to generate up to 1e7.
**/
void generatePhi() {
   phi[1] = 0;
   for (int i = 2; i <= MAX; i++) {
       if(!phi[i]) {
           phi[i] = i-1;
           for(int j = (i << 1); j <= MAX; j += i) {
               if(!phi[j]) phi[j] = j;
               phi[j] = phi[j] * (i-1) / i;
           }
       }
   }
}
