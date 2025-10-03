/*
* chill.c           Garrett Wellens              fa25
*
* Purpose: To create a visually appealing table consiting of temperature wind and the calculated 
* wind chill. Temperatures are in Farenheit. Wind is in MPH.
*
* Input: Takes 0, 1, or 2 arguments. Both arguments are floating point values
* First argument is assumed to be the temperature
* second is assumed to the wind --> if one argument, assumes temperature
*
*
* Output:if no arguments, prints temp (-10 --> 40), wind (5 --> 15), and calculated wind chill
* if one argument, prints inputted temp, wind (5 --> 15), and calculated wind chill
*
*Functions: 
*windChillCalc: takes in two params temperature and wind --> calculates windchill 
*oneArg: takes no arguments and outputs temps -10 --> 40, wind 5 --> 15 and calculated wind chill
*twoArgs: takes two arguments and prints table of inputted temp, wind, and calulated windchill
*printHeader: prints the designated header of Wind, Temp, and Chill
*printFormat: prints the properly designated format of Wind Temp and Chill
*
* Errors
* 1: Improper input
* 2: Wind or temp is out of bounds
*/ 




#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void noArg(void);
void oneArg(float temp);
void twoArg(float wind, float temp);
float windChillCalc(float temp, float wind);
void printFormat(float temp,float wind, float chill);
void printHeader(void);

int main(const int argc, const char * argv[])
{
  if(argc == 1){ //checks number of arguments
    noArg(); //calls no arg function
  }
  
  else if(argc == 2){ //checks if one argument
    float temp; //creates float variable temp

    if(sscanf(argv[1], "%f", &temp) == 0){ //using sscanf sets value of temp

       fprintf(stderr,"Usage: %s [argv]: input error, unable to read \n", argv[0]);
       return 1;


    }

    if(temp >= 50.0 || temp <= -99.0){ //checks boundary case of temperature
     
     fprintf(stderr,"Usage: %s [argv]: input error, unable to read \n", argv[0]);
     return 2; //returns 2 --> error associated with out of bounds case
    } 
    

    oneArg(temp); //calls oneArg function --> one argument given


  }

  else if (argc == 3){ //checks if two arguments

    float temp; //creates float for temp
    float wind; //creates float for wind
    
    if(sscanf(argv[2], "%f", &wind) == 0 || sscanf(argv[1], "%f", &temp) == 0){

        fprintf(stderr,"Usage: %s [argv]: input error, unable to read \n", argv[0]);
        return 1;


    } //assigns temp and wind to argument 1 and checks if number



    if(temp >= 50.0 || temp <= -99.0 || wind < 0.5 || wind > 231.0){ //check if inputs are within bounds 
      fprintf(stderr,"Usage: %s [argv]: input error, unable to read \n", argv[0]);
      return 2; //exit 2 --> error associated with out of bounds temp or wind
      
    }
    twoArg(temp,wind); //calls twoArg function
}

  else{ //improper number of arguments
    
    fprintf(stderr,"Usage: %s [argv]: input error, unable to read \n", argv[0]); //usage error --> incorrect number of arguments
    return 1;
        
    
  }

return 0; //success return 0
}
/*
Wind Chill Calc calculates the wind chill based on the params of wind and 
temperature
returns float value of wind chill
void method
*/
float windChillCalc(float wind, float temp){

  float chill;

  //calculation based on equation for windchill

  chill = 35.74 + 0.621*temp - 35.75 * pow(wind,.16) + .4275*temp*pow(wind,.16);

  return chill;
}

void 
noArg(){

  printHeader(); //prints header

  for(float t = -10.0; t <= 40; t+=10){ //looping for temperature (t)
   
    for(float w = 5.0; w <= 15; w += 5){ //looping for wind (w)
      float tempChill = windChillCalc(w,t); //calculates wind chill

      printFormat(t,w,tempChill); //prints out properly formatted wind temp chill

    }
 printf("\n"); //line break for proper spacing
  }
}

/* 
oneArg takes one parameter of temperature
outputs table of the temperature with wind velocities -5 --> 15 with
calculated wind chill
void method
*/

void oneArg(float temp){

  printHeader(); //prints header

  for(float w = 5; w <= 15; w += 5){ //loops through wind speeds
    
    float tempChill = windChillCalc(w,temp); //calculates wind chill

    printFormat(temp,w,tempChill); //prints out properly formatted wind temp chill
  }

  

}

/*
twoArg takes two parameters, temp and wind
outputs table of temp wind and chill based on two params
void method
*/

void 
twoArg(float temp, float wind){

  printHeader(); //prints header

  float tempChill = windChillCalc(wind,temp); //calculates wind chill

  printFormat(temp,wind,tempChill); //prints format of temp wind chill
 

}
/*
Prints out proper format of table --> rows with numbers
void method
*/
void printFormat(float temp, float wind, float chill)
{

 printf("%5.1f  %5.1f  %5.1f\n",temp,wind,chill); //properly spaces

}
/*
prints out properly formatted header of table
*/

void printHeader(){

 printf(" Temp   Wind  Chill\n");
 printf("-----  -----  -----\n");  

}

// #include <stdio.h>
// #include <stdlib.h>
// #include <math.h>

// static double wind_chill(double T, double V) {
//     /* Wind Chill = 35.74 + 0.6215T - 35.75(V^0.16) + 0.4275T(V^0.16) */
//     double v016 = pow(V, 0.16);
//     return 35.74 + 0.6215*T - 35.75*v016 + 0.4275*T*v016;
// }

// static int temp_ok(double T) {
//     return (T < 50.0 && T > -99.0);
// }

// static int wind_ok(double V) {
//     return (V >= 0.5);
// }

// static void print_header(void) {
//     printf("  %5s  %5s  %5s\n", "Temp", "Wind", "Chill");
//     printf(" -----  -----  -----\n");
// }

// static void print_line(double T, double V) {
//     printf(" %5.1f  %5.1f  %5.1f\n", T, V, wind_chill(T, V));
// }

// static void usage(const char *prog) {
//     fprintf(stderr, "usage: %s [TEMP [WIND]]\n", prog);
// }

// int main(int argc, char *argv[]) {
//     if (argc == 1) {
//         print_header();
//         for (int T = -10; T <= 40; T += 10) {
//             for (int V = 5; V <= 15; V += 5) {
//                 print_line((double)T, (double)V);
//             }
//             printf("\n");
//         }
//         return 0;
//     } else if (argc == 2) {
//         double T = atof(argv[1]);
//         if (!temp_ok(T)) {
//             fprintf(stderr, "./chill: Temperature must be less than or equal to 50.0 degrees Fahrenheit\n");
//             return 1;
//         }
//         print_header();
//         for (int V = 5; V <= 15; V += 5) {
//             print_line(T, (double)V);
//         }
//         return 0;
//     } else if (argc == 3) {
//         double T = atof(argv[1]);
//         double V = atof(argv[2]);
//         if (!temp_ok(T)) {
//             fprintf(stderr, "./chill: Temperature must be less than or equal to 50.0 degrees Fahrenheit\n");
//             return 1;
//         }
//         if (!wind_ok(V)) {
//             fprintf(stderr, "./chill: Wind velocity must be greater than or equal to 0.5 MPH\n");
//             return 1;
//         }
//         print_header();
//         print_line(T, V);
//         return 0;
//     } else {
//         usage(argv[0]);
//         return 1;
//     }
// }

