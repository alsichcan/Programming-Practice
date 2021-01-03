/*
 ============================================================================
 Name        : 2048.c
 Author      : Maurits van der Schee
 Description : Console version of the game "2048" for GNU/Linux
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <termios.h>
#include <stdbool.h>
#include <time.h>

#define SIZE 4
int board[SIZE][SIZE];
int currBoard[SIZE][SIZE];
int checkBoard[SIZE][SIZE];

void setBufferedInput(bool enable) {
	static bool enabled = true;
	static struct termios old;
	struct termios new;

	if (enable && !enabled) {
		// restore the former settings
		tcsetattr(STDIN_FILENO,TCSANOW,&old);
		// set the new state
		enabled = true;
	} else if (!enable && enabled) {
		// get the terminal settings for standard input
		tcgetattr(STDIN_FILENO,&new);
		// we want to keep the old setting to restore them at the end
		old = new;
		// disable canonical mode (buffered i/o) and local echo
		new.c_lflag &=(~ICANON & ~ECHO);
		// set the new settings immediately
		tcsetattr(STDIN_FILENO,TCSANOW,&new);
		// set the new state
		enabled = false;
	}
}

int checkBoardFull(){
  for(int i = 0; i < SIZE; i++){
    for(int j = 0; j < SIZE; j++){
      if(board[i][j] == 0)
        return false;
    }
  }
  return true;
}

void addRandom(){
  if(checkBoardFull()) return;

  int i, j;
  while(true){
    i = rand() % SIZE;
    j = rand() % SIZE;

    if(board[i][j] != 0){
      continue;
    } else{
      board[i][j] = 2;
      break;
    }
  }
}

void initBoard(){
  for(int i = 0; i < SIZE; i++){
    for(int j = 0; j < SIZE; j++){
      board[i][j] = 0;
    }
  }
  addRandom();
}

void initCurrBoard(){
  for(int i = 0; i < SIZE; i++){
    for(int j = 0; j < SIZE; j++){
      currBoard[i][j] = 0;
    }
  }
}

void initCheckBoard(){
  for(int i = 0; i < SIZE; i++){
    for(int j = 0; j < SIZE; j++){
      checkBoard[i][j] = 0;
    }
  }
}

void drawBoard(){
  printf("\033[?25l\033[2J\033[H");
  for(int i = 0; i < SIZE; i++){
    for(int j = 0; j < SIZE; j++){
      printf("%10d\t", board[i][j]);
    }
    printf("\n");
  }
}

void slideBoard(){

  // Shift left to get rid of zeros
  for(int i = 0; i < SIZE; i++){
    for(int j = 0; j < SIZE; j++){
      if(currBoard[i][j] != 0){
        for(int k = 0; k < j; k++){
          if(currBoard[i][k] == 0){
            currBoard[i][k] = currBoard[i][j];
            currBoard[i][j] = 0;
            break;
          } else continue;
        }
      }
    }
  }

  // Merge if values are same from left
  for(int i = 0; i < SIZE; i++){
    for(int j = 0; j < SIZE-1; j++){
      if(currBoard[i][j] == currBoard[i][j+1]){
        currBoard[i][j] = currBoard[i][j] + currBoard[i][j+1];
        currBoard[i][j+1] = 0;
      }
    }
  }

  // Shift left to get rid of zeros
  for(int i = 0; i < SIZE; i++){
    for(int j = 0; j < SIZE; j++){
      if(currBoard[i][j] != 0){
        for(int k = 0; k < j; k++){
          if(currBoard[i][k] == 0){
            currBoard[i][k] = currBoard[i][j];
            currBoard[i][j] = 0;
            break;
          } else continue;
        }
      }
    }
  }

}

void moveLeft(){
  initCurrBoard();

  for(int i = 0; i < SIZE; i++){
    for(int j = 0; j < SIZE ; j++){
      currBoard[i][j] = board[i][j];
    }
  }

  slideBoard();

  for(int i = 0; i < SIZE; i++){
    for(int j = 0; j < SIZE ; j++){
      board[i][j] = currBoard[i][j];
    }
  }

  addRandom();
}

void moveRight(){
  initCurrBoard();

  for(int i = 0; i < SIZE; i++){
    for(int j = 0; j < SIZE; j++){
      currBoard[i][j] = board[i][SIZE-1-j];
    }
  }

  slideBoard();

  for(int i = 0; i < SIZE; i++){
    for(int j = 0; j < SIZE; j++){
      board[i][j] = currBoard[i][SIZE-1-j];
    }
  }

  addRandom();    
}

void moveUp(){
  initCurrBoard();

  for(int i = 0; i < SIZE; i++){
    for(int j = 0; j < SIZE; j++){
      currBoard[i][j] = board[j][i];
    }
  }

  slideBoard();

  for(int i = 0; i < SIZE; i++){
    for(int j = 0; j < SIZE; j++){
      board[i][j] = currBoard[j][i];
    }
  }

  addRandom();
}

void moveDown(){
  initCurrBoard();

  for(int i = 0; i < SIZE; i++){
    for(int j = 0; j < SIZE ; j++){
      currBoard[i][j] = board[SIZE-1-j][i];
    }
  }

  slideBoard();
  
  for(int i = 0; i < SIZE; i++){
    for(int j = 0; j < SIZE ; j++){
      board[i][j] = currBoard[j][SIZE-1-i];
    }
  }


  addRandom();
}

int checkEquality(){
  for(int i = 0; i < SIZE; i++){
    for(int j = 0; j < SIZE; j++){
      if(board[i][j] != checkBoard[i][j]){
        return false;
      }
    }
  }
  return true;
}

int checkMoveLeft(){
  initCurrBoard();
  initCheckBoard();

  for(int i = 0; i < SIZE; i++){
    for(int j = 0; j < SIZE ; j++){
      currBoard[i][j] = board[i][j];
    }
  }

  slideBoard();

  for(int i = 0; i < SIZE; i++){
    for(int j = 0; j < SIZE ; j++){
      checkBoard[i][j] = currBoard[i][j];
    }
  }

  return checkEquality();
}

int checkMoveRight(){
  initCurrBoard();
  initCheckBoard();

  for(int i = 0; i < SIZE; i++){
    for(int j = 0; j < SIZE ; j++){
      currBoard[i][j] = board[i][SIZE-1-j];
    }
  }

  slideBoard();

  for(int i = 0; i < SIZE; i++){
    for(int j = 0; j < SIZE ; j++){
      checkBoard[i][j] = currBoard[i][SIZE-1-j];
    }
  }

  return checkEquality();
}

int checkMoveUp(){
  initCurrBoard();
  initCheckBoard();

  for(int i = 0; i < SIZE; i++){
    for(int j = 0; j < SIZE ; j++){
      currBoard[i][j] = board[j][i];
    }
  }

  slideBoard();

  for(int i = 0; i < SIZE; i++){
    for(int j = 0; j < SIZE ; j++){
      checkBoard[i][j] = currBoard[j][i];
    }
  }

  return checkEquality();
}

int checkMoveDown(){
  initCurrBoard();
  initCheckBoard();

  for(int i = 0; i < SIZE; i++){
    for(int j = 0; j < SIZE ; j++){
      currBoard[i][j] = board[SIZE-1-j][i];
    }
  }

  slideBoard();

  for(int i = 0; i < SIZE; i++){
    for(int j = 0; j < SIZE ; j++){
      checkBoard[i][j] = currBoard[j][SIZE-1-i];
    }
  }

  return checkEquality();
}

int gameOverCheck(){
  int checkFull, checkSame;
  int checkLeft, checkRight, checkUp, checkDown;

  checkFull = checkBoardFull();
  checkLeft = checkMoveLeft();
  checkRight = checkMoveRight();
  checkUp = checkMoveUp();
  checkDown = checkMoveDown();

  checkSame = (checkLeft + checkRight + checkUp + checkDown) == 4? 1 : 0;

  return checkFull && checkSame;
}

int main(void) {
	char c;
	bool success;
  srand(time(NULL));

	initBoard();
  drawBoard();
  
	setBufferedInput(false);
	while (true) {
		c=getchar();

		switch(c) {
			case 97:	// 'a' key
			case 68:	// left arrow
				moveLeft();  break;
			case 100:	// 'd' key
			case 67:	// right arrow
				moveRight(); break;
			case 119:	// 'w' key
			case 65:	// up arrow
				moveUp();    break;
			case 115:	// 's' key
			case 66:	// down arrow
				moveDown();  break;
		}

    drawBoard();
		
    if (gameOverCheck()) {
			printf("         GAME OVER          \n");
			break;
	  }
	}
	setBufferedInput(true);

	printf("\033[?25h\033[m");

	return 0;
}