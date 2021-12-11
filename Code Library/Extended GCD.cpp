void ext_gcd(int a, int b, int *X, int *Y)
{
    int x, y, r, x1, y1, x2, y2, r1, r2, q;
    x2 = 1, y2 = 0;
    x1 = 0, y1 = 1;
    for(r2 = a, r1 = b; r1 != 0; r2 = r1, r1 = r, x2 = x1, x1 = x, y2 = y1, y1 = y){
        q = r2/r1;
        r = r2%r1;
        x = x2-q*x1;
        y = y2-q*y1;
    }
    *X = x2, *Y = y2;
}
