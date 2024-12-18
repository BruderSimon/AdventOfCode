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
#include <stdlib.h>

struct rule{
  int num;
  int after[100];
};

int containsAfter(struct rule* r, int check)
{
  if(r == NULL)
    return 0;
  for (int i = 0; i < 100; i++){
    if(r->after[i] == check)
      return 1;
  }
  return 0;
};
int* getNumbers(char* line)
{
  int* arr = calloc(100, sizeof(int));
  int count = 0;
  int current_number = 0;
  for (int i = 0;  line[i] != '\n' && line[i] != '\0'; i++)
    {
      if (line[i] >= '0' && line[i] <= '9')
	{
	  current_number = current_number * 10 + (line[i] - '0');
	}
      else
	{
	  arr[count++] = current_number;
	  current_number = 0;
	}
    }
  return arr;
}
void addRule(char* line, struct rule* rules)
{
  int* num = getNumbers(line);
  rules[num[0]].after[num[1]] = num[1];
  free(num);
}
int part1(char* line, struct rule* rules){
  
  int* update = getNumbers(line);

  int isGoodUpdate = 0;
  int count = 0;
  for(int i = 1; update[i] != 0; i++)
    {
      for(int d = i-1; d >= 0 && i > 0; d--)
	{
	  if(&rules[update[i]] == NULL)
	    break;
	  if(containsAfter(&rules[update[i]], update[d]))
	    {
	      free(update);
	      return 0;
	    }
	}
      count = i;
    }
  free(update);
  return update[count/2];
      
}

int main()
{
  FILE* fptr;
  errno_t err = fopen_s(&fptr, "Test.txt", "r");
    
  if(err != 0) {
    printf("Error while opening file: input.txt\n");
    return 1;
  }

  int result1 = 0;
  char line[256];
  struct rule rules[100];
  int isUpdate = 0;
   while (fgets(line, sizeof(line), fptr))
    {
      if(!isUpdate)
	addRule(line, rules);

      if(line[0] == '\n')
	isUpdate = 1;
	
      result1 += part1(line, rules);
    }
   printf("Result Part 1: %d \n", result1);
  fclose(fptr);
}
