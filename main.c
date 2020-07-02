#include <stdio.h>
#include <stdlib.h>

#include <string.h>

int saved=0,counter=0,ftopen=0,stop=1;

typedef struct
{


    int bday,bmonth,byear;


} b_date;
typedef struct
{
    char first_name[50],last_name[50],email[50],address[50],number[11];
    b_date bdate;

} contact;
contact THE_OBJECTS[100];

void add_contact()
{




    char fname[50],lname[50],address[200],email[100],temp,number[11];
    int bday=-1,bmonth=-1,byear=-1,email_len,i,j;



    printf("enter first name\n");
    scanf("%s",fname);
    fflush(stdin);
    printf("enter last name\n");
    scanf("%s",lname);

    scanf("%c",&temp);
    printf("enter address\n");
    scanf("%[^\n]",address);
    fflush(stdin);

    while(1)
    {
        printf("enter number\n");
        scanf("%s",number);
        if(strlen(number)<12&&strlen(number)>7)
            break;
        else
            printf("enter valid number\n");
    }
    fflush(stdin);
    while (1)
    {
        printf("enter birth day\n");
        scanf("%d",&bday);
        if(bday>31||bday<1)
            printf("enter proper birth day\n");
        else
            break;
    }
    fflush(stdin);
    while(1)
    {
        printf("enter birth month\n");
        scanf("%d",&bmonth);
        if(bmonth>12||bmonth<1)
            printf("enter proper birth month\n");
        else
            break;
    }
    fflush(stdin);
    while(1)
    {
        printf("enter birth year\n");
        scanf("%d",&byear);
        if(byear>2014||byear<=1900)
            printf("enter proper birth year\n");
        else
            break;
    }
    fflush(stdin);
    int test=0;
    while(!test)
    {

        printf("enter email\n");
        scanf("%s",email);
        email_len=strlen(email);
        for(i=0; i<email_len; i++)
        {

            if(email[i]=='@')
            {
                for(j=i; j<email_len; j++)
                {
                    if(email[j]=='.')
                        test=1;
                }

            }

        }

        if(!test)
            printf("enter valid email\n");
    }
    fflush(stdin);

    strcpy(THE_OBJECTS[counter].first_name,fname);
    strcpy(THE_OBJECTS[counter].last_name,lname);
    strcpy(THE_OBJECTS[counter].number,number);
    strcpy(THE_OBJECTS[counter].address,address);
    strcpy(THE_OBJECTS[counter].email,email);
    THE_OBJECTS[counter].bdate.bday=bday;
    THE_OBJECTS[counter].bdate.bmonth=bmonth;
    THE_OBJECTS[counter].bdate.byear=byear;


}
void load()
{

    FILE *pf;
    pf=fopen("contacts.txt","r");
    int da_y,mont_h,yea_r,testnum;

    char day[10],month[10],year[10];
    //printf("\n %d \n",feof(pf));

    while(!feof(pf))
    {   //printf("%d",counter);
      //   printf("\n %d \n",feof(pf));

        fscanf(pf,"%[^,],",THE_OBJECTS[counter].first_name);
       // printf("\n %s \n",THE_OBJECTS[counter].first_name);
        fscanf(pf,"%[^,],",THE_OBJECTS[counter].last_name);
       // printf("\n %s \n",THE_OBJECTS[counter].last_name);
        fscanf(pf,"%[^,],",THE_OBJECTS[counter].number);
        //if(THE_OBJECTS[counter].number==NULL) continue;
      //  printf("\n %s \n",THE_OBJECTS[counter].number);
        fscanf(pf,"%[^,],",day);
        fscanf(pf,"%[^,],",month);
        fscanf(pf,"%[^,],",year);
        da_y=atoi(&day);
        mont_h=atoi(&month);
        yea_r=atoi(&year);
        THE_OBJECTS[counter].bdate.bday=da_y;
        THE_OBJECTS[counter].bdate.bmonth=mont_h;
        THE_OBJECTS[counter].bdate.byear=yea_r;
      //  printf("\n%d %d %d\n ",THE_OBJECTS[counter].bdate.bday,THE_OBJECTS[counter].bdate.bmonth,THE_OBJECTS[counter].bdate.byear);
        fscanf(pf,"%[^,],",THE_OBJECTS[counter].address);
       // printf("\n %s \n",THE_OBJECTS[counter].address);

         fscanf(pf,"%[^\n]\n",THE_OBJECTS[counter].email);
       // printf("\n %s \n",THE_OBJECTS[counter].email);
        //printf("\n%d\n",ftell(pf));
       // fflush(pf);


       testnum=atoi(&THE_OBJECTS[counter].number);

        counter=counter+1;
        if(testnum==0){ counter=counter-1;}

    }

    //if (THE_OBJECTS[counter].first_name&&THE_OBJECTS[counter].last_name&&THE_OBJECTS[counter].number==NULL)

    fclose(pf);
}



