//
//  memory.cpp
//  matrix-mult
//
//  Created by mndx on 26/10/2021.
//

#include "memory.hpp"
#include "user_types.hpp"

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

int** int2D(int nx, int ny) {
    int** p = new int*[nx];

    for(int i = 0; i < nx; ++i) {
        p[i] = new int[ny];
    }

    return p;

}

void free_int2D(int** p, int nx) {
    for(int i = 0; i < nx; ++i) {
        delete [] p[i];
    }

    delete [] p;
}
