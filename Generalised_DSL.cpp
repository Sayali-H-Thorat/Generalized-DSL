#include<iostream>
using namespace std;

////////////////////////////////////////////Structure of Singly LinkedList//////////////////////////////////////////////////////////////////////////////
template <class T>
struct nodeS
{
    T data;
    struct nodeS *next;
};
////////////////////////////////////////////Structure of Doubly LinkedList////////////////////////////////////////////////////////////////////////////////////////
template <class T>
struct nodeD
{
    T data;
    struct nodeD *next;
    struct nodeD *prev;
};
////////////////////////////////////////////Class of Singly Linear LinkedList////////////////////////////////////////////////////////////////////////////////////////
template <class T>
class SinglyLL
{
    public:
        struct nodeS<T> * First;

        SinglyLL();
        void InsertFirst(T no);
        void InsertLast(T no);
        void InsertAtPos(T no,int ipos);

        void DeleteFirst();
        void DeleteLast();
        void DeleteAtPos(int ipos);

        int SearchFirstOccurence(T no);
        int SearchLastOccurence(T no);
        int Addition();
        int Maximum();
        int Minimum();
        int AdditionEven();
        int SecMaximum();
        
        void Display();
        int Count();
};
//////////////////////////////////////////////////////////////////Functions of SinglyLL started here//////////////////////////////////////////////////////////////
//////////////////////////////////////###############################################################////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Constructor Name: SinglyLL()
// Description :  Constructor of Singly linear linkedlist
// Author :       Sayali Hanumant Thorat
// Date :         08/02/2023
//
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
template <class T>
SinglyLL <T> :: SinglyLL()
{
    First = NULL;
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Function Name: InsertFirst()
// Description :  Insert the number at first position
// Input :        Number
// Output :       
// Author :       Sayali Hanumant Thorat
// Date :         08/02/2023
//
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
template <class T>
void SinglyLL <T>:: InsertFirst(T no)
{
    struct nodeS<T> * newn = new nodeS<T>;  

    newn -> data = no;
    newn->next = NULL;

    if(First == NULL)
    {
        First = newn;
    }
    else
    {
        newn->next = First;
        First = newn;
    }
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Function Name: InsertLast()
// Description :  Insert the number at last position
// Input :        Number
// Output :       
// Author :       Sayali Hanumant Thorat
// Date :         08/02/2023
//
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
template <class T>
void SinglyLL <T>:: InsertLast(T no)
{
    struct nodeS<T> * newn = new nodeS<T>;  

    newn -> data = no;
    newn->next = NULL;

    if(First == NULL)
    {
        First = newn;
    }
    else
    {
        struct nodeS<T> * temp = First;

        while(temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newn;
    }
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Function Name: InsertAtPos()
// Description :  Insert the number at position
// Input :        Number and position
// Output :       Insert number at mentioned position
// Author :       Sayali Hanumant Thorat
// Date :         08/02/2023
//
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
template <class T>
void SinglyLL<T>:: InsertAtPos(T no, int ipos)
{
    int NodeCnt = 0, iCnt = 0;

    NodeCnt = Count();

    if((ipos < 1) || (ipos > NodeCnt+1))
    {
        cout<<"Invalid position"<<"\n";
        return;
    }

    if(ipos == 1)
    {
        InsertFirst(no);
    }
    else if(ipos == NodeCnt + 1)
    {
        InsertLast(no);
    }
    else
    {
        struct nodeS<T> * newn = new nodeS<T>;  

        newn->data = no;
        newn->next = NULL;

        struct nodeS<T> * temp = First;  
        for(int iCnt = 1; iCnt < ipos-1; iCnt++)
        {
            temp = temp->next;
        }

        newn->next = temp->next;
        temp->next = newn;
    }

}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Function Name: DeleteFirst()
// Description :  Delete the number at first position
// Input :        
// Output :       Delete the number which is on first position
// Author :       Sayali Hanumant Thorat
// Date :         08/02/2023
//
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
template <class T>
void SinglyLL<T> :: DeleteFirst()
{
    if(First == NULL)   // if(iCount == 0)
    {
        return;
    }
    else if(First -> next == NULL) // else if(iCount == 1)
    {
        delete First;
        First = NULL;
        
    }
    else
    {
        struct nodeS <T>* temp = First;
        First = First -> next;
        delete temp;
     
    }
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Function Name: DeleteLast()
// Description :  Delete the number at last position
// Input :        
// Output :       Delete the number which is present on last position
// Author :       Sayali Hanumant Thorat
// Date :         08/02/2023
//
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
template <class T>
void SinglyLL <T>:: DeleteLast()
{    
    if(First == NULL)   // if(iCount == 0)
    {
        return;
    }
    else if(First -> next == NULL) // else if(iCount == 1)
    {
        delete First;
        First = NULL;
        
    }
    else
    {
        struct nodeS <T> * temp = First;

        while(temp->next->next != NULL)
        {
            temp = temp->next;
        }

        delete temp->next;
        temp->next = NULL;
    }
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Function Name: DeleteAtPos()
// Description :  Delete the number from accepted position
// Input :        position
// Output :       Delete the number from position
// Author :       Sayali Hanumant Thorat
// Date :         08/02/2023
//
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
template <class T>
void SinglyLL <T>:: DeleteAtPos(int ipos)
{
    int NodeCnt = 0, iCnt = 0;

    NodeCnt = Count();

    if((ipos < 1) || (ipos > NodeCnt))
    {
        cout<<"Invalid position"<<"\n";
        return;
    }

    if(ipos == 1)
    {
        DeleteFirst();
    }
    else if(ipos == NodeCnt)
    {
        DeleteLast();
    }
    else
    {
		struct nodeS <T>* temp1 = First;
		struct nodeS <T>* temp2 = First;
		
		for(int iCnt = 1; iCnt < ipos - 1; iCnt++)
		{
			temp1 = temp1->next;
		}
		temp2 = temp1->next;
		
		temp1->next = temp2->next;
		delete temp2;		

    }
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Function Name: Display()
// Description :  Display the elements of LinkedList
// Input :        
// Output :       All elements of linkedlist
// Author :       Sayali Hanumant Thorat
// Date :         08/02/2023
//
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
template <class T>
void SinglyLL<T> :: Display()
{
    struct nodeS<T> * temp = First;

    cout<<"Elements of Linked list are :"<<"\n";
    while(temp != NULL)
    {
        cout<<temp->data<<" ";
        temp = temp -> next;
    }
    cout<<"\n";
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Function Name: Count()
// Description :  Count the number of elements from linkedlist
// Input :        
// Output :       return the count of elements in linkedlist
// Author :       Sayali Hanumant Thorat
// Date :         08/02/2023
//
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
template <class T>
int SinglyLL <T>:: Count()
{
    struct nodeS<T> * temp = First;
    int iCnt = 0;

    while(temp != NULL)
    {
        iCnt++;
        temp = temp -> next;
    }
    return iCnt;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Function Name: SearchFirstOccurence()
// Description :  Search First Occurence of elements from linkedlist
// Input :        
// Output :       index of first occurrence of element in linkedlist
// Author :       Sayali Hanumant Thorat
// Date :         08/02/2023
//
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
template<class T>
int SinglyLL <T> :: SearchFirstOccurence(T No)
{
    struct nodeS<T> * newn = First; 
    int iPos = 0;
	while(newn != NULL)
    {
        if(newn -> data == No)
        {
            return iPos;
        }
        iPos++;
        newn= newn->next;
    }
    return -1;
        
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Function Name: SearchLastOccurence()
// Description :  Search Last Occurence of elements from linkedlist
// Input :        
// Output :       index of Last occurrence of element in linkedlist
// Author :       Sayali Hanumant Thorat
// Date :         08/02/2023
//
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
template<class T>
int SinglyLL <T> :: SearchLastOccurence(T No)
{
    struct nodeS<T> * newn = First; 
    int iPos = 0,iCnt = 0;
	while(newn != NULL)
    {
        
        if(newn->data == No)
        {
          iCnt = iPos;           
        }
        iPos++;
        newn= newn->next;
        
    }
    return iCnt;      
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Function Name: Addition()
// Description :  Addition of all the elements from linkedlist
// Input :        
// Output :       Addition of elements
// Author :       Sayali Hanumant Thorat
// Date :         08/02/2023
//
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
template<class T>
int SinglyLL <T> :: Addition()
{
    struct nodeS<T> * newn = First; 
    int iSum = 0;

    while(newn != NULL)
    {
        iSum = iSum + newn->data;
        newn = newn->next;
    }
    return iSum;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Function Name: Maximum()
// Description :  Maximum element from linkedlist
// Input :        
// Output :       Maximum element in linkedlist
// Author :       Sayali Hanumant Thorat
// Date :         08/02/2023
//
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
template<class T>
int SinglyLL <T> :: Maximum()
{
    struct nodeS<T> * newn = First; 
    int imax = First->data;
     
    while (newn != NULL) 
    {
        if (imax < newn->data)
        {
            imax = newn->data;
        }
        newn = newn->next;
    }
    return imax;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Function Name: Minimum()
// Description :  Minimum element from linkedlist
// Input :        
// Output :       Minimum element in linkedlist
// Author :       Sayali Hanumant Thorat
// Date :         08/02/2023
//
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
template<class T>
int SinglyLL <T> :: Minimum()
{
    struct nodeS<T> * newn = First; 
    int iMin = First->data;
 
    while (newn != NULL) 
    {
        if (iMin > newn->data)
        {
            iMin = newn->data;
        }
        newn = newn->next;
    }
    return iMin;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Function Name: AdditionEven()
// Description :  Addition of Even element from linkedlist
// Input :        
// Output :       Addition of Even element in linkedlist
// Author :       Sayali Hanumant Thorat
// Date :         08/02/2023
//
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
template<class T>
int SinglyLL <T> :: AdditionEven()
{
    struct nodeS<T> * newn = First; 
    int iSum = 0;
	while(newn != NULL)
	{
        if(((newn->data)%2 == 0))
		{
			iSum = iSum + (newn->data);
		}
	   
		newn = newn -> next;
	}
    return iSum;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Function Name: SecMaximum()
// Description :  Second maximum element from linkedlist
// Input :        
// Output :       Second maximum element in linkedlist
// Author :       Sayali Hanumant Thorat
// Date :         08/02/2023
//
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
template<class T>
int SinglyLL <T> :: SecMaximum()
{
	int iMax = 0;
	
	if(First == NULL)
	{
		printf("Linked list is empty\n");
		return 0;
	}
	
	iMax = First->data;
    int SecMax = First->data;
	
    while(First != NULL)
    {
      if (First->data > iMax) 
      {
        SecMax = iMax;
        iMax = First->data;
      }
      else if(First->data > SecMax)
      
        SecMax = First->data;
        First = First->next;         
   }
   return SecMax;	
	
}
//////////////////////////////////////////////////////////////////Functions of SinglyLL Ended here///////////////////////////////////////////////////////
//////////////////////////////////////###############################################################/////////////////////////////////////////////////////
////////////////////////////////////////////Class of Singly Circular LinkedList started here//////////////////////////////////////////////////////////////
template <class T>
class SinglyCL
{
    public:
        struct nodeS<T> * First;
        struct nodeS<T> * Last;

        SinglyCL();
        void InsertFirst(T no);
        void InsertLast(T no);
        void InsertAtPos(T no,int ipos);

        void DeleteFirst();
        void DeleteLast();   
        void DeleteAtPos(int ipos);

        int SearchFirstOccurence(T no);
        int SearchLastOccurence(T no);
        int Addition();
        int Maximum();
        int Minimum();
        int AdditionEven();

        void Display();
        int Count();
};
//////////////////////////////////////////////////////////////////Functions of SinglyCL started here///////////////////////////////////////////////////////
//////////////////////////////////////###############################################################//////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Constructor Name: SinglyCL()
// Description :  Constructor of Singly circular linkedlist
// Author :       Sayali Hanumant Thorat
// Date :         08/02/2023
//
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

template <class T>
SinglyCL <T> :: SinglyCL()
{
    First = NULL;
    Last = NULL;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Function Name: InsertFirst()
// Description :  Insert the number at first position
// Input :        Number
// Output :       
// Author :       Sayali Hanumant Thorat
// Date :         08/02/2023
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
template <class T>
void SinglyCL <T>:: InsertFirst(T no)
{
	struct nodeS<T> * newn = new nodeS<T>;  
	
    newn->data = no;
    newn->next = NULL;

    if((First == NULL) && (Last == NULL))    // Empty LL
    {
       First = Last = newn;
        (Last)->next = First;
    }
    else    // LL contains atleast one node
    {
        newn->next = First;
        First = newn;
        (Last)->next = First;
    }
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Function Name: InsertLast()
// Description :  Insert the number at last position
// Input :        Number
// Output :       
// Author :       Sayali Hanumant Thorat
// Date :         08/02/2023
//
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
template <class T>
void SinglyCL <T>:: InsertLast(T no)
{
	struct nodeS<T> * newn = new nodeS<T>;  
	
    newn->data = no;
    newn->next = NULL;

    if((First == NULL) && (Last == NULL))    // Empty LL
    {
       First = Last = newn;
        (Last)->next = First;
    }
   else    // LL contains atleast one node
    {
        (Last) -> next = newn;
        Last = newn;
        (Last)->next = First;
    }
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Function Name: InsertAtPos()
// Description :  Insert the number at position
// Input :        Number and position
// Output :       Insert number at mentioned position
// Author :       Sayali Hanumant Thorat
// Date :         08/02/2023
//
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
template <class T>
void SinglyCL <T>:: InsertAtPos(T no, int iPos)
{
	int iNodeCnt = 0, iCnt = 0;
    iNodeCnt = Count();
    struct nodeS<T> * newn = new nodeS<T>;
    struct nodeS<T> * temp = First;

    if((iPos < 1) || (iPos > iNodeCnt + 1))
    {
        cout<<"Invalid position"<<"\n";
        return;
    }

    if(iPos == 1)
    {
        InsertFirst(no);
    }
    else if(iPos == iNodeCnt+1)
    {
        InsertLast(no);
    }
    else
    {
		struct nodeS<T> * newn = new nodeS<T>;
		
        newn->data = no;
        newn->next = NULL;

        for(iCnt = 1; iCnt < iPos-1; iCnt++)
        {
            temp = temp->next;
        }

        newn->next = temp->next;
        temp->next = newn;
    }
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Function Name: DeleteFirst()
// Description :  Delete the number at first position
// Input :        
// Output :       Delete the number which is on first position
// Author :       Sayali Hanumant Thorat
// Date :         08/02/2023
//
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
template <class T>
void SinglyCL <T>:: DeleteFirst()
{
	struct nodeS<T> * temp = First;
	
	if((First == NULL) && (Last == NULL))  //Empty LL
	{
		return;
	}
	else if(First == Last)   //Single node in LL
	{
		// free(*First);
		delete(First);
		First = NULL;
		Last = NULL;
		
	}
	else                   // IF LL contains more than one node.
	{
		First = (First) -> next;
		// free(temp);
		delete(temp);
		(Last) -> next = First;
	}
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Function Name: DeleteLast()
// Description :  Delete the number at last position
// Input :        
// Output :       Delete the number which is present on last position
// Author :       Sayali Hanumant Thorat
// Date :         08/02/2023
//
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
template <class T>
void SinglyCL <T> :: DeleteLast()
{
	struct nodeS<T> * temp = First;
	
	if((First == NULL) && (Last == NULL))  //Empty LL
	{
		return;
	}
	else if(First == Last)   //Single node in LL
	{
		// free(*First);
		delete(First);
		First = NULL;
		Last = NULL;
		
	}
	else                   // IF LL contains more than one node.
	{
		while((temp->next) != (Last))
		{
			temp = temp->next;
		}
		// free(temp -> next);   //free(*Last);
		delete(temp -> next);   //free(*Last);
		
		Last = temp;
		(Last)->next = First;
		
		
	}
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Function Name: DeleteAtPos()
// Description :  Delete the number from accepted position
// Input :        position
// Output :       Delete the number from position
// Author :       Sayali Hanumant Thorat
// Date :         08/02/2023
//
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
template <class T>
void SinglyCL<T> :: DeleteAtPos(int iPos)
{
	int iNodeCnt = 0, iCnt = 0;
    iNodeCnt = Count();
    struct nodeS<T> * temp1 =First;
    struct nodeS<T> * temp2 = new nodeS<T>;  

    if((iPos < 1) || (iPos > iNodeCnt))
    {
        cout<<"Invalid position"<<"\n";
        return;
    }

    if(iPos == 1)
    {
        DeleteFirst();
    }
    else if(iPos == iNodeCnt)
    {
        DeleteLast();
    }
    else
    {
        for(iCnt = 1; iCnt < iPos-1; iCnt++)
        {
            temp1 = temp1->next;
        }   
        temp2 = temp1 ->next;

        temp1->next = temp2->next;
        // free(temp2);
        delete(temp2);
    }
	
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Function Name: Display()
// Description :  Display the elements of LinkedList
// Input :        
// Output :       All elements of linkedlist
// Author :       Sayali Hanumant Thorat
// Date :         08/02/2023
//
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
template <class T>
void SinglyCL <T> :: Display()
{
	struct nodeS<T> * temp = First;  
	
    cout<<"Elements of Linked list are :"<<"\n";

    do
    {
        cout<<temp->data<<" ";
        temp = temp -> next;
    }while(temp != Last->next);
    cout<<"\n";
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Function Name: Count()
// Description :  Count the number of elements from linkedlist
// Input :        
// Output :       return the count of elements in linkedlist
// Author :       Sayali Hanumant Thorat
// Date :         08/02/2023
//
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
template <class T>
int SinglyCL <T>:: Count()
{
	struct nodeS<T> * temp = First;
    int iCnt = 0;
    do
    {
        iCnt++;
        temp = temp -> next;
    }while(temp != Last->next);
    return iCnt;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Function Name: SearchFirstOccurence()
// Description :  Search First Occurence of elements from linkedlist
// Input :        
// Output :       index of first occurrence of element in linkedlist
// Author :       Sayali Hanumant Thorat
// Date :         08/02/2023
//
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
template <class T>
int SinglyCL <T> :: SearchFirstOccurence(T No)
{
    struct nodeS<T> * newn = First; 
    int iPos = 0;
	while(newn != NULL)
    {
        if(newn -> data == No)
        {
            return iPos;
        }
        iPos++;
        newn= newn->next;
    }
    return -1;
        
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Function Name: SearchLastOccurence()
// Description :  Search First Occurence of elements from linkedlist
// Input :        
// Output :       index of first occurrence of element in linkedlist
// Author :       Sayali Hanumant Thorat
// Date :         08/02/2023
//
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
template <class T>
int SinglyCL <T> :: SearchLastOccurence(T No)
{
    struct nodeS<T> * newn = First; 
    int iPos = 0,iCnt = 0;
	while(newn->next != First)
    {
        
        if(newn->data == No)
        {
          iCnt = iPos;           
        }
        iPos++;
        newn= newn->next;        
    }
    return iCnt;      
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Function Name: Addition()
// Description :  Addition of all the elements from linkedlist
// Input :        
// Output :       Addition of elements
// Author :       Sayali Hanumant Thorat
// Date :         08/02/2023
//
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
template<class T>
int SinglyCL <T> :: Addition()
{
    struct nodeS<T> * newn = First; 
    int iSum = 0;

    if(newn != NULL)
    {
        do
        {
            newn = newn->next;
            iSum = iSum + newn->data;            

        }while(newn != First);
       
    }
    return iSum;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Function Name: AdditionEven()
// Description :  Addition of Even element from linkedlist
// Input :        
// Output :       Addition of Even element in linkedlist
// Author :       Sayali Hanumant Thorat
// Date :         08/02/2023
//
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
template<class T>
int SinglyCL <T> :: AdditionEven()
{
    struct nodeS<T> * newn = First; 
    int iSum = 0;
	while(newn->next != First)
	{
        if(((newn->data)%2 == 0))
		{
            iSum = iSum + newn->data;            
		}
        newn =newn->next;
	   
	}
    return iSum;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Function Name: Maximum()
// Description :  Maximum element from linkedlist
// Input :        
// Output :       Maximum element in linkedlist
// Author :       Sayali Hanumant Thorat
// Date :         08/02/2023
//
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
template<class T>
int SinglyCL <T> :: Maximum()
{
    struct nodeS<T> * newn = First; 
    int imax = First->data;
     
    do 
    {
        if (imax < newn->data)
        {
            imax = newn->data;
        }
        newn = newn->next;
    }while(newn != First);

    return imax;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Function Name: Minimum()
// Description :  Minimum element from linkedlist
// Input :        
// Output :       Minimum element in linkedlist
// Author :       Sayali Hanumant Thorat
// Date :         08/02/2023
//
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
template<class T>
int SinglyCL <T> :: Minimum()
{
    struct nodeS<T> * newn = First; 
    int iMin = First->data;
 
    do 
    {
        if (iMin > newn->data)
        {
            iMin = newn->data;
        }
        newn = newn->next;
    }while(newn != First);

    return iMin;
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////Functions of SinglyCL Ended here///////////////////////////////////////////////////////////
//////////////////////////////////////###############################################################/////////////////////////////////////////////////////////
////////////////////////////////////////////Class of Doubly Linear LinkedList started here///////////////////////////////////////////////////////////////////
template <class T>
class DoublyLL
{
    public:
        struct nodeD<T> * First;

        DoublyLL();
        void InsertFirst(T no);
        void InsertLast(T no);
        void InsertAtPos(T no,int ipos);

        void DeleteFirst();
        void DeleteLast();   
        void DeleteAtPos(int ipos);

        int SearchFirstOccurence(T no);
        int SearchLastOccurence(T no);
        int Addition();
        int Maximum();
        int Minimum();
        int AdditionEven();
        int SecMaximum();

        void Display();
        int Count();
};
//////////////////////////////////////////////////////////////////Functions of Doubly Linear LinkedList started here////////////////////////////////////////
//////////////////////////////////////###############################################################///////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Constructor Name: DoublyLL()
// Description :  Constructor of Doubly linear linkedlist
// Author :       Sayali Hanumant Thorat
// Date :         08/02/2023
//
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
template <class T>
DoublyLL <T> :: DoublyLL()
{
    First = NULL;
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Function Name: InsertFirst()
// Description :  Insert the number at first position
// Input :        Number
// Output :       
// Author :       Sayali Hanumant Thorat
// Date :         08/02/2023
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

template <class T>
void DoublyLL <T>:: InsertFirst(T no)
{
   struct nodeD<T> *newn = new nodeD<T>;

    newn->data = no;
    newn->next = NULL;
    newn->prev = NULL;      // X

    if(First == NULL)
    {
        First = newn;
    }
    else
    {
        newn->next = First;
        (First)->prev = newn;  // X

        First = newn;
    }
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Function Name: InsertLast()
// Description :  Insert the number at last position
// Input :        Number
// Output :       
// Author :       Sayali Hanumant Thorat
// Date :         08/02/2023
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
template <class T>
void DoublyLL <T>:: InsertLast(T no)
{
    struct nodeD <T> *newn = new nodeD<T>;
    struct nodeD <T> *temp = First;

    newn->data = no;
    newn->next = NULL;
    newn->prev = NULL;      // X

    if(First == NULL)
    {
        First = newn;
    }
    else
    {
        while(temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newn;
        newn->prev = temp;      // X
    }
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Function Name: Display()
// Description :  Display the elements of LinkedList
// Input :        
// Output :       All elements of linkedlist
// Author :       Sayali Hanumant Thorat
// Date :         08/02/2023
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
template <class T>
void DoublyLL <T>:: Display()
{
    struct nodeD <T> * temp= First;
    cout<<"Elements of Linked list are:"<<"\n";


    while(temp != NULL)
    {
        cout<<"| "<<temp->data<<" |->";
        temp = temp->next;
    }
    cout<<"NULL "<<"\n";
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Function Name: InsertAtPos()
// Description :  Insert the number at position
// Input :        Number and position
// Output :       Insert number at mentioned position
// Author :       Sayali Hanumant Thorat
// Date :         08/02/2023
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
template <class T>
void DoublyLL <T>:: InsertAtPos(T No, int iPos)
{
	int NodeCnt =0, iCnt = 0;
		
	NodeCnt = Count();
	
	if((iPos < 1) || (iPos > (NodeCnt+1)))
	{
		cout<<"Invalid Position"<<"\n";
		return;
	}
	
	if(iPos == 1)
	{
		InsertFirst(No);
		
	}
	else if(iPos == NodeCnt+1)
	{
		InsertLast(No);
	}
	else
	{
		struct nodeD <T> *newn = new nodeD<T>;
		
		newn -> data = No;
		newn -> next = NULL;
		newn->prev = NULL;   //X
		
		struct nodeD <T> *temp = First;
		
		for(iCnt = 1; iCnt < iPos-1; iCnt++)
		{
			temp = temp -> next;
		}
		newn->next = temp->next;
		temp->next->prev = newn;  //X
		
		temp->next = newn;
		newn->prev=temp;  //X
			
	}
	
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Function Name: DeleteFirst()
// Description :  Delete the number at first position
// Input :        
// Output :       Delete the number which is on first position
// Author :       Sayali Hanumant Thorat
// Date :         08/02/2023
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

template <class T>
void DoublyLL <T>:: DeleteFirst()
{
	if(First == NULL)   //LL is empty
	{
		return;
		
	}
	else if((First->next) == NULL)  //LL contains 1 node
	{
		free(First);
		First = NULL;		
	}
	else  //LL contains more than 1 node
	{
		First = First->next;
		free(First->prev);
		First->prev = NULL;
		
	}
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Function Name: DeleteLast()
// Description :  Delete the number at last position
// Input :        
// Output :       Delete the number which is present on last position
// Author :       Sayali Hanumant Thorat
// Date :         08/02/2023
//
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
template <class T>
void DoublyLL <T>:: DeleteLast()
{
	struct nodeD <T> *temp = First;
	
	if(First == NULL)   //LL is empty
	{
		return;
		
	}
	else if((First->next) == NULL)  //LL contains 1 node
	{
		delete(First);

		First = NULL;		
	}
	else  //LL contains more than 1 node
	{
		while(temp->next->next != NULL)
		{
			temp = temp->next;
		}
		
		delete(temp->next);
		temp->next = NULL;
		
	}
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Function Name: DeleteAtPos()
// Description :  Delete the number from accepted position
// Input :        position
// Output :       Delete the number from position
// Author :       Sayali Hanumant Thorat
// Date :         08/02/2023
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
template <class T>
void DoublyLL <T>:: DeleteAtPos(int iPos)
{
	struct nodeD <T> *temp1 = NULL;
	struct nodeD <T> *temp2 = NULL;
	int iCnt = 0, NodeCnt = 0;
	
	NodeCnt = Count();
	
	if((iPos < 1)||(iPos > NodeCnt))
	{
		cout<<"Invalid Position"<<"\n";
		return;
	}
	
	if(iPos == 1)
	{
		DeleteFirst();
		
	}
	else if(iPos == NodeCnt)
	{
		DeleteLast();		
	}
	else
	{
		temp1 = First;
		
		for(iCnt = 1; iCnt < iPos - 1; iCnt++)
		{
			temp1 = temp1->next;
		}
		temp2 = temp1->next;
		
		
		temp1->next = temp2->next;  //temp1->next = temp1->next->next;
		temp2->next->prev = temp1;    //X
		delete(temp2);
	}
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Function Name: Count()
// Description :  Count the number of elements from linkedlist
// Input :        
// Output :       return the count of elements in linkedlist
// Author :       Sayali Hanumant Thorat
// Date :         08/02/2023
//
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
template <class T>
int DoublyLL <T> :: Count()
{
    int iCnt = 0;
    struct nodeD <T> *temp = First;

    while(temp != NULL)
    {
        iCnt++;
        temp = temp->next;
    }

    return iCnt;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Function Name: SearchFirstOccurence()
// Description :  Search First Occurence of elements from linkedlist
// Input :        
// Output :       index of first occurrence of element in linkedlist
// Author :       Sayali Hanumant Thorat
// Date :         08/02/2023
//
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
template<class T>
int DoublyLL <T> :: SearchFirstOccurence(T No)
{
    struct nodeD<T> * newn = First; 
    int iPos = 0;
	while(newn != NULL)
    {
        if(newn -> data == No)
        {
            return iPos;
        }
        iPos++;
        newn= newn->next;
    }
    return -1;
        
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Function Name: SearchLastOccurence()
// Description :  Search Last Occurence of elements from linkedlist
// Input :        
// Output :       index of Last occurrence of element in linkedlist
// Author :       Sayali Hanumant Thorat
// Date :         08/02/2023
//
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
template<class T>
int DoublyLL <T> :: SearchLastOccurence(T No)
{
    struct nodeD<T> * newn = First; 
    int iPos = 0,iCnt = 0;
	while(newn != NULL)
    {
        
        if(newn->data == No)
        {
          iCnt = iPos;           
        }
        iPos++;
        newn= newn->next;
        
    }
    return iCnt;      
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Function Name: Addition()
// Description :  Addition of all the elements from linkedlist
// Input :        
// Output :       Addition of elements
// Author :       Sayali Hanumant Thorat
// Date :         08/02/2023
//
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
template<class T>
int DoublyLL <T> :: Addition()
{
    struct nodeD<T> * newn = First; 
    int iSum = 0;

    while(newn != NULL)
    {
        iSum = iSum + newn->data;
        newn = newn->next;
    }
    return iSum;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Function Name: Maximum()
// Description :  Maximum element from linkedlist
// Input :        
// Output :       Maximum element in linkedlist
// Author :       Sayali Hanumant Thorat
// Date :         08/02/2023
//
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
template<class T>
int DoublyLL <T> :: Maximum()
{
    struct nodeD<T> * newn = First; 
    int imax = First->data;
     
    while (newn != NULL) 
    {
        if (imax < newn->data)
        {
            imax = newn->data;
        }
        newn = newn->next;
    }
    return imax;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Function Name: Minimum()
// Description :  Minimum element from linkedlist
// Input :        
// Output :       Minimum element in linkedlist
// Author :       Sayali Hanumant Thorat
// Date :         08/02/2023
//
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
template<class T>
int DoublyLL <T> :: Minimum()
{
    struct nodeD<T> * newn = First; 
    int iMin = First->data;
 
    while (newn != NULL) 
    {
        if (iMin > newn->data)
        {
            iMin = newn->data;
        }
        newn = newn->next;
    }
    return iMin;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Function Name: AdditionEven()
// Description :  Addition of Even element from linkedlist
// Input :        
// Output :       Addition of Even element in linkedlist
// Author :       Sayali Hanumant Thorat
// Date :         08/02/2023
//
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
template<class T>
int DoublyLL <T> :: AdditionEven()
{
    struct nodeD<T> * newn = First; 
    int iSum = 0;
	while(newn != NULL)
	{
        if(((newn->data)%2 == 0))
		{
			iSum = iSum + (newn->data);
		}
	   
		newn = newn -> next;
	}
    return iSum;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Function Name: SecMaximum()
// Description :  Second maximum element from linkedlist
// Input :        
// Output :       Second maximum element in linkedlist
// Author :       Sayali Hanumant Thorat
// Date :         08/02/2023
//
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
template<class T>
int DoublyLL <T> :: SecMaximum()
{
	int iMax = 0;
	
	if(First == NULL)
	{
		printf("Linked list is empty\n");
		return 0;
	}
	
	iMax = First->data;
    int SecMax = First->data;
	
    while(First != NULL)
    {
      if (First->data > iMax) 
      {
        SecMax = iMax;
        iMax = First->data;
      }
      else if(First->data > SecMax)
      
        SecMax = First->data;
        First = First->next;         
   }
   return SecMax;	
	
}

//////////////////////////////////////////////////////////////////Functions of DoublyLL Ended here/////////////////////////////////////////////////////
//////////////////////////////////////###############################################################//////////////////////////////////////////////////
////////////////////////////////////////////Class of Doubly Circular LinkedList////////////////////////////////////////////////////////////////////////
template <class T>
class DoublyCL
{
    public:
        struct nodeD<T> * First;
        struct nodeD<T> * Last;

        DoublyCL();
        void InsertFirst(T no);
        void InsertLast(T no);
        void InsertAtPos(T no,int ipos);

        void DeleteFirst();
        void DeleteLast();   
        void DeleteAtPos(int ipos); 

        int SearchFirstOccurence(T no);
        int SearchLastOccurence(T no);
        int Addition();
        int Maximum();
        int Minimum();

        void Display();
        int Count();
};
//////////////////////////////////////////////////////////////////Functions of Doubly Circular LinkedList started here////////////////////////////////////////
//////////////////////////////////////###############################################################/////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Constructor Name: DoublyCL()
// Description :  Constructor of Doubly circular linkedlist
// Author :       Sayali Hanumant Thorat
// Date :         08/02/2023
//
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
template <class T>
DoublyCL <T> :: DoublyCL()
{
    First = NULL;
    Last = NULL;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Function Name: InsertFirst()
// Description :  Insert the number at first position
// Input :        Number
// Output :       
// Author :       Sayali Hanumant Thorat
// Date :         08/02/2023
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
template <class T>
void DoublyCL <T>:: InsertFirst(T no)
{
	struct nodeD <T> *newn = new nodeD<T>;
	
	newn->data = no;
	newn->next = NULL;
	newn->prev = NULL;
	
	if((First == NULL) && (Last == NULL))   //if LL is empty
	{
		First=newn;
		Last=newn;
	}
	else  //LL contains 1 or more than one nodes
	{
		newn->next = First;
		(First)->prev = newn;
		First = newn;	
		
	}
	
	(First)->prev = Last;
	(Last)->next = First;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Function Name: InsertLast()
// Description :  Insert the number at last position
// Input :        Number
// Output :       
// Author :       Sayali Hanumant Thorat
// Date :         08/02/2023
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
template <class T>
void DoublyCL <T>:: InsertLast(T no)
{
	struct nodeD <T> *newn = new nodeD <T>;
	
	newn->data = no;
	newn->next = NULL;
	newn->prev = NULL;
	
	if((First == NULL) && (Last == NULL))   //if LL is empty
	{
		First=newn;
		Last=newn;
	}
	else  //LL contains 1 or more than one nodes
	{
		(Last) ->next = newn;
		newn->prev = Last;
		Last = newn;
		
	}
	
	(First)->prev = Last;
	(Last)->next = First;	
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Function Name: InsertAtPos()
// Description :  Insert the number at position
// Input :        Number and position
// Output :       Insert number at mentioned position
// Author :       Sayali Hanumant Thorat
// Date :         08/02/2023
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
template <class T>
void DoublyCL <T>:: InsertAtPos(T no, int iPos)
{
	int iNodeCnt = Count();
	struct nodeD <T> *newn = NULL;
	struct nodeD <T> *temp = NULL;
	int iCnt = 0;
	
	if((iPos < 1) || (iPos > iNodeCnt+1))
	{
		cout<<"Invalid Position"<<"\n";
		return;
	}
	if(iPos == 1)
	{
		InsertFirst(no);
	}
	else if(iPos == iNodeCnt+1)
	{
		InsertLast(no);
	}
	else
	{
		newn = new nodeD <T>;
		
		newn->data= no;
		newn->next = NULL;
		newn->prev = NULL;
		temp = First;
		
		for(iCnt = 1; iCnt <iPos-1; iCnt++)
		{
			temp = temp->next;
		}
		
		newn->next = temp->next;
		temp->next->prev = newn;
		
		temp->next = newn;
		newn->prev = temp;
	}
	
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Function Name: DeleteFirst()
// Description :  Delete the number at first position
// Input :        
// Output :       Delete the number which is on first position
// Author :       Sayali Hanumant Thorat
// Date :         08/02/2023
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
template <class T> 
void DoublyCL <T> :: DeleteFirst()
{
	if(First == NULL && Last == NULL) // LL empty
	{
		return;
	}
	else if(First == Last)  // Single node
	{
		free(First);
		First = NULL;
		Last = NULL;
		
	}
	else  //More than one node
	{
		First = (First)->next;
		delete((Last)->next);  //free((*First)->prev);
		
		(First)->prev = Last;  //maintain Circular nature
		(Last)->next = First;  //maintain Circular nature
	}
	
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Function Name: DeleteLast()
// Description :  Delete the number at last position
// Input :        
// Output :       Delete the number which is present on last position
// Author :       Sayali Hanumant Thorat
// Date :         08/02/2023
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
template <class T>
void DoublyCL <T>:: DeleteLast()
{
	if(First == NULL && Last == NULL) // Empty LL
    {
        return;
    }
    else if(First == Last)    // Single node
    {
        free(First);
        First = NULL;
        Last= NULL;
    }
    else    // More than one node
    {
        Last = (Last) -> prev;
        delete((First)->prev);       // free((*Last)->next);

        (First)->prev = Last;
        (Last)->next = First;
    }
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Function Name: DeleteAtPos()
// Description :  Delete the number from accepted position
// Input :        position
// Output :       Delete the number from position
// Author :       Sayali Hanumant Thorat
// Date :         08/02/2023
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
template <class T>
void DoublyCL <T>:: DeleteAtPos(int iPos)
{
	int iNodeCnt = Count();
	
	struct nodeD <T> *temp = NULL;
	int iCnt = 0;
	
	if((iPos < 1) || (iPos > iNodeCnt))
	{
		cout<<"Invalid Position"<<"\n";
		return;
	}
	if(iPos == 1)
	{
		DeleteFirst();
	}
	else if(iPos == iNodeCnt)
	{
		DeleteLast();
	}
	else
	{
		temp = First;
		
		for(iCnt = 1; iCnt <iPos-1; iCnt++)
		{
			temp = temp->next;
		}
		
		temp->next = temp->next->next;
		delete(temp->next->prev);
		temp->next->prev = temp;
		
	}
	
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Function Name: Display()
// Description :  Display the elements of LinkedList
// Input :        
// Output :       All elements of linkedlist
// Author :       Sayali Hanumant Thorat
// Date :         08/02/2023
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
template <class T>
void DoublyCL <T>:: Display()
{
	struct nodeD <T> *temp = First;
	
	if(First == NULL && Last == NULL)  //if LL is empty
	{
		cout<<"Linked List is empty"<<"\n";
		return;
	}
	
	cout<<"Elements of linkedlist are:"<<"\n";
	do
	{
		cout<<"|"<<temp->data<<"|<=>";
		temp = temp->next;
	}while(temp != Last->next);
	cout<<"\n";
	
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Function Name: Count()
// Description :  Count the number of elements from linkedlist
// Input :        
// Output :       return the count of elements in linkedlist
// Author :       Sayali Hanumant Thorat
// Date :         08/02/2023
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
template <class T>
int DoublyCL <T>:: Count()
{
	int iCnt = 0; 
	struct nodeD <T> *temp = First;
	if(First == NULL && Last == NULL)  //if LL is empty
	{
		
		return iCnt;
	}
	do
	{
		iCnt++;
		temp = temp->next;
	}while(temp != Last->next);
	
	return iCnt;
	
}


///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Function Name: SearchFirstOccurence()
// Description :  Search First Occurence of elements from linkedlist
// Input :        
// Output :       index of first occurrence of element in linkedlist
// Author :       Sayali Hanumant Thorat
// Date :         08/02/2023
//
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
template <class T>
int DoublyCL <T> :: SearchFirstOccurence(T No)
{
    struct nodeD<T> * newn = First; 
    int iPos = 0;
	while(newn != NULL)
    {
        if(newn -> data == No)
        {
            return iPos;
        }
        iPos++;
        newn= newn->next;
    }
    return -1;
        
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Function Name: SearchLastOccurence()
// Description :  Search First Occurence of elements from linkedlist
// Input :        
// Output :       index of first occurrence of element in linkedlist
// Author :       Sayali Hanumant Thorat
// Date :         08/02/2023
//
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
template <class T>
int DoublyCL <T> :: SearchLastOccurence(T No)
{
    struct nodeD<T> * newn = First; 
    int iPos = 0,iCnt = 0;
	while(newn->next != First)
    {
        
        if(newn->data == No)
        {
          iCnt = iPos;           
        }
        iPos++;
        newn= newn->next;        
    }
    return iCnt;      
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Function Name: Addition()
// Description :  Addition of all the elements from linkedlist
// Input :        
// Output :       Addition of elements
// Author :       Sayali Hanumant Thorat
// Date :         08/02/2023
//
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
template<class T>
int DoublyCL <T> :: Addition()
{
    struct nodeD<T> * newn = First; 
    int iSum = 0;

    if(newn != NULL)
    {
        do
        {
            newn = newn->next;
            iSum = iSum + newn->data;            

        }while(newn != First);
       
    }
    return iSum;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Function Name: Maximum()
// Description :  Maximum element from linkedlist
// Input :        
// Output :       Maximum element in linkedlist
// Author :       Sayali Hanumant Thorat
// Date :         08/02/2023
//
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
template<class T>
int DoublyCL <T> :: Maximum()
{
    struct nodeD<T> * newn = First; 
    int imax = First->data;
     
    do 
    {
        if (imax < newn->data)
        {
            imax = newn->data;
        }
        newn = newn->next;
    }while(newn != First);

    return imax;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Function Name: Minimum()
// Description :  Minimum element from linkedlist
// Input :        
// Output :       Minimum element in linkedlist
// Author :       Sayali Hanumant Thorat
// Date :         08/02/2023
//
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
template<class T>
int DoublyCL <T> :: Minimum()
{
    struct nodeD<T> * newn = First; 
    int iMin = First->data;
 
    do 
    {
        if (iMin > newn->data)
        {
            iMin = newn->data;
        }
        newn = newn->next;
    }while(newn != First);

    return iMin;
}

//////////////////////////////////////////////////////////////////Functions of DoublyCL Ended here////////////////////////////////////////////
//////////////////////////////////////###############################################################//////////////////////////////////////
/////////////////////////////////////////////main() function started here///////////////////////////////////////////////////////////////////
int main()
{
    cout<<"-------------------------------------------------------"<<"\n";
    cout<<"#########################################################"<<"\n\n";
    cout<<"GENERALIZED DATA STRUCTURE LIBRARY PROJECT..."<<"\n";
    cout<<"#########################################################"<<"\n\n";
    cout<<"-------------------------------------------------------"<<"\n";
    int SLRet = 0,iRet = 0,iRetL = 0;
    SinglyLL <char> SLcobj;
    cout<<"*******************************************************"<<"\n";
    cout<<"Singly Linear LinkedList Output:"<<"\n";
    cout<<"*******************************************************"<<"\n";
	SLcobj.InsertFirst('a');
    SLcobj.InsertFirst('b');
	SLcobj.InsertLast('c');
    SLcobj.InsertLast('a');
    SLcobj.InsertLast('n');
    SLcobj.InsertLast('s');
    SLcobj.InsertAtPos('d',5);
    SLcobj.Display();
    iRet = SLcobj.SearchFirstOccurence('a');
    if(iRet == -1)
    {
        printf("Element not found");
    }
    else
    {
        printf("First occurrence of 'a' is at position : %d\n", iRet+1);
    }
    iRetL = SLcobj.SearchLastOccurence('a');
    if(iRetL == -1)
    {
        printf("Element not found");
    }
    else
    {
        printf("Last occurrence of 'a' is at position : %d\n", iRetL+1);
    }
    SLcobj.DeleteAtPos(5);
    SLcobj.Display();
    SLcobj.DeleteFirst();
    SLcobj.DeleteLast();
	SLcobj.Display();
    SLRet = SLcobj.Addition();
    cout<<"Addition of elements is : "<<SLRet<<"\n";
	SLRet = SLcobj.Count();
	cout<<"Number of character nodes are : "<<SLRet<<"\n";
    SLRet = SLcobj.Maximum();
    cout<<"Maximum element is : "<<SLRet<<"\n";
    SLRet = SLcobj.Minimum();
    cout<<"Minimum element is : "<<SLRet<<"\n";
    SLRet = SLcobj.AdditionEven();
    cout<<"Addition of even elements is : "<<SLRet<<"\n";
    SLRet = SLcobj.SecMaximum();
    cout<<"Second maximum element from linkedlist is : "<<SLRet<<"\n";    
    cout<<"-------------------------------------------------------"<<"\n";

    int SCRet = 0;
    SinglyCL <float> SCcobj;
    cout<<"*******************************************************"<<"\n";
    cout<<"Singly Circular LinkedList Output:"<<"\n";
    cout<<"*******************************************************"<<"\n";
	SCcobj.InsertFirst(21.10f);
    SCcobj.InsertFirst(11.10f);
	SCcobj.InsertLast(10.15f);
    SCcobj.InsertLast(11.10f);
    SCcobj.InsertAtPos(110.50f,5);
    SCcobj.Display();
    SCRet = SCcobj.SearchFirstOccurence(11.10f);
    if(SCRet == -1)
    {
        printf("Element not found");
    }
    else
    {
        printf("First occurrence of 11.10f is at position : %d\n", SCRet+1);
    }
    SCRet = SCcobj.SearchLastOccurence(11.10f);
    if(SCRet == -1)
    {
        printf("Element not found");
    }
    else
    {
        printf("Last occurrence of 11.10f is at position : %d\n", SCRet+1);
    }
    SCRet = SCcobj.Addition();
    cout<<"Addition of elements is : "<<SCRet<<"\n";
	SCRet = SCcobj.Count();
	cout<<"Number of float nodes are : "<<SCRet<<"\n";
    SCRet = SCcobj.Maximum();
    cout<<"Maximum element is : "<<SCRet<<"\n";
    SCRet = SCcobj.Minimum();
    cout<<"Minimum element is : "<<SCRet<<"\n";
    SCcobj.DeleteAtPos(3);
    SCcobj.Display();
    SCRet = SCcobj.Count();
	cout<<"Number of Float nodes after deletion of 3rd node is : "<<SCRet<<"\n";
    SCcobj.DeleteFirst();
    SCcobj.DeleteLast();
    SCcobj.Display();
	SCRet = SCcobj.Count();
	cout<<"Number of Float nodes after deletion of first and last node is : "<<SCRet<<"\n";

    cout<<"-------------------------------------------------------"<<"\n";

    int DLRet = 0;
    DoublyLL <int> DLcobj;
    cout<<"*******************************************************"<<"\n";
    cout<<"Doubly Linear LinkedList Output:"<<"\n";
    cout<<"*******************************************************"<<"\n";
	DLcobj.InsertFirst(21);
    DLcobj.InsertFirst(11);
	DLcobj.InsertLast(51);
    DLcobj.InsertLast(11);
    DLcobj.InsertAtPos(111,5);
    DLcobj.Display();
    DLRet = DLcobj.SearchFirstOccurence(11);
    if(DLRet == -1)
    {
        printf("Element not found");
    }
    else
    {
        printf("First occurrence of 11 is at position : %d\n", DLRet+1);
    }
    DLRet = DLcobj.SearchLastOccurence(11);
    if(DLRet == -1)
    {
        printf("Element not found");
    }
    else
    {
        printf("Last occurrence of 11 is at position : %d\n", DLRet+1);
    }
    DLcobj.Display();
    DLcobj.DeleteAtPos(5);
    DLcobj.DeleteFirst();
    DLcobj.DeleteLast();
	DLcobj.Display();
	DLRet = DLcobj.Count();
	cout<<"Number of Integer nodes are : "<<DLRet<<"\n";
    DLRet = DLcobj.Addition();
    cout<<"Addition of elements is : "<<DLRet<<"\n";
    DLRet = DLcobj.Maximum();
    cout<<"Maximum element is : "<<DLRet<<"\n";
    DLRet = DLcobj.Minimum();
    cout<<"Minimum element is : "<<DLRet<<"\n";
    DLRet = DLcobj.AdditionEven();
    cout<<"Addition of even elements is : "<<DLRet<<"\n";
    DLRet = DLcobj.SecMaximum();
    cout<<"Second maximum element from linkedlist is : "<<DLRet<<"\n";   
    cout<<"-------------------------------------------------------"<<"\n";

    int DCiRet = 0;
    DoublyCL <double> DCcobj;
    cout<<"*******************************************************"<<"\n";
    cout<<"Doubly Circular LinkedList Output:"<<"\n";
    cout<<"*******************************************************"<<"\n";
	DCcobj.InsertFirst(21.20);
    DCcobj.InsertFirst(11.40);
	DCcobj.InsertLast(55.40);
    DCcobj.InsertLast(11.40);
    DCcobj.InsertAtPos(51.60,5);
    DCcobj.Display();
    DCiRet = DCcobj.SearchFirstOccurence(11.40);
    if(DCiRet == -1)
    {
        printf("Element not found");
    }
    else
    {
        printf("First occurrence of 11.40 is at position : %d\n", DCiRet+1);
    }
    DCiRet = DCcobj.SearchLastOccurence(11.40);
    if(DCiRet == -1)
    {
        printf("Element not found");
    }
    else
    {
        printf("Last occurrence of 11.40 is at position : %d\n", DCiRet+1);
    }
    DCcobj.DeleteAtPos(2);
    DCcobj.DeleteFirst();
    DCcobj.DeleteLast();
	DCcobj.Display();
    DCiRet = DCcobj.Count();
	cout<<"Number of Double nodes are : "<<DCiRet<<"\n";
    DCiRet = DCcobj.Addition();
	cout<<"Addition of double nodes is : "<<DCiRet<<"\n";
    DCiRet = DCcobj.Maximum();
	cout<<"Maximum of double nodes is : "<<DCiRet<<"\n";
    DCiRet = DCcobj.Minimum();
	cout<<"Minimum of double nodes is : "<<DCiRet<<"\n";
    cout<<"-------------------------------------------------------"<<"\n";

    
    return 0;
}