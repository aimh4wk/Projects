#include <iostream>
#include <iomanip>
#include <vector>
#include <ctime>
#include <string>

#define MAX_NUM 100	// Largest number generated by srand
#define MAX_ELEMENTS 20 // Largest number of elements generates
#define MAX_VECTOR 10 // The amount of vectors to be displayed

using namespace std;
void quickSortHelper(vector<int>&, int, int);
int partition(vector<int>&, int, int);
string ordinal(int i);

int main()
{
	vector<int> randomNums;	// Vector of random integers
	srand((int)time(NULL));

	// Main Loop
	for (int i = 0; i < MAX_VECTOR; i++)
	{
		int a = rand() % MAX_ELEMENTS; // Create a random number of elements not greater than the maximum number of elements
			for (int i = 0; i < a; i++)
			{
				int b = rand() % MAX_NUM; // Create a random number of integers not greater than 100
				randomNums.push_back(b);
		}
			
			cout << "The " << i + 1 << ordinal(i + 1) << " set of data(" << a << "):" << endl;
			// Output original data
			if (a == 0) {
				cout << "The vector is empty.\n\n";
			}
			else if (a == 1)
			{
				cout << "Initial vector value is: " << endl;
				for (auto e : randomNums)
				{
					cout << setw(3) << e << " ";
				}
				cout << endl;
			}
			if (a >= 2) {
				cout << " Initial vector values are: " << endl;
				cout << "  ";
				for (auto e : randomNums)
				{
					cout << setw(3) << e << " ";
				}
				cout << endl;
			}
			
			int p = 0;
			quickSortHelper(randomNums, p, a); // Call quicksort function
			// Output modified data
			if (a == 0)
			{
				cout << "The sorted vector is empty.";
			}

			else if (a == 1)
			{
				cout << "Vector is sorted: " << endl;
				for (auto e : randomNums)
				{
					cout << setw(3) << e << " ";
				}
				cout << endl;
			}
			if (a >= 2)
			{
				cout << " The sorted vector values are: " << endl;
				cout << "  ";

				for (auto e : randomNums)
				{
					cout << setw(3) << e << " ";
				}
			}
			
			randomNums = {}; // Create an empty vector
			cout << endl << endl;
	}
	system("pause");
	return 0;
} // end main

// *******************************************
// Quicksort Function - Displays sorted values
// *******************************************
void quickSortHelper(vector<int>& randomNums, int p, int a)
{
	int r;
	if (p < a)
	{
		r = partition(randomNums, p, a);
		quickSortHelper(randomNums, p, r);
		quickSortHelper(randomNums, r + 1, a);
	}
} // end quicksort function

// *****************************
// Partitionion Function - Takes the first element of the unsorted vector and determines its final location in the sorted vector
// *****************************
int partition(vector<int>& randomNums, int p, int a)
{
	int x = randomNums[p];
	int i = p;
	int j;
	
	for (j = p + 1; j < a; j++)
	{
		if (randomNums[j] <= x)
		{
			i = i + 1;
			swap(randomNums[i], randomNums[j]);
		}
	}
	swap(randomNums[i], randomNums[p]);
	return i;
}


// *******************************
// Ordinal Function - Not the most efficient but a quick way to receive an ordinal suffix for the specific data set being displayed in this program.
// *******************************
string ordinal(int i)
{
	switch (i)
	{
	case 1:
		return "st";
	case 2:
		return "nd";
	case 3:
		return "rd";
	case 4:
		return "th";
	case 5:
		return "th";
	case 6:
		return "th";
	case 7:
		return "th";
	case 8:
		return "th";
	case 9:
		return "th";
	case 10:
		return "th";
		break;
	default:
		cout << "Exceeds maximum number of vectors.\n";
		return 0;
	}
}
