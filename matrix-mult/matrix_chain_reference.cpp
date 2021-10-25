//
//  matrix_chain_reference.cpp
//  matrix-mult
//
//  Created by Derek Harrison on 25/10/2021.
//

#include <cstdlib>
#include <iostream>
#include <stdio.h>
#include <time.h>

#include "matrix_chain_reference.hpp"

int dp[100][100];
 
// Function for matrix chain multiplication
int matrix_chain_memoized(int* p, int i, int j) {
    
    if (i == j) {
        return 0;
    }
    if (dp[i][j] != -1) {
        return dp[i][j];
    }
    dp[i][j] = INT_MAX;
    for (int k = i; k < j; k++) {
        int num_ops1 = matrix_chain_memoized(p, i, k);
        int num_ops2 = matrix_chain_memoized(p, k + 1, j);
        int num_add_ops = p[i - 1] * p[k] * p[j];
        dp[i][j] = std::min(dp[i][j], num_ops1 + num_ops2 + num_add_ops);
    }
    
    return dp[i][j];
}

int matrix_chain_order_ref(int* p, int n) {
    
    int i = 1, j = n - 1;
    memset(dp, -1, sizeof dp);
    
    return matrix_chain_memoized(p, i, j);
}
