#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <pthread.h>
#include <semaphore.h>
#define IMMUNE_TH 1000
#define INCUBATED_TH 100
#define COUNTER_TO_STATE 100
#define INFECTED_TH 300
#define QUARANTINE_TH 400
#define DECEASED_TH 600
#define REMOVED_TH 900
float getRandomNumberFromRange(float, float);
int m,i,j,threadCount,inputTurn,quarantine,traditions,turn;
int* subjectsArray;

