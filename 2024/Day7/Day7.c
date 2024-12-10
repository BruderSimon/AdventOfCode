/**
 * Solution for Advent of Code
 * https://adventofcode.com/
 * 
 * Day 7, 2024:
 *
 * @author: Simon Engel
 */
#include <stdio.h>

int checkOperators()
{

}
int part1(char* line)
{
  int current_number = 0;
  int solution = 0;
  int constants[50]= {0};
  int constantsCount = 0;
  for (int i = 0;  line[i] != '\n'; i++) {
    if (line[i] >= '0' && line[i] <= '9'){
      current_number = current_number * 10 + (line[i] - '0');
    }else if (line[i] == ':'){
      solution = current_number;
      current_number = 0;
    }else{
      constants[constantsCount++] = current_number;
      current_number = 0;
    }
  }
  int resultPlus = 0;
  int resultMul = 1;
  for(int i = 0; i < constantsCount; i++){
    resultPlus += constants[i];
    resultMul *= constants[i];
  }
  if(resultPlus == solution ||resultMul == solution)
    return 1;
  
  while(1){
    
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
  char line[256];
  while(fgets(line, sizeof(line), fptr)){
    part1(line);

  }
  fclose(fptr);
}
