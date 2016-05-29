/* 
 * File:   main.c
 * Author: Darius Musiolik
 *
 * Created on 29. Mai 2016, 14:22
 */

#include <stdio.h>
#include <stdlib.h>

//Var
int version = 1;
char fields[9] = {'0', '1', '2', '3', '4', '5', '6', '7', '8'};
int loop = 0;
int player = 2;
int userinput;
char xro; //Decides between X or O


/*
0 | 1 | 2 
---------
3 | 4 | 5  fields in his startform.
---------
6 | 7 | 8 
 */


//Startmethod
int main(int argc, char** argv) {

    printf("Welcome to TicTacToe_CLI Version %i!\n", version);
    
    do { //mainloop
    
            //Draw the fields
            draw(fields);
            
            //Choose Player
            if (player == 2) {
                player--;
                xro = 'x';
            }else{
                player++;
                xro = 'o';
            }
         
            do {
                //Scan input
                printf("\nChoose a number Player%i: ", player);
                scanf("%i", &userinput);
                getchar();
                printf("\nIhre eingabe war: >%i<! Das System kann diese zahl nicht verarbeiten!\n\n", userinput);
            }while(userinput < 0 || userinput > 8 || fields[userinput] == 'x' || fields[userinput] == 'o');
            
            //set input
            fields[userinput] = xro;
            
            //Clear
            system("clear");
            
            //Check if someone has won
            checkwin();
    
        }while(loop == 0);
    
    return 0;
}

//Draw the graphic
int draw(char input[]) {
    int threestep = 0; //Useing vor Vertical formating and lines
    int horstep = 0; //Using for Horizontal lines
    printf("\n");
    
    for(int i = 0; i < 9; i++) {
        
        //On 1 fill a horizontal line
        if (horstep == 1) {
            printf("---------\n");
            horstep = 0;
        }
        
        //Mainpart for printing
        printf("%c ", input[i]);
        threestep++;
        
        //On 1 and 2 fill a |
        if (threestep == 1 || threestep == 2) {
            printf("| ");
        }
        
        //All 3 prints do a \n
        if (threestep == 3) {
            threestep = 0;
            printf("\n");
            horstep++;
        }
    }
}

int checkwin() {
    if (fields[0] == xro && fields[1] == xro && fields[2] == xro) {
        win();
    }
    if (fields[3] == xro && fields[4] == xro && fields[5] == xro) {
        win();
    }
    if (fields[6] == xro && fields[7] == xro && fields[8] == xro) {
        win();
    }
    if (fields[0] == xro && fields[3] == xro && fields[6] == xro) {
        win();
    }
    if (fields[1] == xro && fields[4] == xro && fields[7] == xro) {
        win();
    }
    if (fields[2] == xro && fields[5] == xro && fields[8] == xro) {
        win();
    }
    if (fields[6] == xro && fields[4] == xro && fields[2] == xro) {
        win();
    }
    if (fields[0] == xro && fields[4] == xro && fields[8] == xro) {
        win();
    }
}

int win() {
    //Draw the fields
    draw(fields);
    
    printf("\n\nPlayer%i wins!", player);
    exit(0);
}