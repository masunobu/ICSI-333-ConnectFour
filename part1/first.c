    /*
    ICSI 333 Connect-Four (part 1) Naganobu Masuda(001447584)
    */
#include <stdio.h>
    /* name for two players */
    char name1[20], name2[20];
    /* the columns of the board */
    char col[] = {'A','B','C','D','E','F','G'};
    /* height and width of the board */
    int height=6, width=7;
    /* global state(mostly used in the future project) */
    int state;

/* initializes project to let two player start game */
void Initialization(void){
    printf("\nSetting up the game.\n");

    printf("\nWhat's first player's name?: ");
    scanf("%s",name1);
    printf("\nWhat's second player's name?: ");
    scanf("%s",name2);
}

/* tears down to exit the game */
void TearDown(void){
    printf("\nDestroying the game.\n");
}

/* accepts player input to drop a disc or quit the game */
char AcceptInput(void){
    int num;
    do{
        printf("\nEnter between 0 and 6 to drop a disc. Enter 7 to quit the game: ");
        scanf("%d",&num);
    }while(num < 0 || 7 < num);
    if(0 <= num && num <= 6){
        return col[num];
    }else if(num == 7){
        printf("---Quit the game.\n");
    }return 0;
}

/* updates the world correspondin to player's input */
int UpdateWorld(char *item){
    printf("\nDropping a disc on column '%c'\n", *item);
    if(*item == 'A'){
        state = 1;
    }else{
        state = 0;
    }return state;
}

/* displays the world which updated in the UpdateWorld function */
void DisplayState(int state){
    if(state == 1){
        printf("---Winning move!\n");
    }else{
        printf("---Please continue\n");
    }
}

/* the main function */
/* set up the data structures that model the “game world” */
int main(int argc, char const *argv[]){
    Initialization();
    char item;
    do{
        item = AcceptInput();
        if(item != 0){
            state = UpdateWorld(&item);
            DisplayState(state);
        }
    }while(item != 'A' && item != 0);
    TearDown();

    return 0;
}
