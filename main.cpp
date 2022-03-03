// System libraries
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>

// User libraries
#include "lea9.h"

using namespace std;


int main(int argc, char* argv[])
{
    // Local variables
    char buffer[3];
    uint64_t file_size = 0;
    uint64_t max_index = 0;
    uint8_t key[9];

    if(argc == 12){
        // Get arguments
        string filename1 = argv[1];
        string filename2 = argv[2];
        for(int i = 0; i<9; i++){
            key[i] = atoi(argv[i+3]);
        }

        // Open files
        ifstream f1 (filename1, ios::in | ios::binary);
        ofstream f2 (filename2, ios::out | ios::binary);

        // get file length
        if(f1 && f2){
            f1.seekg(0,f1.end);
            file_size = f1.tellg();
            f1.seekg(0,f1.beg);
            cout << "File is " << file_size << " bytes" << endl;

            max_index = (file_size - (file_size % 3))/3;

            // Encrypt
            cout << "Encrypting..." << endl;
            for(uint64_t i = 0; i < max_index; i++){
                if(f1 && f1.read(buffer,3)){
                    crypt(buffer, key);
                    f2.write(buffer,3);
                }else{
                    cout << "Exit here 1" << endl;
                    break;
                }
            }

            // Write last bytes
            for(uint64_t i = 0; i < (file_size%3); i++){
                if(f1 && f1.read(buffer,1)){
                    f2.write(buffer,1);
                }else{
                    cout << "Exit here 1" << endl;
                    break;
                }
            }

            // Closing files
            f1.close();
            f2.close();
            cout << "Done." << endl;
        } else {
            cout << "Error opening file" << endl;
        }

    } else {
        cout << "Incorrect arguments" << endl;
    }

    // Exit
    return (0);
}
