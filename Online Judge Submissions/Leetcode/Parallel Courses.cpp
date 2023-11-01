/*

  Problem Link: https://leetcode.com/problems/parallel-courses/
  Time Complexity: O(M*log(N) + N)
  Space Complexity: O(N + M)

  Here,
  M = amount of courseRelations
  N = distinct courses

*/

class Solution {
    const static int VISITED = 1;
    const static int FINISHED = 2;
private:
    map<int, vector<int>> courseRelations;
    unordered_map<int, int> semesterDepth;
    unordered_map<int, int> status;

    int DFS(int course){
        if(status[course] == VISITED) return INT_MAX/2;
        if(status[course] == FINISHED) return semesterDepth[course];

        status[course] = VISITED;
        int depth = 0;
        for(auto& dependedCourse: courseRelations[course]){
            depth = max(depth, 1 + DFS(dependedCourse));
        }
        status[course] = FINISHED;

        return semesterDepth[course] = depth;
    }
public:
    int minimumSemesters(int n, vector<vector<int>>& relations) {
        for(auto& relation: relations){
            courseRelations[ relation[0] ].push_back(relation[1]);
        }
        int semester = 0;
        for(auto& courseRelation: courseRelations){
            semester = max(semester, 1 + DFS(courseRelation.first));
        }
        return (semester >= INT_MAX/2) ? -1 : semester;
    }
};
