//
//  matrix_chain_reference.hpp
//  matrix-mult
//
//  Created by mndx on 25/10/2021.
//

#ifndef matrix_chain_reference_hpp
#define matrix_chain_reference_hpp

#include <stdio.h>

#include "user_types.hpp"

int matrix_chain_order_ref(int* p, int n);
void matrix_chain_order(int p[], int len_p, int** m, int** s);
void print_optimal_parens(int** s, int i, int j);

#endif /* matrix_chain_reference_hpp */
