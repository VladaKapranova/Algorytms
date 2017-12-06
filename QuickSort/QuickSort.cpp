#include <stdio.h>  
#include <malloc.h> 
#include <stdlib.h> 

void quicksort(int *a, int n)
{
	for (;;)
	{
		if (n < 2)
			return;
		int i = 0, j = n - 1;
		int p = 0; 
		if (n == 2)
			p = a[n / 2];
		else
		{
			p = a[0]>a[n / 2] ? a[0] : a[n / 2];
			p = p<a[n - 1] ? p : a[n - 1];
		}
		do
		{
			while (a[i] < p)
				i++;
			while (a[j] > p)
				j--;
			if (i <= j)
			{
				int k = a[i];
				a[i] = a[j];
				a[j] = k;
				i++;
				j--;
			}
		} while (i <= j);
		
		if ((j + 1) > (n - 1))
		{
			quicksort(a, j + 1);
			a = a + i;
			n = n - i;
		}
		else
		{
			quicksort(a + i, n - i);
			n = j + 1;
		}
	}
}

void print(int *arr, int len)
{
	for (int i = 0; i < len; i++)
	{
		printf("%i_", arr[i]);
	}
	printf("\n");
}

void test(int *arr_sort, int *arr_true, int len)
{
	if (len != 0)
	{
		int wrong_idx = 0;
		bool correct_result = true;
		quicksort(arr_sort, len);

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
	else printf("Array hasn't elements\n");
}

int main(void)
{
	int len1 = 10, len2 = 1, len3 = 2, len4 = 6, len5 = 5, len6 = 7;
	int arr1[10] = {5,9,4,10,5,2,8,3,1,6};
	int arr_sort1[10] = {1,2,3,4,5,5,6,8,9,10};
	int arr2[1] = {5};
	int arr_sort2[1] = {5};
	int arr3[2] = { 5,3 };
	int arr_sort3[2] = { 3,5 };
	int arr4[6] = { 1,2,3,4,5,6 };
	int arr_sort4[6] = { 1,2,3,4,5,6 };
	int arr5[5] = { 10,9,8,7,6 };
	int arr_sort5[5] = { 6,7,8,9,10 };
	int arr6[7] = { 7,7,7,7,7,7,7 };
	int arr_sort6[7] = { 7,7,7,7,7,7,7 };
	
	print(arr1, len1);
	test(arr1, arr_sort1, len1);

	print(arr2, len2);
	test(arr2, arr_sort2, len2);

	print(arr3, len3);
	test(arr3, arr_sort3, len3);

	print(arr4, len4);
	test(arr4, arr_sort4, len4);

	print(arr5, len5);
	test(arr5, arr_sort5, len5);

	print(arr6, len6);
	test(arr6, arr_sort6, len6);
	
	int *arr7 = (int*)malloc(0 * sizeof(int));
	test(arr7, arr7, 0);
	free(arr7);
	return 0;
}

