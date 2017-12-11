/***************************************************

Name:Pua Jun Ming

ID: 1141128767

Email: junming0000@gmail.com ; Phone: 017-9824232

***************************************************/



#include "LinkedList.h"
#include <cassert>

template<class ItemType>
LinkedList<ItemType>::LinkedList() : headPtr(nullptr), itemCount(0)
{
}  // end default constructor

//COPY CONSTRUCTOR
template<class ItemType>
LinkedList<ItemType>::LinkedList(const LinkedList<ItemType>& aList) : itemCount(aList.itemCount)
{
   Node<ItemType>* origChainPtr = aList.headPtr;  // Points to nodes in original chain

   if (origChainPtr == nullptr)
      headPtr = nullptr;  // Original list is empty
   else
   {
      // Copy first node
      headPtr = new Node<ItemType>();
      headPtr->setItem(origChainPtr->getItem());

      // Copy remaining nodes
      Node<ItemType>* newChainPtr = headPtr;      // Points to last node in new chain
      origChainPtr = origChainPtr->getNext();     // Advance original-chain pointer
      while (origChainPtr != nullptr)
      {
         // Get next item from original chain
         ItemType nextItem = origChainPtr->getItem();

         // Create a new node containing the next item
         Node<ItemType>* newNodePtr = new Node<ItemType>(nextItem);

         // Link new node to end of new chain
         newChainPtr->setNext(newNodePtr);

         // Advance pointer to new last node
         newChainPtr = newChainPtr->getNext();

         // Advance original-chain pointer
         origChainPtr = origChainPtr->getNext();
      }  // end while

      newChainPtr->setNext(nullptr);              // Flag end of chain
   }  // end if
}  // end copy constructor

//DESTRUCTOR
template<class ItemType>
LinkedList<ItemType>::~LinkedList()
{
   clear();
}  // end destructor

template<class ItemType>
bool LinkedList<ItemType>::isEmpty() const
{
   return itemCount == 0;
}  // end isEmpty

template<class ItemType>
int LinkedList<ItemType>::getLength() const
{
   return itemCount;
}  // end getLength

template<class ItemType>
bool LinkedList<ItemType>::insert(int newPosition, const ItemType& newEntry)
{
   bool ableToInsert = (newPosition >= 1) && (newPosition <= itemCount + 1);
   if (ableToInsert)
   {
      // Create a new node containing the new entry
      Node<ItemType>* newNodePtr = new Node<ItemType>(newEntry);

      // Attach new node to chain
      if (newPosition == 1)
      {
         // Insert new node at  beginning of chain
         newNodePtr->setNext(headPtr);
         headPtr = newNodePtr;
      }
      else
      {
         // Find node that will be before new node
         Node<ItemType>* prevPtr = getNodeAt(newPosition - 1);

         // Insert new node after node to which prevPtr points
         newNodePtr->setNext(prevPtr->getNext());
         prevPtr->setNext(newNodePtr);
      }  // end if

      itemCount++;  // Increase count of entries
   }  // end if

   return ableToInsert;
}  // end insert


template<class ItemType>
bool LinkedList<ItemType>::sortedInsertDesc(const ItemType& newEntry)
{

    if (isEmpty())
    {
        insert(1, newEntry);
    }
    else
    {

        int i = 1;
        if (newEntry->getscorePercentage() > retrieve(1)->getscorePercentage())
        {
            insert(1, newEntry);
        }
        else
        {
            while (i < 10)
            {

                if ((newEntry->getscorePercentage() <= retrieve(i)->getscorePercentage() ) && (newEntry->getscorePercentage() >= retrieve(i+1)->getscorePercentage() ) )
                {

                    insert(i+1, newEntry);
                    return true;
                }
                i++;
            }

        insert(i+1, newEntry);
        }


    }
    return true;
}










template<class ItemType>
bool LinkedList<ItemType>::erase(int position)
{
   bool ableToRemove = (position >= 1) && (position <= itemCount);
   if (ableToRemove)
   {
      Node<ItemType>* curPtr = nullptr;
      if (position == 1)
      {
         // Remove the first node in the chain
         curPtr = headPtr; // Save pointer to node
         headPtr = headPtr->getNext();
      }
      else
      {
         // Find node that is before the one to delete
         Node<ItemType>* prevPtr = getNodeAt(position - 1);

         // Point to node to delete
         curPtr = prevPtr->getNext();

         // Disconnect indicated node from chain by connecting the
         // prior node with the one after
         prevPtr->setNext(curPtr->getNext());
      }  // end if

      // Return node to system
      curPtr->setNext(nullptr);
      delete curPtr;
      curPtr = nullptr;

      itemCount--;  // Decrease count of entries
   }  // end if

   return ableToRemove;
}  // end erase

template<class ItemType>
void LinkedList<ItemType>::clear()
{
   while (!isEmpty())
      erase(1);
}  // end clear


//sjow the num of ques
template<class ItemType>
ItemType LinkedList<ItemType>::retrieve(int position) const throw(PrecondViolatedExcep)
{
   // Enforce precondition
   bool ableToGet = (position >= 1) && (position <= itemCount);
   if (ableToGet)
   {
      Node<ItemType>* nodePtr = getNodeAt(position);
      return nodePtr->getItem();
   }
   else
   {
      string message = "retrieve() called with an empty list or ";
      message  = message + "invalid position.";
      throw(PrecondViolatedExcep(message));
   }  // end if
}  // end retrieve

//change data
template<class ItemType>
void LinkedList<ItemType>::setEntry(int position, const ItemType& newEntry) throw(PrecondViolatedExcep)
{
   // Enforce precondition
   bool ableToSet = (position >= 1) && (position <= itemCount);
   if (ableToSet)
   {
      Node<ItemType>* nodePtr = getNodeAt(position);
      nodePtr->setItem(newEntry);
   }
   else
   {
      string message = "setEntry() called with an invalid position.";
      throw(PrecondViolatedExcep(message));
   }  // end if
}  // end setEntry

template<class ItemType>
Node<ItemType>* LinkedList<ItemType>::getNodeAt(int position) const
{
   // Debugging check of precondition
   assert( (position >= 1) && (position <= itemCount) );

   // Count from the beginning of the chain
   Node<ItemType>* curPtr = headPtr;
   for (int skip = 1; skip < position; skip++)
      curPtr = curPtr->getNext();

   return curPtr;
}  // end getNodeAt

template<class ItemType>
void LinkedList<ItemType>::randomize()
{
    srand(time(0));
    int counter = 1;
    for (int a=1; a<itemCount; a++)
    {
        Node<ItemType>* oriPtr = headPtr;
        Node<ItemType>* chgPtr = headPtr;
        for (int b=1; b < counter ; b++)
        {
            oriPtr = oriPtr->getNext();
        }
        int shuffleCounter = (rand()% itemCount)+1;
        for( int c = 1; c< shuffleCounter ; c++)
        {
            chgPtr = chgPtr->getNext();
        }
        Node<ItemType>* temp = new Node<ItemType>(oriPtr->getItem());
        oriPtr->setItem(chgPtr->getItem());
        chgPtr->setItem(temp->getItem());
    }
}

/*bool LinkedList<ItemType>:operator>= (ItemType highScore1, ItemType highScore2)
{
    return highScore1>=highScore2;
}

bool LinkedList<ItemType>:operator<= (ItemType highScore1, ItemType highScore2)
{
    return highScore1<=highScore2;
}

bool LinkedList<ItemType>:operator> (ItemType highScore1, ItemType highScore2)
{
    return highScore1>highScore2;
}*/




