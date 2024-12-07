/**
 * My solutions to Advent of Code
 * https://adventofcode.com/
 *
 * Day 3, 2024: Corruped memory
 *
 * mul\([0-9]*,[0-9]*\)
 * @author: Simon Engel
 */

#include <stdio.h>
#include <stdlib.h>

void part1(FILE* fptr){
  
  int character;
  int result = 0;
  char* mul = "mul(,)";
  int count = 0;
  int current_number = 0;
  int add = 1;
    
  while ((character = fgetc(fptr)) != EOF){
    char c = (char) character;
    
    if(count >= 4){
      if (c >= '0' && c <= '9') {
	if((current_number/100) < 10)
	  current_number = current_number * 10 + (c - '0');
	else{
	  current_number = 0;
	  count = 0;
	  add = 1;
	}
      }else if(c == ','){

	add *= current_number;
	current_number = 0;
	count++;
	
      }else if(c == ')'){
	add *= current_number;
	result += add;
	current_number = 0;
	count = 0;
	add = 1;
      }else{
	current_number = 0;
	count = 0;
	add = 1;
      }
    }else{
      if(c == mul[count]){
	count++;
      }else{
	count = 0;
      }
    }
  }
  printf("Result: %d \n", result);
}


int main()
{
  FILE* fptr;
  errno_t err = fopen_s(&fptr, "input.txt", "r");
    
  if(err != 0) {
    printf("Error while opening file: input.txt\n");
    return 1;
  }

  part1(fptr);
}
