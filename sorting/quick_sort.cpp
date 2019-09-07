#include <iostream>
#include <vector>

using namespace std;

int partition(vector<int>& numbers, int low, int high)
{
	int pivot = numbers.at(high);
	int i = low - 1;

	for (int j = low; j < high; j++)
	{
		if (numbers.at(j) <= pivot)
		{
			i++;
			swap(numbers.at(i), numbers.at(j));
		}
	}

	swap(numbers.at(i + 1), numbers.at(high));
	return i + 1;
}

void quick_sort(vector<int>& numbers, int low, int high)
{
	if (low < high)
	{
		int partition_index = partition(numbers, low, high);
		quick_sort(numbers, low, partition_index - 1);
		quick_sort(numbers, partition_index + 1, high);
	}
}


int main()
{
	vector<int> numbers;
	numbers.push_back(10);
	numbers.push_back(2);
	numbers.push_back(7);
	numbers.push_back(22);
	numbers.push_back(100);
	numbers.push_back(1);
	numbers.push_back(5);
	numbers.push_back(20);

	cout << "Unsorted Vector: " << endl;
	vector<int>::iterator numbersIterator;

	for (numbersIterator = numbers.begin(); numbersIterator != numbers.end(); numbersIterator++)
		cout << *numbersIterator << " ";

	cout << endl;
	quick_sort(numbers, 0, numbers.size() - 1);

	cout << "Sorted Vector: " << endl;

	for (numbersIterator = numbers.begin(); numbersIterator != numbers.end(); numbersIterator++)
		cout << *numbersIterator << " ";
}