#include "main.h"
/**
 * **strtow - splits a string into words. Repeat delimiters are ignored
 * @str: the input string
 * @d: the delimiter string
 * Return: a pointer to an array of strings, or NULL on failure
 */
char **strtow(char *str, char *d)
{
    int i, j, k, numwords = 0;
    char **s;

    if (str == NULL || str[0] == '\0')
        return (NULL);

    if (d == NULL)
        d = " ";

    /* count the number of words in the input string */
    for (i = 0; str[i] != '\0'; i++)
    {
        if (!is_delim(str[i], d) && (is_delim(str[i + 1], d) || str[i + 1] == '\0'))
            numwords++;
    }

    if (numwords == 0)
        return (NULL);

    /* allocate memory for the array of words */
    s = malloc((numwords + 1) * sizeof(char *));
    if (!s)
        return (NULL);

    /* split the input string into words and store them in the array */
    for (i = 0, j = 0; j < numwords; j++)
    {
        /* skip any leading delimiters */
        while (is_delim(str[i], d))
            i++;

        /* calculate the length of the current word */
        k = 0;
        while (!is_delim(str[i + k], d) && str[i + k] != '\0')
            k++;

        /* allocate memory for the current word */
        s[j] = malloc((k + 1) * sizeof(char));
        if (!s[j])
        {
            /* if memory allocation fails, free all previously allocated memory */
            for (k = 0; k < j; k++)
                free(s[k]);
            free(s);
            return (NULL);
        }

        /* copy the current word into the array */
        for (k = 0; !is_delim(str[i + k], d) && str[i + k] != '\0'; k++)
            s[j][k] = str[i + k];
        s[j][k] = '\0';

        /* move to the next word */
        i += k;
    }

    s[numwords] = NULL;
    return (s);
}
