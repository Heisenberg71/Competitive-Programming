int findP(int u)
{
    if(u == pr[u]) return u;
    return pr[u] = findP(pr[u]);
}

void connect(int u, int v)
{
    u = findP(u);
    v = findP(v);
    if(u != v)
        pr[u] = v;
}

/// findP(value)  NEED TO CALL FROM MAIN
/// connect(x, y) NEED TO CALL FROM MAIN
/// INITIALIZE VALUE OF pr[] FROM MAIN
