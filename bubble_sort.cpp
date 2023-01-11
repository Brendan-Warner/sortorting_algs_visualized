using namespace std;
#include <iostream>
#include <vector>
#include "bubble_sort.h"
#include "output.h"





void bubble_sort(int size, int output, bool file)
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
		create_array(to_sort, max_num, size);
	}

	print_array(to_sort, max_num, file);

	//this is the main for loop, with bubble sort, the idea is that larger numbers in the array "bubble" to the top of the array. the complexity of bubble sort is On^2
	int i = 0, j = 0;
	for (i = 0; i < to_sort.size(); i++)
	{
		for (j = 0; j < to_sort.size() - 1; j++)
		{
			if (to_sort[j] > to_sort[j + 1])
			{
				int temp = to_sort[j];
				to_sort[j] = to_sort[j + 1];
				to_sort[j + 1] = temp;
				screen_output++;


				if (screen_output == output)
				{
					screen_output = 0;
					print_array(to_sort, max_num, j, j+1, file);
				}

			}

		}
	}

}






