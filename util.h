#ifndef BILETE_UTIL_H
#define BILETE_UTIL_H

char *intToString(int num) {
    int numDigits = 0, aux;

    aux = num;
    while (aux) {
        numDigits++;
        aux /= 10;
    }

    static char str[1000]; // static ca sa putem returna variabila

    for (int i = numDigits - 1; i >= 0 ; --i) {
        str[i] = '0' + num % 10;
        num /= 10;
    }
    str[numDigits] = '\0';

    return str;
}

#endif //BILETE_UTIL_H
