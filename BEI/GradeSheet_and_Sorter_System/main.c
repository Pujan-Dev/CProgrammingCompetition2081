//Student Record System; stores student data; uses bubble sort to sort given student data; prints mark sheet based on given subject data

#include <stdio.h>
#include <string.h>

#define MAX 200 //max number of students

int n; //number of students

struct Student//str for student data
{
    char name[100];
    int roll_no;
    float percent;
};
typedef struct Student student; //defining new type 'student' that has the type of 'struct Student'
student s[MAX]; //array of type 'student' having size MAX

struct Subject//str for subject data
{
    char name[100];
    float marks;
    char grade;
};
typedef struct Subject subject; //defining new type 'subject' that has the type of 'struct Subject'

int getdata(); //function to get student data
int sort(); //function to sort student data
void orderprint(int n, student array[]); //function to print the arranged data of student
int marksheet(); //function to print mark sheet

int main(void)
{
    while (1)
    {
        int choice, r; //initial choice
        printf("\n\n\n\nSTUDENT RECORD SYSTEM\n\n");
        printf("Choose from following options:\n");
        printf("1. Record student data.\n");
        printf("2. Sort student record in an order.\n");
        printf("3. Print Grade Sheet of a student.\n");
        printf("4. End program.\n\n");
        scanf("%i", &choice);

        if (!(choice >= 1 && choice <= 4)) //invalid input
        {
            printf("Invalid choice!\n");
        }

        if (choice == 4) //end program
        return 0;

        if (choice == 1) //record data
        {
            r = getdata();
            if (r == 1)
            return 1;
        }

        if (choice == 2) //sort student record in an order
        {
            r = sort();
            if (r == 1)
            return 1;
        }

        if (choice == 3) //mark sheet
        {
            r = marksheet();
            if (r == 1)
            return 1;
        }
    }
}

int getdata()
{
    printf("\nEnter the number of students: ");
    scanf("%i", &n);
    if (n > MAX) //n exceeds the limit MAX
    {
        return 1;
    }
    printf("Enter the students information: \n");

    for (int i = 0; i < n; i++) //records student data in respective str member
    {
        printf("\nStudent %i:\n", i+1);
        printf("Name: ");
        scanf(" %[^\n]s", s[i].name);
        printf("Roll no. :");
        scanf("%i", &s[i].roll_no);
        printf("Percent: ");
        scanf("%f", &s[i].percent);
    }
    return 0;
}

int sort()
{
    student t, alpha[MAX], rank[MAX], roll[MAX]; //arrays for sorted data

    for (int i = 0; i < n; i++) //initialization to given order
    {
        alpha[i] = s[i];
        rank[i] = s[i];
        roll[i] = s[i];
    }

    for (int i = 0; i < n - 1; i++) //bubble sort for roll no. based arrangement (ascending of roll no.)
    {
        for (int j = 0; j < n - 1; j++)
        {
            if (roll[j].roll_no > roll[j + 1].roll_no)
            {
                t = roll[j];
                roll[j] = roll[j + 1];
                roll[j + 1] = t;
            }
        }
    }

    for (int i = 0; i < n - 1; i++) //bubble sort for rank based arrangement (descending of percent.)
    {
        for (int j = 0; j < n - 1; j++)
        {
            if (rank[j].percent < rank[j + 1].percent)
            {
                t = rank[j];
                rank[j] = rank[j + 1];
                rank[j + 1] = t;
            }
        }
    }

    for (int i = 0; i < n - 1; i++) //bubble sort for alphabetical arrangement (based on name)
    {
        for (int j = 0; j < n - 1; j++)
        {
            if (strcmp(alpha[j].name, alpha[j + 1].name) > 0)
            {
                t = alpha[j];
                alpha[j] = alpha[j + 1];
                alpha[j + 1] = t;
            }
        }
    }
    
    int order;
    printf("\n");
    printf("Enter the order you want the record in:\n");
    printf("1. Roll no. wise\n");
    printf("2. Alphabetically wise.\n");
    printf("3. Rank wise.\n");
    printf("4. All\n");
    scanf("%i", &order);
    if (!(order >= 1 && order <= 4))
    {
        printf("Invalid input!");
        return 1;
    }

    if (order == 1) //roll no. wise
    {
        printf("-----------------------------------------------------------------------------------");
        printf("\nRoll no wise:\n");
        orderprint(n, roll); //orderprint() prints array roll[n] which is already sorted
    }

    if (order == 2)
    {
        printf("-----------------------------------------------------------------------------------");
        printf("\nAlphabetically wise:\n");
        orderprint(n, alpha);
    }

    if (order == 3)
    {
        printf("-----------------------------------------------------------------------------------");
        printf("\nRank wise:\n");
        orderprint(n, rank);
    }

    if (order == 4)
    {
        printf("-----------------------------------------------------------------------------------");
        printf("\nRank wise:\n");
        orderprint(n, rank);
        printf("-----------------------------------------------------------------------------------");
        printf("\nAlphabetically wise:\n");
        orderprint(n, alpha);
        printf("-----------------------------------------------------------------------------------");
        printf("\nRoll no wise:\n");
        orderprint(n, roll);
    }
    return 0;
}

