#pragma once
#include <vector>

std::vector<int> merge(std::vector<int> to_sort_left, std::vector<int> to_sort_right, int max);

std::vector<int> merg_sort(std::vector<int> to_sort, int max);

void merge_sort_prep(int size, int output, bool file);
