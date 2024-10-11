#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin >> T;
    while(T--){
        long long N, R1, C1, R2, C2;
        cin >> N >> R1 >> C1 >> R2 >> C2;
        long long dx = abs(R1 - R2);
        long long dy = abs(C1 - C2);
        if(dx < dy){
            swap(dx, dy);
        }
        if(dx <=300 && dy <=300){
            // BFS
            vector<pair<int,int>> moves = { {-2,-1}, {-1,-2}, {1,-2}, {2,-1}, {2,1}, {1,2}, {-1,2}, {-2,1} };
            // Initialize visited as a 1D array
            // Mapping (x, y) where x and y range from -300 to +300
            // Index = (x + 300) * 601 + (y + 300)
            // Total size = 601 * 601 = 361201
            vector<char> visited(601*601, 0);
            queue<pair<int,int>> q;
            // Starting at (0,0)
            q.push({0, 0});
            visited[300 * 601 + 300] = 1;
            int steps =0;
            bool found = false;
            while(!q.empty()){
                int qsize = q.size();
                for(int i=0;i<qsize;i++){
                    pair<int,int> current = q.front(); q.pop();
                    int x = current.first;
                    int y = current.second;
                    if(x == dx && y == dy){
                        cout << steps << "\n";
                        found = true;
                        break;
                    }
                    for(auto &[mx, my] : moves){
                        int nx = x + mx;
                        int ny = y + my;
                        if(abs(nx) >300 || abs(ny) >300){
                            continue;
                        }
                        // Check if within board boundaries
                        long long new_r = R1 + nx;
                        long long new_c = C1 + ny;
                        if(new_r <1 || new_r >N || new_c <1 || new_c >N){
                            continue;
                        }
                        // Check if visited
                        int idx = (nx +300)*601 + (ny +300);
                        if(!visited[idx]){
                            visited[idx]=1;
                            q.push({nx, ny});
                        }
                    }
                }
                if(found) break;
                steps++;
            }
            if(!found){
                // As per problem statement, a solution always exists
                // This should not occur
                cout << "-1\n";
            }
        }
        else{
            // Use formula for infinite chessboard
            // Ensure dx >= dy
            // Handle special cases
            long long answer;
            if(dx ==1 && dy ==0){
                answer =3;
            }
            else if(dx ==2 && dy ==2){
                answer =4;
            }
            else{
                // Calculate ceil(dx / 2) and ceil((dx + dy)/3)
                long long d1 = (dx +1)/2;
                long long d2 = (dx + dy +2)/3;
                long long d = max(d1, d2);
                // Adjust based on parity
                if( (d %2) == ( (dx + dy) %2 )){
                    answer =d;
                }
                else{
                    answer =d +1;
                }
            }
            cout << answer << "\n";
        }
    }
}
