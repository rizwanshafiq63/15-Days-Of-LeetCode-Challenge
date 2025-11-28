class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int> indegree(numCourses, 0);

        // Build adjacency list + indegree count
        for (auto& p : prerequisites) {
            int course = p[0], pre = p[1];
            adj[pre].push_back(course);
            indegree[course]++;
        }

        // Queue for all nodes with indegree 0
        queue<int> q;
        for (int i = 0; i < numCourses; i++) {
            if (indegree[i] == 0) q.push(i);
        }

        int taken = 0;

        // BFS 
        while (!q.empty()) {
            int curr = q.front(); q.pop();
            taken++;

            for (int next : adj[curr]) {
                indegree[next]--;
                if (indegree[next] == 0) {
                    q.push(next);
                }
            }
        }

        // If we could take all courses, no cycle exists
        return taken == numCourses;
    }
};
