#include <iostream>
#include "String.h"

int main() {
    int aCnt = 0, eCnt = 0, iCnt = 0, oCnt = 0, uCnt = 0,
        theCnt = 0, itCnt = 0, wdCnt = 0, notVowel = 0;

    String buf, the( "the" ), it( "it" ), break_pt( "break_pt" );
    while ( std::cin >> buf ) {
        if ( buf == break_pt ) {
            break;
        }
        
        wdCnt++;
        std::cout << buf << ' ';

        if ( wdCnt % 12 == 0 ) {
            std::cout << std::endl;
        }

        if ( buf == it || buf == "It" ) {
            itCnt++;
        } else if ( buf == the || buf == "The" ) {
            theCnt++;
        }

        for ( int index = 0; index < buf.size(); index++ ) {
            switch ( buf[index] ) {
                case 'a': case 'A': aCnt++; break;
                case 'e': case 'E': eCnt++; break;
                case 'i': case 'I': iCnt++; break;
                case 'o': case 'O': oCnt++; break;
                case 'u': case 'U': uCnt++; break;
                default: notVowel++; break;
            }
        }
    }

    std::cout << "\n\n"
        << "Words: " << wdCnt << "\n\n"
        << "the/The: " << theCnt << '\n'
        << "it/It: " << itCnt << "\n\n"
        << "consonant: " << notVowel << "\n\n"
        << "a: " << aCnt << '\n'
        << "e: " << eCnt << '\n'
        << "i: " << iCnt << '\n'
        << "o: " << oCnt << '\n'
        << "u: " << uCnt << std::endl;

    system("pause");
    return 0;
}