void orderprint(int n, student array[])
{
    for (int i = 0; i < n; i++)
    {

        printf("Name: %s\n", array[i].name);
        printf("Roll no: %i\n", array[i].roll_no);
        printf("Percent: %.2f\n", array[i].percent);
        printf("\n");
    }
    printf("-----------------------------------------------------------------------------------");
}

int marksheet()
{
    subject sub[7]; //array of type 'subject' of size 7 for 7 subjects
    char result[10], sname[100], grade;
    int roll;
    float t = 0, percent;
    strcpy(result, "PASS"); //initially result is pass

    strcpy(sub[0].name, "EDRG101"); //subject names
    strcpy(sub[1].name, "PHYS101");
    strcpy(sub[2].name, "MATH101");
    strcpy(sub[3].name, "ENGG111");
    strcpy(sub[4].name, "COMP102");
    strcpy(sub[5].name, "CHEM101");
    strcpy(sub[6].name, "ENGG101");

    printf("Enter the roll number of the student:"); //for student whose marksheet is to be printed
    scanf("%i", &roll);
    for (int i = 0; i < n; i++)
    {
        if (s[i].roll_no == roll)
        {
            strcpy(sname, s[i].name);
        }
    }

    printf("Enter the marks scored in each subject:\n"); 
    for (int i = 0; i < 7; i++) //collects marks for each subject
    {
        printf("Subject: %s\n", sub[i].name);
        printf("Enter marks(of 100):");
        scanf("%f", &sub[i].marks);
        if (sub[i].marks > 100)
        {
            printf("Invalid Input!\n");
        }
    }

    for (int i = 0; i < 7; i++) //assigns grade for each subject based on marks scored
    {
        if (sub[i].marks >= 80)
        sub[i].grade = 'A';
        if (sub[i].marks >= 70 && sub[i].marks <80)
        sub[i].grade = 'B';
        if (sub[i].marks >= 60 && sub[i].marks <70)
        sub[i].grade = 'C';
        if (sub[i].marks >= 50 && sub[i].marks <60)
        sub[i].grade = 'D';
        if (sub[i].marks >= 40 && sub[i].marks <50)
        sub[i].grade = 'E';
        if (sub[i].marks < 40) //if <40 in aany subject then student has failed
        {
            sub[i].grade = 'N';
            strcpy(result, "FAIL");
        }
    }
    
    for (int i = 0; i < 7; i++) // calculates percent 
    {
        t = t + sub[i].marks;
    }
    percent = t / 7;

    if (percent >= 80) //assigns grade to student based on percent
    grade = 'A';
    if (percent >= 70 && percent < 80)
    grade = 'B';
    if (percent >= 60 && percent < 70)
    grade = 'C';
    if (percent >= 50 && percent < 60)
    grade = 'D';
    if (percent >= 40 && percent < 50)
    grade = 'E';
    if (percent < 40)
    {
        grade = 'N';
    }

    if (strcmp(result, "FAIL") == 0)
    grade = 'N';

    printf("-----------------------------------------------------------------------------------");
    printf("\n\n\t\t\t\t\tTRIBHUWAN UNIVERSITY\n\n\t\t\t\t\tGRADE SHEET\n\n");
    printf("Name: %s\n",sname);
    printf("Roll no.: %i\n\n", roll);
    printf("Subject\t\t\t\t\tMarks\t\t\t\t\tGrade\n");
    for (int i = 0; i < 7; i++) //loop for each subject
    {
        printf("%s\t\t\t\t\t%.2f\t\t\t\t\t%c\n", sub[i].name, sub[i].marks, sub[i].grade);
    }
    printf("\nResult = %s", result);
    printf("\nPercentage = %.2f", percent);
    printf("\nGrade = %c", grade);
    printf("\n");
    printf("-----------------------------------------------------------------------------------");
    return 0;
}