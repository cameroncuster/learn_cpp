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
void permute( int soln[], bool used[], int n, int pos );

int main( int argc, char *argv[] )
{
    ifstream fin;
    string header;
    vector<rune> glyph;
    int soln[3] = { 0 };
    bool used[3] = { false };
    int count = 0;
    int pos = 0;

    if( argc != 2 )
    {
        cout << "m0100.exe csvdatafile";
        exit( 0 );
    }

    fin.open( argv[1] );
    if( !fin.is_open( ) )
    {
        cout << " Unable to open: " << argv[1];
        exit( 0 );
    }

    getline( fin, header );

    read( fin, glyph );

    permute( soln, used, glyph.size( ), pos );

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
        else if( tempString == "Essence" )
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

void permute( int soln[], bool used[], int n, int pos )
{
    int i;

    if( pos == n )
    {
        for( i = 0; i < n; i++ )
        {
            cout << soln[i] << " ";
        }
        cout << endl;
        return;
    }

    for( i = 0; i < n; i++ )
    {
        if( used[i] == false )
        {
            soln[pos] = i;
            used[i] = true;
            permute( soln, used, n, pos + 1 );
            used[i] = false;
        }
    }
}