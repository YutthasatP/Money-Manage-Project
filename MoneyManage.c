#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <math.h>

int checkid(char ID[]);
void waterbills();
void Electricitybills();
void userregister();
void Savings();
void buyphone();
void waterAelectri();
void SavingsGoal();
char* encode(char* str)
{
    int i = 0;
    while (str[i] != '\0')
    {
        str[i] = str[i]-15;
        i++;
    }
    return (str);
}
char* decode(char* str)
{
    int i = 0;
    while (str[i] != '\0')
    {
        str[i] = str[i]+15;
        i++;
    }
    return (str);
}

struct
{
    char name[100],id[100],surname[100],gender[7],pass[100];
    int salary;
} User;

main()
{
    FILE *fp;
    time_t rawtime;
    struct tm *local;
    char ID[100],pass[100];
    int c,n,i;
    do
    {
        system ("cls");
        c=0;
        printf ("=============================\n");
        printf ("\t-- LOGIN -- \n");
        printf (" ****Enter 0 to register****\n");
        printf ("\tID: ");
        fflush(stdin);
        scanf  ("%s",ID);
        if(strcmp(ID,"0")==0)
            userregister();
        else
            c=checkid(ID);
    }while(c == 0);
    printf ("---Login successfully---");
    Sleep(1000);

    do
    {
        system ("cls");
        time(&rawtime);
        local = localtime(&rawtime);
        if (local->tm_hour >= 0 && local->tm_hour <12)
            {
                printf ("\t---Good Morning---\n");
                if (strcmp(User.gender,"male") == 0)
                    printf ("     Mr.%-10s %s",User.name,User.surname);
                else if (strcmp(User.gender,"female")==0)
                    printf ("     Ms.%-10s %s",User.name,User.surname);
                else
                    printf ("     %-10s %s",User.name,User.surname);
            }
        else if (local->tm_hour >= 12 && local->tm_hour <18)
            {
                printf ("\t---Good Afternoon---\n");
                if (strcmp(User.gender,"male")==0)
                    printf ("     Mr.%-10s %s",User.name,User.surname);
                else if (strcmp(User.gender,"female")==0)
                    printf ("     Ms.%-10s %s",User.name,User.surname);
                else
                    printf ("     %-10s %s",User.name,User.surname);
            }
        else if (local->tm_hour >= 18 && local->tm_hour <24)
            {
                printf ("\t---Good Evening---\n");
                if (strcmp(User.gender,"male")==0)
                    printf ("     Mr.%-10s %s",User.name,User.surname);
                else if (strcmp(User.gender,"female")==0)
                    printf ("     Ms.%-10s %s",User.name,User.surname);
                else
                    printf ("     %-10s %s",User.name,User.surname);
            }
        printf("\nMENU\n");
        printf("========================================================\n");
        printf ("1. Saving money per month\n");
        printf ("2. Smartphones With Bundled Package Calculator\n");
        printf ("3. Water and electricity bills\n");
        printf ("4. Savings Goal Calculator\n");
        printf ("5. Logout\n");
        printf ("0. Quit\n");
        printf("========================================================\n");
        scanf ("%d",&n);
         switch(n)
         {
         case 1:
             Savings();
             break;
         case 2:
             buyphone();
             break;
         case 3:
             waterAelectri();
             break;
         case 4:
             SavingsGoal();
             break;
         case 5:
             main();
             break;
         }
    }while(n!=0);

}
void userregister()
{

    FILE *fp,*fp2;
    int c,salary,i,ascii;
    char id[100],name[100],surname[100],gender[100],cpass[100];
    char confirmpass[100],*str;
    fp = fopen("user.txt","a");
    do
    {
        system("cls");
        printf ("=============================\n");
        c=0;
        printf ("---Register---\n\n");
        printf ("ID : ");
        scanf ("%s",User.id);
        str = User.id;
        strcpy(User.id,encode(str));
        printf ("Name : ");
        scanf ("%s",User.name);
        str = User.name;
        strcpy(User.name,encode(str));
        printf ("Surname : ");
        scanf ("%s",User.surname);
        str = User.surname;
        strcpy(User.surname,encode(str));
        printf ("Gender [male,female] : ");
        scanf ("%s",User.gender);
        str = User.gender;
        strcpy(User.gender,encode(str));
        printf ("Password : ");
        scanf ("%s",User.pass);
        printf ("Confirm Password : ");
        scanf ("%s",confirmpass);
        str = confirmpass;
        strcpy(confirmpass,encode(str));
        printf ("Salary : ");
        scanf ("%d",&User.salary);
        for (i=0;i<strlen(User.pass);i++)
        {
            ascii = User.pass[i];
            if (ascii > 32 && ascii <48)
            {
                printf ("** Password must not contain special characters. **");
                Sleep (2000);
                c=1;
                break;
            }
        }
        if(c != 1)
        {
            str = User.pass;
            strcpy(User.pass,encode(str));
            fp2 = fopen("user.txt","r");
            while (!feof(fp2))
            {
                fscanf (fp2,"%s %s %s %s %s %d",id,name,surname,gender,cpass,&salary);
                if (strcmp(User.id,id) == 0)
                {
                    printf ("** That username is taken. Try another");
                    Sleep (2000);
                    c = 1;
                    break;
                }
            }
        fclose(fp2);
        }
        if (strcmp(confirmpass,User.pass) != 0 && c!=1)
        {
            printf ("** Password not correct **");
            Sleep (2000);
            c=1;
        }
        else if(c!=1)
        {
            fprintf (fp,"%s %s %s %s %s %d\n",User.id,User.name,User.surname,User.gender,User.pass,User.salary);
        }
    }
    while(c==1);
    printf ("-- Successfully registered --\n");
    printf ("=============================\n");
    Sleep (2000);
    fclose(fp);
}
int checkid(char ID[])
{
    FILE *fp;
    int c,i;
    char pass[100],*str;
    if((fp = fopen("user.txt","r")) == NULL)
    {
        printf ("***Please register first.***\n");
        printf ("=============================\n");
        Sleep (2500);
        return c;
    }
    while (!feof(fp))
    {
        fscanf (fp,"%s %s %s %s %s %d",User.id,User.name,User.surname,User.gender,User.pass,&User.salary);
        str = User.id;
        strcpy (User.id,decode(str));
        if (strcmp(User.id,ID) == 0)
            break;
    }
    fclose(fp);
    str = User.pass;
    strcpy (User.pass,decode(str));
    printf ("\tPassword: ");
    for(i=0;i<strlen(User.pass);i++)
    {
        fflush(stdin);
        pass[i]=getch();
        printf("*");
    }
    if (strcmp(User.id,ID) == 0 && strcmp(pass,User.pass) == 0)
    {
        printf ("\n=============================\n");
        str = User.name;
        strcpy (User.name,decode(str));
        str = User.surname;
        strcpy (User.surname,decode(str));
        str = User.gender;
        strcpy (User.gender,decode(str));
        c=1;
    }
    else
    {
        printf ("\n***ID or Password not correct***\n");
        printf ("=============================\n");
        Sleep (2500);
    }
    return c;
}
void Savings()
{
    system ("cls");
    float food,rent,food_pm,remain,save,moneypd;
    printf ("\n\t---Welcome to savings calculator---\n");
    printf("========================================================\n");
    printf ("Food cost per meal = ");
    scanf  ("%f",&food);
    printf ("Cost per month (Ex.House,Car,etc) = ");
    scanf  ("%f",&rent);
    food_pm = food*90;
    remain = User.salary-rent-food_pm;
    if(remain > 0)
    {
        save = remain*0.75;
        moneypd = ((remain-save)+food_pm)/30;
        printf ("You should collect %.2f baht per salary\n",save);
        printf ("The money you should spend per day is %.2f baht.\n",moneypd);
    }
    else if (remain <=0)
    {
        printf ("You cant save the money\n");
    }
    printf("========================================================\n");
    getch();
}
void buyphone()
{
    system ("cls");
    int n,i,x,min;
    float sprice,advpay,package,totalprice[100],advpayvat,depackage,discount,packagevat,t;
    printf ("\n\t---Welcome to smartphones bundled package calculator---\n");
    printf("=======================================================================\n");
    printf ("How many Bundle Package : ");
    scanf ("%d",&n);
    for (i = 0 ; i<n ; i++)
    {
        printf ("--------------------------------\n");
        printf ("%d. Special Price = ",i+1);
        scanf ("%f",&sprice);
        printf ("   Advance Payment = ");
        scanf ("%f",&advpay);
        printf ("   Package = ");
        scanf ("%f",&package);
        advpayvat = (advpay*1.07)-advpay;
        if (advpay <= 1000)
        {
            discount = advpay/10;
            depackage = (package-discount)*1.07;
            depackage = depackage*10;
            packagevat = package*1.07;
            packagevat = packagevat*2;
            totalprice[i] = sprice+advpayvat+depackage+packagevat;
            printf ("Total is %.2f baht\n",totalprice[i]);
        }
        else if (advpay > 1000)
        {
            discount = advpay/12;
            depackage = (package-discount)*1.07;
            depackage = depackage*12;
            totalprice[i] = sprice+advpayvat+depackage;
            printf ("Total is %.2f baht\n",totalprice[i]);
        }
    }
    for (i=0;i<n;i++)
    {
        if (i==0)
        {
            min = totalprice[i];
            x = i+1;
        }
        else if (min > totalprice[i])
        {
            min = totalprice[i];
            x = i+1;
        }
    }
    printf ("\n ---Bundle %d has the lowest total price.---\n",x);
    printf("========================================================\n");
    getch();
}
void waterAelectri()
{
    int type;
    do
    {
    system ("cls");
    printf ("\n\t---Welcome to water and electricity bills calculator---\n");
    printf("===================================================================\n");
    printf ("1. Water bills.\n");
    printf ("2. Electricity bills.\n");
    printf ("0. Quit\n");
    printf("===================================================================\n");
    scanf ("%d",&type);
    switch (type)
        {
        case 1: waterbills(); break;
        case 2: Electricitybills(); break;
        }
    }while (type !=0);
    getch();
}
void waterbills()
{
    system ("cls");
    float unit,total;
    printf ("\n\t---Welcome to water bills calculator---\n");
    printf("===================================================================\n");
    printf ("    Enter water unit : ");
    scanf("%f",&unit);
    if(unit <=10)
        total = unit*10.2;
    else if (unit <=20)
        total = ((unit-10)*16)+102;
    else if (unit <=30)
        total = ((unit-20)*19)+262;
    else if (unit <=50)
        total = ((unit-30)*21.2)+452;
    printf ("    Water price %.2f baht\n",total);
    printf("===================================================================\n");
    getch();
}
void Electricitybills()
{
    system ("cls");
    int type;
    float unit,totalunit,total,Ft,totalvat,totalprice;
    printf ("\n\t---Welcome to electricity bills calculator---\n");
    printf("=========================================================================================\n");
    printf ("1. Consumes no more than 150 units of electrical energy for a period of 3 months. \n");
    printf ("2. Consume more than 150 units of electrical energy for a period of 3 months.\n");
    printf("=========================================================================================\n");
    scanf("%d",&type);
    if (type == 2)
    {
        system ("cls");
        printf ("\n\t---Welcome to electricity bills calculator---\n");
        printf("============================================================\n");
        printf ("    Enter electricity unit : ");
        scanf ("%f",&unit);
        if (unit <= 15)
            total = unit*2.3488;
        else if (unit <=25)
        {
            totalunit = unit-15;
            total = totalunit*2.9882;
            total = total+35.232;
        }
        else if (unit <=35)
        {
            totalunit = unit-25;
            total = totalunit*3.2405;
            total = total+65.114;
        }
        else if (unit <= 100)
        {
            totalunit = unit-35;
            total = totalunit*3.6237;
            total = total+97.519;
        }
        else if (unit <= 150)
        {
            totalunit = unit-100;
            total = totalunit*3.7171;
            total = total+333.0595;
        }
        else if (unit <= 400)
        {
            totalunit = unit-150;
            total = totalunit*4.2218;
            total = total+518.9145;
        }
        else
        {
            totalunit = unit-400;
            total = totalunit*4.42218;
            total = total+1574.3645;
        }
        total = total+38.22;
        Ft = unit*-0.116;
        totalvat = (total+Ft)*0.07;
        totalprice = total+Ft+totalvat;
        printf ("    Electricity cost %.2f baht\n",totalprice);
        printf("============================================================\n");
    }
    else if (type == 1)
    {
        system ("cls");
        printf ("\n\t---Welcome to electricity bills calculator---\n");
        printf("========================================\n");
        printf ("    Enter electricity unit : ");
        scanf ("%f",&unit);
        if (unit <=150)
            total = unit*3.2484;
        else if (unit <=400)
        {
            totalunit = unit-150;
            total = totalunit*4.2218;
            total = total+487.26;
        }
        else
        {
            totalunit = unit-400;
            total = totalunit*4.4217;
            total = total +1542.71;
        }
        total = total+8.19;
        Ft = unit*-0.116;
        totalvat = (total+Ft)*0.07;
        totalprice = total+Ft+totalvat;
        printf ("    Electricity cost %.2f baht\n",totalprice);
        printf("========================================\n");
    }
    getch();
}
void SavingsGoal()
{
    int time;
    float goal,start,interest,save;
    system ("cls");
    printf ("\n\t---Welcome to savings goal calculator---\n");
    printf ("=========================================================================================\n");
    printf ("Savings goal : ");
    scanf ("%f",&goal);
    printf ("Starting balance : ");
    scanf ("%f",&start);
    printf ("Time to grow (Months) : ");
    scanf ("%d",&time);
    printf ("Annual interest rate (%%) : ");
    scanf ("%f",&interest);
    save = (goal-start)/time;
    save = (save*100)/(100+interest);
    printf ("Suggested monthly contribution  = %.2f bath\n",save);
    printf ("=========================================================================================\n");
    getch();
}
