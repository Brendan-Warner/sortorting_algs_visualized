
int user_choice()
{
	char userChoice = ' ';
	cout << "Would you like to create the array or have it randomized" << endl;
	cin >>userChoice;
	
	if(userChoice = 'y')
	{
		return true;
	}
	
	
	
	return false;
}

create_array_user(vector<int_arr>& to_sort, int max, int size)
{
	int i = 0;
	int input = 0;
	for(i = 0; i < size; i++)
	{
		cout << "Please enter the next number of the vector" << end;
		cin >> input;
		to_sort.push_back(input);
		
		if(input > max)
		{
			max = input;
		}
		
	}
	
	
}

create_array(vector<int_arr>& to_sort, int max, int size)
{
	int i = 0;
	int input = 0;
	for(i = 0; i < size; i++)
	{
		srand(time(0) + (i+max);
		
		input = rand() % 12;
		to_sort.push_back(input);
		
		if(input > max)
		{
			max = input;
		}
		
	}
	
	
}

void print_array(vector<int_arr> to_sort, int max)
{
	int i = 0, j = 0;
	for(i = 0, i < max; i++)
	{
		for(j = 0; j< to_sort.size(); j++)
		{
			if(to_sort[j]->num >= max)
			{
				cout << "* "
			}
			
		}
		cout << endl;
		
	}
	
	
	
}