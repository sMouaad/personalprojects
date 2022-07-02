#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
bool win(int p[], int k);
int main() {
    bool p1=false, p2=false;
    int s=1,i=0,k,l=0,player1[5],player2[4];
    char m;
    do {
    char xo[9]={'1','2','3','4','5','6','7','8','9'};
    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t1\t||\t2\t||\t3\t\n--------------------------------------------------\n\t4\t||\t5\t||\t6\t\n--------------------------------------------------\n\t7\t||\t8\t||\t9\t\n");
        do {
        if (s==1) {
            printf("Player 1 play: ");
            scanf("%d", &player1[i]);
            while(xo[player1[i]-1]=='O' || xo[player1[i]-1]=='X'){printf("\nInput another number... : ");scanf("%d", &player1[i]);}
            xo[player1[i]-1]='X';
            s=-s;
            l++;
            if(l>=3){
            p1 = win(player1,i);
            }
        printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t%c\t||\t%c\t||\t%c\t\n--------------------------------------------------\n\t%c\t||\t%c\t||\t%c\t\n--------------------------------------------------\n\t%c\t||\t%c\t||\t%c\t\n", xo[0], xo[1], xo[2], xo[3], xo[4], xo[5], xo[6],xo[7],xo[8]);
        }
    else {
        printf("Player 2 play: ");
        scanf("%d", &player2[i]);
        while(xo[player2[i]-1]=='O' || xo[player2[i]-1]=='X'){printf("\nInput another number... : ");scanf("%d", &player2[i]);}
        xo[player2[i]-1]='O';
        printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t%c\t||\t%c\t||\t%c\t\n--------------------------------------------------\n\t%c\t||\t%c\t||\t%c\t\n--------------------------------------------------\n\t%c\t||\t%c\t||\t%c\t\n", xo[0], xo[1], xo[2], xo[3], xo[4], xo[5], xo[6],xo[7],xo[8]);
        s=-s;
        l++;
        if(l>=3){
           p2 = win(player2,i);
            }
         i++;
        }
    }while(l<9 && (p1!=true && p2!=true));
    if (p1==true){printf("PLAYER 1 WON!");}
    else if (p2==true){printf("PLAYER 2 WON!");}
    else {printf("ITS A DRAW!!!!!!!");}
    s=-s;
    printf("\nWould you like to play again? y/n\n");scanf(" %c", &m);}while(m=='y');
    return 0;
}
bool win(int p[], int k) {
    int i=0,l,t[24]={1,2,3,4,5,6,7,8,9,1,5,9,3,5,7,1,4,7,2,5,8,3,6,9};
    bool found=false,won=false;
    k++;
    while(i<24 && won==false) {
        l=0;
        found=false;
        while(l<k & found==false) {
            if (t[i]==p[l]) {
                found = true;
            }
            else {
                l++;
            }
        }
        if(found==true) {
            if ((i+1)%3==0) {
                won=true;
            }
            else {
                i++;
            }
        }
        else {
           while((i+1)%3!=0){
               i++;
            }
            i++;
        }
    }
    return won;
}
