#include "main.h"
/**

str_length - returns the length of a string
@str: the string whose length to check
Return: integer length of string
*/
int str_length(const char *str)
{
    int len = 0;
    while (*str++)
        len++;
    return len;
}
/**

string_compare - performs lexicographic comparison of two strings.
@str1: the first string
@str2: the second string
Return: negative if str1 < str2, positive if str1 > str2, zero if str1 == str2
*/
int string_compare(const char *str1, const char *str2)
{
    while (*str1 && *str2)
    {
        if (*str1 != *str2)
            return (*str1 - *str2);
        str1++;
        str2++;
    }
    if (*str1 == *str2)
        return 0;
    else
        return (*str1 < *str2 ? -1 : 1);
}
/**

string_starts_with - checks if needle starts with haystack
@haystack: string to search
@needle: the substring to find
Return: pointer to the next character of haystack or NULL
*/
const char *string_starts_with(const char *haystack, const char *needle)
{
    while (*needle)
    {
        if (*needle != *haystack)
            return NULL;
        needle++;
        haystack++;
    }
    return haystack;
}
/**

string_concatenate - concatenates two strings
@dest: the destination buffer
@src: the source buffer
Return: pointer to destination buffer
*/
char *string_concatenate(char *dest, const char *src)
{
    char *ret = dest;
    while (*dest)
        dest++;
    while ((*dest++ = *src++))

        return ret;
}