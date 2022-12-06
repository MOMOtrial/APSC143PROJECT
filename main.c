#include <stdio.h>
#include <stdlib.h>
#include "colours.h"
#include<iostream>
#include<cstdlib>
#include<ctime>

using namespace std;

//we attest to our academic integrity, Love Sam and Matt
//before we added ghosts that are buggy pacman moves properly and win function worked if ghosts are commented out it works perfectly thought we though we should add the ghost code was worth leaving in  
// You don't need to use these, but they help make your code look more organized
#define PACMAN 'P'
#define GHOSTA 'G'
#define GHOSTB 'g'
#define DOT '.'
#define WALL 'W'
#define EMPTY ' '
#define UP 'w'
#define LEFT 'a'
#define DOWN 's'
#define RIGHT 'd'

int winCheck();
void loadMap();
int rows = 11;
int cols = 11;
int loseCheck(char* ptr[rows][cols]);
char* pointerMap[11];
int currentLoco[2];
int ghostLoco[2];
int GhostLoco[2];
void createArray(){
    for(int i = 0; i < 11; i++){
        pointerMap[i]=(char* )malloc(33*sizeof(char));
    }
}
//finding the map
void loadMap(FILE* filePointer){
    for(int y = 0; y < 11; y++){
        for(int x = 0; x < 33; x++){
            fscanf(filePointer, "%c", &pointerMap[y][x]);
        }
    }
}

void printMap(){
    for(int i = 0; i<11; i++) {
        for (int j = 0; j < 33; j++) {
            if (pointerMap[i][j] == WALL) {
                colourChange(BLUE);
            } else if (pointerMap[i][j] == DOT) {
                colourChange(WHITE);
            } else if (pointerMap[i][j] == PACMAN) {
                colourChange(YELLOW);
            } else {
                colourChange(PINK);
            }
            printf("%c", pointerMap[i][j]);
        }
    }
}
int winCheck() {
    int count = 0;
    for (int i = 0; i < sizeof(pointerMap) / sizeof(pointerMap[0]); i++) {
        for (int j = 0; j < sizeof(pointerMap[0]) / sizeof(pointerMap[0][0]); j++) {
            if (pointerMap[i][j] == DOT) {
                return 0;
            }
        }
    }
    return 1;
}

int isWall( int row, int column){
   if(row > 10 || column > 32){
       return 1;
   }
   if(pointerMap[row][column] == WALL){
       return 1;
   }
   return 0;
}

