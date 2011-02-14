/*
**  PNG Optimizer
**
**  Author:		Charlie Chen
**  Website:	http://www.CharmySoft.com/
*/

#include <iostream>
#include <fstream>
#include <string.h>

using namespace std;

/* ------------------------ *\
Print help information (manual)
\* ------------------------ */
void help(){
    cout << "PNG Optimizer" << endl;
    cout << "--------------" << endl;
    cout << "	CharmySoft.com" << endl;
    cout << "--------------" << endl;
    cout << "Usage: pngc [files...]" << endl;
    cout << "<to compress files>" << endl;
    cout << "--------------" << endl;
    cout << "Warning: this will remove all unnecessary chunks. Backup before use." << endl;
    cout << "After compression, only the following chunks will be left:" << endl;
    cout << " * IHDR" << endl;
    cout << " * IDAT" << endl;
    cout << " * PLTE" << endl;
    cout << " * tRNS" << endl;
    cout << " * IEND" << endl;
    cout << "Any other chunks will be removed. This can loslessly reduce the PNG file size." << endl;
}


#ifndef TYPE_U8U16U32
#define TYPE_U8U16U32
typedef unsigned char   U8;
typedef unsigned short  U16;
typedef unsigned int    U32;
#endif

struct PNG_chunk_head{
    U32 length;
    U32 type;
};

#define TEMP_FILE_NAME_SUFFIX "_temp_c_"

/* ------------------------ *\
Compress the PNG file
\* ------------------------ */
bool compressPNG(char* fileName){
    cout << "Compressing file " << fileName << endl;
    int saved_size = 0;
    ifstream file;
    file.open(fileName, ios::in | ios::binary);
    if(!file.is_open()){
         cerr << "Error opening the file " << fileName << endl;
         return false;
    }
    else{
        char fileHeader[8];
        const char fileSignature[] = { 137, 80, 78, 71, 13, 10, 26, 10 };
        file.read(fileHeader, 8);

        // The first eight bytes of a PNG file should always contain the signature;
        if(memcmp(fileHeader, fileSignature, 8) != 0){
            cerr << "Error: Invalid PNG file. " << fileName << endl;
            return false;
        }

        // write output to a temporary file
        ofstream output;
        output.open(string(fileName).append(TEMP_FILE_NAME_SUFFIX).c_str(), ios::out | ios::binary);
        if(!output.is_open()){
            cerr << "Error creating the temporary file." << endl;
            return false;
        }
        output.write(fileSignature, 8);

        while(true){
            PNG_chunk_head chunk;
            file.read((char *)&chunk, 8);

            // strangely, the length value is seemingly stored in reverse order by bytes???
            // This is a workaround to get the correct length by reversing the order of the bytes
            // Can't think of any better way for now.
            chunk.length =
            (chunk.length & 0xff000000) >> 24 |
            (chunk.length & 0x00ff0000) >> 8 |
            (chunk.length & 0x0000ff00) << 8 |
            (chunk.length & 0x000000ff) << 24;


            if(chunk.type != *(U32*)"IHDR" && chunk.type != *(U32*)"PLTE" && chunk.type != *(U32*)"IEND"
                && chunk.type != *(U32*)"tRNS" && chunk.type != *(U32*)"IDAT"){
                // Leave out any other chunks except IHDR, PLTE, tRNS, IDAT and IEND
                char type_name[5];
                type_name[4] = 0;
                memcpy(type_name, &chunk.type, 4);
                cout << "Removing chunk " << type_name << ", " << chunk.length << " bytes saved" << endl;
                saved_size += chunk.length;
                //  The length counts only the data field, +4 because there's a 4-byte CRC followed by it.
                file.seekg(chunk.length + 4, ios_base::cur);

            } else{
                // Necessary chunks, write to new file
                file.seekg(-8, ios_base::cur);
                char* chunkBuffer = new char[chunk.length + 12];
                file.read(chunkBuffer, chunk.length + 12);
                output.write(chunkBuffer, chunk.length + 12);
                delete [] chunkBuffer;
                if(chunk.type == *(U32*)"IEND"){
                    // IEND marks the end of a PNG file
                    break;
                }
            }
        }
        file.close();
        output.close();
        remove(fileName);
        rename(string(fileName).append(TEMP_FILE_NAME_SUFFIX).c_str(), fileName);
        cout << "Finished! " << saved_size << " bytes in total saved!" << endl;
        return true;
    }
}

int main(int argc, char* argv[])
{
    if (argc <= 1) {
        //If not enough parameters have been passed, print help info.
        help();
    } else {
        for (int i = 1; i < argc; i++) {
            compressPNG(argv[i]);
        }
    }
    cin.get();
    return 0;
}