void save()
{
    saved=0;
    int i;
    FILE *f;
    f=fopen("contacts.txt","w");
    for(i=0; i<counter; i++)
    {
        fprintf(f,"%s,%s,%s,%d,%d,%d,%s,%s\n",THE_OBJECTS[i].first_name,THE_OBJECTS[i].last_name,THE_OBJECTS[i].number,THE_OBJECTS[i].bdate.bday,THE_OBJECTS[i].bdate.bmonth,THE_OBJECTS[i].bdate.byear,THE_OBJECTS[i].address,THE_OBJECTS[i].email);

    }
    fclose(f);

}

void sortlastname()
{
    int pass,j,compare;
    contact temp;

    for(pass=1; pass<counter; pass++)
    {
        for(j=0; j<counter-pass; j++)
        {
            compare=strcasecmp(THE_OBJECTS[j].last_name,THE_OBJECTS[j+1].last_name);
            if(compare>0)
            {
                temp=THE_OBJECTS[j];
                THE_OBJECTS[j]=THE_OBJECTS[j+1];
                THE_OBJECTS[j+1]=temp;
               }
               else if(compare==0){

if(strcasecmp(THE_OBJECTS[j].first_name,THE_OBJECTS[j+1].first_name)>0){

                temp=THE_OBJECTS[j];
                THE_OBJECTS[j]=THE_OBJECTS[j+1];
                THE_OBJECTS[j+1]=temp;

}
else if(strcasecmp(THE_OBJECTS[j].first_name,THE_OBJECTS[j+1].first_name)==0){

    if(strcasecmp(THE_OBJECTS[j].number,THE_OBJECTS[j+1].number)>0){

                temp=THE_OBJECTS[j];
                THE_OBJECTS[j]=THE_OBJECTS[j+1];
                THE_OBJECTS[j+1]=temp;
    }
}
               }
        }

    }
}




void sortdate()
{
    int pass,j;
    contact temp;
    long long x,y;

    for(pass=1; pass<counter; pass++)
    {


        for(j=0; j<counter-pass; j++)
        {
            x=((THE_OBJECTS[j].bdate.byear)*365)+((THE_OBJECTS[j].bdate.bmonth)*30)+THE_OBJECTS[j].bdate.bday;
            y=((THE_OBJECTS[j+1].bdate.byear)*365)+((THE_OBJECTS[j+1].bdate.bmonth)*30)+THE_OBJECTS[j+1].bdate.bday;

            if(x>y)
            {
                temp=THE_OBJECTS[j];
                THE_OBJECTS[j]=THE_OBJECTS[j+1];
                THE_OBJECTS[j+1]=temp;
            }
        }
    }
}

void printcontacts(){
   int i;
   for(i=0;i<counter;i++){
        printf("contact #%d \n",i+1);
    printf("Last Name: %s\n",THE_OBJECTS[i].last_name);
    printf("First Name: %s\n",THE_OBJECTS[i].first_name);
    printf("Address: %s\n",THE_OBJECTS[i].address);
    printf("E-mail: %s\n",THE_OBJECTS[i].email);
    printf("Number : %s\n",THE_OBJECTS[i].number);
    printf("Date :  %d-%d-%d\n",THE_OBJECTS[i].bdate.bday,THE_OBJECTS[i].bdate.bmonth,THE_OBJECTS[i].bdate.byear);
   }
}

void search_1()
{
    char l_name[50];
    int i;
    int count=0;
    printf("Enter last name :");
    scanf("%s",l_name);
    int found=0;
    for(i=0;i<=counter;i++)
    {
        if(!strcasecmp(l_name,THE_OBJECTS[i].last_name))
        {    count++;
             found=1;
               printf("#%d contact \n",count);
            printf("Last name:%s  First name:%s  Date of birth:%d.%d.%d  Address:%s  Email:%s  Number:%s\n",THE_OBJECTS[i].last_name,THE_OBJECTS[i].first_name,THE_OBJECTS[i].bdate.bday,THE_OBJECTS[i].bdate.bmonth,THE_OBJECTS[i].bdate.byear,THE_OBJECTS[i].address,THE_OBJECTS[i].email,THE_OBJECTS[i].number);
            found=1;
        }





    }
    if(found==0){
        printf("corresponding data not found\n");
    }
}


