//---------------------------------------------------------------------------

#pragma hdrstop

//---------------------------------------------------------------------------

#pragma argsused

#include <iostream.h>
#include <conio.h>
#include <string.h>
#include <stdio.h>

#include "CRC.h"

void main()
{
char saisie[10];        // Tableau stockant la saisie

printf("Veuillez saisir votre trame (2 octets en hexadecimal): ");
gets(saisie);


Crc monCrc(saisie);



monCrc.calculerCrc();
printf("%x",monCrc.getCrc());

getch();
}
//---------------------------------------------------------------------------
 