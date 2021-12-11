const double eps = 1e-9;
 
// Find the first K digits of N!
int leadingDigitFact ( int n, int k ) {
    double fact = 0;
 
    // Find log(N!)
    for ( int i = 1; i <= n; i++ ) {
        fact += log10 ( i );
    }
 
    // Find the value of q
    double q = fact - floor ( fact+eps );
 
    double B = pow ( 10, q );
 
    // Shift decimal point k-1 \times
    for ( int i = 0; i < k - 1; i++ ) {
        B *= 10;
    }
 
    // Don't forget to floor it
    return floor(B+eps);