int search_delete()
{
    contact con;
    int j;
int flag=0;
    printf("Last name:\n");
    scanf("%s",con.last_name);
    printf("First name:\n");
    scanf("%s",con.first_name);
    for(j=0;j<=counter;j++)
    {
        if(!strcasecmp(con.last_name,THE_OBJECTS[j].last_name))
        {
            if(!strcasecmp(con.first_name,THE_OBJECTS[j].first_name))
{	flag=1;
                break;
}
        }

    }
if(flag)
printf("Contact successfully deleted");
else{
printf("Contact not found"); return -1;}
    return j;
}

void delete_contact()
{
    int k=search_delete();
    if(k==-1) return 0;
    int i;
    for(i=k;i<=counter-2;i++)
    {
        THE_OBJECTS[i]=THE_OBJECTS[i+1];
    }
    counter--;

}

void modify()
{
int user_inp,index;
    char l_name[50];
int i,indexes[20],found=0;
printf("Enter Last Name:\n");
scanf("%s",l_name);

for(i=0;i<20;i++){indexes[i]=NULL;}
for(i=0;i<counter;i++){
if(strcasecmp(l_name,THE_OBJECTS[i].last_name)==0)
{
    indexes[found]=i;
    found++;

}}
if(found==0){
    printf("No such contact\n");
    return 0;
}
for(i=0;i<found;i++){
     printf("#%d \n",i+1);

    printf("Last Name:%s  First Name:%s  Date of Birth:%d.%d.%d  Address:%s  Email:%s  Number:%s\n",THE_OBJECTS[indexes[i]].last_name,THE_OBJECTS[indexes[i]].first_name,THE_OBJECTS[indexes[i]].bdate.bday,THE_OBJECTS[indexes[i]].bdate.bmonth,THE_OBJECTS[indexes[i]].bdate.byear,THE_OBJECTS[indexes[i]].address,THE_OBJECTS[indexes[i]].email,THE_OBJECTS[indexes[i]].number);




}
while(1){
printf("Choose which contact:\n");
scanf("%d",&user_inp);
if(user_inp<=found&&user_inp!=0)
    break;
else printf("Enter a valid key\n");
}

index=indexes[user_inp-1];


 char fname[50],lname[50],address[200],email[100],temp,number[11];
    int bday=-1,bmonth=-1,byear=-1,test=1,email_len,j;
    int user;
    while(1){
        printf("Enter \n1.Modify Fname\n2.Modify Lname\n3.Modify address\n4.Modify number\n5.Modify email\n6.Modify birth date\n7.Modify all\n");
        scanf("%d",&user);
        if(user>0&&user<8) break;



    }
    switch(user){
case 1:
    printf("Enter Fname:\n");
    scanf("%s",fname);


        strcpy(THE_OBJECTS[index].first_name,fname);
    break;
case 2:
    printf("Enter Lname:\n");
    scanf("%s",lname);
    strcpy(THE_OBJECTS[index].last_name,lname);
    break;
case 3:
     scanf("%c",&temp);

     printf("Enter Address:\n");
    scanf("%[^\n]",address);
    strcpy(THE_OBJECTS[index].address,address);

    break;
case 4:
    while(1){
    printf("Enter Number\n");
    scanf("%s",number);
      if(strlen(number)==11||strlen(number)==9)
            break;
        else
            printf("enter valid number\n");
    }
        strcpy(THE_OBJECTS[index].number,number);


    break;
case 5:
    test=0;
        while(!test)
    {

        printf("Enter email\n");
        scanf("%s",email);
        email_len=strlen(email);
        for(i=0; i<email_len; i++)
        {

            if(email[i]=='@')
            {
                for(j=i; j<email_len; j++)
                {
                    if(email[j]=='.')
                        test=1;
                }

            }

        }

        if(!test)
            printf("Enter valid email\n");
    }
    strcpy(THE_OBJECTS[index].email,email);

    break;
case 6:
    test=1;
        while (test)
    {
        printf("Enter birth day\n");
        scanf("%d",&bday);
        if(bday>31||bday<1)
            printf("Enter proper birth day\n");
        else
            test=0;
    }
    fflush(stdin);
    while(!test)
    {
        printf("Enter birth month\n");
        scanf("%d",&bmonth);
        if(bmonth>12||bmonth<1)
            printf("Enter proper birth month\n");
        else
            test=1;
    }
    fflush(stdin);
    while(test)
    {
        printf("Enter birth year\n");
        scanf("%d",&byear);
        if(byear>2014||byear<=1900)
            printf("Enter proper birth year\n");
        else
            test=0;
    }

    THE_OBJECTS[index].bdate.bday=bday;
    THE_OBJECTS[index].bdate.bmonth=bmonth;
    THE_OBJECTS[index].bdate.byear=byear;
    break;
    case 7:
        printf("Enter first name\n");
    scanf("%s",fname);
    fflush(stdin);
    printf("Enter last name\n");
    scanf("%s",lname);

    scanf("%c",&temp);
    printf("Enter address\n");
    scanf("%[^\n]",address);
    fflush(stdin);

    while(1)
    {
        printf("Enter number\n");
        scanf("%s",number);
        if(strlen(number)<12&&strlen(number)>7)
            break;
        else
            printf("Enter valid number\n");
    }
    fflush(stdin);
    while (test)
    {
        printf("Enter birth day\n");
        scanf("%d",&bday);
        if(bday>31||bday<1)
            printf("Enter proper birth day\n");
        else
            test=0;
    }
    fflush(stdin);
    while(!test)
    {
        printf("Enter birth month\n");
        scanf("%d",&bmonth);
        if(bmonth>12||bmonth<1)
            printf("Enter proper birth month\n");
        else
            test=1;
    }
    fflush(stdin);
    while(test)
    {
        printf("Enter birth year\n");
        scanf("%d",&byear);
        if(byear>2014||byear<=1900)
            printf("Enter proper birth year\n");
        else
            test=0;
    }
    fflush(stdin);

    while(!test)
    {

        printf("Enter email\n");
        scanf("%s",email);
        email_len=strlen(email);
        for(i=0; i<email_len; i++)
        {

            if(email[i]=='@')
            {
                for(j=i; j<email_len; j++)
                {
                    if(email[j]=='.')
                        test=1;
                }

            }

        }

        if(!test)
            printf("Enter valid email\n");
    }
    fflush(stdin);

    strcpy(THE_OBJECTS[index].first_name,fname);
    strcpy(THE_OBJECTS[index].last_name,lname);
    strcpy(THE_OBJECTS[index].number,number);
    strcpy(THE_OBJECTS[index].address,address);
    strcpy(THE_OBJECTS[index].email,email);
    THE_OBJECTS[index].bdate.bday=bday;
    THE_OBJECTS[index].bdate.bmonth=bmonth;
    THE_OBJECTS[index].bdate.byear=byear;

break;

    }









}



