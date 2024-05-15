#pragma once

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include "Defs.h"

using namespace std;

// Define direction offsets: up, down, left, right
const int dx[] = { 0, 0, -1, 1 };
const int dy[] = { -1, 1, 0, 0 };

// Define a pair for coordinates
typedef pair<int, int> pii;

// Function to check if a cell is valid (within grid bounds and not a wall)
bool isValid_(int x, int y, int rows, int cols, const vector<vector<int>>& grid) {
    return x >= 0 && x < rows && y >= 0 && y < cols && grid[x][y] != 0;
}

// Function to find shortest path using BFS
vector<pii> shortestPath(vector<vector<int>>& grid, int startRow, int startCol, int endRow, int endCol) {
    int rows = grid.size();
    int cols = grid[0].size();

    // Queue for BFS
    queue<pii> q;
    q.push({ startRow, startCol });

    // Vector to store parent information for backtracking
    vector<vector<pii>> parent(rows, vector<pii>(cols, { -1, -1 }));

    // Mark start cell as visited
    vector<vector<bool>> visited(rows, vector<bool>(cols, false));
    visited[startRow][startCol] = true;

    // BFS traversal
    while (!q.empty()) {
        pii current = q.front();
        q.pop();

        int currentX = current.first;
        int currentY = current.second;

        // Check if reached the destination
        if (currentX == endRow && currentY == endCol) {
            break;
        }

        // Explore neighbors
        for (int i = 0; i < 4; ++i) {
            int newX = currentX + dx[i];
            int newY = currentY + dy[i];

            // Check if neighbor is valid and not visited
            if (isValid_(newX, newY, rows, cols, grid) && !visited[newX][newY]) {
                q.push({ newX, newY });
                visited[newX][newY] = true;
                parent[newX][newY] = { currentX, currentY }; // Store parent for backtracking
            }
        }
    }

    // Backtrack to find the shortest path
    vector<pii> path;
    int x = endRow, y = endCol;
    while (x != -1 && y != -1) {
        path.push_back({ x, y });
        pii p = parent[x][y];
        x = p.first;
        y = p.second;
    }

    // Reverse the path to get it from start to end
    reverse(path.begin(), path.end());

    return path;
}
