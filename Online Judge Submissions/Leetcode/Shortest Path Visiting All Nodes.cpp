/*

  Problem Link: https://leetcode.com/problems/shortest-path-visiting-all-nodes/description/

*/

class Solution {
private:
    int INVALID = -1;
    vector<vector<int>> shortestDistance, ways;
    int nodeSize;

    void warshall(int nodeSize, vector<vector<int>>& graph){
        shortestDistance.assign(nodeSize, vector<int>(nodeSize, INT_MAX/2));

        for(int u = 0; u < nodeSize; u++){
            shortestDistance[u][u] = 0;
            for(int i = 0; i < graph[u].size(); i++){
                int v = graph[u][i];
                shortestDistance[u][v] = shortestDistance[v][u] = 1;
            }
        }

        for(int u = 0; u < nodeSize; u++){
            for(int v = 0; v < nodeSize; v++){
                for(int i = 0; i < nodeSize; i++){
                    shortestDistance[u][v] = min(shortestDistance[u][v], 
                    shortestDistance[u][i] + shortestDistance[i][v]);
                }
            }
        }
    }

    int findShortestLength(int currentNode, int mask){
        if(mask + 1 == (1 << nodeSize)) return 0;
        int& ret = ways[currentNode][mask];
        if(ret != INVALID) return ret;

        ret = INT_MAX/2;
        for(int i = 0; i < nodeSize; i++){
            if((mask&(1 << i))) continue;
            ret = min(ret, shortestDistance[currentNode][i] + findShortestLength(i, (mask|(1 << i))));
        }

        return ret;
    }
public:
    int shortestPathLength(vector<vector<int>>& graph) {
        nodeSize = graph.size();
        warshall(nodeSize, graph);
        int shortestLength = INT_MAX;
        for(int start = 0; start < nodeSize; start++){
            ways.assign(nodeSize, vector<int>((1 << nodeSize), INVALID));
            shortestLength = min(shortestLength, findShortestLength(start, (1 << start)));
        }

        return shortestLength;
    }
};
