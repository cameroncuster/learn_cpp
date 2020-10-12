/** **************************************************************************
 * @file    
 *
 * @brief   The declaration of the singly linked list for a list that
 *          is sorted.
 ****************************************************************************/
#include <iostream>
#include <string>
using std::ostream;
using std::string;
using std::nothrow;
/*****************************************************************************
 * do not edit this file
 ****************************************************************************/

/** **************************************************************************
 * @class   sortedSingle
 *
 * @brief   A sorted singly linked list of integers.
 ****************************************************************************/
class sortedSingle
{
    public:

    // do not write.
    sortedSingle( sortedSingle &l );

    // file sortedSinglea.cpp
    sortedSingle( );
    ~sortedSingle( );
    bool find( int item );
    int retrievePosition( int item );
    int size( );
    bool empty( );

    // file sortedSingleb.cpp
    bool insert( int item );
    void print( ostream &out, string seperator = ", " );

    // file sortedSinglec.cpp
    bool remove( int item );
    void clear( );


    private:

    /** 
     * @brief  the storage container for each item in the list 
     */
    struct node
    {

        int theItem;    /*!< the item */
        node *next;     /*!< pointer to the remaining nodes in list */
    };
    node *headptr;      /*!< The location of the first node in the list */
};