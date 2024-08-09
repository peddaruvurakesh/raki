/*
 * This program is to check  error checking in day_of_year or month_day. Remedy this defect.
 *  month_day(1988, 60, &m, &d) sets m to 2 and d to 29 (February 29th).  
 * Author: rakesh
 * Created: 17 July, 2024
 * Modified:17 July, 2024
 */
/** REQUIRED HEADER FILES */
#include <stdio.h>
/** MACRO DEFINITIONS */

/** FUNCTION PROTOTYPES */
int day_of_year(int year, int month, int day);
void month_day(int year, int yearday, int *pmonth, int *pday);
static char daytab[2][13] = {
	{0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
	{0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
};
/** MAIN PROGRAM */
/** main: Multidimensional array */
int main(){
	int day = day_of_year(1988, 2, 29);
	printf("day of the year: %d\n", day);
	int month;
	int day_month;

	month_day(1988, 60, &month, &day_month);
	printf("month: %d, day: %d\n", month, day_month);

}
/* End main() */
/* day_of_year: set day of year from month & day */
int day_of_year(int year, int month, int day)
{
	int i, leap;
	leap = year%4 == 0 && year%100 != 0 || year%400 == 0;
	//checking months,if more than 12 months are there it shows error
	if(month>12)
	{
		printf("error:months are between 1 and 12 \n");
		return 0;
	}
	// checking days ,Additional checks for days.
	if (day > daytab[leap][month])
	{
		printf("error:More days are there then required in month\n");
		return 0;
	}
	for (i = 1; i < month; i++)
		day += daytab[leap][i];
	return day;
}

/* month_day: set month, day from day of year */
void month_day(int year, int yearday, int *pmonth, int *pday)
{
	int i, leap;
	leap = year%4 == 0 && year%100 != 0 || year%400 == 0;
	//checking yearday
	if((leap) && (yearday>366) || (!leap) && (yearday>365)){
		printf("check yeardays\n");
		*pmonth=0;
		*pday=0;
	}
	for (i = 1; yearday > daytab[leap][i]; i++)
		yearday -= daytab[leap][i];
	*pmonth = i;
	*pday = yearday;
}
