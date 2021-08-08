#include"music.h"
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
void print()
{
        printf("Press the keys according to your choice\n");
        printf("s: start the player\n");
        printf("j: Jump to a specific track\n");
        printf("n: next track\n");
        printf("p: previous track\n");
        printf("f: first track\n");
        printf("l: last track\n");
        printf("a: add a track after an existing track\n");
        printf("b: add a track before an existing track\n");
        printf("r: remove a specific track from the list\n");
        printf("o: O: sort the tracks in alphabetical order ");
        printf("t: stop the player\n");
        printf("c: change the track position\n");
        printf("d: display all tracks\n");
        printf("PRESS E TO EXIT \n");

        
}

int main()
{
    FILE *fp;
    node *rear=NULL;
    fp=fopen("c:\\Users\\rahma\\import.txt","r+");
    print();
    musicplayer(&rear,fp);
    fclose(fp);
    return 0;
}    