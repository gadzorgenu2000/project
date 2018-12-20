#include <iostream>
using namespace std;

void binary_search(int *arr, int search, int len);

int main() {
	int arr[10] = {1,2,3,4,5,6,7,8,9,10};

	//Length of the array
	int len = 10;
	
	//we want to search for the number 7
	int search = 7;
	
	binary_search(arr, search, len);
	
	return 0;
}


// arr = array that contains items/numbers
//search = number you want to find its location
// len = length of the array

void binary_search(int *arr, int search, int len) {
	int first, last, middle;
	first = 0;
	last = len-1;
	middle = (first+last)/2;
	
	while (first <= last)
	{
		if(arr[middle] < search)
		{
			first = middle + 1;

		}
		else if(arr[middle] == search)
		{
			cout<<search<<" found at location "<<middle+1<<"\n";
			break;
		}
		else
		{
			 last = middle - 1;
		}
		middle = (first + last)/2;
	}
	if(first > last)
	{
		cout<<"Not found! "<<search<<" is not present in the list.";
	}
	
}
