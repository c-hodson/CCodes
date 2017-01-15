#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

//function1 open text file
double func1 (double array1[12], double array2[12]){
int ii,jj;
FILE *fid1;
double angle, lift;
	//open and read file
		fid1=fopen("liftcoeff.txt","r");
	
		//if file reading wrong message
		if(fid1 != NULL){
			for(ii=0; ii<=11; ii=ii+1){
			//scan in values
			fscanf(fid1, "%lf %lf", &array1[ii], &array2[ii]);
			//print angle and lift into array 
			printf("%lf %lf\n", array1[ii], array2[ii]);
			}
			}
	
		else { 
		//print error if not ok
		printf("Could not open file 1!\n");
		}
	fclose(fid1);
return(0);
}
	
int main (){
double array1[12], array2[12];

func1(array1,array2);

return(0);
}
