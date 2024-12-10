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

void part1(FILE* fptr){
  
  int character;
  int result = 0;
  int current_number = 0;
  struct rule rules[100];
  int* update = (int*) calloc(256, sizeof(int));
  struct rule* ruleptr = NULL;
  
  char line[256];
  int isUpdate = 0;
  int updateNums = 0;
  while (fgets(line, sizeof(line), fptr)){
    for (int i = 0;  line[i] != '\n'; i++) {
      if (line[i] >= '0' && line[i] <= '9'){
	current_number = current_number * 10 + (line[i] - '0');
      }else if (line[i] == '|'){
	ruleptr = &rules[current_number];
	ruleptr->num = current_number;
	current_number = 0;
      }else if (line[i] == ','){
	isUpdate = 1;
	update[updateNums++] = current_number;
	current_number = 0;
      }
    }
    if(current_number != 0){
      if(!isUpdate){
	ruleptr->after[current_number] = current_number;
	ruleptr = NULL;
      }else{
	update[updateNums++] = current_number;
      }
    }
    current_number = 0;
    if(isUpdate){
      int isGoodUpdate = 0;
      for(int i = updateNums-1; i >= 0; i--){
	 for(int d = i-1; d >= 0 && i > 0; d--){
	   if(&rules[update[i]] == NULL)
	     break;
	   if(containsAfter(&rules[update[i]], update[d])){
	     isGoodUpdate = 0;
	     break;
	   }else{
	     isGoodUpdate = 1;
	   }
	 }
      }
      if(isGoodUpdate){
	result += update[updateNums/2];
      }
    }
  }
  printf("Result: %d \n", result);
  free(update);}

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
