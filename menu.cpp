#include <iostream>
#include <vector>
#include "menu.h"
#include "bubble_sort.h"
#include "quick_sort.h"
#include "selection_sort.h"
#include "merge_sort.h"
#include "output.h"



using namespace std;


//main function, asks the user everything from which alg they want to if they want to include walls and if the graph is weighted at all.
void menuFunc()
{
	int size = 0; output = 0, algo_choice = 0;
	char  choiceFile = ' ';
	bool outputFile = false;
	
	
	cout << "Hello, welcome to this algorithim visualization program" << endl;
	cout << "Here, you will select a sorting algorithm to operate on an array.." << endl;
	cout << "The visulaiszation number is for how many times the visuization will appear, inputing zero will have the final sorted array appear only. " << endl;
	
	
	

	cout << "how large would you like your array to be?" << endl;
	cin >> size;
	cout << "Please enter how much you would like to refresh the array." << endl;
	cin >> output;
	
	
	cout << "Would you like your output to go to a file?" << endl;
	cin >>  choiceFile;
	
	if(choiceFile == 'y')
	{
		outputFile = true;
	}
	
	cout << "Which algorithm would you like to use? input 1 bubble sort, 2 for quick sort, 3 for insertion sort, 4 for selection sort, and 5 for merge sort" << endl;
	cin >> algo_choice;
	
	
	if(algo_choice == 1)
	{
		bubble_sort(size, output, outputFile);
	}
	
	else if(algo_choice == 2)
	{
		quick_sort(size, output, outputFile);
	}
	
	else if(algo_choice == 3)
	{
		insertion_sort(size, output, outputFile);
	}
	else if(algo_choice == 4)
	{
		selection_sort(size, output, outputFile);
	}
	
	else if(algo_choice == 5)
	{
		merge_sort(size, output, outputFile);
	}
	
	
	
	
}

