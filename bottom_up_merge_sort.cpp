#include <iostream>
#include <vector>
#include "output.h"

using namespace std;

void merge_bottom_up(vector<int>& to_sort, int start, int end, int size, int max, bool output)
{
	int start_half = start;//this keeps track of where our first subvector starts
	int second_half = start + size;//this keeps track of where the second subvector start
	
	
	
	int size_first = size, size_second = end - second_half;//the second size is calculated this way in case we have a situation where we have sub vectors of say 8 and 4, this way we dont overrun the vector.
	if (second_half > to_sort.size())
	{
		size_first = end - start;
	}
	int i = 0;

	vector<int> sorted;//where the elements are to be added as sorted elements.

	while (size_first > 0 && size_second > 0)
	{
		if (to_sort[start_half] < to_sort[second_half])
		{
			size_first--;
			sorted.push_back(to_sort[start_half]);
			start_half++;
			


		}

		else 
		{
			size_second--;
			sorted.push_back(to_sort[second_half]);
			second_half++;

		}

		
	}

	while (size_first > 0)
	{
		size_first--;
		sorted.push_back(to_sort[start_half]);
		start_half++;
	}

	while (size_second > 0)
	{
		size_second--;
		sorted.push_back(to_sort[second_half]);
		second_half++;
	}

	//maybe do this in a way that is faster, like starting with the back elements of sorted and replacing the values in to_sort
	//we are overrunning one of the arrays here, which one it is is not yet know.
	for (i = start; i < end; i++)
	{
		to_sort[i] = sorted.front();
		cout << "----------------------------------------------" << endl;
		print_array(sorted, max, output);
		print_array(to_sort, max, output);
		cout << "----------------------------------------------" << endl;
		sorted.erase(sorted.begin());
		

	}
	
	

}

void bottom_up_sort(int size, int output, bool file)
{

	bool user = user_choice();
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
		create_array(to_sort, max_num, size);
	}


	print_array(to_sort, max_num, file);

	int vec_size = 1, i = 0, j = 0, temp = 0;


	do
	{
		//we get every two sets to compare and sort them in the main vector
		for (i = 0; i < to_sort.size(); i = i +(2)*vec_size)
		{
			//if our vector groups would be bigger then the vecotor, then we want to make sure we don't overun the vector in merge by passing the size of the array rather then the 
			//next i as our end point.
			if (i + (2) * vec_size > to_sort.size())
			{
				merge_bottom_up(to_sort, i, to_sort.size(), vec_size, max_num, file);
				continue;
			}
			//if we are not overrunnint the vecotr, then we can safly pass the next i as the end of our vector.
			merge_bottom_up(to_sort, i, i + (2) * vec_size, vec_size, max_num, file);//if this i + 2* vec_size is greater then to_sort.size, then instead of passing the next group, we pass in to_sort size,

		}

		vec_size = vec_size * 2;//double the subvector size limits.
	} while (vec_size <= to_sort.size());
	print_array(to_sort, max_num, file);



}
