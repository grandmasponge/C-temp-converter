#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "temp.h"


void help();

const char *HELPMSG = "Usage: Command, Arguments\n Commands:\n toc - converts a farenheight number/float to celcuis\n tof - converts a celcuis number/float to farenheight";

int main(int argc, char *argv[]) {
  if (argc < 2) {  // Need exactly two arguments (conversion type and value)
    perror("Not enough supplied arguments to the program \n");
    help();
    exit(1);
  }
  else if(argc > 2) {
    perror("Too many arguments were supplied \n");
    help();
    exit(1);
  }

  // Compare the two strings that were inputted
  if(strcmp(argv[1],"toc") == 0) {
    double input = atof(argv[2]);
    double output = toc(input);
    printf("%f\n", output);
  }
  else if (strcmp(argv[1], "tof") == 0 ) {
    double input = atof(argv[2]);
    double output = tof(input);
    printf("%f\n", output);
  }
  else {
    perror("Incorrect usage of program commands and arguments \n");
    help();
    exit(1);
  }

  return 0;
}

void help() {
  printf("%s", HELPMSG);
}

