#include "slide.h"

int main(){
    bool flag=true;
    int choice,deckCount=0,deckNumber;
    Deck *decks=NULL; 

    do{
     cout<<"Enter Your Choice"<<endl;
     cout<<"1. Add Deck"<<endl;
     cout<<"2. Remove Deck"<<endl;
     cout<<"3. Display Deck"<<endl;
     cout<<"4. Exit"<<endl;
     cin>>choice; 
      switch(choice){
             case 1:
                  decks=createDeck(decks,deckCount);
                   deckCount++;
                   break;          

             case 2:
                   if(deckCount==0){
                         cout<<"No deck Exist yet first create a deck"<<endl;
                         break;
                   }
                   cout<<"Enter deck number you want to delete- ";
                   cin>>deckNumber;                   
                   while(deckNumber<1||deckNumber>deckCount){
                   cout<<"ERROR! Deck does not exist, enter a valid deck number- ";
                    cin>>deckNumber;
                   }
                   decks=removeDeck(decks,deckCount,deckNumber); 
                   deckCount--;
                   break; 

             case 3:
                   if(deckCount==0){
                         cout<<"No deck Exist yet first create a deck"<<endl;
                         break;
                   }
                   cout<<"Enter deck number you want to display- ";
                   cin>>deckNumber;
                   while(deckNumber<1||deckNumber>deckCount){
                   cout<<"ERROR! Deck does not exist, enter a valid deck number- ";
                   cin>>deckNumber;
                   }
                   displayDeck(decks,deckNumber-1);
                   break;

             case 4:
                    flag = false;
                    break;

             default:
                   cout<<"Enter a valid choice"<<endl;                 
      }

    }while(flag);


    return 0;
}