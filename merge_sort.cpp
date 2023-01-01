using namespace std;

#include <iostream>
#include <vector>
#include "merge_sort.h"
#include "output.h"





//this is where mergsort combines to partionted parts of the orginal vector.
vector<int> merge(vector<int> to_sort_left, vector<int> to_sort_right, int max)
{
	vector<int> combined_vects;
	while (!to_sort_left.empty() && !to_sort_right.empty())//checks if one of the partions is empty.
	{
		if (to_sort_left[0] < to_sort_right[0])//if the left partion number is smaller, then add it to the vector, else we add the right number to the vector.
		{
			combined_vects.push_back(to_sort_left[0]);
			print_array(combined_vects, max);
			to_sort_left.erase(to_sort_left.begin());
		}

		else {
			combined_vects.push_back(to_sort_right[0]);
			print_array(combined_vects, max);
			to_sort_right.erase(to_sort_right.begin());
		}

	}

	while (!to_sort_left.empty())//if the left array is not empty but the right is, then we add the remaning left numbers to the array. These values should already be sorted by a previous merge.
	{
		combined_vects.push_back(to_sort_left[0]);
		print_array(combined_vects, max);
		to_sort_left.erase(to_sort_left.begin());
	}

	while (!to_sort_right.empty())//if the right array is not empty but the left is, then we add the remaning right numbers to the array. These values should already be sorted by a previous merge.
	{
		combined_vects.push_back(to_sort_right[0]);
		print_array(combined_vects, max);
		to_sort_right.erase(to_sort_right.begin());
	}

	return combined_vects;

}

//This is the other main portion of merge sort, it partions the vector recursivly until we are left with vectors of size one. after that, we use the merge function above to combine the vectors back into one large one. 
vector<int> merg_sort(vector<int> to_sort, int max)
{
	if (to_sort.size() == 1)
	{
		return to_sort;

	}

	vector<int> to_sort_left;
	vector<int> to_sort_right;
	int i = 0;
	for (i = 0; i < to_sort.size() / 2; i++)//size = 2, i = 0, limit 1
	{
		to_sort_left.push_back( to_sort[i]);
	}
	for (i = to_sort.size()/2; i < to_sort.size(); i++)//size = 2, i = 2 /2 = 1, limit 2
	{
		to_sort_right.push_back(to_sort[i]);
	}
	
	to_sort_left = merg_sort(to_sort_left, max);
	to_sort_right = merg_sort(to_sort_right, max);

	return merge(to_sort_left, to_sort_right, max);





}



void merge_sort_prep(int size, int output, bool file)
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

	to_sort = merg_sort(to_sort, max_num);

}




