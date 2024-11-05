
#include <iostream>
#include <limits>
using namespace std;

namespace confidate
{
    struct info
    {
        short year = 0;
        short month = 0;
        short day = 0;
    };

    short positive_number(string massege)
    {
        short number = 0;
        cout << massege;
        cin >> number;

        while (cin.fail())
        {
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

            cout << "Please Tray Again: ";
            cin >> number;
        }
        return number;
    }

    string read_string(string massage)
    {
        string text;
        cout << massage;
        getline(cin >> ws, text);
        return text;
    }

    info read_data()
    {
        info self;
        self.day = positive_number("Enter The Day: ");
        self.month = positive_number("Enter The Month: ");
        self.year = positive_number("Enter The Year: ");

        return self;
    }

    bool is_leap_year(short year)
    {
    return (year % 400 == 0) || (year % 4 == 0 && year % 100 != 0);
    }

    short days_in_year(short year)
    {
        return is_leap_year(year) ? 366 : 365;
    }

    short hours_in_year(short year)
    {
        return days_in_year(year) * 24;
        // return check_year(number) ? 366 * 24 : 365 * 24;
    }

    short minutes_in_year(short year)
    {
        return hours_in_year(year) * 60;
        // return check_year(number) ? 366 * 24 * 60 : 365 * 24 * 60;
    }

    int seconds_in_year(short year)
    {
        return minutes_in_year(year) * 60;
        // return check_year(number) ? 366 * 24 * 60 * 60 : 365 * 24 * 60 * 60;
    }

