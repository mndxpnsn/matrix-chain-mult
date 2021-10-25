//
//  memory.hpp
//  matrix-mult
//
//  Created by Derek Harrison on 26/10/2021.
//

#ifndef memory_hpp
#define memory_hpp

#include <stdio.h>

#include "user_types.hpp"

m_table new_memo_table(int n, int m);
void free_memo_table(m_table r, int n);
int** int2D(int nx, int ny);
void free_int2D(int** p, int nx);

#endif /* memory_hpp */
