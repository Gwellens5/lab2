/*
*
* Histo.c           Garrett Wellens               25F
*
* Purpose: To create a histogram consisting of 16 bins of equal spacing
* each bin should be equally spaced and proceeded by a number of "*" to 
* to indicate the number per bin
*
* Input: takes input from stdin --> assume input contains only integers
* assume smallest value is 0 (ignore negatives)
*
* Output: Properly spaced histogram --> with each line labeled with the 
* appropriate bins and number of stars per bin.
*
*Functions: 
*displayHistogram (outputs visual of histogram), 
*combineBins(combines bins of histogram) and returns updated array
*
*Return Value: 
*0: successfully run program
*/ 

#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

void displayHistogram(int * bins, int binSize, int max); //method header for printed output for histogram
int * combineBin(int * bins, int growth, int binSize, int max); //method header for combining bins

int
main(const int argc, const char * argv [])
{

  int max = 16; //initial max value of bins
  int num; // number used in scanning of stdin --> to add to bins
  int * bins = calloc(16, sizeof(int)); //creates array of size 16 as bins for histogram
  int binSize = 1; //sets initial gap between bins to be one
  


  while(scanf("%d", &num) == 1) //assigns stdin to num
  {

    if(num < 0){ //checks if num is a positive number
     // returnValue = 1;
      continue;
    }

    int growth = 0; //initializes value of growth --> used for iterations in combine bins

    while(num >= max){ //while the num from stdin > max 

      growth = growth + 1; //increases growth factor of bin

      max = max * 2; //doubles max

      binSize = binSize*2; //doubles bin size
      
    }
    if(growth > 0){ //checks if neccesary to grow bins

      bins = combineBin(bins, growth, binSize, max); //makes new bin sizes combineBins returns new array

    }
    int index = num/binSize; //index to insert into array 
    bins[index] = bins[index] + 1; //increments number of numbers in bin



  }
  displayHistogram(bins, binSize, max); //prints out updated histogram

  return 0; //return 0 --> successfully run return 1 --> error in input

}

/*
three arguments: array of bins, growth factor for array, size of bins, max value of bins

function combines bins based on the growth factor

prints updated bin size and range of bins

returns updated array of bins

*/
int * combineBin(int * bins, const int growth, const int binSize, const int max) //creates new array for update bin sizes
{ 

  for(int i = 0; i < growth; i ++){ //grows array by growth rate 2^growth

    int index = 0; //sets index for combinig

    for(int i = 0; i < 16; i ++){

      if(index<16){ //checks if in range to combine

        int total = bins[index] + bins[index+1]; //combines second bin with first
        bins[index] = 0; //sets value of first bin to 0
        bins[index+1] = 0; //sets value of second bin to 0
        bins[index] = total; //updates number of numbers in bin
        index += 2; //increments index

      }
    }
  }
  printf("16 bins of size %d for range [0, %d]\n", binSize, max); //print statement for updated size of bins

  return bins; //returns updated bins

}

/* 
three arguments: array of bins, bin size, and max

displays the histogram by bin with number of stars indicating number of numbers per bin

returns void

*/

void displayHistogram(int * bins, const int binSize, const int max) //displays histogram
{
  int firstNum = 0; //lower bound for bin
  int lastNum = binSize -1; //upper bound for bin

  for(int i = 0; i < 16; i ++){ // iterates through each bin

    char * binStar = calloc(bins[i], sizeof(char)); //creates array for bins of stars

    for(int j = 0; j < bins[i]; j++){ //

      strcat(binStar, "*"); //adds star to binstar --> used for printing
    }

    
    int num = 1; //used to determine appropriate spacing for histogram bins
    int temp = max; //creates temp var max

    while(temp > 9){

      temp /= 10; // divides temp by 10
      num++; //adds one to number of digits
    }
      

    printf("[%*d:%*d] %s\n", num, firstNum, num, lastNum, binStar);

    firstNum += binSize; //increments lower bound of bin
    lastNum += binSize; //increments upper bound of bin

  }
  return;

}
    



