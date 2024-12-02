/**
 * My solutions to Advent of Code
 * https://adventofcode.com/
 *
 * Day 1, 2024
 * @author: Simon Engel
 */

#include <stdio.h>

#define BUF_SIZE 65536

#define LINE_COUNT 1000

void selectionSort(int* arr, int length) {
    for(int i = 0; i < length; i++) {
        int minIndex = i;  
        for(int j = i + 1; j < length; j++) {
            if(arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        int temp = arr[i];
        arr[i] = arr[minIndex];
        arr[minIndex] = temp;
    }
}

void readLine(int* leftside, int* rightside, FILE* fptr)
{
  int numberCount_L = 0;
  int numberCount_R = 0;
  char line[256];
    
  while (fgets(line, sizeof(line), fptr)) {
    int current_number = 0;
    for (int i = 0; line[i] != '\0' && line[i] != '\n'; i++) {
      if (line[i] >= '0' && line[i] <= '9') {
	current_number = current_number * 10 + (line[i] - '0');
      } else if (line[i] == ' ') {
	if(current_number != 0){
	  leftside[numberCount_L++] = current_number;
	  current_number = 0;
	}
      }
    }
    rightside[numberCount_R++] = current_number;
  }
  
}

int main(void) {
    FILE* fptr;
    errno_t err = fopen_s(&fptr, "input.txt", "r");
    
    if(err != 0) {
        printf("Error while opening file: input.txt\n");
        return 1;
    }
    
    int leftside[LINE_COUNT];
    int rightside[LINE_COUNT];
    readLine(leftside, rightside, fptr);
    fclose(fptr); // Don't need it anymore

    selectionSort(leftside, LINE_COUNT);
    selectionSort(rightside, LINE_COUNT);
    
    // --- Part One ---
    int result = 0;
    for (int i = 0; i < LINE_COUNT; i++){
      int t = leftside[i] - rightside[i];
      if (t < 0)
	t *= -1;
      result += t;
    }
    printf("Result Part 1: %d \n", result);
    
    // --- Part Two ---
    result = 0;
    for (int i = 0; i < LINE_COUNT; i++){
      int num = leftside[i];
      int count = 0;
      for (int t = 0; t < LINE_COUNT; t++){
	if(rightside[t] == num)
	  count++;
      }
      result += num*count;
    }
    printf("Result Part 2: %d \n", result);
    return 0;
}
