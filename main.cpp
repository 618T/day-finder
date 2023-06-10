#include <iostream>
#include <sstream>
#include <chrono>
#include <iomanip>
#include <string>

struct ZodiacSign {
    std::string name;
    int startMonth;
    int startDay;
    int endMonth;
    int endDay;
};

const ZodiacSign zodiacSigns[] = {
    {"Capricorn", 12, 22, 1, 19},
    {"Aquarius", 1, 20, 2, 18},
    {"Pisces", 2, 19, 3, 20},
    {"Aries", 3, 21, 4, 19},
    {"Taurus", 4, 20, 5, 20},
    {"Gemini", 5, 21, 6, 20},
    {"Cancer", 6, 21, 7, 22},
    {"Leo", 7, 23, 8, 22},
    {"Virgo", 8, 23, 9, 22},
    {"Libra", 9, 23, 10, 22},
    {"Scorpio", 10, 23, 11, 21},
    {"Sagittarius", 11, 22, 12, 21}
};

int calculateDayOfWeek(int q, int m, int k, int j) {
    int h = (q + ((m + 1) * 26) / 10 + k + k / 4 + j / 4 - 2 * j) % 7;
    return h;
}

std::string getDayOfWeek(int h) {
    std::string daysOfWeek[] = {"Saturday", "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday"};
    return daysOfWeek[h];
}

std::string getZodiacSign(int month, int day) {
    for (const auto& sign : zodiacSigns) {
        if ((month == sign.startMonth && day >= sign.startDay) ||
            (month == sign.endMonth && day <= sign.endDay) ||
            (month > sign.startMonth && month < sign.endMonth)) {
            return sign.name;
        }
    }
    return "";
}

int main() {
    // Get date input from the user
    std::string date;
    std::cout << "Enter the date (day month year, For example: 10 06 2000): ";
    std::getline(std::cin, date);

    // Parse day, month, and year from the input string
    int day, month, year;
    std::istringstream(date) >> day >> month >> year;

    // Get current date
    auto now = std::chrono::system_clock::now();
    std::time_t now_time = std::chrono::system_clock::to_time_t(now);
    std::tm* now_tm = std::localtime(&now_time);

    // Get the target date
    std::tm target_tm = *now_tm;
    target_tm.tm_mday = day;
    target_tm.tm_mon = month - 1;
    target_tm.tm_year = year - 1900;
    std::mktime(&target_tm);

    // Calculate the difference in days between the two dates
    std::time_t target_time = std::mktime(&target_tm);
    double diff_seconds = std::difftime(now_time, target_time);
    int diff_days = diff_seconds / (60 * 60 * 24);

    // Calculate the day of the week for the target date
    int dayOfWeek = calculateDayOfWeek(day, month, year % 100, year / 100);
    std::string dayName = getDayOfWeek(dayOfWeek);

    // Get the zodiac sign for the target date
    std::string zodiacSign = getZodiacSign(month, day);

    // Print the entered date and the current date
    std::cout << "Current Date: " << std::put_time(now_tm, "%d.%m.%Y") << std::endl;
    std::cout << "Entered Date: " << std::setfill('0') << std::setw(2) << day << "." << std::setfill('0') << std::setw(2) << month << "." << year << std::endl;
    
    std::cout << "The entered date falls on a " << dayName << "." << std::endl;
    std::cout << "Number of days elapsed since today: " << diff_days << std::endl;

    if (!zodiacSign.empty()) {
        std::cout << "Zodiac Sign: " << zodiacSign << std::endl;
    } else {
        std::cout << "Could not determine the Zodiac Sign for the entered date." << std::endl;
    }

    return 0;
}
