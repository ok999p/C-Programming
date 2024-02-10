

typedef struct accout_data accouttype;//For Present
struct accout_data{
	char accout_number[20];
	char accout_type[50];
	float balance;
	float credit_limit;
};

typedef struct person_data persontype;
struct person_data{
	char person_id[20];
	char person_name[25];
	char person_surname[25];
	accouttype accout[10];
};


#include <stdio.h>
#include <string.h>
int main(){
	int n,i,j,check,Pnumber;
	float deposit,withdraw;
	printf("How many customers need to collect data : ");
	scanf("%d",&Pnumber);
	if(Pnumber<0){
		Pnumber=-Pnumber;
	}
	persontype person_info[Pnumber];
	for(i=0;i<Pnumber;i++){
	printf("\n******************* Person No.%d *******************\n",i+1);
	printf("Enter your id : ");
	scanf("%s",person_info[i].person_id);
	printf("Enter your name (only name) : ");
	scanf("%s",person_info[i].person_name);
	printf("Enter your surname : ");
	scanf("%s",person_info[i].person_surname);
	printf("How many your accout (maximun 10 accout) : ");
	scanf("%d",&n);
	for(j=0;j<n;j++){
		printf("\n================= Accout No.%d =================\n",j+1);
		printf("Enter your account id : ");
		scanf("%s",person_info[i].accout[j].accout_number);
		printf("Enter your accout type (SavingsAccount or CurrentAccount): ");
		scanf("%s",person_info[i].accout[j].accout_type);
		printf("Enter your balance : ");
		scanf("%f",&person_info[i].accout[j].balance);
		if (strcmp(person_info[i].accout[j].accout_type, "CurrentAccount") == 0	){
		printf("Enter your credit limit : ");
		scanf("%f",&person_info[i].accout[j].credit_limit);
			}
		}
		j = 0;
		printf("Enter Accout No. : ");
		scanf("%d",&j);
		j = j - 1;
		printf("Deposit (Press 1) Withdraw (Press 2) Cancel (Press 9): ");
		scanf("%d",&check);
		if (check == 1){
		printf("How much do you need to deposit? (Baht) : ");
		scanf("%f",&deposit);
		person_info[i].accout[j].balance = person_info[i].accout[j].balance + deposit;
		}
		else if (check == 2){
		printf("How much do you need to withdraw? (Baht) : ");
		scanf("%f",&withdraw);
		if(person_info[i].accout[j].balance>=withdraw){
		person_info[i].accout[j].balance = person_info[i].accout[j].balance - withdraw;
			}else 
			printf("You can't withdraw'");
		}else if(check == 9){
		 	
		}
	}
    for(i=0;i<Pnumber;i++) {
        printf("\n\n^_^***Info Person No. %d^_^\nId : %s\nName : %s\nSurname : %s\nNumber of Account : %d\n",
               i + 1, person_info[i].person_id, person_info[i].person_name, person_info[i].person_surname, n);
        for (j = 0; j < n; j++) {
            printf("\n\n=======Info account No. %d======\nAccount Id : %s\nAccount Type : %s\nBalance : %0.2f\nCredit_limit : %0.2f",
               j + 1, person_info[i].accout[j].accout_number, person_info[i].accout[j].accout_type,
               person_info[i].accout[j].balance, person_info[i].accout[j].credit_limit);
        }
	}
}