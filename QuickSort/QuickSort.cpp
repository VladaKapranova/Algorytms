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

int main(void)
{
	int n = 10;
	int *b = (int*)malloc(n * sizeof(int));
	for (int k = 0; k < n; k++)
		b[k] = rand()% 10 + 1;
	for (int k = 0; k < n; k++)
		printf("%i\n", b[k]);
	printf("\n");
	quicksort(b, n);
	printf("\n");
	for (int k = 0; k < n; k++)
		printf("%i\n", b[k]);
	free(b);
	return 0;
}

