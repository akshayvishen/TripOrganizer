#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define NODE 48

enum state{menu,loggedin};
enum state currentstate=menu;

typedef struct user
{
    char username[100];
    char password[100];
    char place[100];
    float price;
    int numtick;
    struct user *next;
}user;


void ShowBrochure();
user* InitializeList(user*);
user* AddUser(user*);
void LoginUser(user*);
void DisplayAll(user*);
void WriteToFile(user*);
void ExitProgram();

char currentuser[100];

int main()
{
    printf("\t\t\t==== || TOURISM MANAGEMENT SYSTEM || ====\n");
    printf("\n \t\t\t\t\t\t\t\t Developed BY: \n \t\t\t\t\t\t\t\t\t\t 1. Abhijeet Rai \n\t\t\t\t\t\t\t\t\t\t 2. Akshay Singh \n\t\t\t\t\t\t\t\t\t\t 3. Alok Dubey \n\t\t\t\t\t\t\t\t\t\t 4. Ashmit Piyush");
    user *h=NULL;
    int ch1,ch2;
    h=InitializeList(h);
    while (1)
    {
    	
        if(currentstate==menu)
        {
        	
            printf("\n\t\t\t\tAdd User - 1\n\t\t\t\tLogin User - 2\n\t\t\t\tBrochure - 3\n\t\t\t\tExit - 4\n\n\t\t\t\tEnter:");
            scanf("%d",&ch1);
            switch(ch1)
            {
                case 1:
                    h=AddUser(h);
                    break;
                case 2:
                    LoginUser(h);
                    break;
                case 3:
                    ShowBrochure();
                    break;
                case 4:
                    ExitProgram();
                    exit(0);
                    break;
                default:
                    printf("Not a valid input at this stage\n");
            }
        }
        else if(currentstate==loggedin)
        {
        system("CLS");
 
// numberArray is the array of datsets which we are fetching through file
int numberArray[50][50];
int ch,i,j,char1,k=0,m=0;
FILE *myFile;
char arrr[NODE][NODE] = {"Aldona    ","Arambol   ","Baga      ","Bambolim  ","Bandora   ","Benaulim  ","Calangute ","Candolim  ","Carapur   ","Cavelossim","Chicalim  ","Chinchinim","Colovale  ","Colva     ","Cortalim  ","Cuncolim  ","Curchorem ","Curti     ","Davorlim  ","Dicholi   ","Goavelha  ","Guirim    ","Jua       ","Kankon    ","Madgaon   ","Morjim    ","Mormugao  ","Mapuca    ","Navelim   ","Palle     ","Panaji    ","Pernem    ","Ponda     ","Quepem    ","Queula    ","Raia      ","Saligao   ","Sancoale  ","Sanguem   ","Sanquelim ","Sanvordem ","Serula    ","Solim     ","Taleigao  ","Vagator   ","Valpoy    ","Varca     ","Vascodagama"};
//read file into array
myFile = fopen("newset.txt", "r");
if (myFile == NULL)
{
        printf("Error Reading File\n");
   exit (0);
}

   while(1)
{
    ch=fgetc(myFile); // to get character
       fscanf(myFile, " %d,", &char1 );
    if(ch==EOF) // to check whether we reach  to last of file
    {
        break;
	}
       numberArray[m][k]=char1;
     k++;
     
      if(k>47)
  {
      k=0;
      m++;
  }
   }
   /*for(i=0;i<48;i++)
   {
   	printf("Location:%s\n",arrr[i]);
   	for(j=0;j<48;j++)
   	{
   		printf("%d km is away from '%s'\n",numberArray[i][j],arrr[j]);
	   }
	printf("\n");
   }*/
 // floyd warshall algo implemented
   int cost[NODE][NODE];    //defind to store shortest distance from any node to any node
  for(i = 0; i<NODE; i++)
     for(j = 0; j<NODE; j++)
        cost[i][j] = numberArray[i][j];     //copy costMatrix to new matrix

  for(k = 0; k<NODE; k++) {
     for( i = 0; i<NODE; i++)
        for(j = 0; j<NODE; j++)
           if(cost[i][k]+cost[k][j] < cost[i][j])
              cost[i][j] = cost[i][k]+cost[k][j];
  }

  printf("Enter the location from which you want to visit: \n 1. Aldona \n 2. Arambol \n 3. Baga \n 4. Bambolim \n 5. Bandora\n 6. Benaulim\n 7. Calangute\n 8. Candolim\n 9. Carapur\n 10. Cavelossim \n 11. Chicalim \n 12. Chinchinim \n 13. Colovale \n 14. Colva \n 15. Cortalim \n 16. Cuncolim \n 17. Curchorem \n 18. Curti \n 19. Davorlim \n 20. Dicholi \n 21. Goa \n 22. Velha \n 23. Guirim \n 24. Jua \n 25. Kankon \n 26. Madgaon \n 27. Morjim \n 28. Mormugao \n 29. Mapuca \n 30. Navelim \n 31. Palle \n 32. Panaji \n 33. Pernem \n 34. Ponda \n 35. Quepem \n 36. Queula \n 37. Raia \n 38. Saligao \n 39. Sancoale \n 40. Sanguem \n 41. Sanquelim \n 42. Sanvordem \n 43. Serula Solim \n 44. Taleigao \n 45. Vagator \n 46. Valpoy \n 47. Varca \n 48. Vasco da Gama\n"); 
  int loc;  // place is variable which is used to find row no.
  printf("enter no:");
scanf("%d",&loc);
loc = loc-1;
  int dist=0;
  for(j = 0; j<NODE; j++)
  {
  printf("%s   : %d km\t \t\t",arrr[j],cost[loc][j]);
  dist++;
  if(dist==3
  )
  {
  	printf("\n");
  	dist=0;
  }
  }
   fclose(myFile);    return 0;
}
}
}
user* InitializeList(user *h)
{
    user* t,*ptr,temp;
    FILE *fp;
    int cc=0,x;
    float ff;
    fp=fopen("users.txt","r");

    if(fp==NULL)
        return NULL;

    if(fgetc(fp)==EOF)
        return NULL;

    rewind(fp);
	while(fscanf(fp,"%s %s %s %f %d",temp.username,temp.password,temp.place,&temp.price,&temp.numtick)!=EOF)
	{
		ptr=(user*)malloc(sizeof(user));
		strcpy(ptr->username,temp.username);
		strcpy(ptr->password,temp.password);
		strcpy(ptr->place,temp.place);
		ptr->price=temp.price;
		ptr->numtick=temp.numtick;
		ptr->next=NULL;

		if(h==NULL)
            h=t=ptr;
		else
		{
			h->next=ptr;
			h=ptr;
		}
	}
	fclose(fp);
    return t;
}

