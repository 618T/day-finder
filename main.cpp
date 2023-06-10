#include <iostream>
#include <sstream>
#include <chrono>
#include <iomanip>

struct TimeElapsed {
    int years;
    int months;
    int days;
};

TimeElapsed calculateTimeElapsed(const std::chrono::system_clock::time_point& start, const std::chrono::system_clock::time_point& end) {
    TimeElapsed elapsed;

    std::chrono::duration<double> diff = end - start;
    double totalDays = diff.count() / (60 * 60 * 24);
    elapsed.years = totalDays / 365;
    elapsed.months = (totalDays - (elapsed.years * 365)) / 30;
    elapsed.days = totalDays - (elapsed.years * 365) - (elapsed.months * 30);

    return elapsed;
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

    // Get the target date
    std::tm target_tm = *std::localtime(new std::time_t{0});
    target_tm.tm_mday = day;
    target_tm.tm_mon = month - 1;
    target_tm.tm_year = year - 1900;
    std::chrono::system_clock::time_point target = std::chrono::system_clock::from_time_t(std::mktime(&target_tm));

    // Calculate the time elapsed
    TimeElapsed elapsed = calculateTimeElapsed(target, now);

    // Print the entered date and the current date
    std::cout << "Entered Date: " << std::setfill('0') << std::setw(2) << day << "." << std::setfill('0') << std::setw(2) << month << "." << year << std::endl;
    std::time_t now_time = std::chrono::system_clock::to_time_t(now);
    std::cout << "Current Date: " << std::put_time(std::localtime(&now_time), "%d.%m.%Y") << std::endl;

    // Print the time elapsed
    auto duration = std::chrono::duration_cast<std::chrono::hours>(now - target);
    int hours = duration.count() % 24;
    int days = duration.count() / 24;

    std::cout << "----------------------------------" << std::endl;
    std::cout << "Time Elapsed: " << days << " days, " << hours << " hours." << std::endl;
    std::cout << "Time Elapsed (in year month day): " << elapsed.years << " years, " << elapsed.months << " months, " << elapsed.days << " days." << std::endl;
    std::cout << "----------------------------------" << std::endl;

    return 0;
}
