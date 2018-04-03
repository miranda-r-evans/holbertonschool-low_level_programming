#include "holberton.h"

/**
 * rot13 - encrypt a string to rot13
 * @str: string to be encrypted
 *
 * Return: pointer to string
 */
char *rot13(char *str)
{
        char *ptr = str;

        while (*ptr != '\0')
        {
                if ((*ptr >= 'a' && *ptr <= 'm')
                    || (*ptr >= 'A' && *ptr <= 'M'))
                        *ptr += 13;
                else if (*ptr >= 'n' && *ptr <= 'z')
                        *ptr = 'a' + *ptr - 'n';
                else if (*ptr >= 'N' && *ptr <= 'Z')
                        *ptr = 'A' + *ptr - 'N';

                ptr++;
        }

        return (str);
}
