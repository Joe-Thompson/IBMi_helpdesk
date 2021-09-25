//
// Created by Joe on 9/24/2021.
//

#ifndef IBMI_HELPDESK_STRCMP_H
#define IBMI_HELPDESK_STRCMP_H

#endif //IBMI_HELPDESK_STRCMP_H

/*
    my_strcmp function was used from OverLQ.com
    from a tutorial about how to properly compare
    strings.  The expected output of two identical
    strings would be 0, however the result turns out
    to be 10.

    tutorial url -
    https://overiq.com/c-programming-101/the-strcmp-function-in-c/https://overiq.com/c-programming-101/the-strcmp-function-in-c/
 */

int my_strcmp(char *strg1, char *strg2)
{
    while( ( *strg1 != '\0' && *strg2 != '\0' ) && *strg1 == *strg2 )
    {
        strg1++;
        strg2++;
    }

    if(*strg1 == *strg2)
    {
        return 0; // strings are identical
    }

    else
    {
        return *strg1 - *strg2;
    }
}
