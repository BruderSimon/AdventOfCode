/**
 * Solution for Advent of Code
 * https://adventofcode.com/
 * 
 * Day 4, 2024: XMAS Pattern Search
 * Searches for "XMAS" patterns in a matrix in eight directions
 * 
 * @author: Simon Engel
 */

#include <stdio.h>

#define MATRIX_SIZE 256
#define TARGET "XMAS"
#define TARGET_LENGTH 4

// Direction vectors for all eight possible directions
const int DIRECTIONS[8][2] =
  {
    {1, 1},   // diagonal right down
    {1, -1},  // diagonal left down
    {-1, 1},  // diagonal right up
    {-1, -1}, // diagonal left up
    {0, 1},   // right
    {0, -1},  // left
    {1, 0},   // down
    {-1, 0}   // up
  };

#define TARGET2 "MAS"
#define TARGET_LENGTH2 3

/**
 * Checks if coordinates are within matrix bounds
 */
static int is_valid_position(int line, int row)
{
  return line >= 0 && line < MATRIX_SIZE && row >= 0 && row < MATRIX_SIZE;
}

static int search_pattern(const char matrix[MATRIX_SIZE][MATRIX_SIZE], 
                         int line, 
                         int row, 
                         int dir_idx, 
                         int char_idx) {
    // Base cases
    if (!is_valid_position(line, row)) {
        return 0;
    }
    
    if (matrix[line][row] != TARGET[char_idx]) {
        return 0;
    }
    
    // Found complete pattern
    if (char_idx == TARGET_LENGTH - 1) {
        return 1;
    }
    
    // Continue search in same direction
    return search_pattern(
        matrix,
        line + DIRECTIONS[dir_idx][0],
        row + DIRECTIONS[dir_idx][1],
        dir_idx,
        char_idx + 1
    );
}
static int search_pattern2(const char matrix[MATRIX_SIZE][MATRIX_SIZE], int line, int row)
{
  int b1 = 0;
  int b2 = 0;
  if (line == 0 || row == 0 || line == MATRIX_SIZE-1 || row == MATRIX_SIZE-1)
    return 0;

  if((matrix[line-1][row+1] == 'M' && matrix[line+1][row-1] == 'S')
     || (matrix[line-1][row+1] == 'S' && matrix[line+1][row-1] == 'M'))
    b1 = 1;

  if((matrix[line-1][row-1] == 'M' && matrix[line+1][row+1] == 'S')
     || (matrix[line-1][row-1] == 'S' && matrix[line+1][row+1] == 'M'))
    b2 = 1;
  
  return b1 && b2;
}


int main(void) {
    char matrix[MATRIX_SIZE][MATRIX_SIZE] = {0};  // Initialize to zeros
    int result = 0;
    int result2 =0;
    
    FILE* fptr;
    errno_t err = fopen_s(&fptr, "input.txt", "r");
    
    if(err != 0) {
      printf("Error while opening file: input.txt\n");
      return 1;
    }
    
    char line[MATRIX_SIZE];
    int lines = 0;
    
    // Read file line by line
    while (fgets(line, sizeof(line), fptr) && lines < MATRIX_SIZE)
      {
        for(int i = 0; line[i] != '\n' && line[i] != '\0'; i++)
	  {
	    matrix[lines][i] = line[i];
	  };
        lines++;
      }
    
    fclose(fptr);
    
    // Search for patterns
    for (int i = 0; i < lines; i++)
      {
	for (int j = 0; matrix[i][j] != '\0'; j++)
	  {
	    // Only start search from 'X'
	    if (matrix[i][j] != TARGET[0] && matrix[i][j] != TARGET2[1])
	      {
		continue;
	      }
            
	    // Try all directions
	    if(matrix[i][j] == TARGET[0])
	      {
		  
		for (int dir = 0; dir < 8; dir++) {
		  if (search_pattern(matrix, i, j, dir, 0))
		    {
		      result++;
		    }
		}
	      }
	    else if(matrix[i][j] == TARGET2[1])
	      {
		
		if (search_pattern2(matrix, i, j))
		  {
		    result2++;
		  }
		
	      }
	  }
      }
    
    printf("Result Part 1: %d\n", result);
    printf("Result Part 2: %d\n", result2);
    return 0;
}
