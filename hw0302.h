#ifndef HW0302_H_INCLUDE
#define HW0302_H_INCLUDE

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int choice();
void Champion(char team[400][30],int *win,int count);
void ScoreKing(char team[400][30],int *score,int count);
void RedCard(char team[400][30],int *rd,int count);
void Court(char team[400][30],int *win,int count);
void Gap(char h[400][30],char a[400][30],int *gap);

#endif

