class Solution {
private:
    bool isCycleExistsInLastFourMoves(int i, vector<int>& distance) {
        int x0 = 0, y0 = 0;
        int x1 = x0, y1 = y0 + distance[i - 3];
        int x2 =  x1 - distance[i - 2], y2 = y1;
        int x3 = x2, y3 = y2 - distance[i - 1];
        int x4 = x3 + distance[i], y4 = y3;

        return (y0 <= y3 && y3 <= y1 && x3 <= x0 && x0 <= x4);
    }

    bool isCycleExistsInLastFiveMoves(int i, vector<int>& distance) {
        int x0 = 0, y0 = 0;
        int x1 = x0, y1 = y0 + distance[i - 4];
        int x2 =  x1 - distance[i - 3], y2 = y1;
        int x3 = x2, y3 = y2 - distance[i - 2];
        int x4 = x3 + distance[i - 1], y4 = y3;
        int x5 = x4, y5 = y4 + distance[i];

        return (x0 == x5 && y4 <= y0 && y0 <= y5);
    }

    bool isCycleExistsInLastSixMoves(int i, vector<int>& distance) {
        int x0 = 0, y0 = 0;
        int x1 = x0, y1 = y0 + distance[i - 5];
        int x2 = x1 - distance[i - 4], y2 = y1;
        int x3 = x2, y3 = y2 - distance[i - 3];
        int x4 = x3 + distance[i - 2], y4 = y3;
        int x5 = x4, y5 = y4 + distance[i - 1];
        int x6 = x5 - distance[i], y6 = y5;

        return (y0 <= y6 && y6 <= y1 && x6 <= x0 && x0 <= x5);
    }

    bool doesSelfCross(int i, vector<int>& distance) {
        if(i < 3) return false;
        if(isCycleExistsInLastFourMoves(i, distance)) return true;

        if(i < 4) return false;
        if(isCycleExistsInLastFiveMoves(i, distance)) return true;

        if(i < 5) return false;
        return isCycleExistsInLastSixMoves(i, distance);
    }
public:
    bool isSelfCrossing(vector<int>& distance) {
        int n = distance.size();
        
        bool isSelfCrossed = false;
        for(int i = 0; i < n; i++){
            isSelfCrossed |= doesSelfCross(i, distance);
        }

        return isSelfCrossed;
    }
};
