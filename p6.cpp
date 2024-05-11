#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

bool isValidMove(vector<vector<int>>& matrix, vector<vector<bool>>& visited, int x, int y) {
    int n = matrix.size();
    return x >= 0 && x < n && y >= 0 && y < n && matrix[x][y] == 1 && !visited[x][y];
}

void findPaths(vector<vector<int>>& matrix, vector<vector<bool>>& visited, int x, int y, string path, vector<string>& result) {
    int n = matrix.size();
    if (x == n - 1 && y == n - 1) {
        result.push_back(path);
        return;
    }

    vector<pair<int, int>> directions = { {1, 0}, {0, -1}, {0, 1}, {-1, 0} };
    vector<char> moves = { 'D', 'L', 'R', 'U' };

    for (int i = 0; i < 4; ++i) {
        int nx = x + directions[i].first;
        int ny = y + directions[i].second;
        if (isValidMove(matrix, visited, nx, ny)) {
            visited[nx][ny] = true;
            findPaths(matrix, visited, nx, ny, path + moves[i], result);
            visited[nx][ny] = false;
        }
    }
}

vector<string> printPath(int N, vector<vector<int>>& m) {
    if (m[0][0] == 0 || m[N - 1][N - 1] == 0) {
        return {};
    }

    vector<vector<bool>> visited(N, vector<bool>(N, false));
    vector<string> result;

    visited[0][0] = true;
    findPaths(m, visited, 0, 0, "", result);

    sort(result.begin(), result.end());

    return result;
}


int main() {
    int N = 4;
    vector<vector<int>> matrix = {
        {1, 0, 0, 0},
        {1, 1, 0, 1},
        {1, 1, 0, 0},
        {0, 1, 1, 1}
    };

    vector<string> paths = printPath(N, matrix);

    for (const auto& path : paths) {
        cout << path << " ";
    }
    cout << endl;

    return 0;
}
