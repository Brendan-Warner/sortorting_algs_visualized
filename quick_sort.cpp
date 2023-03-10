using namespace std;
#include <iostream>
#include <vector>
#include "quick_sort.h"
#include "output.h"




//this is the partioning algorithm. This is works by checking values i and j against the starting number know as the pivot of the partion. if a i value is less then our pivot, we stwitch it with the next j value that is 
//less then our pivot value. We do this until j has passed i, in which case we sqap the pivot with j, now everything before our pivot is less then it and everything after is greater. those values are not sorted,
//but we are one step closer. the time complexity is O(n*logn)
int quick_sort_partition(int start, int end, vector<int>& to_sort, int max, int output, bool file)
{

	int i = start;
	int j = end;
	int o= 0;
	
	while (i < j)//if i is greater then j, we want to stop.
	{
		do
		{
			i++;


		} while (to_sort[i] <= to_sort[start] && i < to_sort.size() - 1);//if at any point i is greater then pivot, we need to swap that i value with a j. 

		do
		{
			j--;

		} while (to_sort[j] > to_sort[start] && j > 0);//if we encounter a value where j is less then the pivot, we need to swap that j value with an i.

		if (i < j) {
			int temp = to_sort[i];
			to_sort[i] = to_sort[j];
			to_sort[j] = temp;
		}
		o++;

		if (output == o)
		{
			print_array(to_sort, max, i, j, file);
			o = 0;

		}

	}

	//this swaps the pivot with the current j value.
	
	int temp = to_sort[start];
	to_sort[start] = to_sort[j];
	to_sort[j] = temp;

	print_array(to_sort, max, i, j, file);

	return j;//return our j value as it will be the basis for seperating our vector into to small vectors.




}

//this is an recursive function, which partitions our vector into smaller and smaller halves until the array is sorted.
void quick_sort(int start, int end, vector<int>& to_sort, int max, int output, bool file)
{
	
	if (start < end)
	{
		int j = quick_sort_partition(start, end, to_sort, max, output, file);//this creates a partition, and assignes the new partion point to j.
		quick_sort(start, j, to_sort, max, output, file);//this is the first half of the new partitioned vector
		quick_sort(j + 1, end, to_sort, max, output, file);//this is the second half of the new partitioned vector.

	}

}

void quick_sort_setup(int size, int output, bool file)
{

	bool user =  user_choice();
	int max_num = 0;
	int screen_output = 0;
	vector<int> to_sort;
	if (user)
	{
		create_array_user(to_sort, max_num, size);
	}

	else
	{
		cout << "please enter a max number" << endl;
		cin >> max_num;
		create_array(to_sort, max_num,size);
	}

	print_array(to_sort, max_num, file);

	quick_sort(0, to_sort.size(), to_sort, max_num, output, file);

}






