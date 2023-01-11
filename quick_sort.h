#pragma once
#include <vector>

int quick_sort_partition(int start, int end, std::vector<int>& to_sort, int max, int output, bool file);

void quick_sort(int start, int end, std::vector<int>& to_sort, int max, int output, bool file);

void quick_sort_setup(int size, int output, bool file);
