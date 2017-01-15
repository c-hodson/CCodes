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

//function2 using linear interpolation to output lift coefficient
double func2 (double angle, double array1[12], double array2[12]){
double liftcoef, m;
int ii;

for(ii=0; ii<=12; ii=ii+1){

	//check for duplicate
	if (array1[ii]==angle){
	printf("The value already exists and is %lf\n",array2[ii]);
	{
	break;}
	}
	
	
	if (array1[ii+1]>angle){
	//linearly interpolate

	//find gradient
	m=((array2[ii+1]-array2[ii])/(array1[ii+1]-array1[ii]));
	//find yq
	liftcoef=(m*(angle-array1[ii])+array2[ii]);
	//print lift coefficient
	printf("lift coefficient =%lf\n", liftcoef);
	return(0);
	}
}

return(0);
	
 }
	
int main (){
double array1[12], array2[12], angle, liftcoef;

	// run function
	func1(array1,array2);
	
	// ask for user to input angle and scan angle
	printf("Input value for angle of attack: \n");
	scanf("%lf", &angle);

	//run function2 
	func2(angle,array1,array2);
	
return(0);
}