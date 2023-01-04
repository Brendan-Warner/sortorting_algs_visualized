#pragma once
#include <vector>

bool user_choice();

void create_array_user(std::vector<int>& to_sort, int& max, int size);

void create_array(std::vector<int>& to_sort, int max, int size);

void print_array(std::vector<int> to_sort, int max);

void print_array(std::vector<int> to_sort, int max, int to_swap_1, int to_swap_2);

void print_array_merge(std::vector<int> combined_vec, std::vector<int> working_vec_left, std::vector<int> working_vec_right, int max);
