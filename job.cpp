#include "job.h"
#include <vector>

using namespace std;

bool canFinish(int n, vector<pair<int, int>> &dependencies) { 
    vector<vector<int>> graph(n);
    vector<int> indegrees(n, 0);

    for (auto &dependency : dependencies) {
        int x = dependency.first - 1;
        int y = dependency.second - 1;
        graph[x].push_back(y);
        indegrees[y]++;
    }

    queue<int> q;
    for (int i = 0; i < n; i++) {
        if (indegrees[i] == 0) {
            q.push(i);
        }
    }

    int finished_jobs = 0;
    while (!q.empty()) {
        int job = q.front();
        q.pop();
        finished_jobs++;

        for (int dependent_job : graph[job]) {
            indegrees[dependent_job]--;
            if (indegrees[dependent_job] == 0) {
                q.push(dependent_job);
            }
        }
    }

    return finished_jobs == n;
}
  

bool canRun(int n, vector<pair<int, int>> &dependencies, int j, int i) {
  return false;
}
