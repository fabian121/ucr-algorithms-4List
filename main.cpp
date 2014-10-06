/* 
 * File:   main.cpp
 * Author: user
 *
 * Created on January 21, 2014, 5:29 PM
 */

#include <cstdlib>
#include "List.h"
#include <stdio.h>

void listTesting();
void instructions();

/*
 * 
 */
int main(int argc, char** argv) {
    
    //menu----------------------
    
    //variables
    List myList;
    int choice;
    char item;
    
    instructions();
    printf("?   ");
    scanf("%d", &choice);
    
    //menu cycle
    while(choice != 3){
        
        switch(choice){
            case 1:{
                printf("Enter a character: ");
                scanf("\n%c", &item);
                myList.insertIntoList(item);
                
                system("clear");
                instructions();
                myList.printList();
                break;
            }
            case 2:{
                if(!myList.isEmpty()){
                    printf("Enter character to be deleted: ");
                    scanf("\n%c", &item);
                    
                    if(myList.deleteFromList(item)){
                        printf("%c deleted.\n", item);
                        
                        system("clear");
                        instructions();
                        myList.printList();
                    }else{
                        system("clear");
                        instructions();
                        printf("%c not found.\n\n", item);
                    }
                }else{
                    system("clear");
                    instructions();
                    printf("List is empty.\n\n");
                }
                break;
            }
            default:{
                system("clear");
                instructions();
                printf("Invalid choice.\n\n");
                instructions();
                break;
            }
        }//end switch
        printf("?   ");
        scanf("%d", &choice);
    }//end while (choice != 3)
    
    printf("End of run.\n");
    return 0;
}

/*show up instructions*/
void instructions(){
    printf("Enter your choice:\n"
            "   1 to insert an element into the list.\n"
            "   2 to delete an element from the list.\n"
            "   3 to end.\n\n");
}

/*test list class*/
void listTesting(){
    List myList;
    
    //indicates if the list is empty
    printf("Is empty: %d\n\n", myList.isEmpty());
    
    //insertions
    myList.insertIntoList('b');
    myList.insertIntoList('a');
    myList.insertIntoList('d');
    myList.insertIntoList('c');
    myList.printList();
    
    //delete
    myList.deleteFromList('z');
    myList.printList();
    printf("Is empty: %d\n\n", myList.isEmpty());
}