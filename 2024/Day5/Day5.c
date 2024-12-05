/**
 * Solution for Advent of Code
 * https://adventofcode.com/
 * 
 * Day 5, 2024: Sleigh launch safety manual
 * Check if the pages are printed acording to the pagee ordering rules
 * 
 * @author: Simon Engel
 */

#include <stdio.h>

#define ARRAY_SIZE 256

struct rule{
  int numBefore, num, numAfter;
};

int main()
{
  FILE* fptr;
  errno_t err = fopen_s(&fptr, "input.txt", "r");
    
  if(err != 0) {
    printf("Error while opening file: input.txt\n");
    return 1;
  }
    
  char line[ARRAY_SIZE];
  int lines = 0;
    
  // Read file line by line
  while (fgets(line, sizeof(line), fptr)) {
    
    lines++;
  }
    
  fclose(fptr);
}
