#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <Windows.h>
#include <conio.h>


bool loggedIn=false;


typedef struct user{
	char email[30];
	char password[8];
}user;
typedef struct data{
	char city[15];
	int id;
	char address[50];
	char number[11];
	int price;
//	char *type;
}data;
typedef struct sales{
	char city[15];
	int id;
	char address[50];
	char buyer_number[11];
	int price;
	char email[30];
}sales;
void login(){
	system("cls");
	
	// Heading
	int i;
	for(i=1;i<120;i++){
    	printf("-");
	}
	printf("\n\n");
	printf("  \t\t\t\t\t\t   REAL ESTATE SYSTEM  ");
	printf("\n\n");
	 for(i=1;i<120;i++){
    	printf("-");
	}
	printf("\n");
	for(i=0;i<55;i++){
		printf(" ");
	}
	printf("'LOGIN'");
	printf("\n\n");
	
	// Login System
	user allusers,*logged_in_user;
	FILE *fp,*fp1;
	
	fp = fopen("signedusers.txt","r");
	fp1 = fopen("loggedinuser.txt","w");	
	
	
	int resulte,resultp,flag=0;
	logged_in_user = (user*) calloc(1,sizeof(user));
	printf("\t\t\t\t\tEnter email : ");
	scanf("%s",logged_in_user[0].email);
	printf("\t\t\t\t\tEnter password : ");
	scanf("%s",logged_in_user[0].password);
	
	while(fread(&allusers,sizeof(user),1,fp)){
		resulte = strcmp(logged_in_user[0].email,allusers.email);
		resultp = strcmp(logged_in_user[0].password,allusers.password);
		if(resulte == 0 && resultp == 0){
			flag=1;
			break;
		}
		else{
			flag=0;
		}
	}
	
	if(flag==1){
		printf("\nLogged In!");
		fwrite(&logged_in_user[0],sizeof(user),1,fp1);
		loggedIn = true;
	}
	else{
		printf("\nNo user found with this data.\nMoving you to the Login/Signup Screen Again...");
		sleep(3);
		system("cls");
		loggedIn = false;
	}
	free(logged_in_user);
	fclose(fp);
	fclose(fp1);
}
void signup(){
	system("cls");
	
	// Heading
	int i;
	for(i=1;i<120;i++){
    	printf("-");
	}
	printf("\n\n");
	printf("  \t\t\t\t\t\t   REAL ESTATE SYSTEM  ");
	printf("\n\n");
	 for(i=1;i<120;i++){
    	printf("-");
	}
	printf("\n");
	for(i=0;i<55;i++){
		printf(" ");
	}
	printf("'SIGNUP'");
	printf("\n\n");
	
	// Sign up system
	FILE *fp;
	fp = fopen("signedusers.txt","a");
	
	user *signed_up_user;
	
	bool flag = false , eflag_spec1 = false , eflag_spec2 = false , eflag_smchar = false , eflag_capchar = false , eflag_nums = false,
	pflag_nums = false , pflag_smchar = false , pflag_capchar = false;
	int j;
	signed_up_user = (user*) calloc(1,sizeof(user));
	do{
		printf("\t\t\t\t\tEnter email : ");
		scanf("%s",signed_up_user[0].email);
		
		printf("\t\t\t\t\tEnter password : ");
		scanf("%s",signed_up_user[0].password);
		
		// Email validation
		for(j=0;j<strlen(signed_up_user[0].email);j++){
			if( signed_up_user[0].email[j]>= 'a' && signed_up_user[0].email[j]<='z' ){
				eflag_smchar = true;
			}
			else if( signed_up_user[0].email[j]>= 'A' && signed_up_user[0].email[j]<='Z' ){
				eflag_capchar = true;
			}
			else if( signed_up_user[0].email[j] == '@' ) {
				eflag_spec1 = true;
			}
			else if( signed_up_user[0].email[j] == '.' ) {
				eflag_spec2 = true;
			}	
		}
		
		// Password validation
		for(j=0;j<strlen(signed_up_user[0].password);j++){
			if( signed_up_user[0].password[j]>= 'a' && signed_up_user[0].password[j]<='z' ){
				pflag_smchar = true;
			}
			else if( signed_up_user[0].password[j]>= 'A' && signed_up_user[0].password[j]<='Z' ){
				pflag_capchar = true;
			}
			else if( signed_up_user[0].password[j] >= '0' || signed_up_user[0].password[j] <= '9' ) {
				pflag_nums = true;
			}	
		}
		
		// Email errors
		
		if( eflag_smchar == false ){
			printf("Email must contain small letter.\n");
		}
		if( eflag_capchar == true ){
			printf("Email can't contain capital letter.\n");
		}
		if( eflag_spec1 == false ) {
			printf("Email must contain @.\n");
		}
		if( eflag_spec2 == false ) {
			printf("Email must contain '.'\n");
		}
		
		// Password errors
		
		if( pflag_smchar == false ){
			printf("Password must contain atleast 1 small letter.\n");
		}
		if( pflag_capchar == false ){
			printf("Password must contain atleast 1 capital letter.\n");
		}
		if( pflag_nums == false ) {
			printf("Password must contain atleast 1 number.\n");
		}
		if( strlen(signed_up_user[0].password) > 8 ) {
			printf("Password length should be less than or equal to 8.\n");
		}
		if( strlen(signed_up_user[0].password) < 6 ) {
			printf("Password length should be atleast 6.\n");
		}
		
		// Overall flag
		if( eflag_spec1 == true && eflag_spec2 == true && eflag_smchar == true && pflag_nums == true && pflag_capchar == true 
		&& pflag_smchar == true && eflag_capchar == false && strlen(signed_up_user[0].password) <= 8 && strlen(signed_up_user[0].password) >= 6 ){
			flag = true;
		}
	
	}while( flag !=true );

	fwrite(&signed_up_user[0],sizeof(user),1,fp);
	printf("You have successfully created account!\n");
	printf("Moving to the Login page...\n");
	sleep(3);
	
	free(signed_up_user);
	fclose(fp);
	login();
}
void sell(){
	system("cls");
	// Heading
	int i;
	for(i=1;i<120;i++){
		printf("-");
	}
	printf("\n\n");
	printf("  \t\t\t\t\t\t  SELL PAGE  ");
	printf("\n\n");
	for(i=1;i<120;i++){
		printf("-");
	}
	printf("\n");
	for(i=0;i<45;i++){
		printf(" ");
	}
	
	//Sell Function function
	data *h;
	FILE *fp;
	
	fp = fopen("data.txt","a");
	h = (data*) calloc(1,sizeof(data));
		
		fflush(stdin);
		printf("\nEnter your city : ");
		scanf("%[^\n]s",h[0].city);
		
		fflush(stdin);
		printf("\nEnter your address : ");
		scanf("%[^\n]s",h[0].address);
		
		fflush(stdin);
		printf("\nEnter your contact number : ");
		scanf("%[^\n]s",h[0].number);
			
		fflush(stdin);
		printf("\nEnter an id (The id should not exceed 5 digits) : ");
		scanf("%d",&h[0].id);
		
		fflush(stdin);
		printf("\nEnter Price: ");
		scanf("%d",&h[0].price);
	fwrite(&h[0],sizeof(data),1,fp);
	
	fclose(fp);
	printf("\nYour House is listed Successfully!\n\nPress any Key to go back...");
	getch();
	system("cls");
	free(h);
}
void buy(){
	system("cls");
	// Heading
	int i;
	for(i=1;i<120;i++){
		printf("-");
	}
	printf("\n\n");
	printf("  \t\t\t\t\t\t  BUY PAGE  ");
	printf("\n\n");
	for(i=1;i<120;i++){
		printf("-");
	}
	printf("\n");
	for(i=0;i<45;i++){
		printf(" ");
	}
	
	//Buy function
	data h1;
	user u1;
	sales s1;
	char querycity[20],buyer_num[11];
	FILE *fp,*fp1,*fp2,*logged_user,*sold;
	int query,found=0;
	
	printf("\nEnter city in which you want to buy house : ");
	scanf("%s",querycity);
	
	fp = fopen("data.txt","r");
	fp1 = fopen("tempbuy.txt","w");
	fp2 = fopen("tempbuy2.txt","w");
	logged_user = fopen("loggedinuser.txt","r");
	
	fread(&u1,sizeof(user),1,logged_user);
	strcpy(s1.email,u1.email);
	
	fclose(logged_user);
	
	while(fread(&h1,sizeof(data),1,fp)){
		if(strcmp(querycity,h1.city)==0){
			fwrite(&h1,sizeof(data),1,fp2);
		}
	}
	
	fclose(fp2);
	printf("\nAvailable Houses in %s:",querycity);
	fp2 = fopen("tempbuy2.txt","r");
	printf("\n\nID   CITY\t   ADDRESS\t\t\t\t   PHONENUMBER\t    PRICE\n");
     for(i=1;i<120;i++){
     	printf("-");
	 }
	while(fread(&h1,sizeof(data),1,fp2)){
		printf("\n%-5d%-14s%-40s%-17s%-10d",h1.id,h1.city,h1.address,h1.number,h1.price);
	}
	printf("\n");
	 for(i=1;i<120;i++){
	 	printf("-");
	 }
	printf("\n\nEnter id to buy house : ");
	scanf("%d",&query);
	rewind(fp);
	sold = fopen("soldhouses.txt","a");
	while(fread(&h1,sizeof(data),1,fp)){
		if( query == h1.id ){
			found = 1;
			strcpy(s1.address,h1.address);
			strcpy(s1.city,h1.city);
			s1.id = h1.id;
			s1.price = h1.price;
			fflush(stdin);
			printf("\nID found!Enter your contact number : ");
			scanf("%s",buyer_num);
			strcpy(s1.buyer_number,buyer_num);
			fwrite(&s1,sizeof(sales),1,sold);
		}
		else{
			fwrite(&h1,sizeof(data),1,fp1);
		}
	}
	fclose(sold);
	fclose(fp);	
	fclose(fp1);
	fclose(fp2);
	if(found){
		fp = fopen("data.txt","w");
		fp1 = fopen("tempbuy.txt","r");
		while(fread(&h1,sizeof(data),1,fp1)){
			fwrite(&h1,sizeof(data),1,fp);
		}
		printf("\nYou have bought house with id %d.",query);
		fclose(fp);	
		fclose(fp1);
	}
	else{
		printf("\nInvalid Id entered.");	
	}
	fclose(fp);	
	fclose(fp1);
	printf("\n\nPress any Key to go back...");
	getch();
	system("cls");
}
void allhouses(){
	system("cls");	
	data h1;
	int i;
	for(i=1;i<120;i++){
		printf("-");
	}
	printf("\n\n");
	printf("  \t\t\t\t\t\t  ALL HOUSES  ");
	printf("\n\n");
	for(i=1;i<120;i++){
		printf("-");
	}
	printf("\n");

	FILE *fp;
	
	fp = fopen("data.txt","r");
	
	printf("ID   CITY\t   ADDRESS\t\t\t\t   PHONENUMBER\t    PRICE\n");
    for(i=1;i<120;i++){
    	printf("-");
	}
	while(fread(&h1,sizeof(data),1,fp)){
		printf("\n%-5d%-14s%-40s%-17s%-10d",h1.id,h1.city,h1.address,h1.number,h1.price);
	}
	printf("\n");
	 for(i=1;i<120;i++){
	 	printf("-");
	 }
	fclose(fp);
	printf("\n\nPress any Key to go back...");
	getch();
	system("cls");
}
void userlist(){
	system("cls");
	// Heading
	int i;
	for(i=1;i<120;i++){
		printf("-");
	}
	printf("\n\n");
	printf("  \t\t\t\t\t\t ALL USERS  ");
	printf("\n\n");
	for(i=1;i<120;i++){
		printf("-");
	}
	printf("\n");
	
	user u1;
	FILE *fp;
	
	fp = fopen("signedusers.txt","r");
	
	printf("EMAIL\t\t\t      PASSWORD\n");
	
    for(i=1;i<120;i++){
    	printf("-");
	}
	
	char adminemail[] = "admin@gmail.com";
	while(fread(&u1,sizeof(user),1,fp)){
		if((strcmp(u1.email,adminemail))==0){
			printf("");
		}
		else{
			printf("\n%-30s%-8s",u1.email,u1.password);	
		}
	}
	printf("\n");
	 for(i=1;i<120;i++){
	 	printf("-");
	 }
	fclose(fp);
		printf("\n\nPress any Key to go back...");
	getch();
	system("cls");
}
void deleterecordsadmin(){
	system("cls");
	// Heading
	int i;
	for(i=1;i<120;i++){
		printf("-");
	}
	printf("\n\n");
	printf("  \t\t\t\t\t\t DELETE RECORD  ");
	printf("\n\n");
	for(i=1;i<120;i++){
		printf("-");
	}
	printf("\n");
	
	data d1;
	FILE *fp,*fp1;
	
	fp = fopen("data.txt","r");
	printf("ID   CITY\t   ADDRESS\t\t\t\t   PHONENUMBER\t    PRICE\n");
    for(i=1;i<120;i++){
     	printf("-");
	}
	while(fread(&d1,sizeof(data),1,fp)){
		printf("\n%-5d%-14s%-40s%-17s%-10d",d1.id,d1.city,d1.address,d1.number,d1.price);
	}
	printf("\n");
	 for(i=1;i<120;i++){
	 	printf("-");
	 }
	fclose(fp);
	
	fp = fopen("data.txt","r");
	fp1  = fopen("temp.txt","w");	
	int j,query,found=0;
	printf("\nEnter the house Id to delete house : ");
	scanf("%d",&query);

	while(fread(&d1,sizeof(data),1,fp)){
		if(query == d1.id){
			found = 1;
		}else{
			fwrite(&d1,sizeof(data),1,fp1);
		}
	}
	fclose(fp);
	fclose(fp1);
	
	if(found){
		fp = fopen("data.txt","w");
		fp1  = fopen("temp.txt","r");
		while(fread(&d1,sizeof(data),1,fp1)){
			fwrite(&d1,sizeof(data),1,fp);
		}
		printf("\nSuccessfully deleted house with id %d!",query);
		fclose(fp);
		fclose(fp1);
	}else{
		printf("No Record found with this Id.");
	}
	printf("\n\nPress any Key to go back...");
	getch();
	system("cls");
}
void deleteusers(){
	system("cls");
	// Heading
	int i;
	for(i=1;i<120;i++){
		printf("-");
	}
	printf("\n\n");
	printf("  \t\t\t\t\t\t DELETE USER  ");
	printf("\n\n");
	for(i=1;i<120;i++){
		printf("-");
	}
	printf("\n");
	user u1;
	FILE *fp,*fp1;
	
	fp = fopen("signedusers.txt","r");
	char adminemail[] = "admin@gmail.com";
	
	while(fread(&u1,sizeof(user),1,fp)){
		if((strcmp(u1.email,adminemail))==0){
			printf("");
		}
		else{
			printf("%-30s%-8s\n",u1.email,u1.password);	
		}
	}
	
	 for(i=1;i<120;i++){
	 	printf("-");
	 }
	rewind(fp);
	fp1  = fopen("tempusers.txt","w");	
	int found=0;
	char email[30];
	printf("\nEnter the email to delete user : ");
	fflush(stdin);
	scanf("%s",email);

	while(fread(&u1,sizeof(user),1,fp)){
		if((strcmp(u1.email,email))==0){
			found = 1;
		}else{
			fwrite(&u1,sizeof(user),1,fp1);
		}
	}
	fclose(fp);
	fclose(fp1);
	
	if(found){
		fp = fopen("signedusers.txt","w");
		fp1  = fopen("tempusers.txt","r");
		while(fread(&u1,sizeof(user),1,fp1)){
			fwrite(&u1,sizeof(user),1,fp);
		}
		printf("\nSuccessfully deleted user with email %s!",email);
		fclose(fp);
		fclose(fp1);
	}else{
		printf("No Record found with this email.");
	}
	printf("\n\nPress any Key to go back...");
	getch();
	system("cls");
}
void soldhouses(){
	system("cls");
	// Heading
	int i;
	for(i=1;i<120;i++){
		printf("-");
	}
	printf("\n\n");
	printf("  \t\t\t\t\t\t 	SOLD HOUSES   ");
	printf("\n\n");
	for(i=1;i<120;i++){
		printf("-");
	}
	sales s1;
	FILE *fp;
	
	fp = fopen("soldhouses.txt","r");
	printf("\nID   CITY\t    BUYERNUMBER\t        BUYEREMAIL\t         PRICE \n");
     for(i=1;i<120;i++){
     	printf("-");
	 }
	while(fread(&s1,sizeof(sales),1,fp)){
		printf("\n%-5d%-15s%-20s%-25s%-10d",s1.id,s1.city,s1.buyer_number,s1.email,s1.price);
	}
	printf("\n");
	 for(i=1;i<120;i++){
	 	printf("-");
	 }
	fclose(fp);
	printf("\nPress any Key to go back...");
	getch();
	system("cls");
}
void commission(){
	system("cls");
	// Heading
	int i;
	for(i=1;i<120;i++){
		printf("-");
	}
	printf("\n\n");
	printf("  \t\t\t\t\t\t 	COMMISSION   ");
	printf("\n\n");
	for(i=1;i<120;i++){
		printf("-");
	}
	sales s1;
	FILE *fp;
	int comiss,tot_commiss=0;
	fp = fopen("soldhouses.txt","r");
	
	printf("\nID   CITY\t    BUYERNUMBER\t        BUYEREMAIL\t         PRICE\t\tCOMMISSION \n");
     for(i=1;i<120;i++){
     	printf("-");
	 }
	while(fread(&s1,sizeof(sales),1,fp)){
		comiss = s1.price*0.1;
		printf("\n%-5d%-15s%-20s%-25s%-10d     %-6d",s1.id,s1.city,s1.buyer_number,s1.email,s1.price,comiss);
		tot_commiss+=comiss;
	}
	printf("\n");
	 for(i=1;i<120;i++){
	 	printf("-");
	 }
	 printf("\n\nYour total Commission : %d",tot_commiss);
	fclose(fp);
	printf("\n\nPress any Key to go back...");
	getch();
	system("cls");
}
char usertype(){
	FILE *fp;
	fp = fopen("loggedinuser.txt","r");
	char adminemail[] = "admin@gmail.com";
	user usertype;
	
	fread(&usertype,sizeof(user),1,fp);
	
	if(strcmp(usertype.email,adminemail)==0){
		return '1';
	}else{
		return '0';
	}
}
int main(){	

	char opt;
	int i;
	while(loggedIn==false){
		system("cls");
		// Heading
		for(i=1;i<120;i++){
	    	printf("-");
		}
		printf("\n\n");
		printf("  \t\t\t\t\t\t   REAL ESTATE SYSTEM  ");
		printf("\n\n");
		 for(i=1;i<120;i++){
	    	printf("-");
		}
		printf("\n");
		for(i=0;i<55;i++){
			printf(" ");
		}
		printf("\n\n");

		printf("\n1.LOGIN\n");
		printf("\n2.SIGNUP\n");
		fflush(stdin);
		printf("\nEnter your choice : ");
		scanf("%c",&opt);
		
		switch(opt){
			case '1':
				login();
			break;
			case '2':
				signup();
			break;
		}
	}	
	printf("\nMoving you to the Home page...");
	sleep(3);
	system("cls");	
	char user_type = usertype();
	
	char ch;
	
	switch(user_type){
		case '0':
				do{	
					for(i=1;i<120;i++){
				    	printf("-");
					}
					printf("\n\n");
					printf("  \t\t\t\t\t\t  MAIN MENU  ");
					printf("\n\n");
					for(i=1;i<120;i++){
				    	printf("-");
					}
					printf("\n");
					for(i=0;i<45;i++){
						printf(" ");
					}
					printf("'LOGGED IN AS USER'");
					printf("\n\n");
					printf("\n1.I WANT TO SELL \n");
					printf("\n2.I WANT TO BUY(Search City to check for houses) \n");
					printf("\n3.SEE ALL AVAILABLE HOUSES IN ALL CITIES(NO BUY OPTION ONLY CHECK) \n");
					printf("\n0.EXIT \n");
					
					fflush(stdin);
					printf("\nEnter your choice : ");
					scanf("%c",&ch);
					
					switch(ch){
						case '1':
							sell();
						break;
						case '2':
							buy();
						break;
						case '3':
							allhouses();
						break;
					}
				}while(ch!= '0');
		break;
		case '1':
				do{
					for(i=1;i<120;i++){
			    	printf("-");
					}
					printf("\n\n");
					printf("  \t\t\t\t\t\t  MAIN MENU  ");
					printf("\n\n");
					 for(i=1;i<120;i++){
				    	printf("-");
					}
					printf("\n");
					for(i=0;i<45;i++){
						printf(" ");
					}
					printf("'LOGGED IN AS ADMIN'");
					printf("\n\n");
					printf("\n1.SEE ALL RECORDS \n ");
					printf("\n2.DELETE RECORDS\n  ");
					printf("\n3.SEE ALL SIGNED UP USERS \n ");
					printf("\n4.DELETE USERS \n ");
					printf("\n5.SEE SOLD HOUSES \n ");
					printf("\n6.SEE YOUR COMMISSION \n ");
					printf("\n0.EXIT \n ");
					
					fflush(stdin);
					printf("\nEnter your choice : ");
					scanf("%c",&ch);
					
					switch(ch){
						case '1':
							allhouses();
						break;
						case '2':
							deleterecordsadmin();
						break;
						case '3':
							userlist();
						break;
						case '4':
							deleteusers();
						break;
						case '5':
							soldhouses();
						break;
						case '6':
							commission();
						break;
					}
				}while(ch!= '0');
		break;
	}
	
	return 0;
}
