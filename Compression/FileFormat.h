#include <fstream>

class FileFormat
{
public:
    FileFormat(char * name) : fname(name) {

        FILE * compr;
        compr=fopen("pcasm-book.pdf","rb");
        long lSize;
        fseek (compr , 0 , SEEK_END);
        lSize = ftell (compr);
        rewind (compr);
        unsigned char buffer[lSize];
        //buffer = (unsigned char*) malloc (sizeof(char)*lSize);
        fread (buffer,1,lSize,compr);
    }

    ~FileFormat() {}
private:
    //FILE * fptr;
    char * fname;
};
