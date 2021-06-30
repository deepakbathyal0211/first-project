#ifndef PPT_H
#define PPT_H
#include <iostream>
#include <string>
#include <list>
#include <unistd.h>
using namespace std;

class TextBox                        //textbox class having length and breadth of textbox
{ 
    int length;
    int breadth;

public:
    TextBox();
    TextBox(int, int);
    // void setLengthTB(int);
    // void setBreadthTB(int);
    void addTextBox(int, int);
    int getLengthTB();
    int getBreadthTB();
};

class Shape                              //shape class having length breadth & type of shape
{
    string type;
    int length;
    int breadth;

public:
    Shape();
    Shape(string, int, int);
    // void setLengthS(int);
    // void setBreadthS(int);
    // void setNameS(string);
    void addShape(string, int, int);
    int getLengthS();
    int getBreadthS();
    string getTypeS();
};

class Image                                     //image class having length, breadth & color of image
{
    int length;
    int breadth;
    string color;

public:
    Image();
    Image(string, int, int);
    // void setLengthI(int);
    // void setBreadthI(int);
    // void setColorI(string);
    void addImage(string, int, int);
    int getLengthI();
    int getBreadthI();
    string getColorI();
};

class Deck : public TextBox, public Shape, public Image         //deck class inherited from textbox, shape & image
{

public:
    int t, s, i;
    Deck();
    void setT(int);
    void setS(int);
    void setI(int);
    int getT();
    int getS();
    int getI();
    void display();
};

list<Deck> addSlides1(list<Deck>);             //all function declartion
list<Deck> addSlides2(list<Deck>);
void removeSlides(list<Deck> *, int *, int);
void copyAndPaste(list<Deck> *, list<Deck> *, int *, int);
void moveSlides(list<Deck> *, int *, int);
void displayAll(list<Deck> *, list<Deck> *);
// void cutAndPaste();
#endif