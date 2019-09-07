#include <iostream>
#include <vector>

using namespace std;

int binarySearch(vector<int> numbers, int target, int index_low, int index_high)
{
	int index = (index_low + index_high)/2;
	
	if (index_low > index_high)
		return -1;
	else if (numbers.at(index) == target)
		return index;
	else if (numbers.at(index) > target)
		return binarySearch(numbers, target, index_low, index - 1);
	else if (numbers.at(index) < target)
		return binarySearch(numbers, target, index + 1, index_high);
}

int main()
{
	vector<int> numbers;
	numbers.push_back(1);
	numbers.push_back(2);
	numbers.push_back(3);
	numbers.push_back(4);
	numbers.push_back(5);
	numbers.push_back(6);
	numbers.push_back(7);
	numbers.push_back(8);

	int index = binarySearch(numbers, 1, 0, numbers.size()-1);

	if (index != -1)
		cout << "Found at index: " << index << endl;
	else
		cout << "Not Found" << endl;

}