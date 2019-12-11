
#include "header.h"

int main(){

    printf( "\n Please input the size of the matrix \n");
    scanf("%d",&m);
    printf("\n size is: %d \n",m);

     printf( "\n Please input the turn you wish to run \n");
    scanf("%d",&inputTurn);
    printf("\n turns : %d \n",m);

    printf( "\n Please select option... Do you wish to consider the tradition of mourning the dead for 3 turns?(1/0) \n");
    scanf("%d",&traditions);
    printf("\n traditions is: %d \n",traditions);

    printf( "\n Please select option... Do you wish to consider the quarantine feature?(1/0)\n");
    scanf("%d",&quarantine);
    printf("\n quarantine is: %d \n",quarantine);

    subjectsArray = (int *)malloc(m*2*m*sizeof(int ));


    for(i=0;i<m*m;i++){

        int immunity,age,initialState,futureState;
        futureState = m*m+i;

        if(getRandomNumberFromRange(0.0,10.0)<=1){

            immunity = IMMUNE_TH;
        }else{

            immunity = 0;
        }

        if(getRandomNumberFromRange(0.0,10.0)<=1 && immunity==0){

	        initialState = INCUBATED_TH;
        }else{

	        initialState = 0;
        }
            age = getRandomNumberFromRange(1,99);

            subjectsArray[i] = (immunity + initialState +age);
            subjectsArray[futureState] = (immunity + initialState +age);
            printf("\n-- subject: %d->%d  --intialized -|- immunity is: %d -|- state is: %d -|- age is: %d --> %d futureState: %d",i,futureState,immunity,initialState,age,subjectsArray[i],subjectsArray[futureState]);
    }





        printf("\nhere i go");
        int i,k,l,mm;
        int neverInfected,survivors,incubated,infected,dead,removed;


        neverInfected = 0;
        survivors = 0;
        incubated = 0;
        infected = 0;
        dead = 0;
        removed = 0;
        mm=m*m;


    while(inputTurn>0){



        neverInfected = 0;
        survivors = 0;
        incubated = 0;
        infected = 0;
        dead = 0;
        removed = 0;
        mm=m*m;

        for(i=0;i<mm;i++){

            int myRow = (i-i%m)/m;
            int myCol = i%m;

            printf("\n\n %d my row %d my column %d ",i,myRow,myCol);

            printf("\n%d",subjectsArray[i]);

            int upperRow = (myRow+m-1)%m;
            int lowerRow = (myRow+1)%m;
            int leftCol = (m+myCol-1)%m;
            int rightCol = (myCol+1)%m;
            int neighborsInd[8];
            int futureStateIndex = i+mm;

            neighborsInd[0] = myRow*m+leftCol;
            neighborsInd[1] = upperRow*m+leftCol;
            neighborsInd[2] = upperRow*m+myCol;
            neighborsInd[3] = upperRow*m+rightCol;
            neighborsInd[4] = myRow*m+rightCol;
            neighborsInd[5] = lowerRow*m+rightCol;
            neighborsInd[6] = lowerRow*m+myCol;
            neighborsInd[7] = lowerRow*m+leftCol;

            printf("\n\n subject %d: %d neighbors:\n",i,subjectsArray[i]);

                //process neighbors loop begin

            for(k=0;k<8;k++){


                int indexNeighbor = neighborsInd[k]+mm;
                int neighbor = subjectsArray[indexNeighbor];

                printf(" %d ",indexNeighbor);

                // infect neighbors begin

                if(neighbor<IMMUNE_TH && neighbor>0 && neighbor<INCUBATED_TH){

	                float resistance;

	                if(neighbor%100>15 && neighbor%INCUBATED_TH<50)

	                    resistance = 65;
	                else{

	                    resistance = 45;
	                }
	                if(getRandomNumberFromRange(0.0,resistance)<=1){

	                        neighbor = neighbor+COUNTER_TO_STATE;
	                }
	            }

                int element = subjectsArray[i];

	            if(element>0 && element<IMMUNE_TH && element>=INCUBATED_TH){

	                if(quarantine==0){

	                    printf("--processed neighbor%d:->%d %d",indexNeighbor-mm,indexNeighbor,subjectsArray[indexNeighbor]);
	                    subjectsArray[indexNeighbor] = neighbor;
	                    printf(" to %d \n", subjectsArray[indexNeighbor]);

	                }else if(quarantine>0 && element<QUARANTINE_TH) {

	                    printf("--processed neighbor%d: %d",indexNeighbor-mm,subjectsArray[indexNeighbor]);
	                    subjectsArray[indexNeighbor] = neighbor;
	                    printf(" to %d \n", subjectsArray[indexNeighbor]);
	                }
	            }

                    //infect neighbors end

                }

                //process neighbors loop end



                //process sick begin


                int subject = subjectsArray[i];
                int futureSubject = subjectsArray[futureStateIndex];

                printf("\n\n subject %d-->%d was: %d",i,futureStateIndex,subjectsArray[futureStateIndex]);

                if(subject<IMMUNE_TH && subject>=INCUBATED_TH)
                    if(futureSubject>=DECEASED_TH){

	                    printf("\n this subject is down");

	                    if(traditions>0){

	                        if(futureSubject<REMOVED_TH){

	                            printf("\n traditions %d",traditions);
	                            futureSubject = subject+COUNTER_TO_STATE;
	                        }else{

	                            futureSubject = 0;
	                        }
                        }else{

	                            futureSubject = 0;
	                    }
                    }else{

	                    int stateEvolution = 1;

	                    if(futureSubject<INFECTED_TH){

                            futureSubject=futureSubject+100;
	                        stateEvolution--;
	                    }else{

	                        if(getRandomNumberFromRange(0.0,10.0)<=9.0 && stateEvolution>0){

	                            stateEvolution--;
	                            printf("\n -- subject vizibly infected");
	                            futureSubject = futureSubject + COUNTER_TO_STATE;
	                        }else{

	                            futureSubject=futureSubject+IMMUNE_TH;
	                            printf("\n !!subject outlasts desease");
	                        }
                       }

                    }
                    //process sick end

                //update begin

                subjectsArray[futureStateIndex] = futureSubject;
                printf(" -- is: %d \n",subjectsArray[futureStateIndex]);

                printf("\n updating subject %d from: %d",j+i*m, subjectsArray[i]);
                subjectsArray[i]=subjectsArray[futureStateIndex];
                printf(", to: %d",subjectsArray[i]);

                //update end

                printf("\n\n\nday: %d",turn);


            }// big 4

            //sum up begin

            //for(i=0;i<m;i++)
                for(i=0;i<mm;i++){

                    int sumsubject= subjectsArray[i];

                    if(sumsubject<INCUBATED_TH && sumsubject>0){

                        neverInfected++;
                    }

                    if(sumsubject>=IMMUNE_TH){

                        survivors++;
                    }

                    if(sumsubject>=INCUBATED_TH && sumsubject<INFECTED_TH){

                        incubated++;
                    }

                    if(sumsubject>=INFECTED_TH && sumsubject<DECEASED_TH){

                        infected++;
                    }

                    if(sumsubject>=DECEASED_TH && sumsubject<IMMUNE_TH){

	                    dead++;
                    }

                    if(sumsubject==0){

	                    removed++;
                    }
                }

                printf(" \n\n never infected: %d \n survivors: %d \n incubated: %d \n infected: %d \n dead: %d \n removed: %d \n\n\n",neverInfected,survivors,incubated,infected,dead,removed );
                //sum up end

        inputTurn--;
        turn++;

    }//while

    free(subjectsArray);



    return 0;
}
