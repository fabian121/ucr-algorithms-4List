/* 
 * File:   List.h
 * Author: user
 *
 * Created on January 21, 2014, 6:01 PM
 */

#ifndef LIST_H
#define	LIST_H

class List {
public:
    List();
    List(const List& orig);
    virtual ~List();
    
    /*inserts an element to our list*/
    void insertIntoList(char value);
    char deleteFromList(char value);
    void printList();
    int isEmpty();
    
private:
    /*my node as a structure*/
    struct listNode{
        char data;
        struct listNode *nextPtr;
    };
    
    /*variables*/
    typedef struct listNode LISTNODE;
    typedef LISTNODE *LISTNODEPTR;

    LISTNODEPTR startNodeList;
    

};

#endif	/* LIST_H */

