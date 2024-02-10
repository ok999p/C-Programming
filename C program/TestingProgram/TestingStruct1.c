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
persontype inputpersondata(){
    persontype person;
    printf("Enter person id : ");
    scanf("%s",person.person_id);
    printf("Enter person name : ");
    scanf("%s",person.person_name);
    printf("Enter person surname : ");
    scanf("%s",person.person_surname);
    printf("Enter person tall : ");
    scanf("%d",&person.tall);
    printf("Enter person weight : ");
    scanf("%d",&person.weight);
    printf("Enter person date in work : ");
    scanf("%d",&person.dateinwork.day);
    printf("Enter person month in work : ");
    scanf("%d",&person.dateinwork.month);
    printf("Enter person date in work : ");
    scanf("%d",&person.dateinwork.year);
    return person;
}

void displaypersondata(persontype person){
    printf("Person id : %s\n",person.person_id);
    printf("Person name : %s\n",person.person_name);
    printf("Person surname : %s\n",person.person_surname);
    printf("Person tall : %d\n",person.tall);
    printf("Person weight : %d\n",person.weight);
    printf("Person date in work : %d/%d/%d\n",person.dateinwork.day,person.dateinwork.month,person.dateinwork.year);
}

int main(){
    persontype per;
    per = inputpersondata();
    displaypersondata(per);
    return 0;
}