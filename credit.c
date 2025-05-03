#include <stdio.h>
#include "cs50.h"

int main(void)
{
    // получаем номер карты пользователя
    long long userNumber;
    userNumber = get_long("Please, enter the card number: \n");

    long long originalNumber = userNumber; // копия оригинального номера карты;

    // определяем первые две цифры
    long long firstDigits = originalNumber;
    while (firstDigits >= 100)
    {
        firstDigits /= 10;
    }

    // переменные для проверки по методу Луна
    int summEven = 0;
    int sumNoEven = 0;
    int digitPosition = 1;

    // обработка номера карты
    while (userNumber > 0)
    {
        int currentDigit = userNumber % 10;
        if (digitPosition % 2 == 0)
        {
            int multiplication = currentDigit * 2;
            summEven += (multiplication / 10) + (multiplication % 10);
        }
        else
        {
            sumNoEven += currentDigit;
        }
        userNumber /= 10;
        digitPosition++;
    }

    int length = digitPosition - 1;

    // проверка по Луну:
    int summTotal = summEven + sumNoEven;
    if (summTotal % 10 == 0)
    {
        if (length == 15 && (firstDigits == 34 || firstDigits == 37))
        {
            printf("AMEX\n");
        }
        else if (length == 16 && (firstDigits >= 51 && firstDigits <= 55))
        {
            printf("MASTERCARD\n");
        }
        else if ((length == 13 || length == 16) && (firstDigits / 10 == 4))
        {
            printf("VISA\n");
        }

        else
        {
            printf("INVALID\n");
        }
    }

    else
    {
        printf("INVALID\n");
    }
}