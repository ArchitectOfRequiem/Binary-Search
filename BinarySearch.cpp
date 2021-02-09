#include<iostream>
#include <sstream>

struct ReturnValue
{
	int index;
	const char* msg;
	bool found;

	ReturnValue()
	{
		index = 0;
		found = false;
		msg = "";
	}
};

//O(log2n)
ReturnValue BinarySearch(int Array[], int L, int R, int Target)
{
	ReturnValue return_value;
	while (true)
	{
		int binnaryPointer = ((L + R) / 2);

		if (Array[binnaryPointer] == Target) 
		{
			return_value.found = true;
			return_value.index = binnaryPointer;
			return return_value;
		}
		else if (L >= R)
		{
			return_value.msg = "Target is not in array";
			return return_value;
		}
		else if (Array[binnaryPointer] > Target)
		{
			R = binnaryPointer - 1;
		}
		else if (Array[binnaryPointer] < Target)
		{
			L = binnaryPointer + 1;
		}
	}
}

int main()
{
	int Array[] = {1, 4, 5, 7, 10, 22, 24 ,34, 44, 56, 232, 555, 666, 900, 72872};

	ReturnValue* return_value = new ReturnValue;
	return_value = &BinarySearch(Array, 0, 15, 900);

	return_value->found ? std::cout << "Target is found at position: " << return_value->index << std::endl : std::cout << return_value->msg << std::endl;

	std::cin.get();

	return 0;
}