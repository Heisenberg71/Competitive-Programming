#include <bits/stdc++.h>
#define ll long long
#define MAX 100000
#define mat_int int
using namespace std;

int grid[4][3], MOD;

struct matrix{
    int dimR, dimC;
    vector <vector <mat_int> > mat;
    matrix(int _dimR, int _dimC){
        dimR = _dimR;
        dimC = _dimC;
        mat.clear();
        mat.resize(dimR, vector <mat_int> (dimC, 0));
        if(dimR == dimC){
            for(int i = 0; i < dimR; i++)
                mat[i][i] = 1;
        }
    }

    matrix operator * (const matrix &oth)
    {
        int nr = dimR;
        int nc = oth.dimC;
        matrix newMat(nr, nc);
        for(int i = 0; i < nr; i++){
            for(int j = 0; j < nc; j++){
                mat_int sum = 0;
                for(int k = 0; k < dimC; k++)
                {
                    sum += (mat[i][k] * oth.mat[k][j]) % MOD;
                    sum %= MOD;
                }
                newMat.mat[i][j] = sum;
            }
        }
        return newMat;
    }

    matrix operator ^ (ll p)
    {
        matrix res(dimR, dimC);
        matrix x = *this;

        while(p){
            if(p % 2 == 1) res = x * res;
            x = x * x;
            p /= 2;
        }

        return res;
    }

    void print()
    {
        cout << "......" << endl;

        for(int i = 0; i < dimR; i++){
            for(int j = 0; j < dimC; j++){
                cout << mat[i][j] << " ";
            }
            cout << endl;
        }
        cout << "......" << endl;
    }

};

matrix A(6, 6), B(6, 1);

void make_mat()
{
    A.mat[0][0] = grid[0][0]; A.mat[0][1] = grid[0][1]; A.mat[0][2] = 0; A.mat[0][3] = 0; A.mat[0][4] = 0; A.mat[0][5] = grid[0][2];
    A.mat[1][0] = 1; A.mat[1][1] = 0; A.mat[1][2] = 0; A.mat[1][3] = 0; A.mat[1][4] = 0; A.mat[1][5] = 0;
    A.mat[2][0] = 0; A.mat[2][1] = 1; A.mat[2][2] = 0; A.mat[2][3] = 0; A.mat[2][4] = 0; A.mat[2][5] = 0;
    A.mat[3][0] = 0; A.mat[3][1] = 0; A.mat[3][2] = grid[1][2]; A.mat[3][3] = grid[1][0]; A.mat[3][4] = grid[1][1]; A.mat[3][5] = 0;
    A.mat[4][0] = 0; A.mat[4][1] = 0; A.mat[4][2] = 0; A.mat[4][3] = 1; A.mat[4][4] = 0; A.mat[4][5] = 0;
    A.mat[5][0] = 0; A.mat[5][1] = 0; A.mat[5][2] = 0; A.mat[5][3] = 0; A.mat[5][4] = 1; A.mat[5][5] = 0;

    B.mat[0][0] = grid[2][2];
    B.mat[1][0] = grid[2][1];
    B.mat[2][0] = grid[2][0];
    B.mat[3][0] = grid[3][2];
    B.mat[4][0] = grid[3][1];
    B.mat[5][0] = grid[3][0];
}

void make_ans(int n)
{
    matrix ans = (A ^ (n - 2)) * B;
    printf("%d %d\n", ans.mat[0][0], ans.mat[3][0]);
}

int main()
{
    int t, cas = 1, n, i, j, q;
    scanf("%d", &t);
    while(t--){
        for(i = 0; i < 4; i++)
            for(j = 0; j < 3; j++)
                scanf("%d", &grid[i][j]);
        scanf("%d", &MOD);
        scanf("%d", &q);
        make_mat();
        printf("Case %d:\n", cas++);
        while(q--){
            scanf("%d", &n);
            if(n < 3) printf("%d %d\n", grid[2][n]%MOD, grid[3][n]%MOD);
            else make_ans(n);
        }
    }

    return 0;
}
