/// tflclck
/// version 1.18
/// Mateusz Piotrowski
/// 2014

#include <time.h>
#include <cstdio>
#include <iostream>
#include <conio.h>
#include <iomanip>
#include <cstdlib>

using namespace std;

double version = 1.18;
char input;
clock_t start;
double timeLeft;
double duration;
double previousTimeLeft;
double testPreparation, testResponse;

void instruction(){
    printf("Decide what to do now:\n");
    printf("Type 1 for Personal Preference Task.\n");
    printf("Type 2 for Choice Task.\n");
    printf("Type 3 for Read/Listen/Speak Campus Situation Task.\n");
    printf("Type 4 for Read/Listen/Speak Academic Course Task.\n");
    printf("Type 5 for Listen/Speak Campus Situation Task.\n");
    printf("Type 6 for Listen/Speak Academic Course Task.\n");
    printf("Type q to exit the program.\n");
    printf("\n");
}

void timerCounter(double start, double amountOfTime){
    while(timeLeft >= 0){
        duration = (clock() - start) /(double) CLOCKS_PER_SEC;
        timeLeft = amountOfTime -  duration;
        timeLeft = (int)timeLeft;
        if(previousTimeLeft != timeLeft && timeLeft >= 0)
        {
            previousTimeLeft = timeLeft;
            printf("%.f\n", timeLeft);
        }
    }
}

void timer(string taskName, double preparation, double response){

    system("cls");

    printf("%d\n\n", taskName);

    start = clock();
    previousTimeLeft = -1;
    timeLeft = 1;

    printf("PREPARATION\n");
    printf("\a");
    timerCounter(start, preparation);
    printf("\a\a");
    printf("\n");

    start = clock();
    previousTimeLeft = -1;
    timeLeft = 1;

    printf("Now get ready to give your response.\n");
    timerCounter(start, 2);
    printf("\n");

    start = clock();
    previousTimeLeft = -1;
    timeLeft = 1;

    printf("RESPONSE\n");
    printf("\a");
    timerCounter(start,response);
    printf("\a\a");
}


int main(){
    printf("Welcome to tflclck %.2f.\nThe TOEFL exam clock app.\nPlease, have a sit.\n\n", version);
     do{
        instruction();

        input = getch();

        switch(input){
            case '1':
                timer("Task number 1",15,45);
                break;
            case '2':
                timer("Task number 2",15,45);
                break;
            case '3':
                timer("Task number 3",30,60);
                break;
            case '4':
                timer("Task number 4",30,60);
                break;
            case '5':
                timer("Task number 5",20,60);
                break;
            case '6':
                timer("Task number 6",20,60);
                break;
            case 't':{//test
                scanf("%f%f", testPreparation,testResponse);
                timer("Test Task",testPreparation,testResponse);
                break;
                }
            case 'q':
                break;
            default:{
                system("cls");
                printf("Please, try again.\n\n");
                continue;
                break;
            }
        }
        printf("\n");
        system("cls");
        if(input != 'q')
            printf("Time is up!\n\n");
     }while(input != 'q');

    printf("Bye bye Viet Nam.\n\n");
    system("PAUSE");

    return 0;
}
