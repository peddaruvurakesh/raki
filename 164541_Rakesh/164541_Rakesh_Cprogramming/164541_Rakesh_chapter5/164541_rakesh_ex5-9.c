/*
 * This program is to  rewrite the routines day_of_year and month_day with pointers instead of 
indexing.   
 * Author: rakesh
 * Created: 17 July, 2024
 * Modified:17 July, 2024
 */
/** REQUIRED HEADER FILES */
#include <stdio.h>
/** MACRO DEFINITIONS */

/** FUNCTION PROTOTYPES */
int day_of_year(int *year, int *month, int *day);
void month_day(int *year, int *yearday, int *pmonth, int *pday);
static char daytab[]={0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
static char leap_daytab[]={0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
/** MAIN PROGRAM */
/** main: using pointers*/
int main(){
	int year=1988;
	int months=2;
	int days=29;
	int day = day_of_year(&year, &months, &days);
	printf("day of the year: %d\n", day);
	int month;
	int day_month;
        int yearday=60;
	month_day(&year, &yearday, &month, &day_month);
	printf("month: %d, day: %d\n", month, day_month);

}
/* End main() */
/* day_of_year: set day of year from month & day */
int day_of_year(int *year, int *month, int *day)
{
	int i, leap;
	leap = *year%4 == 0 && *year%100 != 0 || *year%400 == 0;
	//checking months,if more than 12 months are there it shows error
	if(*month>12)
	{
		printf("error:months are between 1 and 12 \n");
		return 0;
	}

	for (i = 1; i<*month; i++)
		*day += leap_daytab[i];
	return *day;
}

/* month_day: set month, day from day of year */
void month_day(int *year, int *yearday, int *pmonth, int *pday)
{
	int i, leap;
	leap = *year%4 == 0 && *year%100 != 0 || *year%400 == 0;
	//checking yearday
	if((leap) && (*yearday>366) || (!leap) && (*yearday>365)){
		printf("check yeardays\n");
		*pmonth=0;
		*pday=0;
	}
	for (i = 1; *yearday > leap_daytab[i]; i++)
		*yearday -= leap_daytab[i];
	*pmonth = i;
	*pday = *yearday;
}
