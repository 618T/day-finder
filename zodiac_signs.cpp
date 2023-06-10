#include <string>

std::string determineZodiacSign(int day, int month) {
    std::string zodiacSign;
    switch (month) {
        case 1:
            if (day >= 20)
                zodiacSign = "Aquarius";
            else
                zodiacSign = "Capricorn";
            break;
        case 2:
            if (day >= 19)
                zodiacSign = "Pisces";
            else
                zodiacSign = "Aquarius";
            break;
        case 3:
            if (day >= 21)
                zodiacSign = "Aries";
            else
                zodiacSign = "Pisces";
            break;
        case 4:
            if (day >= 20)
                zodiacSign = "Taurus";
            else
                zodiacSign = "Aries";
            break;
        case 5:
            if (day >= 21)
                zodiacSign = "Gemini";
            else
                zodiacSign = "Taurus";
            break;
        case 6:
            if (day >= 21)
                zodiacSign = "Cancer";
            else
                zodiacSign = "Gemini";
            break;
        case 7:
            if (day >= 23)
                zodiacSign = "Leo";
            else
                zodiacSign = "Cancer";
            break;
        case 8:
            if (day >= 23)
                zodiacSign = "Virgo";
            else
                zodiacSign = "Leo";
            break;
        case 9:
            if (day >= 23)
                zodiacSign = "Libra";
            else
                zodiacSign = "Virgo";
            break;
        case 10:
            if (day >= 23)
                zodiacSign = "Scorpio";
            else
                zodiacSign = "Libra";
            break;
        case 11:
            if (day >= 22)
                zodiacSign = "Sagittarius";
            else
                zodiacSign = "Scorpio";
            break;
        case 12:
            if (day >= 22)
                zodiacSign = "Capricorn";
            else
                zodiacSign = "Sagittarius";
            break;
        default:
            zodiacSign = "Invalid Date";
            break;
    }
    return zodiacSign;
}
