/**
 * My solutions to Advent of Code
 * https://adventofcode.com/
 *
 * Day 2, 2024
 * @author: Simon Engel
 */

#include <stdio.h>

int calculateReport(int* report, int inserts)
{
  int dec = 0;
  int inc = 0;
  for(int i = 1; i < inserts; i++){
    if(report[i-1] < report[i]){
      if(dec)
	return 0;
      inc = 1;
    }else if (report[i-1] > report[i]){
      if(inc)
	return 0;
      dec = 1;
    }else{
      return 0;
    }
    int temp = (report[i-1] - report[i]);
    if(temp < 0)
      temp *= -1;
    if(temp < 1 || temp >3)
      return 0;
  }
  
  return 1;
}

int calculateReport2(int* report, int inserts)
{
  if(calculateReport(report, inserts))
    return 1;

  for(int i = 0; i < inserts; i++){
    int newReport[inserts];
    int index = 0;
    for(int d = 0; d < inserts; d++){
      if(d != i){
	newReport[index++] = report[d];
      }
    }
    if(calculateReport(newReport, inserts-1))
      return 1;
  }
  return 0;
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
  int result = 0;
  int result2 = 0;
  while (fgets(line, sizeof(line), fptr)){
    int current_number = 0;
    int report[256];
    int inserts = 0;
    for (int i = 0;  line[i] != '\n'; i++) {
      if (line[i] >= '0' && line[i] <= '9') {
	current_number = current_number * 10 + (line[i] - '0');
      } else if (line[i] == ' ') {
	report[inserts++] = current_number;
	current_number = 0;
      }
    }
    report[inserts++] = current_number;
    result += calculateReport(report, inserts);
    result2 += calculateReport2(report, inserts);
    
  }
  printf("Result for Part 1 is: %d \n", result);
  printf("Result for Part 2 is: %d \n", result2);
}
