#include <stdio.h>
#include<stdlib.h>
#include<time.h>

#define SWAP(a,b)  {int t; t = a; a=b; b=t;}
void BubbleSort(int *base, int max);

int main(int argc, char** argv)
{

	int max = atoi(argv[1]);
	int arr[max];
	int i = 0;
	int j = 0;
	clock_t s1, e1;
	srand((unsigned)time(NULL));
	for (i = 0; i < max; i++)
		arr[i] = rand();
 
	s1 = clock();
	BubbleSort(arr, max);
	e1 = clock();

	printf("bubble_enhanced\nFinished %.3fsec\n", (double)(e1 - s1)/CLOCKS_PER_SEC);
	
	return 0;
}

void BubbleSort(int *base, int max)
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

