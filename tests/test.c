#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include "temp.h"

//tests
#define TEST_1 32
#define TEST_2 0
#define TEST_3 50.18 // 10.1
#define TEST_4 32
#define TEST_5 -17.7778

int main() {
  double input, output;
  printf("Test 1 - converting 0 celcuis to farenheight || expected 32");
  input = 0;
  output = tof(input);
  assert(output == TEST_1);

  printf("Test 2 - converting 32 degress farenheight to celcuis || expected 0 ");
  input = 32;
  output = toc(input);
  assert(output == TEST_2);

  printf("Test 3 - converting 10.1 celcuis to farenheight");
  input = 10.1;
  output = toc(input);
  assert(output == TEST_3);

  printf("Test 4 - converting agdgd to celcuis");
  char *temp = "agdgd";
  input = atof(temp);
  output = toc(input);
  assert(output == TEST_4);

  printf("Test 5 - converting hello world to farenheight");
  char *temp1 = "hello world";
  input = atof(temp1);
  output = tof(input);
  assert(output == TEST_5);


  printf("all Tests succsessfull !");

  return 0;
}
