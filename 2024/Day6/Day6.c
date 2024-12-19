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
static char matrix[ARRAY_SIZE][ARRAY_SIZE];

void part1(int guard_row, int guard_collumn)
{
  if(guard_collumn < 0 || guard_collumn >= 130 ||
     guard_row < 0 || guard_row >= 130)
    return;
      
  switch(matrix[guard_row][guard_collumn])
    {
    case '<':
	   
      if(matrix[guard_row][guard_collumn-1] == '#')
	{
	  matrix[guard_row][guard_collumn] = '^';
	  part1(guard_row, guard_collumn);
	}
      else
	{
	  matrix[guard_row][guard_collumn] = 'X';
	  matrix[guard_row][guard_collumn-1] = '<';
	  part1(guard_row, guard_collumn-1);
	}
      break;
    case '^':
	  
      if(matrix[guard_row-1][guard_collumn] == '#')
	{
	  matrix[guard_row][guard_collumn] = '>';
	  part1(guard_row, guard_collumn);
	}
      else
	{
	  matrix[guard_row][guard_collumn] = 'X';
	  matrix[guard_row-1][guard_collumn] = '^';
	  part1(guard_row-1, guard_collumn);
	}
      break;
    case '>':
      if(matrix[guard_row][guard_collumn+1] == '#')
	{
	  matrix[guard_row][guard_collumn] = 'v';
	  part1(guard_row, guard_collumn);
	}
      else
	{
	  matrix[guard_row][guard_collumn] = 'X';
	  matrix[guard_row][guard_collumn+1] = '^';
	  part1(guard_row, guard_collumn+1);
	}
      break;
    case 'v':
      if(matrix[guard_row+1][guard_collumn] == '#')
	{
	  matrix[guard_row][guard_collumn] = '<';
	  part1(guard_row, guard_collumn);
	}
      else
	{
	  matrix[guard_row][guard_collumn] = 'X';
	  matrix[guard_row][guard_collumn+1] = 'v';
	  part1(guard_row+1, guard_collumn);
	}
      break;
    }
}


int main()
{
  FILE* fptr;
  errno_t err = fopen_s(&fptr, "Test.txt", "r");
    
  if(err != 0)
    {
      printf("Error while opening file: input.txt\n");
      return 1;
    }
  int character;
  int row = 0;
  int collumn = 0;
  int guard_row = 0;
  int guard_collumn = 0;
  while ((character = fgetc(fptr)) != EOF)
    {
      char c = (char) character;
      if(c == '\n')
	{
	  row++;
	  collumn = 0;
	}
      else
	{
	  matrix[row][collumn++] = c;
	}
      if(c == '<' || c == '>' || c == '^' || c == 'v')
	{
	  guard_row = row;
	  guard_collumn = collumn-1;
	}
    }
  fclose(fptr);
  part1(guard_row, guard_collumn);
  int result = 0;
  
  for(int i = 0; i < ARRAY_SIZE; i++)
    for(int d = 0; d < ARRAY_SIZE; d++)
      if(matrix[i][d] == 'X')
	result++;
  printf("Result Part1: %d \n", result);
}
