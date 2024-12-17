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
    
  if(err != 0)
    {
      printf("Error while opening file: input.txt\n");
      return 1;
    }

  int character;
  int result = 0;
  int result2 = 0;
  int boolDo = 1; // 1 = do 0 = don't
  char* mul = "mul(,)";
  char* charDo = "do()";
  char* charDont = "don\'t()";
  int count = 0;
  int countDo = 0;
  int countDont = 0;
  int current_number = 0;
  int add = 1;
    
  while ((character = fgetc(fptr)) != EOF)
    {
      char c = (char) character;
      if(count >= 4)
	{
	  if (c >= '0' && c <= '9')
	    {
	      if((current_number/100) < 10)
		current_number = current_number * 10 + (c - '0');
	      else
		{
		  current_number = 0;
		  count = 0;
		  add = 1;
		}
	    }
	  else if(c == ',')
	    {

	      add *= current_number;
	      current_number = 0;
	      count++;
	
	    }
	  else if(c == ')')
	    {
	      add *= current_number;
	      result += add;

	      if(boolDo)
		result2 += add;
	      
	      current_number = 0;
	      count = 0;
	      add = 1;
	    }
	  else
	    {
	      current_number = 0;
	      count = 0;
	      add = 1;
	    }
	}
      else
	{

	  if(c == charDo[countDo])
	    {
	      if(countDo == 3)
		{
		  boolDo = 1;
		  countDo = 0;
		  countDont = 0;
		}
	      else
		countDo++;
	    }
	  else
	    countDo = 0;

	  if(c == charDont[countDont])
	    {
	      if(countDont == 6)
		{
		  boolDo = 0;
		  countDo = 0;
		  countDont = 0;
		}
	      else
		countDont++;
	    }
	  else
	    countDont = 0;
	  
	  if(c == mul[count])
	    count++;
	  else
	    count = 0;
	}
    }
  printf("Result Part 1: %d \n", result);
  printf("Result part 2: %d \n", result2);
}
