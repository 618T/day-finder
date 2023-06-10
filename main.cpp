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

void printTimeElapsed(const std::chrono::duration<long long>& duration) {
    auto days = std::chrono::duration_cast<std::chrono::hours>(duration) / 24;
    auto hours = std::chrono::duration_cast<std::chrono::hours>(duration) % 24;
    auto minutes = std::chrono::duration_cast<std::chrono::minutes>(duration) % 60;
    auto seconds = std::chrono::duration_cast<std::chrono::seconds>(duration) % 60;

    std::cout << "Time Elapsed: " << days.count() << " days, "
              << hours.count() << " hours, "
              << minutes.count() << " minutes, "
              << seconds.count() << " seconds." << std::endl;

    auto years = std::chrono::duration_cast<std::chrono::years>(days);
    days -= std::chrono::duration_cast<std::chrono::days>(years);

    auto months = std::chrono::duration_cast<std::chrono::months>(days);
    days -= std::chrono::duration_cast<std::chrono::days>(months);

    std::cout << "Time Elapsed (in day month year): " << days.count() << " days "
              << months.count() << " months "
              << years.count() << " years." << std::endl;
}

int main() {
    // Enter the date (day month year)
    std::cout << "Enter the date (day month year): ";
    int day, month, year;
    std::cin >> day >> month >> year;

    // Get the current date and time
    std::chrono::system_clock::time_point now = std::chrono::system_clock::now();
    time_t now_time = std::chrono::system_clock::to_time_t(now);
    struct tm* now_tm = std::localtime(&now_time);

    // Set the target date and time
    struct tm target_tm;
    target_tm.tm_year = year - 1900;
    target_tm.tm_mon = month - 1;
    target_tm.tm_mday = day;
    target_tm.tm_hour = 0;
    target_tm.tm_min = 0;
    target_tm.tm_sec = 0;

    // Calculate the time difference between the current date and the target date
    time_t target_time = std::mktime(&target_tm);
    std::chrono::duration<long long> diff_seconds = std::chrono::duration<long long>(now_time - target_time);

    // Print the entered date and the current date
    std::cout << "Entered Date: " << std::setfill('0') << std::setw(2) << day << "." << std::setfill('0') << std::setw(2) << month << "." << year << std::endl;
    std::cout << "Current Date: " << std::put_time(now_tm, "%d.%m.%Y") << std::endl;

    // Print the day of the week for the target date
    int dayOfWeek = calculateDayOfWeek(day, month, year % 100, year / 100);
    std::string dayName = getDayOfWeek(dayOfWeek);
    std::cout << "The entered date falls on a " << dayName << "." << std::endl;

    // Print the number of days, hours, minutes, and seconds elapsed
    printTimeElapsed(diff_seconds);

    // Get the zodiac sign for the target date
    std::string zodiacSign = getZodiacSign(month, day);
    if (!zodiacSign.empty()) {
        std::cout << "Zodiac Sign: " << zodiacSign << std::endl;
    } else {
        std::cout << "Could not determine the Zodiac Sign for the entered date." << std::endl;
    }

    return 0;
}
