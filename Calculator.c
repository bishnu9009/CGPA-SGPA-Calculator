//  this is the new and improved version of the sgpa calculator with usage of functions.
//  This version has the functionality to calculate CGPA as well.
//  Made by Bishnutosh Panda


#include<stdio.h>
#include<stdlib.h>

//A structure which stores the details of a particular subject.
typedef struct subject{
    int endsem;     //stores endsem marks.
    int midsem;     //stores mid sem marks.
    int internal;   //stores the internal marks.
    int credit;     //stores the credit that subject carries.
    float subtotal; //store the subtotal marks (endsem + midsem + internal).
}subject;

subject s[20];       // Globally declared array of structures.
int grade_point[20]; // Array to store the grade points of each subject.

int total_credit_counter(){ // Function which counts the total credit of all the subjects.
    int total=0,i;
    for(i=0;i<20;i++){
        total+=s[i].credit;
    }
    return total;
}

int totaler(int theo){       // Function which totals out the theory marks.
    int i;
    for(i=0;i<theo;i++)
    {
        s[i].subtotal=s[i].endsem+s[i].midsem+s[i].internal;
    }
}


int point_determiner(int t,int p){      //Function which determines the grade point of each subject.
    int i;
    for(i=0;i<(t+p);i++)
    {
        if(s[i].subtotal>=90)
        {
            grade_point[i]=10;
        }
        else if(s[i].subtotal>=80)
        {
            grade_point[i]=9;
        }
        else if(s[i].subtotal>=70)
        {
            grade_point[i]=8;
        }
        else if(s[i].subtotal>=60)
        {
            grade_point[i]=7;
        }
        else if(s[i].subtotal>=50)
        {
            grade_point[i]=6;
        }
        else if(s[i].subtotal>=40)
        {
            grade_point[i]=5;
        }
        else if(s[i].subtotal<40)
        {
            grade_point[i]=0;
            printf("Failed\n");
            //exit(0);
        }
    }
}

int gp_calculator(int num){       //Function which calculates the total grade point of all the subjects.
    int i,total=0;
    for(i=0;i<num;i++)
    {
        total+=grade_point[i]*s[i].credit;
    }
    return total;
}   

void main()
{
    int num_theo,num_prac,tot_creds,total_gp,num_mand,exit=1,xgpa;
    float sgpa;

    printf("\nWELCOME TO THE GPA CALCULATOR\n-By Bishnu\n\n");
    while(exit==1)
    {
        printf("-------CALCULATE-------\nEnter\n1--> CGPA\n2--> SGPA\n3--> Exit\n");
        scanf("%d",&xgpa);

        switch(xgpa){
            case 1:
            {
                int a,cred[20],credits_for_cgpa=0,resp;
                float gpa[20],cgpa=0;
                printf("Enter you semester:-");
                scanf("%d",&a);
                for(int i=0;i<a;i++)
                {
                    printf("Enter your SGPA in Semester %d:-",i+1);
                    scanf("%f",&gpa[i]);
                    printf("Enter the total credits of Semester %d:-",i+1);
                    scanf("%d",&cred[i]);
                }
                for(int i=0;i<a;i++)
                {
                    cgpa+=(gpa[i]*cred[i]);
                }
                for(int i=0;i<a;i++)
                {
                    credits_for_cgpa+=cred[i];
                }
                printf("\n\nYour CGPA is %f\n",(cgpa/credits_for_cgpa));
                printf("\nWould you like to continue press 1 for YES and 0 for NO ?\n");
                scanf("%d",&resp);
                if(resp==1)
                {
                    exit=1;
                    break;
                }
                else if(resp==0)
                {
                    exit=0;
                }
            }
            case 2:
            {
                printf("Enter the number of Mandatory Subjects:-");
                scanf("%d",&num_mand);
                
                printf("Enter the number of Theory Subjects:-");
                scanf("%d",&num_theo);

                printf("Enter the number of Practical Subjects:-");
                scanf("%d",&num_prac);

                for(int i=num_theo+num_prac;i<num_mand+num_prac+num_theo;i++)
                {
                    printf("\n\nEnter the endsem marks of Mandatory Subject:-");
                    scanf("%d",&s[i].endsem);
                    if(s[i].endsem<30){
                        printf("\n****Failed Mandatory Subject! :(  ****\n");
                        break;
                    }
                    printf("Enter the midsem marks of Mandatory Subject:-");
                    scanf("%d",&s[i].midsem);
                    printf("Enter the internal marks of Mandatory Subject:-");
                    scanf("%d",&s[i].internal);
                    s[i].subtotal=s[i].endsem+s[i].midsem+s[i].internal;
                    if(s[i].subtotal<50){
                        printf("\n****Failed Mandatory Subject! :(  ****\n");
                        break;
                    }
                    else{
                        continue;
                    }
                }

                // Loop which stores the marks in each theory subject.

                printf("\nEnter the marks in each theory subject:-\n");
                for(int i=0;i<num_theo;i++)
                {
                    printf("**************************\nEnter for subject %d \nEndsem marks:-\nMidsem marks:-\nInternal marks:-\nCredit of Subject:-\n**************************\n",i+1);
                    scanf("%d%d%d%d",&s[i].endsem,&s[i].midsem,&s[i].internal,&s[i].credit);
                    if(s[i].endsem<24){
                        printf("\n****Failed Theory Subject! :(  ****\n");
                        break;
                    }
                }

                // Loop which stores the marks in each practical subject.

                printf("\nEnter the marks in each practical subject:-\n");
                for(int i=num_theo;i<num_theo+num_prac;i++)
                {
                    int j=1;
                    printf("**************************\nEnter for practical subject %d \nTotal marks out of 100:-\nCredit of Subject:-\n**************************\n",j);
                    scanf("%f%d",&s[i].subtotal,&s[i].credit);
                    j++;
                }


                tot_creds=total_credit_counter();
                
                totaler(num_theo);
                
                point_determiner(num_theo,num_prac);
                
                printf("\n");
                
                for(int i=0;i<num_prac+num_theo;i++)
                {
                    printf("Your GP in subject %d :- ",i+1);
                    printf("%d",grade_point[i]);
                    printf("\n");
                }

                printf("\nYour total semester credits are:- %d",tot_creds);

                total_gp=gp_calculator(num_theo+num_prac);

                printf("\nYour total grade points are:- %d",total_gp);

                sgpa=total_gp/(float)tot_creds;

                printf("\nYour SGPA is:- %.2f\n\n",sgpa);
                exit=0;
                            printf("----Thank You!----\n");
            }
            case 3:
            {
                printf("\nThank you for using the CGPA calculator\n");
                exit=0;
                break;
            }
            printf("----Thank You!----\n");
        }
    }
}
