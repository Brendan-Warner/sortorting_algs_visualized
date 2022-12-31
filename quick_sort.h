#pragma once

int quick_sort_partition(int start, int end, vector<int>& to_sort, int max, int output);

void quick_sort(int start, int end, vector<int>& to_sort, int max, int output);

void quick_sort_setup(int size, int output, bool file);
