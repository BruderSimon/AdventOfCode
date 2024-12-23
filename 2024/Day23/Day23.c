/**
 * Solution for Advent of Code
 * https://adventofcode.com/
 * 
 * Day 8, 2024: LAN Party
 * 
 * @author: Simon Engel
 */

#include <stdio.h>

struct Connection
{
  char* name;
  char connections[26][2];
};

int main()
{
  FILE* fptr;
  errno_t err = fopen_s(&fptr, "input.txt", "r");
    
  if(err != 0)
    {
      printf("Error while opening file: input.txt\n");
      return 1;
    }
  char line[50];
  struct Connection connections[26];
  while(fgets(line, sizeof(line), fptr))
    {
      
      if(line[0] != 't' && line[3] != 't')
	continue;
    }
  fclose(fptr);
}
