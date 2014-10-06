/* 
 * File:   List.cpp
 * Author: user
 * 
 * Created on January 21, 2014, 6:01 PM
 */

#include "List.h"
#include <malloc.h>
#include <stdlib.h>

List::List() {
    startNodeList = NULL;
}

List::List(const List& orig) {
}

List::~List() {
}


/*inserts a new element into the list*/
void List::insertIntoList(char value) {
        //variables
    LISTNODEPTR newPtr, previousPtr, currentPtr;
    
    //dynamically creation of memory
    newPtr = (LISTNODEPTR)malloc(sizeof(LISTNODE));
    
    /*ask if there is available space*/
    if(newPtr != NULL){
        //load value to the new node
        newPtr->data = value;
        
        //assigned values to my temporal nodes
        previousPtr = NULL;
        currentPtr = startNodeList;
        
        //go over my list looking for the correct place to insert
        while(currentPtr != NULL && value > currentPtr->data){
            previousPtr = currentPtr;
            currentPtr = currentPtr->nextPtr;
        }
        
        //ask if the list is empty
        if(previousPtr == NULL){
            newPtr->nextPtr = currentPtr;
            startNodeList = newPtr;
        }else{
            previousPtr->nextPtr = newPtr;
            newPtr->nextPtr = currentPtr;            
        }
        
    }else{ //newPtr != NULL
        printf("%c not inserted. No available space.\n", value);
    }//end if newPtr != NULL
}

/*delete an element from the list*/
char List::deleteFromList(char value) {
    //variables
    LISTNODEPTR currentPtr = startNodeList, previousPtr = NULL, tempPtr;
    
    //go over the list searching for the requested value
    while(currentPtr != NULL && currentPtr->data != value){
        previousPtr = currentPtr;
        currentPtr = currentPtr->nextPtr;
    }
    
    //the searching element was found
    if(currentPtr != NULL){
        //ask if the element is the first element
        if(previousPtr == NULL){
            tempPtr = startNodeList;
            startNodeList = startNodeList->nextPtr;
            free(tempPtr);
            return value;
        }else{
            tempPtr = currentPtr;
            previousPtr->nextPtr = currentPtr->nextPtr;
            free(tempPtr);
            return value;
        }
    }//end if currentPtr != NULL
    
    return '\0';
}

/*indicates if the list is empty*/
int List::isEmpty() {
    return startNodeList == NULL;
}



/*prints the whole list*/
void List::printList() {
    //current node 
    LISTNODEPTR currentNode = startNodeList;
    
    if(currentNode != NULL){
        
        //go over the list
        while(currentNode != NULL){
            printf("%c--> ", currentNode->data);
            currentNode = currentNode->nextPtr;
        }//end while1
        
        printf("NULL\n\n");
    }//end if
    else{
        printf("The list is empty.\n\n");
    }
}

