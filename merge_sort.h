#pragma once
#include <vector>

std::vector<int> merge(std::vector<int> to_sort_left, std::vector<int> to_sort_right, int max, bool output);

std::vector<int> merg_sort(std::vector<int> to_sort, int max, bool output);

void merge_sort_prep(int size, int output, bool file);
