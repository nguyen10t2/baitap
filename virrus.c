#include <stdio.h>
#include <string.h>
#include <math.h>

typedef struct {
    int day;
    int month;
    int year;
} Date;
typedef struct {
    int hour;
    int min;
} Time;

Date date1, date2;
Time time1, time2;

int leapYear(int year) {
    return (year % 400 == 0) || (year % 100 != 0 && year % 4 == 0);
}
void scanfDate(Date* date, char* value) {
   sscanf(value, "%d-%d-%d", &(date->day), &(date->month), &(date->year));
}
void scanfTime(Time* time, char* value) {
    sscanf(value, "%d:%d", &(time->hour), &(time->min));
}
int daysInMonth(int month, int year) {
    int daysOfMonth[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    daysOfMonth[2] += leapYear(year);
    return daysOfMonth[month];
}
int dateToDays(Date* date) {
    int totalDays = 0;
    for (int y = 1; y < date->year; y++) {
        totalDays += leapYear(y) ? 366 : 365;
    }
    for (int m = 1; m < date->month; m++) {
        totalDays += daysInMonth(m, date->year);
    }
    totalDays += date->day;
    return totalDays;
}
int subtractDate(Date* date1, Date* date2, Time* time1, Time* time2) {
    int days1 = dateToDays(date1);
    int days2 = dateToDays(date2);
    int totalMinutes1 = time1->hour * 60 + time1->min;
    int totalMinutes2 = time2->hour * 60 + time2->min;
    int dayDifference = days2 - days1;
    int minuteDifference = totalMinutes2 - totalMinutes1;
    double totalDifferenceInHours = (double)dayDifference * 24 + minuteDifference / 60.0;

    return (int)ceil(totalDifferenceInHours);
}
int solution(int key) {
    int value = subtractDate(&date1, &date2, &time1, &time2);
    switch(key) {
        case 1:
            printf("%d", 30000 * value);
            break;
        case 2:
            printf("%d", 35000 * value);
        default:
            break;
    }
}
int main() {
    char key1[20], key2[20], h1[10], h2[10];
    int type;
    scanf("%d", &type);
    scanf("%s %s %s %s", key1, h1, key2, h2);
    scanfDate(&date1, key1); scanfDate(&date2, key2);
    scanfTime(&time1, h1)  ; scanfTime(&time2, h2);
    solution(type);
    return 0;
}