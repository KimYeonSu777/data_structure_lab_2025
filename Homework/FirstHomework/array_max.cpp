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

	printf("�迭�� ũ�⸦ �Է��ϼ���: ");
	scanf_s("%d", &array_size);

	//Purpose: �迭�� ���� ����ڷκ��� �Է� �޴´�.
	for (i = 0; i < array_size; i++) {
		printf("%d��° ���� �Է��ϼ���: ",i+1);
		cin >> num;
		input_array.push_back(num);
	    // printf("input_array[%d] = %d\n", i, input_array[i]);
	}

	//Purpose: ���������� ���Ͽ� array_max ���� ã�´�.
	array_max = input_array[0];

	for (i = 0; i < array_size; i++) {
		if (input_array[i] > array_max)
			array_max = input_array[i];
	}

	printf("\narray_max = %d\n", array_max);

	return 0;
}