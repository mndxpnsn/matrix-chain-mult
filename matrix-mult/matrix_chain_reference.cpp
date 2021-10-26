//
//  matrix_chain_reference.cpp
//  matrix-mult
//
//  Created by mndx on 25/10/2021.
//

#include <cstdlib>
#include <iostream>
#include <stdio.h>
#include <time.h>

#include "matrix_chain_reference.hpp"

int dp[100][100];
int cost_parens_ref1 = 0;
int cost_parens_ref2 = 0;
 
// Function for matrix chain multiplication
int matrix_chain_memoized(int* p, int i, int j) {
    
    cost_parens_ref1++;
    
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

void matrix_chain_order(int p[], int len_p, int** m, int** s) {
    int n = len_p - 1;

    for(int i = 1; i <= n; ++i) {
        m[i][i] = 0;
    }

    for(int l = 2; l <= n; ++l) {
        for(int i = 1; i <= n - l + 1; ++i) {
            int j = i + l - 1;
            m[i][j] = 3e+8;
            for(int k = i; k <= j - 1; ++k) {
                cost_parens_ref2++;
                int q = m[i][k] + m[k+1][j] + p[i-1]*p[k]*p[j];
                if(q < m[i][j]) {
                    m[i][j] = q;
                    s[i][j] = k;
                }
            }
        }
    }
}

void print_optimal_parens(int** s, int i, int j) {
    if(i == j) {
        std::cout << "A" << i;
    }
    else {
        std::cout << "(";
        print_optimal_parens(s, i, s[i][j]);
        print_optimal_parens(s, s[i][j]+1, j);
        std::cout << ")";
    }
}
