//---------------------------------------------------------------------------

#pragma hdrstop

#include "CRC.h"
#include <stdlib.h>


//---------------------------------------------------------------------------

Crc::Crc()
        {
        leCrc = 0xFFFF;
        trame = 0x020B;
        }

//---------------------------------------------------------------------------

Crc::Crc(char *maTrame)
        {
        leCrc = 0xFFFF;
        try
                {
                trame = strtoul(maTrame, NULL, 16);  // Conversion de la chaine de caracteren en hexadecimal
                trame = trame << 16;
                trame = trame >> 16;               // On evite un surplus de données dans la trame
                }
        catch(...)
                {
                
                }
        }

//---------------------------------------------------------------------------

Crc::~Crc()
        {
        }

//---------------------------------------------------------------------------

void Crc::calculerCrc()
        {
        unsigned int compteurOctet = 0;
        unsigned int compteurBit = 0;
        unsigned int polynome = 0xA001;
        unsigned int octets[2];
        octets[0] = trame >> 8;
        octets[1] = trame & 0x00ff;


        for (compteurOctet = 0; compteurOctet < 2; compteurOctet++)
                {
                leCrc = leCrc ^ octets[compteurOctet];
                for (compteurBit = 0; compteurBit < 8; compteurBit++)
                        {
                        if ( (leCrc & 0x0001) == 1)   // On test si il va y avoir retenue
                                {
                                leCrc = leCrc >> 1; // Decalage a droite
                                leCrc = leCrc ^ polynome;
                                }
                        else
                                {
                                leCrc = leCrc >> 1; // Decalage a droite
                                }
                        }
                }
        octets[0] = leCrc >> 8;
        octets[1] = leCrc & 0x00ff;
        leCrc = (octets[1] << 8) | octets[0]; // On réorganse les données
        }


//---------------------------------------------------------------------------
#pragma package(smart_init)
