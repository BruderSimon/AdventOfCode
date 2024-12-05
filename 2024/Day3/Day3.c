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

int main()
{
   FILE* fptr;
  errno_t err = fopen_s(&fptr, "input.txt", "r");
    
  if(err != 0) {
    printf("Error while opening file: input.txt\n");
    return 1;
  }
  char line[256];
  int result = 0;
  int result2 = 0;
  while (fgets(line, sizeof(line), fptr)){
    int current_number = 0;
    int report[256];
    int inserts = 0;
    for (int i = 0;  line[i] != '\n'; i++) {
      if (line[i] >= '0' && line[i] <= '9') {
	
      }
    }
    
  }
  
}
