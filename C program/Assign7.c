#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>
struct publishstruct{
    char code[7];
    char title[20];
    int price;
}publishing;
typedef FILE *filetype;

int menu(){
    int answer;
    printf("                  MENU\n");
    printf(" [1] Create a new file\n");
    printf(" [2] Display Data in file\n");
    printf(" [3] Stop running program\n");
    printf("Your answer : ");
    scanf("%d",&answer);
    return answer;
}

filetype CreateFile(filetype fname){
    char filename[10], price[6];
    printf("Enter file name : ");
    gets(filename);
    gets(filename);
    printf("%s\n",filename);
    fname = fopen(filename,"w");
    if(fname == NULL){
        printf("Can't open file\n");
        exit(1);
    }
    do {
        printf("Code ( Enter for stop ) : ");
        gets(publishing.code);
        if(publishing.code[0] != '\0'){
            printf("Title : ");
            gets(publishing.title);
            printf("Price : ");
            gets(price);
            publishing.price = atoi(price);
            fwrite(&publishing,sizeof(struct publishstruct),1,fname);
        }
    } while (publishing.code[0] != '\0');
    fclose(fname);
    return fname;
}

void DisplayFile(filetype fname){
    char filename[10];
    int a;
    printf("File name : ");
    gets(filename);
    gets(filename);
    fname = fopen(filename,"r");
    if(fname == NULL){
        printf("Can't open file\n");
        exit(1);
    }
    a = fread(&publishing,sizeof(struct publishstruct),1,fname);
    while(a == 1){
        printf("code : %s\n",publishing.code);
        printf("title : %s\n",publishing.title);
        printf("price : %d\n",publishing.price);
        a = fread(&publishing,sizeof(struct publishstruct),1,fname);
    }
}

int main(){
    filetype fp;
    int ch = 0;
    while (ch!=3){
        ch = menu();
        if(ch == 1){
            fp = CreateFile(fp);
        }
        else if(ch == 2){
            DisplayFile(fp);
        }else if(ch == 3){
            printf("Thank you for using this program\n");
        }
    }
}