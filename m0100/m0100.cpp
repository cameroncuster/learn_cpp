#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

enum trait
{
    POTENCY,
    ESSENCE,
    ASPECT
};

struct rune
{
    string name;
    trait type;
};

void read( ifstream &fin, vector<rune> &glyph );

int main( int argc, char *argv[] )
{
    ifstream fin;
    string header;
    vector<rune> glyph;

    fin.open( argv[1] );
    if( !fin.is_open( ) )
    {
        cout << "Unable to open: " << argv[1];
        exit( 0 );
    }

    getline( fin, header );

    read( fin, glyph );
    for( int i = 0; i < glyph.size( ); i++ )
    {
        cout << glyph[i].name << ' ';
        cout << glyph[i].type << endl;
    }

    return 0;
}

void read( ifstream &fin, vector<rune> &glyph )
{
    rune temp;
    string tempString;
    while( getline( fin, tempString) )
    {
        temp.name = tempString.substr( 0, tempString.find(',') );
        tempString = tempString.erase( 0, tempString.find( ',' ) + 1 );
        if( tempString == "Potency" )
        {
            temp.type = POTENCY;
        }
        else if( tempString == "Essenece" )
        {
            temp.type = ESSENCE;
        }
        else if( tempString == "Aspect" )
        {
            temp.type = ASPECT;
        }
        glyph.push_back( temp );
    }
}
