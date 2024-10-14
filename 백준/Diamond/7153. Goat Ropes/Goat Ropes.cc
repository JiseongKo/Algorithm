#include <bits/stdc++.h>
using namespace std;

// Define a small epsilon for floating point comparisons
const double EPS = 1e-9;

// Simplex implementation for maximization problem
struct Simplex {
    int m, n; // m constraints, n variables
    vector<vector<double>> A; // Tableau
    vector<int> basic, non_basic;

    Simplex(int constraints, int variables) : m(constraints), n(variables) {
        A.assign(m + 1, vector<double>(n + m + 2, 0.0));
        basic.assign(m, 0);
        non_basic.assign(n + m, 0);
    }

    // Set up the tableau
    void set_constraints(vector<vector<double>> &constraints, vector<double> &b) {
        for(int i=0;i<m;i++) {
            for(int j=0;j<n;j++) {
                A[i][j] = constraints[i][j];
            }
            // Slack variable
            A[i][n+i] = 1.0;
            // RHS
            A[i][n + m +1] = b[i];
            // Initially, basic variables are the slack variables
            basic[i] = n + i;
        }
    }

    // Set the objective function
    void set_objective(vector<double> &c) {
        for(int j=0;j<n;j++) {
            A[m][j] = -c[j];
        }
        // Slack variables have zero coefficient in objective
        for(int j=0;j<m;j++) {
            A[m][n + j] = 0.0;
        }
        // RHS of objective function is 0
        A[m][n + m +1] = 0.0;
    }

    // Perform pivot on (row, col)
    void pivot(int row, int col) {
        // Normalize the pivot row
        double pivot_val = A[row][col];
        for(int j=0; j <= n + m +1; j++) {
            A[row][j] /= pivot_val;
        }

        // Eliminate the pivot column in other rows
        for(int i=0; i <= m; i++) {
            if(i != row && fabs(A[i][col]) > EPS) {
                double factor = A[i][col];
                for(int j=0; j <= n + m +1; j++) {
                    A[i][j] -= factor * A[row][j];
                }
            }
        }

        // Update basic and non-basic variables
        swap(basic[row], non_basic[col]);
    }

    // Solve the simplex and return the maximum value
    double solve() {
        while (true) {
            // Find entering variable (most negative coefficient in objective)
            int enter = -1;
            for(int j=0; j < n + m; j++) {
                if(A[m][j] < -EPS) {
                    enter = j;
                    break; // Can use other selection rules
                }
            }
            if(enter == -1) break; // Optimal

            // Find leaving variable (minimum ratio)
            int leave = -1;
            double min_ratio = 1e100;
            for(int i=0; i < m; i++) {
                if(A[i][enter] > EPS) {
                    double ratio = A[i][n + m +1] / A[i][enter];
                    if(ratio < min_ratio - EPS) {
                        min_ratio = ratio;
                        leave = i;
                    }
                }
            }
            if(leave == -1) {
                // Unbounded
                return 1e100;
            }

            // Pivot on (leave, enter)
            pivot(leave, enter);
        }

        // The optimal value is A[m][n + m +1]
        return A[m][n + m +1];
    }
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    while(1){
        int n;
        cin>>n;
        if(n==0) break;
        vector<pair<int, int>> points(n);
        for(int i=0;i<n;i++) cin>>points[i].first>>points[i].second;
        // Compute all pairwise distances
        int m = n*(n-1)/2;
        vector<vector<double>> constraints;
        vector<double> b;
        // Mapping pairs to constraints
        for(int i=0;i<n;i++) {
            for(int j=i+1;j<n;j++) {
                vector<double> constraint(n, 0.0);
                constraint[i] = 1.0;
                constraint[j] = 1.0;
                constraints.push_back(constraint);
                // Compute distance
                double dx = (double)(points[i].first - points[j].first);
                double dy = (double)(points[i].second - points[j].second);
                double dist = sqrt(dx*dx + dy*dy);
                b.push_back(dist);
            }
        }
        // Objective function: maximize sum r_i
        vector<double> c(n, 1.0);
        // Initialize Simplex
        Simplex simplex_instance(m, n);
        simplex_instance.set_constraints(constraints, b);
        simplex_instance.set_objective(c);
        double result = simplex_instance.solve();
        // Round to two decimal places
        result += 1e-9; // to prevent precision issues
        cout<<fixed<<setprecision(2)<<result<<"\n";
    }
}
