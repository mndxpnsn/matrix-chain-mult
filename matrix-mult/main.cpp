//
//  main.cpp
//  matrix-mult
//
//  Created by Derek Harrison on 22/10/2021.
//

#include <cstdlib>
#include <iostream>

const int inf = 3e+8;
int total_num_ops = 0;
int total_num_ops_saved = 0;

typedef struct memo_table_element {
    bool is_set;
    int num_ops;
} m_table_elem;

typedef m_table_elem** m_table;

m_table new_memo_table(int n, int m) {
    m_table r = new m_table_elem*[n];
    
    for(int i = 0; i < n; ++i) {
        r[i] = new m_table_elem[m];
    }
    
    return r;
}

void free_memo_table(m_table r, int n) {
    for(int i = 0; i < n; ++i) {
        delete [] r[i];
    }
    
    delete [] r;
}

int min_ops(int p[], int i, int j, m_table memo_table) {
    int min_nops = inf;

    total_num_ops++;
    
    //Get value from memo table if possible
    if(memo_table[i][j].is_set) {
        total_num_ops_saved++;
        min_nops = memo_table[i][j].num_ops;
        return min_nops;
    }
    
    //Case single or no matrix
    if(j - i <= 1) {
        memo_table[i][j].is_set = true;
        memo_table[i][j].num_ops = 0;
        return 0;
    }
    
    //Case pair of matrices
    if(j - i == 2) {
        min_nops = p[i] * p[i+1] * p[j];
        memo_table[i][j].is_set = true;
        memo_table[i][j].num_ops = min_nops;
        return min_nops;
    }
    
    //Case more than two matrices being multiplied
    if(j - i > 2) {
        int min_k = 0;
        for(int k = i + 1; k < j; ++k) {
            int num_ops1 = min_ops(p, i, k, memo_table);
            int num_ops2 = min_ops(p, k, j, memo_table);
            int tot_num_ops = num_ops1 + num_ops2;
            if(tot_num_ops < min_nops) {
                min_k = k;
                min_nops = tot_num_ops;
            }
        }
        
        //Add operations upper level of parenthesis tree
        min_nops = min_nops + p[i] * p[min_k] * p[j];
        
        //Set memo table
        memo_table[i][j].is_set = true;
        memo_table[i][j].num_ops = min_nops;
    }
    
    return min_nops;
}

int minimum_num_ops(int p[], int n) {
    
    //Initialize memo table
    m_table memo_table = new_memo_table(n, n);
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < n; ++j) {
            memo_table[i][j].is_set = false;
            memo_table[i][j].num_ops = inf;
        }
    }
    
    //Compute minimum number of operations
    int min_num_ops = min_ops(p, 0, n - 1, memo_table);
    
    return min_num_ops;
}

int main(int argc, const char * argv[]) {
    
    //Input size
    int n = 15;
    
    //Creating random sequence of matrix dimensions
    int* p = new int[n];
    for(int i = 0; i < n; ++i) {
        p[i] = rand() % n + 1;
    }
    
    //Compute minimum number of operations
    int min_num_ops = minimum_num_ops(p, n);
    
    std::cout << "min_num_nops: " << min_num_ops << std::endl;
    std::cout << "total number of calls: " << total_num_ops << std::endl;
    std::cout << "total number of calls saved: " << total_num_ops_saved << std::endl;
    std::cout << "done" << std::endl;
    
    return 0;
}
