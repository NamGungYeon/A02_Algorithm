#include <stdio.h>
#include<stdlib.h>
#include<time.h>

#define SWAP(a,b)  {int t; t = a; a=b; b=t;}
void BubbleSort(int *base, int max);
void BubbleSort_enhanced(int *base, int max);

int main(int argc, char** argv)
{

	int max = atoi(argv[1]);
	int arr[max], arr2[max];
	int i = 0;
	int j = 0;
	clock_t s1, e1, s2, e2;
	srand((unsigned)time(NULL));
	for (i = 0; i < max; i++)
	{
		arr[i] = rand();
		arr2[i] = arr[i];
	} 
	s1 = clock();
	BubbleSort(arr, max);
	e1 = clock();
	s2 = clock();
	BubbleSort_enhanced(arr2, max);
	e2 = clock();
	
	printf("Original : %.3f Sec\n", (float)(e1-s1)/CLOCKS_PER_SEC);
	printf("Enhanced : %.3f Sec\n", (float)(e2-s2)/CLOCKS_PER_SEC);
	printf("Result : %.3fSec\n", (float)((e1 - s1)-(e2 - s2))/CLOCKS_PER_SEC);
	
	return 0;
}

void BubbleSort(int *base, int max)
{
	int i, j;
	for (i = max; i > 1; i--)
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
void BubbleSort_enhanced(int *base, int max)
{
	int i, j;
	int m = 0, n = max - 1;
	int swap, sum = 0, avg;
	int arr3[max];
	for (i = 0; i < max; i++)
		sum += base[i];
	avg = sum / max;
	for (i = 0; i < max; i++)
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
	for (i = max; i > 1; i--)
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


