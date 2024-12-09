/**
 * Solution for Advent of Code
 * https://adventofcode.com/
 * 
 * Day 6, 2024: Sleigh launch safety manual
 * Check if the pages are printed acording to the pagee ordering rules
 * 
 * @author: Simon Engel
 */

#include <stdio.h>

#define ARRAY_SIZE 130

void part1(FILE* fptr)
{
  char matrix[ARRAY_SIZE][ARRAY_SIZE];
  
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

    
  fclose(fptr);
}