void WriteToFile(user *h)
{
    FILE *fp;
    fp=fopen("users.txt","w");
    while(h!=NULL)
    {
        fprintf(fp,"%s %s %s %f %d\n",h->username,h->password,h->place,h->price,h->numtick);
        h=h->next;
    }
    fclose(fp);
}

void ShowBrochure()
{
system("CLS");
  printf("List of Location Available: \n 1. Aldona \n 2. Arambol \n 3. Baga \n 4. Bambolim \n 5. Bandora\n 6. Benaulim\n 7. Calangute\n 8. Candolim\n 9. Carapur\n 10. Cavelossim \n 11. Chicalim \n 12. Chinchinim \n 13. Colovale \n 14. Colva \n 15. Cortalim \n 16. Cuncolim \n 17. Curchorem \n 18. Curti \n 19. Davorlim \n 20. Dicholi \n 21. Goa \n 22. Velha \n 23. Guirim \n 24. Jua \n 25. Kankon \n 26. Madgaon \n 27. Morjim \n 28. Mormugao \n 29. Mapuca \n 30. Navelim \n 31. Palle \n 32. Panaji \n 33. Pernem \n 34. Ponda \n 35. Quepem \n 36. Queula \n 37. Raia \n 38. Saligao \n 39. Sancoale \n 40. Sanguem \n 41. Sanquelim \n 42. Sanvordem \n 43. Serula Solim \n 44. Taleigao \n 45. Vagator \n 46. Valpoy \n 47. Varca Vasco da Gama\n"); 
  }



user* AddUser(user* h)
{
    user *t;
    t=h;
    user *nw;
    nw=(user*)malloc(sizeof(user));
    fflush(stdin);
    printf("Enter username or email\n");
    scanf("%s",nw->username);
    while(h!=NULL)
    {
        if(!strcmp(h->username,nw->username))
        {
            printf("That email already exists\n");
            return t;
        }
        h=h->next;
    }
    h=t;
    fflush(stdin);
    printf("Enter password\n");
    scanf(" %[^\n]s",&nw->password);
    nw->next=NULL;
    strcpy(nw->place,"N/A");
    nw->price=0.0;
    nw->numtick=0;

    if(h==NULL)
    {
        h=t=nw;
    }
    else
    {
        while(h->next!=NULL)
        {
            h=h->next;
        }
        h->next=nw;
    }
    WriteToFile(t);
    return t;
}

void LoginUser(user* h)
{
    char username[100];
    char password[100];
    fflush(stdin);
    printf("\n\n");
    printf("\t\tEnter Email/Username:\n\t\t");
    scanf("%s",username);
    fflush(stdin);
    printf("\n\t\tEnter Password:\n\t\t");
    scanf(" %[^\n]s",password);
    while(h!=NULL)
    {
        if((!strcmp(h->username,username)) && (!strcmp(h->password,password)))
        {
            currentstate=loggedin;
            strcpy(currentuser,username);
            
            printf("\n\t\tLogin successful!\n");
            system("PAUSE");
            return;
        }
        else if((!strcmp(h->username,username)) && (strcmp(h->password,password)))
        {
            printf("Password mismatch\n");
            return;
        }
        h=h->next;
    }
    printf("Sorry, no such user record was found\n");
}


    





void ExitProgram()
{
    printf("Exiting...\nDeveloped By Abhijeet,Akshay,Alok and Ashmit,");
    char exitprog;
    fflush(stdin);
    scanf("%c",&exitprog);
}

