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

	printf("bubble_original\nFinished %.3fsec\n", (double)(e1 - s1)/CLOCKS_PER_SEC);
	
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