int loseCheck(char* ptr[rows][cols]){
    int p = 0;
    for(int i = 0; i< rows; i++){
        for(int j = 0; j<cols; j++) {
            if(*ptr[i][j] == PACMAN){
                p++;
            }
        }
    }
    if(p==0){
        return 1;
    }else{
        return 0;
    }
}
//making pac man move
void movePacman(char move) {
    if (move == UP) {
        if (isWall(currentLoco[0] - 1, currentLoco[1]) == 0) {
            pointerMap[currentLoco[0]][currentLoco[1]] = EMPTY;
            currentLoco[0] -= 1;
            pointerMap[currentLoco[0]][currentLoco[1]] = PACMAN;
        }
    } else if (move == DOWN) {
        if (isWall(currentLoco[0] + 1, currentLoco[1]) == 0) {
            pointerMap[currentLoco[0]][currentLoco[1]] = EMPTY;
            currentLoco[0] += 1;
            pointerMap[currentLoco[0]][currentLoco[1]] = PACMAN;
        }
    } else if (move == LEFT) {
        if (isWall(currentLoco[0], currentLoco[1] - 3) == 0) {
            pointerMap[currentLoco[0]][currentLoco[1]] = EMPTY;
            currentLoco[1] -= 3;
            pointerMap[currentLoco[0]][currentLoco[1]] = PACMAN;
        }
    } else if (move == RIGHT) {
        if (isWall(currentLoco[0], currentLoco[1] + 3) == 0) {
            pointerMap[currentLoco[0]][currentLoco[1]] = EMPTY;
            currentLoco[1] += 3;
            pointerMap[currentLoco[0]][currentLoco[1]] = PACMAN;
        }
    }

// this makes ghost sometimes move but he eats the dots
// set seed to time(0)
    srand(time(0));

    // generate random number
    int random = rand() % 4;

    if (random == 0) {
        if (isWall(GhostLoco[0] - 1, GhostLoco[1]) == 0) {
            pointerMap[GhostLoco[0]][GhostLoco[1]] = EMPTY;
            GhostLoco[0] -= 1;
            pointerMap[GhostLoco[0]][GhostLoco[1]] = GHOSTA;
        }

    }

    if (random == 1) {
        if (isWall(GhostLoco[0] + 1, GhostLoco[1]) == 0) {
            pointerMap[GhostLoco[0]][GhostLoco[1]] = EMPTY;
            GhostLoco[0] += 1;
            pointerMap[GhostLoco[0]][GhostLoco[1]] = GHOSTA;
        }

    }

    if (random == 2) {
        if (isWall(GhostLoco[0], GhostLoco[1] - 3) == 0) {
            pointerMap[GhostLoco[0]][GhostLoco[1]] = EMPTY;
            GhostLoco[1] -= 3;
            pointerMap[GhostLoco[0]][GhostLoco[1]] = GHOSTA;
        }

    }

    if (random == 3) {
        if (isWall(GhostLoco[0], GhostLoco[1] + 3) == 0) {
            pointerMap[GhostLoco[0]][GhostLoco[1]] = EMPTY;
            GhostLoco[1] += 3;
            pointerMap[GhostLoco[0]][GhostLoco[1]] = GHOSTA;
        }

    }
}
// another atempt to make the second ghost move
//    // set seed to time(0)
//    srand(time(0));
//
//    // generate random number
//    int randm = rand()%4;
//
//    if (randm == 0) {
//        if (isWall(GhostLoco[0] - 1, GhostLoco[1]) == 0) {
//            pointerMap[GhostLoco[0]][GhostLoco[1]] = EMPTY;
//            GhostLoco[0] -= 1;
//            pointerMap[GhostLoco[0]][GhostLoco[1]] = GHOSTA;
//        }
//
//    }
//
//    if (randm == 1) {
//        if (isWall(GhostLoco[0] + 1, GhostLoco[1]) == 0) {
//            pointerMap[GhostLoco[0]][GhostLoco[1]] = EMPTY;
//            GhostLoco[0] += 1;
//            pointerMap[GhostLoco[0]][GhostLoco[1]] = GHOSTA;
//        }
//
//    }
//
//    if (randm == 2) {
//
//        if (isWall(ghostLoco[0], ghostLoco[1] - 3) == 0) {
//            pointerMap[ghostLoco[0]][ghostLoco[1]] = EMPTY;
//            ghostLoco[1] -= 3;
//            pointerMap[ghostLoco[0]][ghostLoco[1]] = GHOSTB;
//        }
//    }
//
//    if (randm == 3) {
//
//        if (isWall(ghostLoco[0], ghostLoco[1] + 3) == 0) {
//            pointerMap[ghostLoco[0]][ghostLoco[1]] = EMPTY;
//            ghostLoco[1] += 3;
//            pointerMap[ghostLoco[0]][ghostLoco[1]] = GHOSTB;
//        }
//
//    }

