#include "job.h"
#include <vector>

using namespace std;

bool dfs(vector<vector<int>> &graph, vector<int> &visited, int node);
bool allDependenciesMet(vector<vector<int>> &graph, vector<int> &visited, int node);

bool canFinish(int n, vector<pair<int, int>> &dependencies) {
    vector<vector<int>> graph(n);
    vector<int> visited(n, 0);

    for (int i = 0; i < dependencies.size(); ++i) {
        graph[dependencies[i].first - 1].push_back(dependencies[i].second - 1);
    }

    for (int i = 0; i < n; ++i) {
        if (visited[i] == 0 && !dfs(graph, visited, i)) {
            return false;
        }
    }

    return true;
}

bool dfs(vector<vector<int>> &graph, vector<int> &visited, int node) {
    if (visited[node] == 1) {
        return false;
    }

    visited[node] = 1;

    for (int neighbor : graph[node]) {
        if (visited[neighbor] != 2 && !dfs(graph, visited, neighbor)) {
            return false;
        }
    }

    visited[node] = 2;
    return true;
}

bool canRun(int n, vector<pair<int, int>> &dependencies, int j, int i) {
    if (i < 1 || i > n || j < 1 || j > n) {
        return false;
    }

    if (!canFinish(n, dependencies)) {
        return false;
    }

    vector<vector<int>> graph(n);
    for (const auto& dep : dependencies) {
        graph[dep.first - 1].push_back(dep.second - 1);
    }

    vector<int> visited(n, 0);
    int count = 0;

    while (count < i) {
        bool found = false;
        for (int node = 0; node < n; ++node) {
            if (visited[node] == 0 && allDependenciesMet(graph, visited, node)) {
                if (node == j - 1) {
                    return count == i - 1;
                }
                visited[node] = 1;
                found = true;
                break;
            }
        }
        if (!found) {
            break;
        }
        ++count;
    }

    return false;
}

bool allDependenciesMet(vector<vector<int>> &graph, vector<int> &visited, int node) {
    for (int neighbor : graph[node]) {
        if (visited[neighbor] != 2) {
            return false;
        }
    }

    return true;
}
