#include <iostream>
#include <vector>

using namespace std;

bool isSafe(int v, vector<vector<int>>& graph, vector<int>& color, int c) {
    for (int i = 0; i < graph.size(); ++i) {
        if (graph[v][i] && c == color[i])
            return false;
    }
    return true;
}

bool graphColoringUtil(int v, int M, vector<vector<int>>& graph, vector<int>& color) {
    if (v == graph.size())
        return true;

    for (int c = 1; c <= M; ++c) {
        if (isSafe(v, graph, color, c)) {
            color[v] = c;
            if (graphColoringUtil(v + 1, M, graph, color))
                return true;
            color[v] = 0;
        }
    }
    return false;
}

bool graphColoring(vector<vector<int>>& graph, int M) {
    vector<int> color(graph.size(), 0);

    if (graphColoringUtil(0, M, graph, color)) {
        return true;
    }

    return false;
}

int main() {
    int N = 4;
    int M = 3;
    int E = 5;
    vector<vector<int>> graph = { {0, 1, 0, 1},
                                  {1, 0, 1, 0},
                                  {0, 1, 0, 1},
                                  {1, 0, 1, 0} };

    if (graphColoring(graph, M)) {
        cout << "1" << endl;
    }
    else {
        cout << "0" << endl;
    }

    return 0;
}
