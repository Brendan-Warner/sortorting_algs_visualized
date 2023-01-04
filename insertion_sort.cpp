using namespace std;
#include <iostream>
#include <vector>
#include "insertion_sort.h"
#include "output.h"




//this is the insertion sort vector.  this works by checking the previous values of the vector against our current value we are trying to sort. if the value before is greater then our current, then we swap them.
//we keep doing this until we are at the start of the array the previous value is not greater then our current. since this works from the start of the array checking backwards, if a value previous is not 
//larger then the current, then we know all values before that previous value are also smaller then our current, so we have no need to check them. the time complexity is O(n).
void insertion_sort(int size, int output, bool file)
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

	print_array(to_sort, max_num);

	int i = 0, j = 0;
	for (i = 0; i < to_sort.size(); i++)
	{
		int t = i;
		for (j = i - 1; j >= 0; j--)
		{
			
			if (to_sort[t] < to_sort[j])
			{
				int temp = to_sort[t];
				to_sort[t] = to_sort[j];
				to_sort[j] = temp;
				t--;

				screen_output++;
				if (output == screen_output)
				{
					print_array(to_sort, max_num, t, j);
					screen_output = 0;
				}

			}

			else
			{
				break;
			}
		}
	}

}






