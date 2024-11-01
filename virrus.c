#include <stdio.h>
#include <string.h>

typedef struct {
    int day;
    int month;
    int year;
} Date;

void scanfDate(Date* date, char* value) {
   sscanf(value, "%d-%d-%d", &(date->day), &(date->month), &(date->year));
}

int zeller(Date* date) {
    if(date->month == 1) {date->month = 13; date->year--;}
    if(date->month == 2) {date->month = 14; date->year--;}
    int year = date->year % 100;
    int century = date->year / 100;
    int H = date->day + (13 * (date->month + 1)) / 5 + year + year / 4 + century / 4 + 5 * century;
    H %= 7;
    return H;
}
void solution(int value) {
    if(value == 0) printf("Saturday\0");
    if(value == 1) printf("Sunday\0");
    if(value == 2) printf("Monday\0");
    if(value == 3) printf("Tuesday\0");
    if(value == 4) printf("Wednesday\0");
    if(value == 5) printf("Thursday\0");
    if(value == 6) printf("Friday\0");
}
int main() {
    Date date;
    char key[20];
    scanf("%s", key);
    scanfDate(&date, key);
    // char enum[7][20] = {"Saturday\0", "Sunday\0", "Monday\0", "Tuesday\0", "Wednesday\0", "Thursday\0", "Friday\0"};
    solution(zeller(&date));
    return 0;
}
