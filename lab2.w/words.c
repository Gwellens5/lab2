/*
* words.c           Garrett Wellens              25f
*
* Purpose: To create a program which takes in a file or standard input and outputs
* each word in the file line by line
*
* Input: Can take any number of arguments --> if no argument, standard input
* if - follows file --> looks at file and then takes standard input
*
*
* Output:from input file or standard input, outputs with each word on a seperate line
*
*Functions: 
*processFile: proccesses file and outputs line by line words of file
*checkFile: boolean function that checks if file is readable
*/ 

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>


void processFile(const char *filename);
bool checkFile(const char *filename);

int main(int argc, char * argv[])
{
  if (argc == 1 || strcmp(argv[1],"-") == 0){ //checks if no argument or "-" --> to use stdin
    processFile(NULL); //processes with standard input
  }
  else{

    for(int i = 1; i < argc; i++){ //parses through each argument

      if(strcmp(argv[i],"-") == 0){ //checks if argument is followed by dash --> stdin
        processFile(NULL); //processes with standard input
      }

      else if(checkFile(argv[i])){ //if readable file

          processFile(argv[i]); //process file
       }
      
      else{

        fprintf(stderr, "%s: could not open file", argv[i]); //standard error --> unopenable file
        return 1; //error 

      }    
      
    }

  }

  return 0; //success return 0

}

/*
processFile takes one argument of a character pointer to a filename
processFile checks if NULL or is a file
if a file will take stdin, else it will read the file and output each word
to an individual line
*/


void processFile(const char *filename)
{
  FILE* fp; //creates FILE pointer
  int c; //used for outputting words

  if (filename == NULL){ //checks if file name is null

    fp = stdin; //takes input from stdin
  }
  else{
    fp = fopen(filename, "r"); //opens file

    if(fp == NULL){ //checks if NULL

      fprintf(stderr, "%s: could not open file\n", filename); //standard error   
    }
  }

  while (!feof(fp)) { //continues parsing through file until EOF
    
    if(!isalpha(c) == 0){ //checks if letter

      putchar(c);
      c = fgetc(fp);
    
    }
    
    else{ //if non letter

      printf("\n"); //go to next line
      while(isalpha(c) == 0){

        if(feof(fp)){

          printf("\n");
          return;
        }
        c = fgetc(fp);
      }
      
      }
    }

  if(filename != NULL)//checks if non NULL file --> close
  {

    fclose(fp); //closes file

  }

  printf("\n");

}

/*
checkFile is a boolean function that checks if a file is readable
if it is not used to display error
takes parameter of filename
*/

bool checkFile(const char * filename)
{

  FILE * fp = fopen(filename, "r"); //opens file

  if(fp == NULL){ //if not readable

    return false;  
  
  }

  else{

    fclose(fp); //closes file

    return true;
  }


}

