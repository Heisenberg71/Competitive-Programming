// let p be a 2D parent matrix, where p[i][j] is the last vertex before j
// on a shortest path from i to j, i.e. i -> ... -> p[i][j] -> j
init_path_print() {
    for (int i = 0; i < NODE; i++)
        for (int j = 0; j < NODE; j++)
            p[i][j] = i; // initialize the parent matrix
}
 
// precondition: AdjMat[i][j] contains the weight of edge (i, j)
// or INF (1B) if there is no such edge
// AdjMat is a 32-bit signed integer array
void floyd_warshall() {
    for (int k = 0; k < NODE; k++) {// remember that loop order is k->i->j
        for (int i = 0; i < NODE; i++) {
            for (int j = 0; j < NODE; j++) {
                AdjMat[i][j] = min(AdjMat[i][j], AdjMat[i][k] + AdjMat[k][j]);
                p[i][j] = p[k][j]; // update the parent matrix for path print
            }
        }
    }
}
 
// when we need to print the shortest paths, we can call the method below:
void printPath(int i, int j) {
    if (i != j) printPath(i, p[i][j]);
    printf(" %d", j);
}
