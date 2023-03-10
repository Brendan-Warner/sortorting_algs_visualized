
#include <iostream>
#include <vector>
#include <fstream>

std::string file_output = "array_output.txt";

using namespace std;

bool user_choice()
{
	char userChoice = ' ';
	cout << "Would you like to create the array or have it randomized? enter y for creating your own array, and any other character for a randomized array" << endl;
	cin >> userChoice;

	if (userChoice == 'y')
	{

		return true;
	}



	return false;
}

void create_array_user(vector<int>& to_sort, int& max, int size)
{
	int i = 0;
	int input = 0;
	for (i = 0; i < size; i++)
	{
		cout << "Please enter the next number of the vector" << endl;
		cin >> input;
		to_sort.push_back(input);

		if (input > max)
		{
			max = input;
		}

	}


}

void create_array(vector<int>& to_sort, int max, int size)
{
	int i = 0;
	int input = 0;
	


	for (i = 0; i < size; i++)
	{
		srand(time(0) + (i + max));

		input = rand() % max;
		to_sort.push_back(input);

		if (input > max)
		{
			max = input;
		}

	}


}

void print_array(vector<int> to_sort, int max, bool output)
{
	ofstream user_file;

	if (output)
	{
		user_file.open(file_output, ios::app);
	}
	int i = 0, j = 0;
	for (i = max; i > 0; i--)
	{
		for (j = 0; j < to_sort.size(); j++)
		{
			if (to_sort[j] >= i)
			{
				cout << "* ";

				if (user_file)
				{
					user_file << "* ";
				}
			}

			else
			{
				cout << "  ";

				if (user_file)
				{
					user_file << "  ";
				}

			}

		}
		cout << endl;
		if (user_file)
		{
			user_file << endl;
		}

	}

	for (j = 0; j < to_sort.size(); j++)
	{
		cout << to_sort[j] << " ";
		if (user_file)
		{
			user_file << to_sort[j] << " ";
		}

	}
	cout << endl;
	if (user_file)
	{
		user_file << endl;
		user_file.close();
	}



}



void print_array(vector<int> to_sort, int max, int to_swap_1, int to_swap_2, bool output)
{
	ofstream user_file;

	if (output)
	{
		user_file.open(file_output, ios::app);
	}

	int i = 0, j = 0;
	for (i = max; i > 0; i--)
	{
		for (j = 0; j < to_sort.size(); j++)
		{
			if (to_sort[j] >= i)
			{

				cout << "* ";

				if (user_file)
				{
					user_file << "* ";
				}
			}

			else
			{
				cout << "  ";

				if (user_file)
				{
					user_file << "  ";
				}

			}

		}
		cout << endl;
		if (user_file)
		{
			user_file << endl;
		}

	}

	for (j = 0; j < to_sort.size(); j++)
	{
		cout << to_sort[j] << " ";
		if (user_file)
		{
			user_file << to_sort[j] << " ";
		}

	}

	cout << endl;
	if (user_file)
	{
		user_file << endl;
	}


	for (j = 0; j < to_sort.size(); j++)
	{
		if (j != to_swap_1 && j != to_swap_2)
		{
			cout << "  ";
			if (user_file)
			{
				user_file << "  ";
			}
			continue;
			
		}
		cout << "^ ";
		if (user_file)
		{
			user_file << "^ ";
		}
	}
	cout << endl;

	if (user_file)
	{
		user_file << endl;
	}

	for (j = 0; j < to_sort.size(); j++)
	{
		if (j != to_swap_1 && j != to_swap_2)
		{
			cout << "  ";
			if (user_file)
			{
				user_file << "  ";
			}
			continue;
		}
		cout << "| ";
		if (user_file)
		{
			user_file << "| ";
		}
	}

	cout << "\nThe postions that have been swapped are marked with the arrows, which are " << to_swap_1 << " " << to_swap_2 << endl;
	if (user_file)
	{
		user_file << "\nThe postions that have been swapped are marked with the arrows, which are " << to_swap_1 << " " << to_swap_2 << endl;
		user_file.close();
	}



}


//version for mergesort since its so different from the others//////


void print_array_merge(vector<int> combined_vec, vector<int> working_vec_left, vector<int> working_vec_right, int max, bool output)
{
	ofstream user_file;

	if (output)
	{
		user_file.open(file_output, ios::app);

	}
	int i = 0, j = 0;

	cout << "\n---------------------------------------------\n";
	cout << "current size of the left vecoter " << working_vec_left.size() << " current size of the right vecotr " << working_vec_right.size() << endl;

	if (user_file)
	{
		user_file << "\n---------------------------------------------\n";
		user_file << "current size of the left vecoter " << working_vec_left.size() << " current size of the right vecotr " << working_vec_right.size() << endl;
	}

	//this is for printing out the sub vectors currently being worked on.
	for (i = max; i > 0; i--)
	{
		//we are first printing out the stars to show the visual of the numbers to be sorted, starting with the left one
		for (j = 0; j < working_vec_left.size(); j++)
		{
			if(working_vec_left[j] >= i )
			{
				cout << "* ";
				if (user_file)
				{
					user_file << "* ";
				}
			}

			else
			{
				cout << "  ";
				if (user_file)
				{
					user_file << "  ";
				}

			}

		} 

		cout << "   ";
		if (user_file)
		{
			user_file << "   ";
		}

		//printo out the right vectors stars
		for (j = 0; j < working_vec_right.size(); j++)
		{
			if (working_vec_right[j] >= i)
			{
				cout << "* ";
				if (user_file)
				{
					user_file << "* ";
				}
			}

			else
			{
				cout << "  ";
				if (user_file)
				{
					user_file << "  ";
				}

			}

		}
		cout << endl;
		if (user_file)
		{
			user_file << endl;
		}

	}

	//this is for printing the numbers of the working vector left
	for (i = 0; i < working_vec_left.size(); i++)
	{
		cout << working_vec_left[i] << " ";
		if (user_file)
		{
			user_file << working_vec_left[i] << " ";
		}

	}

	cout << "   ";
	if (user_file)
	{
		user_file << "   ";
	}

	//this is for printing out the numbers of the working vector right
	for (i = 0; i < working_vec_right.size(); i++)
	{
		cout << working_vec_right[i] << " ";
		if (user_file)
		{
			user_file << working_vec_right[i] << " ";
		}

	}

	
	//this is doing the same as above but for the current start of the combined vector.
	for (i = max; i > 0; i--)
	{
		for (j = 0; j < combined_vec.size(); j++)
		{
			if (combined_vec[j] >= i)
			{
				cout << "* ";
				if (user_file)
				{
					user_file << "* ";
				}
			}

			else
			{
				cout << "  ";
				if (user_file)
				{
					user_file << "  ";
				}

			}

		}
		cout << endl;
		if (user_file)
		{
			user_file << endl;
		}

	}

	for (i = 0; i < combined_vec.size(); i++)
	{
		cout << combined_vec[i] << " ";
		if (user_file)
		{
			user_file << combined_vec[i] << " ";
		}

	}

	cout << "\ncurrent combined vector" << endl;
	cout << "\n---------------------------------------------\n\n\n";

	if (user_file)
	{
		user_file << "\ncurrent combined vector" << endl;
		user_file << "\n---------------------------------------------\n\n\n";
		user_file.close();
	}




}
