#include <stdio.h>
#include "function.h" 
void Transpose( int* row, int* col, int matrix[][500] ){
	int i,j,temp,arr[(*row)* (*col)],k = 0;
	temp = *row;
	*row = *col;
	*col = temp;
	for(i = 0; i < *row; i++){
		for(j = 0; j < *col; j++){
			arr[k] = matrix[j][i];
			k++;
		}
	}
	k = 0;
	for(i = 0; i < *row; i++){
		for(j = 0; j < *col; j++){
			matrix[i][j] = arr[k];
			k++;
		}
	}
}
