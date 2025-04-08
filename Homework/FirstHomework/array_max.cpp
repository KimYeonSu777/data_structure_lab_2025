#include <stdio.h>
#include <vector>
#include <iostream>

int main() {

	std::vector<int> input_array;
	int i = 0;
	int num;
	int array_size = 0;
	int array_max = 0;

	using namespace std;

	printf("배열의 크기를 입력하세요: ");
	scanf_s("%d", &array_size);

	//Purpose: 배열의 값을 사용자로부터 입력 받는다.
	for (i = 0; i < array_size; i++) {
		printf("%d번째 값을 입력하세요: ",i+1);
		cin >> num;
		input_array.push_back(num);
	    // printf("input_array[%d] = %d\n", i, input_array[i]);
	}

	//Purpose: 순차적으로 비교하여 array_max 값을 찾는다.
	array_max = input_array[0];

	for (i = 0; i < array_size; i++) {
		if (input_array[i] > array_max)
			array_max = input_array[i];
	}

	printf("\narray_max = %d\n", array_max);

	return 0;
}