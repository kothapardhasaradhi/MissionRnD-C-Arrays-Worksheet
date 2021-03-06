/*
OVERVIEW:  You are given scores for students of a class in alphabetical order. Write a function that sorts these scores in descending order.
Input is array of structures of type student (each student has name and score).
E.g.: If input is [ { "stud1", 20 }, { "stud2", 30 }, { "stud3", 40 } ] (three students with marks 20, 30 , 40).
Output for this will be [ { "stud3", 40 }, { "stud2", 30 }, { "stud1", 20 } ]

INPUTS: Array of structures of type student, length of array.

OUTPUT: Sort the array in descending order of scores.

ERROR CASES: Return NULL for invalid Inputs.

NOTES:
*/

#include <stdio.h>
#include<stdlib.h>
struct student {
	char name[10];
	int score;
};
void sorting(struct student *students, int start, int end)
{
	int pivot, i, j;
	struct student temp;

	if (start < end)
	{
		pivot = start;
		i = start;
		j = end;

		
		while (i < j)
		{
			while (students[i].score >= students[pivot].score && i < end)
			{
				i++;
			}
			while (students[j].score<students[pivot].score)
			{
				j--;
			}

			if (i<j)
			{
				temp = students[i];
				students[i] = students[j];
				students[j] = temp;
			}
		}

		
		temp = students[pivot];
		students[pivot] = students[j];
		students[j] = temp;

		
		sorting(students, start, j - 1);
		sorting(students, j + 1, end);
	}
}
void * scoresDescendingSort(struct student *students, int len) {
	if (students == NULL || len <= 0)
		return NULL;

	sorting(students, 0, len - 1);

	return NULL;

}
