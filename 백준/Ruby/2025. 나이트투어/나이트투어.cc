#include <bits/stdc++.h>
using namespace std;

/*
 * This is a solution to the Knight's Tour problem using Warnsdorff's heuristic.
 * 
 * Problem summary:
 * Given an N×N chessboard (6 ≤ N ≤ 666) and a starting position (r, c),
 * we need to find a sequence of moves of a knight that visits every square 
 * on the board exactly once.
 * 
 * If such a sequence is found, print the moves in order. Otherwise, print "-1 -1".
 * 
 * It is well-known that for all boards of size N ≥ 5 (with a few exceptions), a knight's tour exists.
 * Since the problem guarantees N ≥ 6, a solution should exist for all valid inputs. 
 * Warnsdorff's heuristic is a well-known approach that finds a knight's tour for large boards 
 * quite efficiently. We must still be careful with implementation details to fit into the 
 * given time limit.
 * 
 * Warnsdorff's heuristic:
 * 1. Start from the initial position.
 * 2. At each step, move the knight to the next position that has the fewest onward moves.
 *    In other words, from the current position, look at all possible moves that lead to 
 *    unvisited squares and pick the one that has the fewest onward moves for the next step.
 * 3. Repeat until all squares are visited.
 * 
 * If at some point no further moves are possible and the board is not fully covered, 
 * then no tour is found. However, in practice, Warnsdorff's heuristic 
 * usually finds a solution for large boards quickly.
 * 
 * Implementation details:
 * - We'll store the board positions in a 2D vector.
 * - We'll precompute the moves of a knight.
 * - For each potential next move, count how many onward moves it would have.
 * - Pick the move with the smallest onward moves count.
 * 
 * Time complexity:
 * Warnsdorff's heuristic is very efficient and will typically run in O(N^2) 
 * but with small overhead since each move is decided in constant time given careful 
 * bookkeeping (we will have at most 8 moves to consider for each step).
 * 
 * If a solution is found, print it. Otherwise print "-1 -1".
 */

struct Move {
    int r, c;
};

static const int knightMoves[8][2] = {
    { -2, -1 }, { -2, +1 },
    { -1, -2 }, { -1, +2 },
    { +1, -2 }, { +1, +2 },
    { +2, -1 }, { +2, +1 }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N; cin >> N;
    int sr, sc; cin >> sr >> sc;
    // Convert to 0-based indexing
    sr--; sc--;

    // Board for marking visited cells
    vector<vector<bool>> visited(N, vector<bool>(N, false));
    // Result path
    vector<pair<int,int>> path;
    path.reserve(N*N);

    // Lambda to count onward moves for Warnsdorff
    auto countOnwardMoves = [&](int r, int c) {
        int count = 0;
        for (auto &m : knightMoves) {
            int nr = r + m[0], nc = c + m[1];
            if (nr >= 0 && nr < N && nc >= 0 && nc < N && !visited[nr][nc]) {
                count++;
            }
        }
        return count;
    };

    // Initialize
    int r = sr, c = sc;
    visited[r][c] = true;
    path.emplace_back(r, c);

    for (int step = 1; step < N*N; step++) {
        // Find the next move using Warnsdorff's rule
        int next_r = -1, next_c = -1;
        int minDegree = 9; // larger than any possible onward moves count
        for (auto &mv : knightMoves) {
            int nr = r + mv[0], nc = c + mv[1];
            if (nr < 0 || nr >= N || nc < 0 || nc >= N) continue;
            if (!visited[nr][nc]) {
                int deg = countOnwardMoves(nr, nc);
                if (deg < minDegree) {
                    minDegree = deg;
                    next_r = nr;
                    next_c = nc;
                }
            }
        }
        if (next_r == -1) {
            // No move found
            cout << "-1 -1\n";
            return 0;
        }

        visited[next_r][next_c] = true;
        path.emplace_back(next_r, next_c);
        r = next_r; c = next_c;
    }

    // If we reach here, we have a full tour
    // Print the path in 1-based coordinates
    for (auto &p : path) {
        cout << p.first + 1 << " " << p.second + 1 << "\n";
    }

    return 0;
}
