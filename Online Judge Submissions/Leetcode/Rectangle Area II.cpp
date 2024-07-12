class Solution {
private:
    int MOD = 1000000007;
    map<int, int> x_axis_map, y_axis_map;
    vector<int> x_axis_vector, y_axis_vector;
    set<int> x_axis_set, y_axis_set;

public:
    int rectangleArea(vector<vector<int>>& rectangles) {
        for(auto& rectangle: rectangles){
            x_axis_set.insert(rectangle[0]);
            x_axis_set.insert(rectangle[2]);

            y_axis_set.insert(rectangle[1]);
            y_axis_set.insert(rectangle[3]);
        }

        for(auto& x: x_axis_set){
            x_axis_map[x] = x_axis_vector.size();
            x_axis_vector.push_back(x);
        }
        for(auto& y: y_axis_set){
            y_axis_map[y] = y_axis_vector.size();
            y_axis_vector.push_back(y);
        }

        vector<vector<int>> grid(x_axis_vector.size(), vector<int>(y_axis_vector.size(), false));

        for(auto& rectangle: rectangles){
            for(int x = x_axis_map[ rectangle[0] ]; x < x_axis_map[ rectangle[2] ]; x++){
                for(int y = y_axis_map[ rectangle[1] ]; y < y_axis_map[ rectangle[3] ]; y++){
                    grid[x][y] = true;
                }
            }
        }

        long long total_area_covered = 0;
        for(int x = 0; x + 1 < grid.size(); x++){
            for(int y = 0; y + 1 < grid[0].size(); y++){
                if(!grid[x][y]) continue;

                total_area_covered = (total_area_covered + 
                                     (1LL*(x_axis_vector[x + 1] - x_axis_vector[x])*
                                     (y_axis_vector[y + 1] - y_axis_vector[y])) %MOD) %MOD;
            }
        }

        return total_area_covered;
    }
};
