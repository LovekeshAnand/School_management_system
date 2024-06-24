#include <stdio.h>
#include <string.h>

int i = 0;

struct stud_details {
    char first_name[100];
    char last_name[100];
    int roll;
    int phone;
    int sem;
} sd[100];

void stud_add() {
    printf("                             ADD NEW STUDENT DETAILS\n");
    printf("x----------x----------x----------x----------x----------x----------x----------x\n");

    printf("First Name: ");
    scanf("%s", sd[i].first_name);
    printf("Last Name: ");
    scanf("%s", sd[i].last_name);

    printf("Roll no.: ");
    scanf("%d", &sd[i].roll);

    printf("Phone no.: ");
    scanf("%d", &sd[i].phone);

    printf("Semester: ");
    scanf("%d", &sd[i].sem);

    if(sd[i].sem < 1 || sd[i].sem > 8) {  // Corrected the condition
        printf("Invalid sem...\n");
    }
    else {
        printf("New student details added successfully!\n");
        i++;  // Moved inside else block to ensure increment happens only for valid entries
    }
}

void stud_roll() {
    printf("                             FIND STUDENT DETAILS\n");
    printf("x----------x----------x----------x----------x----------x----------x----------x\n");
    int rollno;
    printf("Enter roll no. of the student you want to find: ");
    scanf("%d", &rollno);
    int found = 0;  // To check if the roll number was found
    for(int j = 1; j <= i; j++) {  // Changed loop condition to j < i
        if(rollno == sd[i].roll) {  // Changed sd[i] to sd[j]
            printf("                       STUDENT DETAILS\n");
            printf("First Name: %s\n", sd[i].first_name);
            printf("Last Name: %s\n", sd[i].last_name);
            printf("Roll no.: %d\n", sd[i].roll);
            printf("Phone no.: %d\n", sd[i].phone);
            printf("Semester: %d\n", sd[i].sem);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Invalid roll number!\n");
    }
}

void stud_sem() {
    printf("                             FIND STUDENTS IN A SEM\n");
    printf("x----------x----------x----------x----------x----------x----------x----------x\n");
    int sem;
    printf("Enter the semester: ");
    scanf("%d", &sem);  // Corrected scanf to take input in sem
    int found = 0;  // To check if any student was found in the given semester
    for(int j = 0; j < i; j++) {  // Changed loop condition to j < i
        if(sem == sd[j].sem) {  // Changed sd[i] to sd[j]
            printf("                       STUDENT DETAILS %d\n", j+1);
            printf("First Name: %s\n", sd[j].first_name);
            printf("Last Name: %s\n", sd[j].last_name);
            printf("Roll no.: %d\n", sd[j].roll);
            printf("Phone no.: %d\n", sd[j].phone);
            printf("Semester: %d\n", sd[j].sem);
            found = 1;
        }
    }
    if (!found) {
        printf("No students found in semester %d!\n", sem);
    }
}

void stud_delete() {
    printf("                             DELETE STUDENTS DETAILS\n");
    printf("x----------x----------x----------x----------x----------x----------x----------x\n");
    int roll;
    printf("Enter the Roll no. you want to delete: ");
    scanf("%d", &roll);
    int found = 0;  // To check if the roll number was found
    for (int j = 0; j < i; j++) {  // Changed loop condition to j < i
        if (roll == sd[j].roll) {
            for (int s = j; s < i - 1; s++){  // Changed s < 99 to s < i-1
                sd[s] = sd[s + 1];
            }
            i--;
            found = 1;
            printf("Roll number removed successfully!\n");
            break;
        }
    }
    if (!found) {
        printf("Invalid roll number!\n");
    }
}

void stud_update() {
    printf("                             UPDATE STUDENTS DETAILS\n");
    printf("x----------x----------x----------x----------x----------x----------x----------x\n");
    int roll;
    printf("Enter the roll no. of the student to update details: ");
    scanf("%d", &roll);
    int found = 0;  // To check if the roll number was found
    for(int j = 0; j < i; j++) {  // Changed loop condition to j < i
        if(roll == sd[j].roll) {  // Changed sd[i] to sd[j]
            printf("CHOOSE THE DETAIL YOU WANT TO UPDATE\n");
            printf("1. First name\n2. Last name\n3. Roll no.\n4. Phone no.\n5. Semester\n");
            int choice;
            printf("Enter choice: ");
            scanf("%d", &choice);
            if(choice == 1) {
                printf("Enter the new first name: \n");
                scanf("%s", sd[j].first_name);
            }
            else if(choice == 2) {
                printf("Enter the new last name: \n");
                scanf("%s", sd[j].last_name);
            }
            else if(choice == 3) {
                printf("Enter the new roll no.: \n");
                scanf("%d", &sd[j].roll);
            }
            else if(choice == 4) {
                printf("Enter the new phone number: \n");
                scanf("%d", &sd[j].phone);
            }
            else if(choice == 5) {
                printf("Enter the new semester: \n");
                scanf("%d", &sd[j].sem);
            }
            else {
                printf("Invalid choice!\n");
            }
            found = 1;
            printf("Details updated successfully!\n");
            break;
        }
    }
    if (!found) {
        printf("Invalid roll number!\n");
    }
}

int main() {
    while(i = 1){
    printf("x----------x----------x----------x----------x----------x----------x----------x\n");
    printf("                      WELCOME TO SCHOOL MANAGEMENT SYSTEM\n");
    printf("x----------x----------x----------x----------x----------x----------x----------x\n");
    printf("                             HOW CAN I HELP YOU?\n");

    printf("PLEASE SELECT THE QUERY\n");
    printf("1. Add new student details.\n");
    printf("2. Find the student details by roll number.\n");
    printf("3. Find the students by semester.\n");
    printf("4. Delete student details.\n");
    printf("5. Update student Details.\n");
    printf("6. Exit\n");
    int query;
    printf("Enter the number of query: ");
    scanf("%d", &query);

    printf("Your query is in process.....\n");

    if(query == 1) {
        stud_add();
    }
    else if(query == 2) {
        stud_roll();
    }
    else if(query == 3) {
        stud_sem();
    }
    else if(query == 4) {
        stud_delete();
    }
    else if(query == 5) {
        stud_update();
    }
    else if(query == 6){
        break;
    }
    else {
        printf("Invalid query!\n");
    }

    printf("x----------x----------x----------x----------x----------x----------x----------x\n");
    printf("              THANK YOU FOR USING THE SCHOOL MANAGEMENT SYSTEM\n");
    printf("x----------x----------x----------x----------x----------x----------x----------x\n");
    }
    return 0;
}
