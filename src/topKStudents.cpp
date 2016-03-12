/*
OVERVIEW:  You are given scores for students of a class in alphabetical order. Write a function that returns the names and scores of top K students.
Input is array of structures of type student (each student has name and score).
E.g.: If input is [ { "stud1", 20 }, { "stud2", 30 }, { "stud3", 40 } ] (three students with marks 20, 30 , 40) and K value is 2.
return top 2 students [ { "stud2", 30 }, { "stud3", 40 } ]

INPUTS: array of structures of type student, length of the array, integer K.

OUTPUT: Return top K students from array. Output need not be in decreasing order of scores.

ERROR CASES: Return NULL for invalid inputs.

NOTES:
*/

#include <iostream>
#include <malloc.h>

struct student {
	char *name;
	int score;
};
void sort(struct student *students, int start, int end)
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


		sort(students, start, j - 1);
		sort(students, j + 1, end);
	}
}

struct student ** topKStudents(struct student *students, int len, int K)
{
	struct student **arr;
	arr = (struct student**)malloc(2 * sizeof(struct student));
	if (students == NULL || len <= 0 || K <= 0)
		return NULL;

	sort(students, 0, len - 1);
	for (int i = 0; i < K; i++)
	{
		arr[i] = &students[i];
	}
	return arr;

	return NULL;
}