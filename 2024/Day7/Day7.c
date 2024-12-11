/**
 * Solution for Advent of Code
 * https://adventofcode.com/
 * 
 * Day 7, 2024:
 *
 * @author: Simon Engel
 */
#include <stdio.h>

int part1(char* line)
{
  int current_number = 0;
  long solution = 0;
  int constants[50]= {0};
  int constantsCount = 0;
  for (int i = 0;  line[i] != '\n'; i++)
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
	  constants[constantsCount++] = current_number;
	  current_number = 0;
	}
    }
  int width = constantsCount-1;  // How many bits we want to count
  int max = 1 << width;  // Calculate 2^width
  int arr[max][width];
  // Count from 0 to max-1
  for (int i = 0; i < max; i++) {
    for (int d = width - 1; d >= 0; d--) {
      // Use bit shifting and masking to get each bit
      int bit = (i >> d) & 1;
      arr[i][d] = bit;
    }
  }
  long result = constants[0];
  for(int i = 0; i < max; i++){
    for(int d = 1; d < width; d++){
      if(arr[i][d] == 1){
	result *= constants[d];
      }else{
	result += constants[d];
      }
    }
    
    if(result == solution){
      printf("%long \n", result);
      return 1;
    }
    int result = constants[0];
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
  int resultP1 = 0;
  while(fgets(line, sizeof(line), fptr))
    {
      resultP1 += part1(line);

    }
  printf("Result Part 1: %d \n", resultP1);
  fclose(fptr);
}
