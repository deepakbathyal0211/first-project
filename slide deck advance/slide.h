#ifndef SLIDE_H
#define SLIDE_H
#include <iostream>
#include <string>
#include <list>
using namespace std;

class TextBox
{
    int length;
    int breadth;
    string heading;
    string content;

public:
    TextBox();
    TextBox(int, int, string, string);
    void displayTextBox();
};

class Shape
{
    int type;
    int length;
    int breadth;

public:
    Shape();
    Shape(int, int, int);
    void displayShape();
};

class Image
{
    int length;
    int breadth;

public:
    Image();
    Image(int, int);
    void displayImage();
};

class Slide
{
    list<TextBox> T;
    list<Shape> S;
    list<Image> I;

public:
    int tCount, sCount, iCount;
    Slide();
    void addItems(Slide *);
    void addTextBox();
    void addShape();
    void addImage();
    void displaySlide();
};

class Deck : public Slide
{
    int slideCount;
    list<Slide> slides;

public:
    Deck();
    void addSlide();
    void removeSlides(int *, int);
    void moveSlides(int *, int, int);
    void copyPasteSlides(Deck *, int *, int, int);
    void cutPasteSlides(Deck *, int *, int, int);
    friend void displayDeck(Deck *, int);
};

Deck *createDeck(Deck *, int);
Deck *removeDeck(Deck *, int, int);
void displayDecks(Deck *, int);

#endif