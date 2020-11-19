//---------------------------------------------------------------------------

#ifndef CRCH
#define CRCH

class Crc
{
private:
        unsigned int leCrc;
        unsigned int trame;
public:
        Crc();
        Crc(char*);
        ~Crc();
        void calculerCrc();
        unsigned int getCrc() {return(leCrc);}
};

//---------------------------------------------------------------------------
#endif
