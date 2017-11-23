#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

void Comp(int *arr, int left, int mid, int right)
{
	int *arr_new = (int*)malloc((right-left) * sizeof(int));

	int i = 0, j = 0;
	 
	while ((left + i < mid) && (mid + j < right))
	{
		if (arr[left + i] < arr[mid + j])
		{
			arr_new[i + j] = arr[left + i];
			i++;
		}
		else
		{
			arr_new[i + j] = arr[mid + j];
			j++;
		}
	}

	while (left + i < mid)
	{
		arr_new[i + j] = arr[left + i];
		i++;
	}

	while (mid + j + 1 < right)
	{
		arr_new[i + j] = arr[mid + j];
		j++;
	}

	for (int x = 0; x < i + j; x++)
	{
		arr[left + x] = arr_new[x];
	}

	free(arr_new);
}

void MergeSort(int *arr, int left, int right)
{
	int mid;
	if (left + 1 < right)
	{
		mid = (left + right) / 2;
		MergeSort(arr, left, mid);
		MergeSort(arr, mid, right);
		Comp(arr, left, mid, right);
	}
}

void test(int *arr_sort, int *arr_true, int len)
{
	int wrong_idx = 0;
	bool correct_result = true;
	MergeSort(arr_sort, 0, len);

	for (int i = 0; i < len; i++)
	{
		if (arr_sort[i] != arr_true[i])
		{
			correct_result = false;
			wrong_idx = i;
			break;
		}
	}

	if (correct_result == false)
	{
		printf("Error at idx %i, got %i, expected %i\n", wrong_idx, arr_sort[wrong_idx], arr_true[wrong_idx]);
	}
	else printf("Array sorted true\n");
}

int main(void)
{
	int len = 10;
	int arr[10] = {5,9,4,10,5,2,8,3,1,6};
	int arr_sort[10] = {1,2,3,4,5,5,6,8,9,10};

	/*for (int i = 0; i < len; i++)
	{
		arr[i] = rand()%10;
	}*/

	for (int i = 0; i < len; i++)
	{
		printf("%i_", arr[i]);
	}
	printf("\n");

	test(arr, arr_sort, len);

	return 0;
}