//Pritesh Pandya first project on C Language
#include <stdio.h>
int isLeapYear(int year) {
    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
        return 1;
    }
    return 0;
}
int getDaysInMonth(int month, int year) {
    switch (month) {
        case 1: case 3: case 5: case 7: case 8: case 10: case 12:
            return 31;
        case 4: case 6: case 9: case 11:
            return 30;
        case 2:
            return isLeapYear(year) ? 29 : 28;
        default:
            return 0;
    }
}
void printMonth(int month, int year, int* startDay) {
    const char* months[] = {
        "January", "February", "March", "April", "May", "June",
        "July", "August", "September", "October", "November", "December"
    };
    
    printf("\n---------- %s %d ----------\n", months[month - 1], year);
    printf("Sun Mon Tue Wed Thu Fri Sat\n");
    for (int i = 0; i < *startDay; i++) {
        printf("    ");
    }
    int days = getDaysInMonth(month, year);
    for (int day = 1; day <= days; day++) {
        printf("%3d ", day); 
        if ((*startDay + day) % 7 == 0) {
            printf("\n");
        }
    }
    printf("\n");
    *startDay = (*startDay + days) % 7;
}

int main() {
    int year = 2025;
    int startDay = 3;
    printf("Calendar for the Year %d\n", year);
    for (int month = 1; month <= 12; month++) {
        printMonth(month, year, &startDay);
    }

    return 0;
}
