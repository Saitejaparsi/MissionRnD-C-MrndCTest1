/*
Given an array which has two arithmetic sequences and 
one geometric sequence (in any order).
Copy indexes where each sequence starts and ends into an Array and return it.

Note : Each sequence will be of atleast LENGTH 3,and The sequences can be overlapping

Ex : 1, 3, 5, 7, 2, 4, 8, 16 18 20, output is [0, 3, 7, 9, 4, 7]
Ex : 1 ,2, 4, 8, 12, 16, 21, 26     output is [2, 5, 5, 7, 0, 3]
Ex : 10 15 20 30 50 70 100 200 400 800  output is [0, 2, 3, 5, 6, 9]

The final_arr[0], final_arr[1] values in final array  
will be start and end indexes of First A.P in the Original Array

The final_arr[2], final_arr[3] values in final array  
will be start and end indexes of Second A.P 

The final_arr[4], final_arr[5] values in final array  
will be start and end indexes of First  G.P (Only)

Input: Array and Length of Array
Output : New Array which has 6 integers , which denote the (start,end) indexes .

Note : All elements in the array will be part of atleast 1 sequence .
Two A.P cannot start at same index . 

Difficulty : Medium
*/

#include <stdlib.h>
#include <stdio.h>
#include <math.h>
int * find_sequences(int *arr, int len){
	if(len<6)
		return NULL;
	else
	{
		int d1 = 0, r = 0, i = 0, j = 0, k=-1,*m,count=0;
		m = (int *)malloc(6 * sizeof(int));
		for(i = 0; i < len; i++)
		{
			d1 = arr[j + 1] - arr[j];
			if (d1 == arr[i + 2] - arr[i+1]){
				for (; i < len; i++){
					if (d1 != arr[i + 1] - arr[i]){
						k++;
						*(m+k) = j;
						count = 1;
						j = i+1;
						k++;
						*(m + k) = i;
						break;
					}
				}
				if (i + 2>len)
					*(m + k) = len - 1;
			}
			else{
				r = arr[j + 1] / arr[j];
				if (count == 1 && r == arr[j] / arr[j - 1])
					*(m+4) = i - 1;
				else
					*(m+4) = i;
				if (i + 2 > len - 1){
					*(m+5) = i + 1;
					break;
				}
				else if (r == arr[i+ 2] / arr[i+ 1]){
					for (; i < len; i++)
					{
						if (r != arr[i + 2] / arr[i + 1])
						{
							j = i + 1;
							k++;
							*(m+5) = i;
							break;
						}
					}
				}
			}
		}
		return m;
	}
}