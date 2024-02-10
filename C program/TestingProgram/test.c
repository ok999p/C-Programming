typedef struct datedata datetype;
struct datedata{
    int day;
    int month;
    int year;
};

typedef struct person_data persontype;
struct person_data{
    char person_id[20];
    char person_name[25];
    char person_surname[25];
    int tall;
    int weight;
    datetype dateinwork;
};

#include<stdio.h>
void inputpersondata(int n, persontype person[]){
    for(int i=0;i<n;i++){
    printf("Enter person id : ");
    scanf("%s",person[i].person_id);
    printf("Enter person name : ");
    scanf("%s",person[i].person_name);
    printf("Enter person surname : ");
    scanf("%s",person[i].person_surname);
    printf("Enter person tall : ");
    scanf("%d",&person[i].tall);
    printf("Enter person weight : ");
    scanf("%d",&person[i].weight);
    printf("Enter person date in work : ");
    scanf("%d",&person[i].dateinwork.day);
    printf("Enter person month in work : ");
    scanf("%d",&person[i].dateinwork.month);
    printf("Enter person date in work : ");
    scanf("%d",&person[i].dateinwork.year);
    }
}

void displaypersondata(int n, persontype person[]){
    for(int i=0;i<n;i++){
    printf("Person id : %s\n",person[i].person_id);
    printf("Person name : %s\n",person[i].person_name);
    printf("Person surname : %s\n",person[i].person_surname);
    printf("Person tall : %d\n",person[i].tall);
    printf("Person weight : %d\n",person[i].weight);
    printf("Person date in work : %d/%d/%d\n",person[i].dateinwork.day,person[i].dateinwork.month,person[i].dateinwork.year);
    }
}

int main(){
    int n;
    printf("Input person num : \n");
    scanf("%d",&n);
    persontype person[n];
    inputpersondata(n, person);
    displaypersondata(n, person);
    return 0;
}