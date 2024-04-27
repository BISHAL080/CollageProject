#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
void addstudent();
void studentrecord();
void searchstudent();
struct std{
    char first_name[20];
    char last_name[20];
    int roll_no;
    float gpa;
};
void main()
{
    int choice;
    while(choice!=4)
    {
        system("cls");
        printf("\t\t\tENTER ANY ACTION\n\n\n");
        printf("\t\t\t1. Add Student\n");
        printf("\t\t\t2. View Student Record\n");
        printf("\t\t\t3. Search Student \n");
        printf("\t\t\t4. Exit \n");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
            addstudent();
            break;

            case 2:
            studentrecord();
            break;

            case 3:
            searchstudent();
        }
    }
}
void addstudent()
{
    struct std info;
    FILE *f;
    char ans[3];
    do
    {
        system("cls");
        printf("\t\t\tEnter Student Info:\n");
        f=fopen("StudentInfo.txt", "a");
        printf("\n\t\t\tEnter First Name: ");
        scanf("%s", info.first_name);
        printf("\n\t\t\tEnter Last Name: ");
        scanf("%s", info.last_name);
        printf("\n\t\t\tEnter Roll NO: ");
        scanf("%d", &info.roll_no);
        printf("\n\t\t\tEnter GPA: ");
        scanf("%f", &info.gpa);
        printf("\n\n\t\t\tData stored successsfully!!!");
        fwrite(&info, sizeof(struct std), 1, f);
        //clrscr();
        printf("\n\t\t\tWant to store more data yes/no?:");
        fflush(stdin);
        gets(ans);
        fclose(f);
    }while(strcmp("no", ans)!=0);

}
void studentrecord()
{
    system("cls");
    struct std info;
    FILE *f;
    printf("\t\t\tSTUDENT RECORD\n\n");
    f=fopen("StudentInfo.txt", "r");
    while(fread(&info, sizeof(struct std), 1, f))
    {
        printf("\t\t\tName = %s %s\n", info.first_name, info.last_name);
        printf("\t\t\tRoll no = %d\n", info.roll_no);
        printf("\t\t\tGPA = %f\n\n", info.gpa);
    }
    fclose(f);
    printf("\t\t\tEnter any key to exit");
    getch();
}
void searchstudent()
{
    system("cls");
    FILE *f;
    struct std info;
    int rollno, found=0;
    printf("\t\t\tEnter Roll no: ");
    scanf("%d", &rollno);
    f=fopen("StudentInfo.txt", "r");
    while(fread(&info, sizeof(struct std), 1, f))
    {
        if(rollno==info.roll_no)
        {
            found=1;
            system("cls");
            printf("\t\t\tSearched Record\n\n\n");
            printf("\t\t\tName = %s %s\n", info.first_name, info.last_name);
            printf("\t\t\tRoll no = %d\n", info.roll_no);
            printf("\t\t\tGPA = %f\n\n", info.gpa);
            printf("\t\t\tEnter any key to exit");
            getch();
        }
    }
    if(found==0)
    {
        printf("\n\t\t\tRecord not found!!!\n");
        printf("\t\t\tEnter any key to exit");
        getch();
    }
    fclose(f);
}