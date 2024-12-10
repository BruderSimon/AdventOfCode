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
  int character;
  int row = 0;
  int collumn = 0;
  int guard_row = 0;
  int guard_collumn = 0;
  while ((character = fgetc(fptr)) != EOF){
    char c = (char) character;
    if(c == '\n'){
      row++;
      collumn = 0;
    }else{
      matrix[row][collumn] = c;
      collumn++;
    }
    if(c == '<' || c == '>' || c == '^' || c == 'v'){
      guard_row = row;
      guard_collumn = collumn;
    }
  }
  
  while(1){
    if(matrix[guard_row][guard_collumn] == '<'){

    }else if(matrix[guard_row][guard_collumn] == '>'){

    }else if(matrix[guard_row][guard_collumn] == '^'){

    }else if(matrix[guard_row][guard_collumn] == 'v'){

    }
  }
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
