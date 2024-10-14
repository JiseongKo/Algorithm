#include <bits/stdc++.h>
using namespace std;

struct Tank {
    int id;
    int r_i, c_i;   // Initial positions
    int tr_i, tc_i; // Target positions
    int cr_i, cc_i; // Current positions
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N;
    cin >> N;
    
    vector<Tank> tanks(N);
    for(int i=0; i<N; ++i){
        cin >> tanks[i].r_i >> tanks[i].c_i;
        tanks[i].id = i+1;
        tanks[i].cr_i = tanks[i].r_i;
        tanks[i].cc_i = tanks[i].c_i;
    }
    
    // Assign target rows
    vector<Tank> sorted_r = tanks;
    sort(sorted_r.begin(), sorted_r.end(), [&](const Tank &a, const Tank &b) -> bool{
        if(a.r_i != b.r_i) return a.r_i < b.r_i;
        return a.id < b.id;
    });
    for(int i=0; i<N; ++i){
        int tank_id = sorted_r[i].id;
        tanks[tank_id-1].tr_i = i+1;
    }
    
    // Assign target columns
    vector<Tank> sorted_c = tanks;
    sort(sorted_c.begin(), sorted_c.end(), [&](const Tank &a, const Tank &b) -> bool{
        if(a.c_i != b.c_i) return a.c_i < b.c_i;
        return a.id < b.id;
    });
    for(int i=0; i<N; ++i){
        int tank_id = sorted_c[i].id;
        tanks[tank_id-1].tc_i = i+1;
    }
    
    // Collect tanks needing to move up and down
    vector<Tank*> move_up;
    vector<Tank*> move_down;
    for(int i=0; i<N; ++i){
        if(tanks[i].tr_i < tanks[i].cr_i){
            move_up.push_back(&tanks[i]);
        }
        else if(tanks[i].tr_i > tanks[i].cr_i){
            move_down.push_back(&tanks[i]);
        }
    }
    
    // Sort move_up in ascending order of current row
    sort(move_up.begin(), move_up.end(), [&](const Tank* a, const Tank* b) -> bool{
        return a->cr_i < b->cr_i;
    });
    
    // Sort move_down in descending order of current row
    sort(move_down.begin(), move_down.end(), [&](const Tank* a, const Tank* b) -> bool{
        return a->cr_i > b->cr_i;
    });
    
    // Collect tanks needing to move left and right
    vector<Tank*> move_left;
    vector<Tank*> move_right;
    for(int i=0; i<N; ++i){
        if(tanks[i].tc_i < tanks[i].cc_i){
            move_left.push_back(&tanks[i]);
        }
        else if(tanks[i].tc_i > tanks[i].cc_i){
            move_right.push_back(&tanks[i]);
        }
    }
    
    // Sort move_left in ascending order of current column
    sort(move_left.begin(), move_left.end(), [&](const Tank* a, const Tank* b) -> bool{
        return a->cc_i < b->cc_i;
    });
    
    // Sort move_right in descending order of current column
    sort(move_right.begin(), move_right.end(), [&](const Tank* a, const Tank* b) -> bool{
        return a->cc_i > b->cc_i;
    });
    
    // Prepare buffer for moves
    // Maximum moves: 2*N*N, each move takes up to 12 characters (including space and newline)
    // So allocate enough memory
    // Using a large buffer allocated on heap
    const int MAX_MOVES = 2000000; // 2 million moves
    // Each move can take up to 12 characters: up to 6 digits for id, space, direction, newline
    // So buffer size is 12 * MAX_MOVES
    // To be safe, use 24 million
    const int BUFFER_SIZE = 24000000;
    char* buffer_moves = new char[BUFFER_SIZE];
    int ptr_moves = 0;
    int K = 0;
    
    // Helper lambda to append a move to buffer
    auto append_move = [&](int id, char dir) {
        // Convert id to digits and append
        char temp[10];
        int len = 0;
        int x = id;
        if(x == 0){
            temp[len++] = '0';
        }
        else{
            while(x > 0){
                temp[len++] = '0' + (x % 10);
                x /= 10;
            }
        }
        for(int i = len-1; i >=0; --i){
            buffer_moves[ptr_moves++] = temp[i];
        }
        buffer_moves[ptr_moves++] = ' ';
        buffer_moves[ptr_moves++] = dir;
        buffer_moves[ptr_moves++] = '\n';
        K++;
    };
    
    // Move vertically
    // Move up
    for(auto tank_ptr : move_up){
        while(tank_ptr->cr_i > tank_ptr->tr_i){
            append_move(tank_ptr->id, 'U');
            tank_ptr->cr_i--;
        }
    }
    // Move down
    for(auto tank_ptr : move_down){
        while(tank_ptr->cr_i < tank_ptr->tr_i){
            append_move(tank_ptr->id, 'D');
            tank_ptr->cr_i++;
        }
    }
    
    // Move horizontally
    // Move left
    for(auto tank_ptr : move_left){
        while(tank_ptr->cc_i > tank_ptr->tc_i){
            append_move(tank_ptr->id, 'L');
            tank_ptr->cc_i--;
        }
    }
    // Move right
    for(auto tank_ptr : move_right){
        while(tank_ptr->cc_i < tank_ptr->tc_i){
            append_move(tank_ptr->id, 'R');
            tank_ptr->cc_i++;
        }
    }
    
    // Output K
    // Since K can be up to 2 million, use fast output
    // First, print K and newline
    // Then, print buffer_moves
    // To convert K to string
    string K_str;
    int tmp = K;
    if(tmp == 0){
        K_str = "0\n";
    }
    else{
        string temp_str;
        while(tmp > 0){
            temp_str += ('0' + (tmp %10));
            tmp /=10;
        }
        // Reverse the string
        string K_rev;
        for(int i = temp_str.size()-1; i >=0; --i){
            K_rev += temp_str[i];
        }
        K_rev += '\n';
        K_str = K_rev;
    }
    // Write K_str
    fwrite(K_str.c_str(), 1, K_str.size(), stdout);
    // Write buffer_moves
    fwrite(buffer_moves, 1, ptr_moves, stdout);
    
    // Clean up
    delete[] buffer_moves;
    
    return 0;
}
