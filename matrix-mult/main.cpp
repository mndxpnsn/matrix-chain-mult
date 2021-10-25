//
//  main.cpp
//  matrix-mult
//
//  Created by mndx on 22/10/2021.
//

#include <cstdlib>
#include <iostream>
#include <stdio.h>
#include <time.h>

#include "matrix_chain.hpp"
#include "matrix_chain_reference.hpp"
#include "memory.hpp"

int main(int argc, const char * argv[]) {

    //Input size
    int n = 11;

    //Allocate space for results
    m_table memo_table = new_memo_table(n, n);

    //Creating random sequence of matrix dimensions
    int* p = new int[n];
    srand((unsigned) time(NULL));
    for(int i = 0; i < n; ++i) {
        p[i] = rand() % n + 2;
    }

    //Compute minimum number of operations
    int min_num_ops = matrix_chain(p, n, memo_table);

    //Verify number of operations
    int min_num_ops_ver = verify_num_ops(n, p, memo_table);

    //Compare with reference results
    int len = n - 1;
    int** m = int2D(len + 1, len + 1);
    int** s = int2D(len, len + 1);

    matrix_chain_order(p, n, m, s);
    
    //Compare with more reference results
    int min_num_ops_ref = matrix_chain_order_ref(p, n);

    //Print results
    print_solution(n, memo_table);
    print_optimal_parens(s, 1, len);
    std::cout << std::endl;
    
    std::cout << "Optimum number of operations for matrix product" << std::endl;
    std::cout << "min_num_ops: " << min_num_ops << std::endl;
    std::cout << "min_num_ops_ver: " << min_num_ops_ver << std::endl;
    
    int left_index = 1;
    int right_index = len;
    
    std::cout << "Number of operations from reference methods:" << std::endl;
    std::cout << "m[1][len]: " << m[left_index][right_index] << std::endl;
    std::cout << "min_num_ops_ref: " << min_num_ops_ref << std::endl;
    
    //Free data
    delete [] p;
    free_memo_table(memo_table, n);
    free_int2D(m, len + 1);
    free_int2D(s, len);
    
    std::cout << "done" << std::endl;

    return 0;
}
