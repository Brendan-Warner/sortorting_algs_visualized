using namespace std;
#include <iostream>
#include <vector>
#include "selection_sort.h"
#include "output.h"




//This is selection sort, this works by trying to find the values that fits in the current spot we are checking in the vector. We try to find the smallest value from the current postion in the vector, if that is simply
//the current, we do nothing, else, we swap with the found smallest number. we do this till we hit the end of the vector. The time complexity is O(n^2)
void selection_sort(int size, int output, bool file)
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

	int i = 0, j = 0, t = 0;
	for (i = 0; i < to_sort.size() - 1; i++)
	{
		t = i;
		for (j = i + 1; j < to_sort.size(); j++)
		{
			if (to_sort[j] < to_sort[t])// if this is true, then we have a found a smaller number to swap with the one at i.
			{
				t = j;

			}


		}

		if (i != t)//if this is true, we have found a number smaller then the one at i, so we swap it with the one at t.
		{
			int temp = to_sort[i];
			to_sort[i] = to_sort[t];
			to_sort[t] = temp;
			screen_output++;
			if (screen_output == output)
			{
				print_array(to_sort, max_num, i, t, file);
				screen_output = 0;
			}

		}


	}

}