    short days_in_month(short month, short year)
    {
        if(month < 1 || month > 12)
            return 0;
        int ray[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        return (month == 2) ? (is_leap_year(year) ? 29 : 28) : ray[month - 1];
    }

    short hours_in_month(short month, short year)
    {
        return days_in_month(month, year) * 24;
    }

    int minutes_in_month(short month, short year)
    {
        return hours_in_month(month, year) * 60;
    }

    int seconds_in_month(short month, short year)
    {
        return minutes_in_month(month, year) * 60;
    }

    short day_in_week(short day, short month, short year)
    {
        short a, y, m;
        a = (14 - month) / 12;
        y = year - a;
        m = month + (12 * a) - 2;
        return (day + y + (y/4) - (y/100) + (y/400) + ((31 * m) / 12)) % 7; // Gregorian Calender start week wiht Dimanch
        // return (5 + day + y + (y/4) + ((31 * m) / 12)) % 7; // Julian Calender start week with Lundi
    }

    short day_in_week(info self) // overload (strong way from teacher)
{
    return day_in_week(self.day, self.month, self.year);
}

    string short_month(short month)
    {
        string ray[12] = {"Jan", "Feb", "Mar", "Apr", "Mai", "Jun", "Jui", "Aou", "Sep", "Oct", "Nov", "Dec"};
        return ray[month-1];
    }

    string short_day(short day)
    {
        string ray[7] = {"Dim", "Lun", "Mar", "Mer", "Jeu", "Van", "Sam"};
        return ray[day];
    }

    void print_month_calender(short month, short year)
    {
        short num_day = days_in_month(month, year);
        short current = day_in_week(1, month, year);

        printf("\n _______________%s__________________\n\n", short_month(month).c_str());
        cout << "  Dim  Lun  Mar  Mer  Jeu  Van  Sam" << endl;

        short i;

        for (i = 0; i < current; i++)
        {
            printf("     ");
        }

        for (short j = 1; j <= num_day; j++)
        {
            printf("%5d", j);

            if (++i == 7)
            {
                i = 0;
                printf("\n");
            }
        }
        printf("\n ____________________________________\n");
    }

    void print_year_calender(short year)
    {
        cout << "\n ------------------------------------\n";
        cout << "          Calender - " << year << endl;
        cout << " ------------------------------------\n";
        for (short i = 1; i <= 12; i++)
        {
            print_month_calender(i, year);
            cout << endl;
        }
    }

    short days_from_begining(short year, short month, short day)
    {
        short total_day = 0;

        for (short i = 1; i < month; i++)
        {
            total_day += days_in_month(i, year);
        }

        total_day += day;

        return total_day;
    }

    info get_order_day(short date_order, short year)
    {
        info self;
        short remain_days = date_order;
        short month_days = 0;

        self.year = year;
        self.month = 1;

        while (true)
        {
            month_days = days_in_month(self.month, year);

            if (remain_days > month_days)
            {
                remain_days -= month_days;
                self.month++;
            }
            else
            {
                self.day = remain_days;
                break;
            }
        }

        return self;
    }

    info date_add_days(short days, info self)
    {
        short remaining_days = days + days_from_begining(self.year, self.month, self.day);
        short month_days = 0;

        self.month = 1;

        while (true)
        {
            month_days = days_in_month(self.month, self.year);

            if (remaining_days > month_days)
            {
                remaining_days -= month_days;
                self.month++;

                if (self.month > 12)
                {
                    self.month = 1;
                    self.year++;
                }
            }
            else
            {
                self.day = remaining_days;
                break;
            }
        }
        return self;
    }

    bool is_date_less_than_other(info self_1, info self_2)
    {
        return (self_1.year < self_2.year) ? true : ((self_1.year == self_2.year && self_1.month < self_2.month) ? true : ((self_1.month == self_2.month && self_1.day < self_2.day) ? true : false));
    }

    bool is_it_equal_date(info self_1, info self_2)
    {
        return (self_1.year == self_2.year && self_1.month == self_2.month && self_1.day == self_2.day) ? true : false;
    }

    bool similar_day(info self)
    {
        return (self.day == days_in_month(self.month, self.year) ? true : false);
    }

    bool similar_month(short month)
    {
        return (month == 12);
    }

    info increase_one_day(info self)
    {
        if (similar_day(self))
        {
            if (similar_month(self.month))
            {
                self.day = 1;
                self.month = 1;
                self.year++;
            }
            else
            {
                self.day = 1;
                self.month++;
            }
        }
        else
            self.day++;
        return self;
    }

    void swap_dates(info &self_1, info &self_2)
    {
        info temp;

        temp.year = self_1.year;
        temp.month = self_1.month;
        temp.day = self_1.day;

        self_1.year = self_2.year;
        self_1.month = self_2.month;
        self_1.day = self_2.day;

        self_2.year = temp.year;
        self_2.month = temp.month;
        self_2.day = temp.day;
    }

    int get_deffrintes_days(info self_1, info self_2, bool increase = false)
    {
        int days = 0;
        short swap_value = 1;

        if (!is_it_equal_date(self_1, self_2))
        {
            swap_dates(self_1, self_2);
            swap_value = - 1;
        }

        while (is_it_equal_date(self_1, self_2))
        {
            days++;
            self_1 = increase_one_day(self_1);
        }
        return increase ? ++days * swap_value : days * swap_value;
    }

    info get_system_date()
    {
        info self;

        time_t t = time(0);
        tm* now = localtime(&t);

        self.year = now->tm_year + 1900;
        self.month = now->tm_mon + 1;
        self.day = now->tm_mday;

        return self;
    }

    info increase_x_day(short days, info self)
    {
        for (short i = 1; i <= days; i++)
        {
            self = increase_one_day(self);
        }
        return self;
    }

    info increase_one_week(info self)
    {
        for (short i = 1; i <= 7; i++)
        {
            self = increase_one_day(self);
        }
        return self;
    }

    info increase_x_week(short week, info self)
    {
        for (short i = 1; i <= week; i++)
        {
            self = increase_one_week(self);
        }
        return self;
    }

    info increase_one_month(info self) // best sulotion forever.
    {
        for (short i = 1; i <= 30; i++)
        {
            self = increase_one_day(self);
        }
        return self;
    }

    // info increase_one_month(info self) // teacher sulotion.
    // {
    //     if (self.month == 12)
    //     {
    //         self.month = 1;
    //         self.year++;
    //     }
    //     else
    //     {
    //         self.month++;
    //     }

    //     //last check day in date should not exceed max days in the current month
    //     // example if date is 31/1/2022 increasing one month should not be 31 / 2 / 2022, it should be 28/2/2022.

    //     short number_day_in_current_month = days_in_month(self.month, self.year);
    //     if (self.day > number_day_in_current_month)
    //     {
    //         self.day = number_day_in_current_month;
    //     }
    //     return self;
    // }

    info increase_x_month(short month, info self)
    {
        for (short i = 1; i <= month; i++)
        {
            self = increase_one_month(self);
        }
        return self;
    }

    info increase_one_year(info self)
    {
        self.year++;
        return self;
    }

    info increase_x_year(short year, info self)
    {
        for (short i = 1; i <= year; i++)
        {
            self = increase_one_year(self);
        }
        return self;
    }

    info increase_x_year_faster(short year, info self)
    {
        self.year += year;
        return self;
    }

    info increase_one_decade(info self)
    {
        self.year += 10;
        return self;
    }

    info increase_x_decade(short decade, info self)
    {
        for (short i = 1; i <= decade; i++)
        {
            self = increase_one_decade(self);
        }
        return self;
    }

    info increase_x_decade_faster(short decade, info self)
    {
        self.year += (decade * 10);
        return self;
    }

    info increase_one_century(info self)
    {
        self.year += 100;
        return self;
    }

    info increase_one_millenuim(info self)
    {
        self.year += 1000;
        return self;
    }

    info decrease_one_day(info self)
    {
        if (self.day == 1)
        {
            if (self.month == 1)
            {
                self.day = 31;
                self.month = 12;
                self.year--;
            }
            else
            {
                self.day = days_in_month(self.month, self.year);
                self.month--;
            }
        }
        else
            self.day--;
        return self;
    }

    info decrease_x_day(short days, info self)
    {
        for (short i = 1; i <= days; i++)
        {
            self = decrease_one_day(self);
        }
        return self;
    }

    info decrease_one_week(info self)
    {
        for (short i = 1; i <= 7; i++)
        {
            self = decrease_one_day(self);
        }
        return self;
    }

    info decrease_x_week(short week, info self)
    {
        for (short i = 1; i <= week; i++)
        {
            self = decrease_one_week(self);
        }
        return self;
    }

    info decrease_one_month(info self) // best sulotion forever.
    {
        for (short i = 1; i <= 30; i++)
        {
            self = decrease_one_day(self);
        }
        return self;
    }

    // info decrease_one_month(info self) // teacher sulotion.
    // {
    //     if (self.month == 1)
    //     {
    //         self.month = 12;
    //         self.year--;
    //     }
    //     else
    //     {
    //         self.month--;
    //     }

    //     //last check day in date should not exceed max days in the current month
    //     // example if date is 31/3/2022 increasing one month should not be 31 / 2 / 2022, it should be 28/2/2022.

    //     short number_day_in_current_month = days_in_month(self.month, self.year);
    //     if (self.day > number_day_in_current_month)
    //     {
    //         self.day = number_day_in_current_month;
    //     }
    //     return self;
    // }

    info decrease_x_month(short month, info self)
    {
        for (short i = 1; i <= month; i++)
        {
            self = decrease_one_month(self);
        }
        return self;
    }

    info decrease_one_year(info self)
    {
        self.year--;
        return self;
    }

    info decrease_x_year(short year, info self)
    {
        for (short i = 1; i <= year; i++)
        {
            self = decrease_one_year(self);
        }
        return self;
    }

    info decrease_x_year_faster(short year, info self)
    {
        self.year -= year;
        return self;
    }

    info decrease_one_decade(info self)
    {
        self.year -= 10;
        return self;
    }

    info decrease_x_decade(short decade, info self)
    {
        for (short i = 1; i <= decade; i++)
        {
            self = decrease_one_decade(self);
        }
        return self;
    }

    info decrease_x_decade_faster(short decade, info self)
    {
        self.year -= (decade * 10);
        return self;
    }

    info decrease_one_century(info self)
    {
        self.year -= 100;
        return self;
    }

    info decrease_one_millenuim(info self)
    {
        self.year -= 1000;
        return self;
    }

    bool is_it_end_of_week(info self)
    {
        return day_in_week(self) == 5;
    }

    bool is_it_weekend(info self)
    {
        short day = day_in_week(self);
        return (day == 4 || day == 5);
    }

    bool is_it_business_day(info self)
    {
        // short day = day_in_week(self);
        // return !(day == 5 || day == 6);
        return !is_it_weekend(self);
    }

    short days_until_end_of_week(info self)
    {
        short days = day_in_week(self);
        return 5 - days;
    }

    short days_until_end_of_month(info self)
    {
        short month = days_in_month(self.month, self.year);
        return month - self.day;
    }

    short days_until_end_of_year(info selfo)
    {
        info selfa;
        selfa.day = 1;
        selfa.month = 1;
        selfa.year = selfo.year;

        short days = get_deffrintes_days(selfa, selfo, true);
        short year = days_in_year(selfo.year);
        return year - days;
    }

    short actucal_vacation_day(info &selfo, info &selfa)
    {
        short vacation = 0;
        while (!is_it_equal_date(selfo, selfa))
        {
            if (is_it_business_day(selfo))
                vacation++;
            selfo = increase_one_day(selfo);
        }
        return vacation;
    }

    info return_vacation_date(info date_from, short vacation)
    {
        short weekend_counter = 0;

        while (is_it_weekend(date_from))
        {
            date_from = increase_one_day(date_from);
        }

        for (short i = 1; i <= vacation + weekend_counter; i++)
        {
            if (is_it_weekend(date_from))
                weekend_counter++;
            
            date_from = increase_one_day(date_from);
        }

        while (is_it_weekend(date_from))
        {
            date_from = increase_one_day(date_from);
        }
        return date_from;
    }

    bool is_date_after_other(info self_1, info self_2)
    {
        return (!is_date_less_than_other(self_1, self_2) && !is_it_equal_date(self_1, self_2));
    }

    enum eninfo {before = -1, equal = 0, after = 1};

    eninfo compare_dates(info self_1, info self_2)
    {
        if (is_date_less_than_other(self_1, self_2))
            return eninfo::before;
        else if (is_it_equal_date(self_1, self_2))
            return eninfo::equal;
        else
            return eninfo::after;
        
        // return eninfo::after;                    // this is faster like teacher sayed.
    }

    struct period
    {
        info start;
        info end;
    };

    period read_data_period()
    {
        period self;
        cout << "Enter Start Date: \n";
        self.start = read_data();
        cout << "Enter End Date: \n";
        self.end = read_data();
        return self;
    }

    bool is_over_lap(period self_1, period self_2)
    {
        if (
            compare_dates(self_2.end, self_1.start) == eninfo::before
            ||
            compare_dates(self_2.start, self_1.end) == eninfo::after
            )
            return false;
        else
            return true; 
    }

    int period_lenght(period perio, bool increase = false)
    {
        return get_deffrintes_days(perio.start, perio.end, increase);
    }

    bool is_date_within_period(info self, period perio)
    {
        return !(compare_dates(self, perio.start) == eninfo::before || compare_dates(self, perio.end) == eninfo::after);
    }

    // int overlap_days(period perio_1, period perio_2)
    // {
    //     int count_days = 0;
    //     while (is_date_within_period(perio_2.start, perio_1))
    //     {
    //         count_days++;
    //         perio_2.start = increase_one_day(perio_2.start);
    //     }
    //     return count_days;
    // }

    int overlap_days(period perio_1, period perio_2) // This Fun Sulotion By Teacher Sadly
    {
        int peri_length_1 = period_lenght(perio_1, true);
        int peri_length_2 = period_lenght(perio_2, true);
        int count_days = 0;

        if (!is_over_lap(perio_1, perio_2))
            return 0;

        if (peri_length_1 < peri_length_2)
        {
            while (is_date_less_than_other(perio_1.start, perio_1.end))
            {
                if (is_date_within_period(perio_1.start, perio_2))
                    count_days++;
                perio_1.start = increase_one_day(perio_1.start);
            }
        }
        else
        {
            while (is_date_less_than_other(perio_2.start, perio_2.end))
            {
                if (is_date_within_period(perio_2.start, perio_1))
                    count_days++;
                perio_2.start = increase_one_day(perio_2.start);
            }
        }
        return count_days;
    }

    bool is_valid_date(info self)
    {
        if (self.day < 1 || self.day > 31)
            return false;
        else if (self.month < 1 || self.month > 12)
            return false;
        else if (self.month == 2)
        {
            if (is_leap_year(self.year))
            {
                if (self.day > 29)
                    return false;
            }
            else
            {
                if (self.day > 28)
                    false;
            }
        }
        short days_month = days_in_month(self.month, self.year);
        if (self.day > days_month)
            return false;
        
        return true;
    }
}