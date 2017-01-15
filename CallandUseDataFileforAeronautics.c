#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

int main (){
int ii,jj;
FILE *fid1;
double angle, lift, array1[ii], array2[jj];

	for(ii=0; ii<=11; ii=ii+1){
		for (jj=0; jj<=1; jj=jj+1){
		
		//open and read file
		fid1=fopen("liftcoeff.txt","r");
	
		//if file reading wrong message
		if(fid1 != NULL){
	
		//read until end of file 
		while(feof(fid1) ==0){
		fscanf(fid1, "%lf %lf", &array1[ii], &array2[jj]);
		
		//print angle and lift into array 
		printf("%lf %lf\n", array1[ii], array2[jj]);
	
	}
	fclose(fid1);
	}
	else { 
	//print error if not ok
	printf("Could not open file 1!\n");
	}
	return(0);
	}}}