int main()
{

    int USER,USER_1,USER_2;
   load();

    while(1)
    {   printf("\n\t\t\t\t==========\n");
        printf("\t\t\t\tPhone Book\n");
        printf("\t\t\t\t==========\n");
        printf("\n\t\t\t\tEnter: \n\t\t1. For Search\t2. For Add\t3. For Delete\n\t\t4. Modify\t5. Print\t6. Save\n\t\t\t\t7. Quit\n");
        scanf("%d",&USER);
        switch (USER)
        {
        case 1:

            if (counter ==0){printf("nothing to do \n"); break;}
          search_1();

          break;
        case 2:

            add_contact();
            counter =counter+1;
            saved=1;
            ftopen=1;

            break;
        case 3:

            if (counter ==0){printf("nothing to do \n");  break;}
            delete_contact();
            saved=1;
            ftopen=1;

            break;
        case 4:

             if (counter ==0){printf("nothing to do \n");  break;}
            modify();
             saved=1;
            ftopen=1;

            break;
        case 5:

             if (counter ==0){printf("nothing to do \n");  break;}
            while(stop==1){
            printf("Enter\n1. to print contacts sorted by last name\n2. to print sorted by date of birth\n3. to print as ordered:\n");

            scanf("%d",&USER_2);
            switch(USER_2){
            case(1):
                sortlastname();
                printcontacts();

            saved=1;
            ftopen=1;
            stop=0;
             break;
            case(2):

                    sortdate();
                    printcontacts();
            stop=0;
            saved=1;
            ftopen=1;
            break;
            case(3):
                printcontacts();
            stop=0;
            break;

            default:
                printf("enter a value from the listed\n");
                continue;
            }
            }
            stop=1;

            break;
        case 7:

            if(saved==1)
            {    while(1){
                printf("if you exit without save things done will be discarded to save before exit press 1 and 0 to exit:\n");
                scanf("%d",&USER_1);
                if(USER_1==1||USER_1==0) break;
                else printf("Enter a valid key\n");
                         }
                if(USER_1!=1)

                    exit(1);
            }
            else


                exit(1);

        case 6:

            if(ftopen==0)
            {
                printf("nothing to be saved");

                break;
            }

            else
            {

                save();
                saved=0;
                ftopen=0;
                printf("Progress Saved\n");
                break;
            }

        default:

            printf("enter a value from the listed above\n");

            continue;

        }
    }
    return 0;

}





