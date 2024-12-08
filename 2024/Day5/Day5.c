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

#define ARRAY_SIZE 256

struct rule{
  int num;
  int after[100];
};

int containsAfter(struct rule* r, int check){
  for (int i = 0; i < 100; i++){
    if(r->after[i] == check)
      return 1;
  }
    return 0;
};

void part1(FILE* fptr){
  
  int character;
  int result = 0;
  int current_nummber = 0;
  struct rule rules [100];
  int update[256];
  struct rule* ruleptr = NULL;
  
  char line[256];
  int isUpdate = 0;
  int updateNums = 0;
  while (fgets(line, sizeof(line), fptr)){
    for (int i = 0;  line[i] != '\n'; i++) {
      if (line[i] >= '0' && line[i] <= '9'){
	current_nummber = current_nummber * 10 + (line[i] - '0');
      }else if (line[i] == '|'){
	ruleptr = &rules[current_nummber];
	ruleptr->num = current_nummber;
	current_nummber = 0;
      }else if (line[i] == ','){
	isUpdate = 1;
	update[updateNums++] = current_nummber;
	current_nummber = 0;
      }else if(line[i] == '\n'){
	if(!isUpdate){
	  ruleptr->after[current_nummber] = current_nummber;
	  ruleptr = NULL;
	}else{
	  update[updateNums++] = current_nummber;
	}
	current_nummber = 0;
      }
    }
    if(isUpdate){
      int isGoodUpdate = 0;
      for(int i = updateNums-1; i >= 0; i--){
	 for(int d = i-1; d >= 0; d--){
	   if(containsAfter(&rules[update[i]], update[d])){
	     isGoodUpdate = 0;
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
