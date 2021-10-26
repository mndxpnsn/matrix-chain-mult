//
//  user_types.hpp
//  matrix-mult
//
//  Created by mndx on 26/10/2021.
//

#ifndef user_types_h
#define user_types_h

const int inf = 3e+8;
extern int cost_parens;
extern int cost_parens_ref1;
extern int cost_parens_ref2;

typedef struct memo_table_element {
    bool is_set;
    int num_ops;
    int cut;
} m_table_elem;

typedef m_table_elem** m_table;

typedef struct parenthesis_element {
    int num_l_par_pos;
    int num_r_par_pre;
} p_elem;


#endif /* user_types_h */
