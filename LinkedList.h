/***************************************************

Name:Pua Jun Ming

ID: 1141128767

Email: junming0000@gmail.com ; Phone: 017-9824232

***************************************************/


#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "PrecondViolateExcep.h"
#include "Node.h"
#include <ctime>
#include <cstdlib>

template<class ItemType>
class LinkedList
{
private:
   Node<ItemType>* headPtr; // Pointer to first node in the chain;
                            // (contains the first entry in the list)
   int itemCount;           // Current count of list items

   // Locates a specified node in this linked list.
   // @pre  position is the number of the desired node;
   //       position >= 1 and position <= itemCount.
   // @post  The node is found and a pointer to it is returned.
   // @param position  The number of the node to locate.
   // @return  A pointer to the node at the given position.
   Node<ItemType>* getNodeAt(int position) const;
   //friend bool operator>= (ItemType highScore1, ItemType highScore2);
  // friend bool operator<= (ItemType highScore1, ItemType highScore2);
   // friend bool operator> (ItemType highScore1, ItemType highScore2);


public:
   LinkedList();
   LinkedList(const LinkedList<ItemType>& aList);
   virtual ~LinkedList();

   bool isEmpty() const;
   int getLength() const;
   bool insert(int newPosition, const ItemType& newEntry);
   bool erase(int position);
   void randomize();
   bool sortedInsertDesc( const ItemType& newEntry);
   void clear();

   /** @throw PrecondViolatedExcep if position < 1 or
                                      position > getLength(). */
   ItemType retrieve(int position) const throw(PrecondViolatedExcep);

   /** @throw PrecondViolatedExcep if position < 1 or
                                      position > getLength(). */
   void setEntry(int position, const ItemType& newEntry)
                               throw(PrecondViolatedExcep);
}; // end LinkedList


#include "LinkedList.cpp"
#endif // LINKEDLIST_H
