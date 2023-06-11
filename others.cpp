#include <ctime>


int determineHijriYear(const std::tm& date) {
    int year = date.tm_year + 1900;
    int month = date.tm_mon + 1;
    int day = date.tm_mday;

    int gregorianYear = year;
    int hijriYear = 0;

    if (gregorianYear >= 622) {
        hijriYear = gregorianYear - 622;
    } else {
        hijriYear = gregorianYear + 378;
    }

    return hijriYear;
}

std::string determineChineseZodiac(int year) {
    std::string chineseZodiac;

    switch ((year - 1900) % 12) {
        case 0: chineseZodiac = "Monkey"; break;
        case 1: chineseZodiac = "Rooster"; break;
        case 2: chineseZodiac = "Dog"; break;
        case 3: chineseZodiac = "Pig"; break;
        case 4: chineseZodiac = "Rat"; break;
        case 5: chineseZodiac = "Ox"; break;
        case 6: chineseZodiac = "Tiger"; break;
        case 7: chineseZodiac = "Rabbit"; break;
        case 8: chineseZodiac = "Dragon"; break;
        case 9: chineseZodiac = "Snake"; break;
        case 10: chineseZodiac = "Horse"; break;
        case 11: chineseZodiac = "Sheep"; break;
    }

    return chineseZodiac;
}
