#include <stdio.h>
#include <ctype.h>

double atof(char s[]);

double atof(char s[]) {
    double val, power, epower_tens;
    int i, sign, pwr_sign, epower;
    epower_tens = 1;

    for (i = 0; isspace(s[i]); i++)
        ;
    sign = (s[i] == '-') ? -1 : 1;
    if (s[i] == '+' || s[i] == '-')
        i++;
    for (val = 0.0; isdigit(s[i]); i++)
        val = 10.0 * val + (s[i] - '0');
    if (s[i] == '.')
        i++;
    for (power = 1.0; isdigit(s[i]); i++) {
        val = 10.0 * val + (s[i] - '0');
        power *= 10.0;
    }
    if (s[i] == 'e' || s[i] == 'E') {
        i++;
        if (isdigit(s[i]))
            pwr_sign = 1;
        else if (s[i] == '-') {
            pwr_sign = 0;
            i++;
        }
        else if (s[i] == '+') {
            pwr_sign = 1;
            i++;
        }
        for (epower = 0.0; isdigit(s[i]); i++)
            epower =  10.0 * epower + (s[i] - '0');
        for (int x = 0; x < epower; ++x)
            epower_tens *= 10;

    }
    double multiplier = pwr_sign ? epower_tens : (1/epower_tens);
    return (sign * val / power) * multiplier;
}