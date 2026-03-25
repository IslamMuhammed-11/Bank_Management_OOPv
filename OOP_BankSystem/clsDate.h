#pragma once
#pragma warning(disable : 4996)
#include<iostream>
#include<ctime>
#include <vector>
#include<string>  
#include<iomanip>
using namespace std;
class clsDate
{
private:
    int _Day;
    int _Month;
    int _Year;


    vector<string> Split(string S1, string Delim)
    {

        vector<string> vString;

        short pos = 0;
        string sWord; // define a string variable  

        // use find() function to get the position of the delimiters  
        while ((pos = S1.find(Delim)) != std::string::npos)
        {
            sWord = S1.substr(0, pos); // store the word   
            if (sWord != "")
            {
                vString.push_back(sWord);
            }

            S1.erase(0, pos + Delim.length());  /* erase() until positon and move to next word. */
        }

        if (S1 != "")
        {
            vString.push_back(S1); // it adds last word of the string.
        }

        return vString;

    }

    static short dayOrder(short month, short year, short day) {


        int a = (14 - month) / 12;
        int y = year - a;
        int m = month + (12 * a) - 2;

        short d = (day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7;
        return d;
    }

    static string dayName(short dayOrder) {
        string arrDays[7] = { "Sun" , "Mon" , "Tue" , "Wed" , "Thu" , "Fri" , "Sat" };

        return arrDays[dayOrder];
    }

    static string monthShortNames(short month) {

        string arrMonth[12] = { "Jan" , "Feb" , "Mar" , "Apr" , "May" , "Jun" ,"Jul" , "Aug" , "Sep" , "Oct" , "Nov" , "Dec" };
        return arrMonth[month - 1];
    }

public:
    clsDate() {
        time_t t = time(0);

        tm* now = localtime(&t);

        _Day = now->tm_mday;
        _Month = now->tm_mon + 1;
        _Year = now->tm_year + 1900;
    }

    clsDate(string Date) {
        vector<string>date = Split(Date, "/");
        _Day = stoi(date[0]);
        _Month = stoi(date[1]);
        _Year = stoi(date[2]);
    }

    clsDate(int day, int month, int year) {
        _Day = day;
        _Month = month;
        _Year = year;
    }

    clsDate(int HowManyDays, int year) {
        _Day = 1;
        _Month = 1;
        _Year = year;
        increaseDateByXDays(HowManyDays);
    }


    void setDay(int day) {
        _Day = day;
    }
    int getDay() {
        return _Day;
    }

    __declspec(property(get = getDay, put = setDay)) int day;


    void setMonth(int month) {
        _Month = month;
    }
    int getMonth() {
        return _Month;
    }

    __declspec(property(get = getMonth, put = setMonth)) int month;

    void setYear(int year) {
        _Year = year;
    }
    int getYear() {
        return _Year;
    }

    __declspec(property(get = getYear, put = setYear)) int year;

    void print() {
        cout << _Day << "/" << _Month << "/" << _Year << endl;
    }


    static clsDate GetSystemDate()
    {
        time_t t = time(0);
        tm* Now = localtime(&t);
        short Day, Month, Year;

        Day = Now->tm_mday;
        Month = Now->tm_mon + 1;
        Year = Now->tm_year + 1900;

        return clsDate(Day, Month, Year);
    }

    static bool isLeapYear(short year) {
        return year % 400 == 0 || (year % 4 == 0 && year % 100 != 0);
    }

    static short howManyDayInAMonth(short year, short month) {
        if (month < 1 || month > 12)
        {
            return 0;
        }

        short arrDayMonth[] = { 0 , 31 , 28 , 31 , 30 , 31 , 30 , 31 , 31 ,30 , 31 , 30 , 31 };
        return month == 2 ? (isLeapYear(year) ? 29 : 28) : arrDayMonth[month];
    }

    short howManyDayInAMonth() {
        return howManyDayInAMonth(_Year, _Month);
    }

    static int totalDaysFromBeginingOfYear(clsDate date) {
        int days = 0;
        for (int i = 1; i < date._Month; i++)
        {
            days += howManyDayInAMonth(date._Year, i);
        }
        days += date._Day;
        return days;
    }

    int totalDaysFromBeginingOfYear() {
        return totalDaysFromBeginingOfYear(*this);
    }

    static bool isLastDayInAMonth(clsDate date) {
        return date._Day == howManyDayInAMonth(date._Year, date._Month);
    }

    static bool isLastMonthInAYear(short month) {
        return month == 12;
    }

    static clsDate adding1DayToDate(clsDate date) {

        if (isLastDayInAMonth(date))
        {
            if (isLastMonthInAYear(date._Month))
            {
                date._Day = 1;
                date._Month = 1;
                date._Year++;
                return date;
            }
            else
            {
                date._Day = 1;
                date._Month++;
                return date;
            }
        }
        else
        {
            date._Day++;
            return date;
        }
    }

    static void increaseDateByXDays(clsDate& date, int x) {


        for (int i = 0; i < x; i++)
        {
            date = adding1DayToDate(date);
        }

    }

    void increaseDateByXDays(int x) {
        increaseDateByXDays(*this, x);
    }

    static void printCalendar(short year, short month) {

        int numberOfDays = howManyDayInAMonth(year, month);

        int current = dayOrder(month, year, 1);

        printf("\n   _______________%s____________\n\n", monthShortNames(month).c_str());

        printf("  Sun  Mon  Tue  Wed  Thu  Fri  Sat\n");
        int i;
        for (i = 0; i <= current; i++)
        {
            printf("     ");
        }
        for (int j = 1; j <= numberOfDays; j++)
        {
            printf("%5d", j);
            if (++i == 7)
            {
                i = 0;
                printf("\n");
            }
        }
        printf("\n\    ____________________________\n");
    }

    void printCalendar() {

        printCalendar(_Year, _Month);
    }

    static void printYearCalendar(short year) {

        printf("\n\n    ___________________________    \n\n");
        printf("           Calendar - %d          ", year);
        printf("\n\n    ___________________________    \n\n");

        for (int i = 1; i <= 12; i++)
        {
            printCalendar(year, i);
            cout << endl;
        }

    }

    void printYearCalendar() {
        printYearCalendar(_Year);
    }

    static void Swap(clsDate& date1, clsDate& date2) {
        clsDate Temp;
        Temp = date1;
        date1 = date2;
        date2 = Temp;
    }

    static bool IsDate1BeforeDate2(clsDate Date1, clsDate Date2) {

        return  (Date1._Year < Date2._Year) ? true : ((Date1._Year == Date2._Year) ? (Date1._Month < Date2._Month ? true : (Date1._Month == Date2._Month ? Date1._Day < Date2._Day : false)) : false);

    }

    bool IsDate1BeforeDate2(clsDate Date2) {
        return IsDate1BeforeDate2(*this, Date2);
    }

    static bool IsDate1AfterDate2(clsDate Date1, clsDate Date2) {
        return !IsDate1BeforeDate2(Date1, Date2);
    }

    bool IsDate1AfterDate2(clsDate Date2) {
        return IsDate1AfterDate2(*this, Date2);
    }

    static bool IsDateInBetween(clsDate DateToCheck, clsDate FromDate, clsDate ToDate) {

        if (IsDate1BeforeDate2(DateToCheck, FromDate) || IsDate1AfterDate2(DateToCheck, ToDate))
            return false;
        else
            return true;
    }

    bool IsDateInBetween(clsDate FromDate, clsDate ToDate) {
        return IsDateInBetween(*this, FromDate, ToDate);
    }

    static bool IsValidDate(clsDate Date) {
        if (Date._Day < 1 || Date._Day > 31)
            return false;
        if (Date._Month < 1 || Date._Month > 12)
            return false;

        //if (Date._Month == 2) {
        //    if (isLeapYear(Date._Year)) {
        //        if (Date._Day > 29)
        //            return false;
        //    }
        //    else {
        //        if (Date._Day > 28)
        //            return false;
        //    }
        //}

        short DayInMonth = clsDate::howManyDayInAMonth(Date._Year, Date._Month);

        if (Date.day > DayInMonth)
            return false;

        return true;
    }

    bool IsValidDate() {
        return IsValidDate(*this);
    }


    static string DateToString(clsDate Date)
    {
        return to_string(Date._Day) + '/' + to_string(Date._Month) + '/' + to_string(Date._Year);
    }

    string DateToString()
    {
        return DateToString(*this);
    }

    static string GetSystemDateAndTimeString() {
        string DateTime = "";

        time_t t = time(0);
        tm* Now = localtime(&t);
        short Day, Month, Year , Hour , Min , Sec;

        Day = Now->tm_mday;
        Month = Now->tm_mon + 1;
        Year = Now->tm_year + 1900;
        Hour = Now->tm_hour;
        Min = Now->tm_min;
        Sec = Now->tm_sec;

        DateTime = to_string(Day) + "/" + to_string(Month) + "/" + to_string(Year) + 
            " - " + to_string(Hour) + ":" + to_string(Min) + ":" + to_string(Sec);
        return DateTime;
    }

};

