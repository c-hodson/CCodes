# CCodes
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

//Name: Chloe Hodson
//Username: ch15270

//funtion to get u
double functionu (double x, double y) {
    double u ;
    u=1+(x/(2*4*atan(1)*((pow(x,2)+pow(y,2)))));
    return (u);
}

//funtion to get v
double functionv (double x, double y) {
    double v ;
    v=y/(2*4*atan(1)*((pow(x,2)+pow(y,2))));
    return (v);
}

//function to get xnew - Euler
double functionxnew (double x, double deltat, double y) {
    double xnew, u ;
    u=functionu(x,y);
    xnew=x+(u*deltat);
    return (xnew);
}

//function to get ynew - Euler
double functionynew (double x, double deltat, double y){
    double ynew, v;
    v=functionv(x,y);
    ynew=y+(v*deltat);
    return (ynew);
}

//function to get xbar - Runge-Kutta
double functionxbar (double x, double deltat, double y){
    double xbar, u;
    u=functionu(x, y);
    xbar=x+(0.5*u*deltat);
    return (xbar);
}

//function to get ybar - Runge-Kutta
double functionybar (double x, double deltat, double y){
    double ybar, v;
    v=functionv(x,y);
    ybar=y+(0.5*v*deltat);
    return (ybar);
}

//function to get ubar - Runge-Kutta
double functionubar (double x, double deltat, double y){
    double ubar, xbar, ybar;
    xbar=functionxbar (x,deltat,y);
    ybar=functionybar(x,deltat,y);
    ubar=functionu(xbar,ybar);
    return(ubar);
}

//function to get vbar - Runge-Kutta
double functionvbar (double x, double deltat, double y){
    double vbar, xbar, ybar;
    xbar=functionxbar (x,deltat,y);
    ybar=functionybar(x,deltat,y);
    vbar=functionv(xbar,ybar);
    return(vbar);
}

//function to get xnew - Runge-Kutta
double functionxnewRK (double x, double deltat, double y){
    double xnewRK, u, ubar;
    u=functionu (x,y);
    ubar=functionubar (x,deltat,y);
    xnewRK=x+0.5*(u+ubar)*deltat;
    return (xnewRK);
}

//function to get ynew - Runge-Kutta
double functionynewRK (double x, double deltat,double y){
    double ynewRK, v, vbar;
    v=functionv (x,y);
    vbar=functionvbar (x,deltat,y);
    ynewRK=y+0.5*(v+vbar)*deltat;
    return (ynewRK);
}

int main (){
    
    //Allocate memory
    int numberofstreamlines, counter, counter1, integrationmethod;
    double x,y,xnew,ynew,deltat,xnewRK,ynewRK;
	
    //REQUEST THE NUMBER OF STREAMLINES TO PLOT
    //Ask user to input the number of streamlines to plot
    printf("How many streamlines would you like to plot? \n");
    scanf("%i", &numberofstreamlines);
    
    //Ensure number of streamlines is between 2 and 100
    if (numberofstreamlines<2 || numberofstreamlines>100){
        do {
            printf("The number of streamlines must be between 2 and 100. Please input a new value \n");
            scanf("%i",&numberofstreamlines);
        }
        while (numberofstreamlines<2 || numberofstreamlines>100);
    }
    //Ensure the user knows the system will use the integer value
    printf("The system will create %i", numberofstreamlines);
    printf(" streamlines %\n\n");
	
    //Set up/clear Tecplot File from last use
    FILE*tecplot;
    tecplot=fopen("stream.plt","w");
	
    //Ask user which integration method they would like to use
    do { printf("Please enter '1' to use the Euler Method of integration, enter '2' to use the 2nd order Runge-Kutta Method of integration\n");
        scanf ("%i", &integrationmethod);
    }
    while (integrationmethod<1 || integrationmethod>2);
	
    //INTEGRATION METHODS
    //If user chose Euler Method
    if (integrationmethod==1){
	
        //loop to give multiple stream lines
        for (counter=0; counter<numberofstreamlines;){
		
            //Set initial y value - NOTE: different initial value required for numberofstreamlines=1
            y=-0.75+(counter*(1.5/(numberofstreamlines-1)));
            
            //Set other initial values
            x=-1;
            deltat=0.02;
			
            //Update counter
            counter=counter+1;
			
            //Set zone
            tecplot=fopen("stream.plt","a");
            fprintf(tecplot,"\nZONE T=\"zone %i\"", counter);
            fprintf(tecplot,"\n%lf %lf", x, y);
			
            //loop to plot streamline
            for(counter1=0; counter1<=200; counter1=counter1+1){
			
                //Calculate new values for x and y
                xnew=functionxnew(x,deltat,y);
                ynew=functionynew(x,deltat,y);
                x=xnew;
                y=ynew;
				
                //LIMIT STREAMLINES RANGE TO -1 TO +1
                if (x>1){break;}
                if (x<-1) {break;}
                if (y>1) {break;}
                if (y<-1) {break;}
				
                //EXPORT DATA TO TECPLOT
                fprintf(tecplot,"\n%lf %lf", xnew, ynew );
            }
        }
        //Tell User to open Graph
        printf("Your graph has now been created using the Euler integration method. Please open the file named 'stream.plt'\n");
    }
    //If user chose Runge-Kutta Method
    if (integrationmethod==2){
	
        //loop to give multiple stream lines
        for (counter=0; counter<numberofstreamlines;){
		
            //Set initial y value - NOTE: different initial value required for numberofstreamlines=1
           
                y=-0.75+(counter*(1.5/(numberofstreamlines-1)));
            
            //Set other initial values
            x=-1;
            deltat=0.02;
			
            //Update counter
            counter=counter+1;
			
            //Set zone 
            tecplot=fopen("stream.plt","a");
            fprintf(tecplot,"\nZONE T=\"zone %i\"", counter);
            fprintf(tecplot,"\n%lf %lf", x, y);
			
            //loop to plot streamline
            for(counter1=0; counter1<=200; counter1=counter1+1){
                //Calculate new values for x and y
                xnewRK=functionxnewRK(x,deltat,y);
                ynewRK=functionynewRK(x,deltat,y);
                x=xnewRK;
                y=ynewRK;
                //LIMIT STREAMLINES RANGE TO -1 TO +1
                if (x>1){break;}
                if (x<-1) {break;}
                if (y>1) {break;}
                if (y<-1) {break;}
                //EXPORT DATA TO TECPLOT
                fprintf(tecplot,"\n%lf %lf", xnewRK, ynewRK);
            }
        }
        //Tell User to open Graph
        printf("Your graph has now been created using the 2nd order Runge-Kutta integration method. Please open the file named 'stream.plt'\n");
    }
    return (0);
}
