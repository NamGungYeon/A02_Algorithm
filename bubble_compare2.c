#include <stdio.h>

#include<stdlib.h>

#include<time.h>

 

#define MAX 50000

#define SWAP(a,b)  {int t; t = a; a=b; b=t;}

 

int max2 = 10;

void ViewArr(int *arr);

void BubbleSort(int *base);

void BubbleSort2(int *base);

int main(void)

{

	int arr[MAX];

	int arr2[MAX];

	int i = 0;

	int j = 0;

	clock_t s1, e1, s2, e2;

 

	srand((unsigned)time(NULL));

	for (max2 = 1000; max2 < 50000; max2 += 1000)

	{

		for (i = 0; i < MAX; i++)

		{

			arr[i] = rand();

			arr2[i] = arr[i];

		}

 

		s1 = clock();

		BubbleSort(arr);

		e1 = clock();

 

		s2 = clock();

		BubbleSort2(arr2);

		e2 = clock();

		printf("Size: %5d\t [Original : %f Sec]\t",max2,  (double)(e1 - s1) / CLOCKS_PER_SEC);

		printf("[Enhanced : %f Sec]\t",  (double)(e2 - s2) / CLOCKS_PER_SEC);

		printf("\t[Result : %f Sec]\n",  (double)((e1 - s1) - (e2 - s2)) / CLOCKS_PER_SEC);

	}

	return 0;

}

void BubbleSort(int *base)

{

	int i, j;

	for (i = max2; i > 1; i--)

	{

		for (j = 1; j < i; j++)

		{

			if (base[j - 1] > base[j])

			{

				SWAP(base[j - 1], base[j]);

			}

		}

	}

}

void BubbleSort2(int *base)

{

	int i, j;

	int m = 0, n = max2 - 1;

	int swap, sum = 0, avg;

	int arr3[MAX];

	for (i = 0; i < max2; i++)

		sum += base[i];

	avg = sum / max2;

	for (i = 0; i < max2; i++)

	{

		if (base[i] <= avg)

		{

			arr3[m] = base[i];

			m++;

		}

		else

		{

			arr3[n] = base[i];

			n--;

		}

	}

 

	for (i = max2; i > 1; i--)

	{

		swap = 0;

		for (j = 1; j < i; j++)

		{

			if (arr3[j - 1] > arr3[j])

			{

				SWAP(arr3[j - 1], arr3[j]);

				swap++;

			}

		}

		if (swap == 0)

			break;

	}

}

 

void ViewArr(int *arr)

{

	int i = 0;

	for (i = 0; i < MAX; i++)

	{

		printf("%2d ", arr[i]);

	}

	printf("\n");

}

