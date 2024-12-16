/**
 * Solution for Advent of Code
 * https://adventofcode.com/
 * 
 * Day 7, 2024:
 *
 * @author: Simon Engel
 */
#include <stdio.h>

unsigned long long part1(unsigned long long* constants, int constantsCount, unsigned long long solution)
{
  int width = constantsCount-1;  // How many bits we want to count
  int max = 1 << width;  // Calculate 2^width
  int arr[width];
  unsigned long long result = constants[0];
  
  for (int i = 0; i < max; i++)
    {
      for (int d = width - 1; d >= 0; d--)
	{
	  // Use bit shifting and masking to get each bit
	  int bit = (i >> d) & 1;
	  arr[d] = bit;
	}
      for(int d = 0; d < width; d++)
	{
	  if(arr[d] == 1)
	    {
	      result *= constants[d+1];
	    }
	  else if(arr[d] == 0)
	    {
	      result += constants[d+1];
	    }
	}
      if(result == solution)
	{
	  return solution;
	}
      result = constants[0];
    }

  return 0;
}
unsigned long long power(int base, int exp)
{
    unsigned long long result = base;
    for(int i = 1; i < exp; i++)
    {
        result *= base;
    }
    return result;
}
void convertToTernary(int* arr, int index, int width, int N)
{
  if (N == 0)
    {
      for(int i = index; i < width; i++)
        {
	  arr[i] = 0;
        }
      return;
    }   
  int x = N % 3;
  N /= 3;
  if (x < 0)
    N += 1;

  convertToTernary(arr, index+1, width, N);

  if (x < 0)
    arr[index] =  x + (3 * -1);
  else
    arr[index] = x;
}
unsigned concatenate(unsigned x, unsigned y)
{
    unsigned pow = 10;
    while(y >= pow)
        pow *= 10;
    return x * pow + y;        
}
unsigned long long part2(unsigned long long* constants, int constantsCount, unsigned long long solution)
{
  int width = constantsCount-1;  // How many bits we want to count
  unsigned long long  max = power(3, width);  // Calculate 2^width
  int arr[width];
  unsigned long long result = constants[0];
  
  for (int i = 0; i < max; i++)
    {
      convertToTernary(arr, 0, width, i);
      for(int d = 0; d < width; d++)
	{
	  if(arr[d] == 1)
	    {
	      result *= constants[d+1];
	    }
	  else if(arr[d] == 0)
	    {
	      result += constants[d+1];
	    }
	  else if(arr[d] == 2)
	    {
	      result = concatenate(result, constants[d+1]);
	    }
	}
      if(result == solution)
	{
	  return solution;
	}
      result = constants[0];
    }

  return 0;
}


int main()
{
  FILE* fptr;
  errno_t err = fopen_s(&fptr, "input.txt", "r");
    
  if(err != 0)
    {
      printf("Error while opening file: input.txt\n");
      return 1;
    }
  char line[256];
  unsigned long long resultP1 = 0;
  unsigned long long resultP2 = 0;
  while(fgets(line, sizeof(line), fptr))
    {
      unsigned long long current_number = 0;
      unsigned long long solution = 0;
      unsigned long long constants[50]= {0};
      int constantsCount = 0;
      for (int i = 0;  line[i] != '\n' && line[i] != '\0'; i++)
	{
	  if (line[i] >= '0' && line[i] <= '9')
	    {
	      current_number = current_number * 10 + (line[i] - '0');
	    }
	  else if (line[i] == ':')
	    {
	      solution = current_number;
	      current_number = 0;
	    }
	  else
	    {
	      if(current_number != 0){
		constants[constantsCount++] = current_number;
		current_number = 0;

	      }
	    }
	}
      constants[constantsCount++] = current_number;
      
      resultP1 += part1(constants, constantsCount, solution);
      resultP2 += part2(constants, constantsCount, solution);

    }
  printf("Result Part 1: %llu \n", resultP1);
  printf("Result Part 2: %llu \n", resultP2);
  fclose(fptr);
}
