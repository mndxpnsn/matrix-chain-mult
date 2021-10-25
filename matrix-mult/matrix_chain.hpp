//
//  matrix_chain.hpp
//  matrix-mult
//
//  Created by mndx on 26/10/2021.
//

#ifndef matrix_chain_hpp
#define matrix_chain_hpp

#include <stdio.h>

#include "user_types.hpp"

int verify_num_ops(int n, int p[], m_table memo_table);
void print_solution(int n, m_table memo_table);
int matrix_chain(int p[], int n, m_table memo_table);

#endif /* matrix_chain_hpp */
