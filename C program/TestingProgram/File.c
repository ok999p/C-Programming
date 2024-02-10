#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>
typedef struct datedata datetype;
struct datedata{
    char date[20];
    char month[20];
    char years[20]; 
};

typedef struct publishingstruct publishingtype;
    struct publishingstruct{
    char id[20];
    char name[20];
    char surname[20];
    char weight[20];
    char tall[20];
    datetype inwork;
};

typedef FILE *filetype;

int menu(){
    int number;
    printf("1. Create file\n");
    printf("2. Display data\n");
    printf("3. Insert data\n");
    printf("4. Exit\n");
    printf("Enter number : ");
    scanf("%d",&number);
    return(number);
}

filetype creatfile(filetype fname){
    publishingtype publishing;
    char filename[20];
    printf("File: ");
    scanf("%s",filename);
    if((fname = fopen(filename, "w")) == NULL){
        printf("Error");
        exit(1);
    }
while(1){
    printf("Id : ");
    gets(publishing.id);
    if(publishing.id[0] == '\0'){
        break;
    }
    printf("Name : ");
    gets(publishing.name);
    printf("Surname : ");
    gets(publishing.surname);
    printf("weight : ");
    gets(publishing.weight);
    printf("Tall : ");
    gets(publishing.tall);
    printf("Date : ");
    gets(publishing.inwork.date);
    printf("Month : ");
    gets(publishing.inwork.month);
    printf("Years : ");
    gets(publishing.inwork.years);      
    fwrite(&publishing, sizeof(publishing), 1, fname);
    if(ferror(fname)){
        printf("Error");
        exit(1);
    }
}
fclose(fname);
return(fname);
}

filetype insertfile(filetype fname){
    publishingtype publishing;
    char filename[20];
    printf("File: ");
    scanf("%s",filename);
    if((fname = fopen(filename, "a")) == NULL){
        printf("Error");
        exit(1);
    }
    while(1){
        printf("Id : ");
        scanf("%s",publishing.id);
        if(publishing.id[0] == '\0'){
            break;
        }
        printf("Name : ");
        gets(publishing.name);
        printf("Surname : ");
        gets(publishing.surname);
        printf("weight : ");
        gets(publishing.weight);
        printf("Tall : ");
        gets(publishing.tall);
        printf("Date : ");
        gets(publishing.inwork.date);
        printf("Month : ");
        gets(publishing.inwork.month);
        printf("Years : ");
        gets(publishing.inwork.years);
        fwrite(&publishing, sizeof(publishing), 1, fname);
        if(ferror(fname)){
            printf("Error");
            exit(1);
        }
    }
    fclose(fname);
}

void displaydata(filetype fname){
    publishingtype publishing;
    char filename[20];
    printf("File: ");
    scanf("%s",filename);
    if((fname = fopen(filename , "r"))==NULL){
        printf("Error");
        exit(1);
    }
    while(fread(&publishing, sizeof(publishing), 1, fname)){
        printf("Id : %s\n", publishing.id);
        printf("Name : %s\n", publishing.name);
        printf("Surname : %s\n", publishing.surname);
        printf("weight : %s\n", publishing.weight);
        printf("Tall : %s\n", publishing.tall);
        printf("Date : %s\n", publishing.inwork.date);
        printf("Month : %s\n", publishing.inwork.month);
        printf("Years : %s\n", publishing.inwork.years);
    }
    fclose(fname); 
}
int main(){
    filetype fp;
    int choice = 0;
    while(choice != 4){
    choice = menu();
    if(choice == 1){
        fp = creatfile(fp);
    }else if(choice == 2){
        displaydata(fp);
    }else if(choice == 3){
        insertfile(fp);
        }else if(choice == 4){
            exit(1);
        }
    }
}