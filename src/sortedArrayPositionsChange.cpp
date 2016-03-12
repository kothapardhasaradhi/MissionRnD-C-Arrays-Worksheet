/*
OVERVIEW: In a given ascending sorted array, two numbers are changed their position, please fix those two numbers.
E.g.: In [10, 40, 30, 20, 50] 20 and 40 are swapped, so final output will be [10, 20, 30, 40, 50]

INPUTS: Ascending sorted array with two positions swapped, length of the array.

OUTPUT: Update sorted array by fixing swapped numbers.

ERROR CASES: Return NULL for invalid Inputs.

NOTES:
*/

#include <stdio.h>

void * sortedArrayPositionsChange(int *Arr, int len)
{
	if (len > 0 && Arr != NULL)
	{
		int i, t1 = -1, t2 = -1, t;
		for (i = 0; i < len; i++)
		{
			if (t1 == -1)
			{
				if (Arr[i]>Arr[i + 1])
				{
					t1 = i;
					i++;
				}
			}
			else
			{
				if (Arr[i] < Arr[i - 1])
				{
					t2 = i;
				}
			}
		}
		if (t2 == -1)
		{
			t = Arr[t1];
			Arr[t1] = Arr[t1 + 1];
			Arr[t1 + 1] = t;
		}
		else
		{
			t = Arr[t1];
			Arr[t1] = Arr[t2];
			Arr[t2] = t;
		}
	}
	else
		return NULL;
}