//used same concept as pacman movement
//void moveGhost1() {
//    srand(time(0));
//
//    int random = rand() % 4;
//  //making the random number equal to ghost going in a direction and using same style as pacman to see if going through a wall and doesn't allow it to
//  // this was supposed to fix the problem of ghosts not always moving as random number was going into the wall but it didnt
//    if (random == 0) {
//        if (isWall(GhostLoco[0] - 1, GhostLoco[1]) == 0) {
//            pointerMap[GhostLoco[0]][GhostLoco[1]] = EMPTY;
//            GhostLoco[0] -= 1;
//            pointerMap[GhostLoco[0]][GhostLoco[1]] = GHOSTA;
//        } else {
//            moveGhost1();
//        }
//
//    }
//
//    if (random == 1) {
//        if (isWall(GhostLoco[0] + 1, GhostLoco[1]) == 0) {
//            pointerMap[GhostLoco[0]][GhostLoco[1]] = EMPTY;
//            GhostLoco[0] += 1;
//            pointerMap[GhostLoco[0]][GhostLoco[1]] = GHOSTA;
//        }
//
//    }
//
//    if (random == 2) {
//        if (isWall(GhostLoco[0], GhostLoco[1] - 3) == 0) {
//            pointerMap[GhostLoco[0]][GhostLoco[1]] = EMPTY;
//            GhostLoco[1] -= 3;
//            pointerMap[GhostLoco[0]][GhostLoco[1]] = GHOSTA;
//        } else {
//            moveGhost1();
//        }
//
//    }
//
//    if (random == 3) {
//        if (isWall(GhostLoco[0], GhostLoco[1] + 3) == 0) {
//            pointerMap[GhostLoco[0]][GhostLoco[1]] = EMPTY;
//            GhostLoco[1] += 3;
//            pointerMap[GhostLoco[0]][GhostLoco[1]] = GHOSTA;
//        } else {
//            moveGhost1();
//        }
//
//    }
//
//}
//
//void moveGhost2() {
//    // generatiing a random number
//    srand(time(0));
//    int randm = rand() % 4;
// //making the random number equal to ghost going in a direction and using same style as pacman to see if going through a wall and doesn't allow it to
//    if (randm == 0) {
//        if (isWall(ghostLoco[0] - 1, ghostLoco[1]) == 0) {
//            pointerMap[ghostLoco[0]][ghostLoco[1]] = EMPTY;
//            ghostLoco[0] -= 1;
//            pointerMap[ghostLoco[0]][ghostLoco[1]] = GHOSTB;
//        } else {
//            moveGhost2();
//        }
//
//    } else if (randm == 1) {
//        if (isWall(ghostLoco[0] + 1, ghostLoco[1]) == 0) {
//            pointerMap[ghostLoco[0]][ghostLoco[1]] = EMPTY;
//            ghostLoco[0] += 1;
//            pointerMap[ghostLoco[0]][ghostLoco[1]] = GHOSTB;
//        } else {
//            moveGhost2();
//        }
//    } else if (randm == 2) {
//
//        if (isWall(ghostLoco[0], ghostLoco[1] - 3) == 0) {
//            pointerMap[ghostLoco[0]][ghostLoco[1]] = EMPTY;
//            ghostLoco[1] -= 3;
//            pointerMap[ghostLoco[0]][ghostLoco[1]] = GHOSTB;
//        } else {
//            moveGhost2();
//        }
//    } else if (randm == 3) {
//
//        if (isWall(ghostLoco[0], ghostLoco[1] + 3) == 0) {
//            pointerMap[ghostLoco[0]][ghostLoco[1]] = EMPTY;
//            ghostLoco[1] += 3;
//            pointerMap[ghostLoco[0]][ghostLoco[1]] = GHOSTB;
//        } else {
//            moveGhost2();
//        }
//    }
//}



int main(){
    char* ptr[rows][cols];
    for(int i=0; i < rows; i++){
        for(int j =0; j < cols; j++){
            (ptr[i][j]) = static_cast<char *>(malloc(sizeof(char)));
            if(ptr[i][j] == NULL) {
                printf("Memory allocation failed");
            }
        }
    }
    //scanning file that we opened and saving into the pointer
    FILE* fp = fopen("map.txt", "r");

    for(int i=0; i < rows; i++){
        for(int j =0; j < cols; j++){
            fscanf(fp, "s", ptr[i][j]);
        }
    }

    if(fp == NULL){
        printf("File not found\n");
        return 0;
    }
    createArray();
    loadMap(fp);
    fclose(fp);
    printMap();
    for(int i=0; i < 11; i++){
        for(int j =0; j < 33; j++){
            if(pointerMap[i][j] == PACMAN){
                currentLoco[0]=i;
                currentLoco[1]=j;
            }
        }
    }
    for(int i=0; i < 11; i++){
        for(int j =0; j < 33; j++){
            if(pointerMap[i][j] == GHOSTA){
                GhostLoco[0]=i;
                GhostLoco[1]=j;
                if(pointerMap[i][j] == GHOSTB){
                    ghostLoco[0]=i;
                    ghostLoco[1]=j;
                }}
        }
    }
//win check
    char nextMove;
    while(winCheck() == 0){
        printf("Enter w, a, s or d to move pacman");
        scanf( "%c", &nextMove);
        movePacman(nextMove);
        printf("\n");
        printMap();
    }
//loose check was making the code not run but we are sure the function is right
//    if(winCheck()){
//        printf("win");
//    }
//    else if(loseCheck(ptr)){
//        printf("Loose");
//    }


}
