/// NEVER UNDERESTIMATE THE POWER OF CONDITIONS IN BINARY SEARCH
bool bs(int x, int n)
{
    int lo = 0, hi = n, md, prev = -1;
    while(lo < hi){
        md = (lo+hi)/2;
        if(v[md] == x) return 1;
        else if(x < v[md]) hi = md;
        else lo = md;

        if(prev == md) break;
        prev = md;
    }
    return 0;
}
