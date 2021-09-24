//
// Created by Joe on 9/24/2021.
//

#ifndef IBMI_HELPDESK_ARRAYDB_H
#define IBMI_HELPDESK_ARRAYDB_H

#endif //IBMI_HELPDESK_ARRAYDB_H
#include "strcmp.h"

/*
    cmdSearch accepts the users input as it's only parameter.
    After changing the case of userInput we loop over the
    commands array, if a match is found the index is returned,
    otherwise negative one will be returned.
 */

char commands[13][20] =
        {
                "LC",
                "STRPDM",
                "CRTPF",
                "CRTSRCPF",
                "DSPFD",
                "DSPFFD",
                "DSPMSG",
                "DSPOBJD",
                "RNMOBJ",
                "STRSEU",
                "WRKMBRPDM",
                "WRKOBJPDM",
                "E"
        };

int cmdSearch (char *userInput)
{
    int cmdIndex = -1;

    // changing case to match above array
    for (int i = 0; i < strlen(userInput); i++)
    {
        userInput[i] = toupper(userInput[i]);
    };

    // looping over known cmds and entering them into my_strcmp
    // comments for my_strcmp can be found at the top of strcmp.h
    for (int j = 0; j < sizeof(commands) / sizeof(commands[0]); j++)
    {
        if (my_strcmp(userInput, commands[j]) == 10)
        {
            cmdIndex = j;
            break;
        }

    };
    return cmdIndex;
}

int displayCmds(void)
{
    for (int k = 0; k < sizeof(commands) / sizeof(commands[0]); k++)
    {
        if (k == 12) // breaks out before display exit case
            break;
        printf("-- %s\n", commands[k]);
    }
    return 0;
}
