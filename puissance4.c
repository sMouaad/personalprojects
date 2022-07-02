#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
const int L=6;
const int C=7;
void board(char af[L][C]);
bool win(char af[L][C], char x);
int main() {
    char menu,a[L][C];
    int k=0,i,n,s=1;
    bool won1 = false, won2=false;
    for(i=0;i<6;i++){
        for(int j=0;j<7;j++) {
            a[i][j]=' ';
        }
    }board(a);
    do {
    if (s==1) {
        printf("\nPLAYER 1 PLAY : ");
        do {i=0;
        do {scanf("%d", &n);}while(n<1 || n>7);
        while(a[i][n-1]=='X' || a[i][n-1]=='O') {
            i++;
        }
        if(i>5) {
            printf("You can't! choose another number : ");
        }
        }while(i>5);
        a[i][n-1]='X';
        board(a);
        if(k>2){
            won1 = win(a, 'X');
        }
        s=-s;
    }
    else {
        printf("\nPLAYER 2 PLAY : ");
        do {i=0;
        do {scanf("%d", &n);}while(n<1 || n>7);
        while(a[i][n-1]=='X' || a[i][n-1]=='O') {
            i++;
        }
        if(i>5) {
            printf("You can't! choose another number : ");
        }
        }while(i>5);
        a[i][n-1]='O';
        board(a);
        if(k>2){
            won2 = win(a, 'O');
        }
        s=-s;
        k++;
    }
    }while(won1==false && won2==false && k<21);
    if (won1==true) {
        printf("\nPlayer 1 WON!");
    }
    else if(won2==true) {
        printf("\nPlayer 2 WON!");
    }
    else {printf("DRAW!!!");}
    printf("\nWould you like to play again? Y/N \n");
    scanf(" %c", &menu);
    if(menu=='y' || menu=='Y') {main();} else {printf("Thanks for playing!");}
    return 0;
}
bool grow(int t[L][C],int k,int b) {
    int i = 1, s=0;
    bool found=false, exit=false;
    if(b==0) {
    while(i<7 && found==false) { /* Horizontal check */
        if (t[k][i]==t[k][i-1]+1) {
            exit=false;
            s=0;
            while (t[k][i]==t[k][i-1]+1 && exit==false) {
                s++;
                if (s==3) {
                    found=true;
                }
                else {
                    i++;
                    if (t[k][i-1]==t[k][i]) {
                        i++;
                    }
                    else if (t[k][i]!=t[k][i-1]+1) {
                        i++;
                        exit = true;
                    }
                }
            }
        }
        else {
            i++;
        }
    }}
    else {
    while(i<6 && found==false) { /* Vertical check */
        if (t[i][k]==t[i-1][k]+1) {
            exit=false;
            s=0;
            while (t[i][k]==t[i-1][k]+1 && exit==false) {
                s++;
                if (s==3) {
                    found=true;
                }
                else {
                    i++;
                    if (t[i-1][k]==t[i][k]) {
                        i++;
                    }
                    else if (t[i][k]!=t[i-1][k]+1) {
                        i++;
                        exit = true;
                    }
                }
            }
        }
        else {
            i++;
        }
    }}
    return found;
}
void board(char af[L][C]) {
    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n ___________________________\n| %c | %c | %c | %c | %c | %c | %c |\n|___|___|___|___|___|___|___|\n| %c | %c | %c | %c | %c | %c | %c |\n|___|___|___|___|___|___|___|\n| %c | %c | %c | %c | %c | %c | %c |\n|___|___|___|___|___|___|___|\n| %c | %c | %c | %c | %c | %c | %c |\n|___|___|___|___|___|___|___|\n| %c | %c | %c | %c | %c | %c | %c |\n|___|___|___|___|___|___|___|\n| %c | %c | %c | %c | %c | %c | %c |\n|___|___|___|___|___|___|___|\n  1   2   3   4   5   6   7 ", af[5][0], af[5][1], af[5][2], af[5][3], af[5][4], af[5][5], af[5][6], af[4][0] ,af[4][1], af[4][2], af[4][3], af[4][4], af[4][5], af[4][6], af[3][0],af[3][1], af[3][2], af[3][3], af[3][4], af[3][5], af[3][6], af[2][0], af[2][1], af[2][2], af[2][3], af[2][4], af[2][5], af[2][6],af[1][0], af[1][1], af[1][2], af[1][3], af[1][4], af[1][5], af[1][6],af[0][0], af[0][1], af[0][2], af[0][3], af[0][4], af[0][5], af[0][6]);
}
bool win(char af[L][C], char x){
    bool winner=false;
    int j,i=0,k=0, s[7]={0},LC[L][C],q=0;
    for(int d=0;d<L;d++){
        for(int o = 0; o<C;o++) {
            LC[d][o]=0;
        }
    }
    while(i<L && winner==false){ /* Horizontal check */
        for(int j=0;j<C;j++){
            if(af[i][j]==x) {
                LC[i][q]=j;
                q++;
                if (q==7) {q=0;}
                s[i]=s[i]+1;
                if (s[i]==4) {
                    if (grow(LC,i,0)==true) {
                        winner=true;
                    }
                }
            }
        }
        i++;
    }
    j=0;k=0;q=0;
    for(int d=0;d<L;d++){       /* Initialization */
        for(int o = 0; o<C;o++) {
            LC[d][o]=0;
            s[o];
        }
    }
    while(j<C && winner==false){    /* Vertical check */
        for(int i=0;i<L;i++){
            if(af[i][j]==x) {
                LC[q][j]=i;
                q++;
                if (q==6) {q=0;}
                s[j]=s[j]+1;
                if (s[j]==4) {
                    if (grow(LC,j,1)==true) {
                        winner=true;
                    }
                }
            }
        }
        j++;
    }
    k=0;q=0,i=0;
    while(i<3 && winner==false){ /* Diagonal check*/
        for(int j=0;j<4;j++){
            if(af[i][j]==x) {
                if((af[i+1][j+1]==x) && (af[i+2][j+2]==x) && (af[i+3][j+3]==x)) {
                    winner=true;
                }
            }
        }
        i++;
    }k=0;q=0,i=0;
    while(i<6 && winner==false){ /* Diagonal check */
        for(int j=3;j<7;j++){
            if(af[i][j]==x) {
                if((af[i+1][j-1]==x) && (af[i+2][j-2]==x) && (af[i+3][j-3]==x)) {
                    winner=true;
                }
            }
        }
        i++;
    }
    return winner;
}