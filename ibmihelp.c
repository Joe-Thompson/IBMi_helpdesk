#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

#include "arraydb.h"

#define MAX 20

int main(void)
{
	bool running = true;
	char select[MAX];
	int cmdPointer = 0;

	printf("\n\n-----IBM i Command Help Desk-----\n");
	
	while (running)
	{
		printf("\nE: End Program   LC: List Commands   <insert cmd>: Displays Information\n");
		printf("Please enter a command:  ");
		fgets(select, MAX, stdin);

		cmdPointer = cmdSearch(select);

        switch (cmdPointer) {
            case 0:
                displayCmds();
                break;
            case 1:
                printf("\nSTRPDM\n");
                printf("Start Programming Development Manager utility cmd displays the initial PDM menu\n");
                break;
            case 2:
                printf("\nCRTPF\n");
                printf("The Create Physical File cmd can be used to create files\non the client and server systems through the SYSTEM parameter\n\n");
                printf("Parameters:\n");
                printf("REQUIRED -> FILE: Specifies the physical file to be created\n");
                printf("Optional -> SRCFILE (source file): Specifies the source file that contains the DDS that describe the record format and its fields\n");
                printf("Optional -> SRCMBR (source member): Specifies the name of the source file member that contains the DDS for the physical file being created\n");
                printf("\nExample:\n");
                printf("CRTPF FILE(<libname>/<pfname>) SRCFILE() ");
                break;
            case 3:
                printf("\nCRTSRCPF\n");
                printf("The Create Source Physical File cmd creates a source physical file\nA source PF can have one or more members\n");
                break;
            case 4:
                printf("\nDSPFD\n");
                printf("The Display File Description cmd shows one or more types\nof information retrieved from the file descriptions\n\n");
                printf("Parameters:\n");
                printf("REQUIRED -> FILE: Specifies the name and library of the files\n");
                printf("Optional -> TYPE: Specifies the type of file information provided\n");
                printf("Optional -> OUTPUT: Specifies where the output from the cmd is sent\n");
                printf("Optional -> FILEATR (file attributes): Specifies the type of file whose attributes are shown\n");
                printf("Optional -> OUTFILE (file to receive output): Specifies the database file where output is directed\n");
                printf("Optional -> OUTMBR: (out member options): Specifies the name of the database file member that receives the output\n");
                printf("Optional -> SYSTEM: Specifies whether the information is returned is about files on the local system or remote system\n");
                break;
            case 5:
                printf("\nDSPFFD\n");
                printf("The Display File Field Description cmd shows, prints, or places in a database file\nfield-level information for one of more files\n\n");
                printf("Parameters:\n");
                printf("REQUIRED -> FILE: Specifies the files for which field information is returned\n");
                printf("Optional -> OUTPUT: Specifies where the output from the cmd is sent\n");
                printf("Optional -> OUTFILE (file to receive output): Specifies the database file where output is directed, create file if it does not exist\n");
                printf("Optional -> OUTMBR (out member options): Specifies the name of the database file member that receives the output\n");
                printf("Optional -> SYSTEM: Specifies whether the information is returned is about files on the local system or remote system\n");
                break;
            case 6:
                printf("\nDSPMSG\n");
                printf("The Display Messages cmd is used to show the messages received at the specified message queue\n\n");
                printf("Parameters:\n");
                printf("Optional -> MSGQ (message queue): Specifies the message queue from which messages are shown\n");
                printf("Optional -> OUTPUT: Specifies where the output from the cmd is sent\n");
                printf("Optional -> MSGTYPE (message type): Specifies the type of messages in the message queue that are shown\n");
                printf("Optional -> START (messages to display first): Specifies whether the newest messages or oldest messages are shown first\n");
                printf("Optional -> SEV (severity code filter): Specifies the lowest severity leve that a message can have and still be delivered to a user in break or notify mode\n");
                printf("Optional -> ASTLVL (assistance level): Specifies which user interface to display\n");
                break;

            case 7:
                printf("\nDSPOBJD\n");
                printf("The Display Object Description cmd shows the names and attributes of specified objects in a specified library\n\n");
                printf("Parameters:\n");
                printf("REQUIRED -> OBJ (object): Specifies which objects in the library are to have their object attributes shown\n");
                printf("REQUIRED -> OBJTYPE (object type): Specifies which types of objects are shown\n");
                printf("Optional -> DETAIL: Specifies which set of attributes is show for each object\n");
                printf("Optional -> ASPDEV (ASP device): Specifies the auxiliary storage pool device name whe storage is allocated for the library containing the object\n");
                printf("Optional -> OUTPUT: Specifies where the output from the cmd is sent\n");
                printf("Optional -> OUTFILE (file to receive output): Specifies the database file where output is directed, create file if it does not exist\n");
                printf("Optional -> OUTMBR (out member options): Specifies the name of the database file member that receives the output\n");
                break;
            case 8:
                printf("\nRNMOBJ\n");
                printf("The Rename Object cmd changes the name of an object in a library, the new name MUST be unique in the library for the object type\n\n");
                printf("Parameters:\n");
                printf("REQUIRED -> OBJ (object): Specifies the object to be renamed\n");
                printf("REQUIRED -> OBJTYPE (object type): Specifies the object type of the object to be renamed\n");
                printf("REQUIRED -> NEWOBJ (new object): Specifies the new name of the object to be renamed, MUST be unique to the library\n");
                printf("Optional -> ASPDEV (ASP device): Specifies the auxiliary storage pool device name whe storage is allocated for the library containing the object\n");
                printf("Optional -> SYSTEM: Specifies if the rename is to be done on the local system or remote system\n");
                break;
            case 9:
                printf("\nSTRSEU\n");
                printf("The Start Source Entry Utility cmd allows you to create, change, display, or print a source member\n\n");
                printf("Parameters:\n");
                printf("Optional -> SRCFILE (source file): Specifies the names of the source physical file and library that contain member to be edited or created\n");
                printf("Optional -> SRCMBR (source member): Specifies the name of the source physical file member to be edited or created\n");
                printf("Optional -> TYPE: Specifies the type of source member to edit or create\n");
                printf("Optional -> OPTION: Specifies the function to perform on the selected member\n");
                printf("Optional -> TEXT: Specifies a character string that describes the member in the text field for the member\n");
                break;
            case 10:
                printf("\nWRKMBRPDM\n");
                printf("The Work with Members Using PDM cmd enables you to work with a list of members in one database file\n\n");
                printf("Parameters:\n");
                printf("Optional -> FILE: Specifies the database file that contains the member you want to work with\n");
                printf("Optional -> MBR (member): Specifies the member or members you want to work with\n");
                printf("Optional -> MBRTYPE (member type): Specifies the member type for members you want to work with\n");
                break;
            case 11:
                printf("\nWRKOBJPDM\n");
                printf("The Work with Objects Using PDM cmd enables you to work with a list of objects in one library\n\n");
                printf("Parameters:\n");
                printf("Optional -> LIB (library): Specifies the library that contains the objects you want to work with\n");
                printf("Optional -> OBJ (object): Specifies the objects you want to work with\n");
                printf("Optional -> OBJTYPE (object type): Specifies the object type for objects you want to work with\n");
                printf("Optional -> OBJATR (object attribute) Specifies the object attribute for objects you want to work with\n");
                break;
            case 12:
                printf("\n\n***** Thank you for using IBM i Help Desk *****\n\n");
                running = false;
                break;
            default:
                printf("\a\n Invalid entry! Try typing LC for help\n");
                break;
        }
	}

	return 0;
}

