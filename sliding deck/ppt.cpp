#include "ppt.h"

TextBox::TextBox()                 //default constructor of textbox
{
    this->length = 0;
    this->breadth = 0;
}

TextBox::TextBox(int length, int breadth)              //parameterized constructor of textbox
{
    this->length = length;
    this->breadth = breadth;
}

/*void TextBox::setLengthTB(int length)
{
    this->length = length;
}

void TextBox::setBreadthTB(int breadth)
{
     this->breadth = breadth;
}*/

void TextBox::addTextBox(int length, int breadth)        //function for adding textbox
{
    this->length = length;
    this->breadth = breadth;
}

int TextBox::getLengthTB()                               //getter for length of textbox
{
    return this->length;
}

int TextBox::getBreadthTB()                             //getter for breadth of textbox
{
    return this->breadth;
}

Shape::Shape()                                    //default constructor of shape
{
    this->type = "Guest";
    this->length = 0;
    this->breadth = 0;
}

Shape::Shape(string type, int length, int breadth)     //parameterized constructor of shape
{
    this->type = type;
    this->length = length;
    this->breadth = breadth;
}

// void Shape::setLengthS(int length)
// {
//     this->length = length;
// }

// void Shape::setBreadthS(int breadth)
// {
//     this->breadth = breadth;
// }

// void Shape::setNameS(string type)
// {
//     this->type = type;
// }

void Shape::addShape(string type, int length, int breadth)         //function for adding any type of shape
{
    this->type = type;
    if (type == "Circle")
        this->length = this->breadth = length;
    else
    {
        this->length = length;
        this->breadth = breadth;
    }
}

int Shape::getLengthS()                  //gettter for length of shape
{
    return this->length;
}

string Shape::getTypeS()                   //getter for getting type of shape
{
    return this->type;
}

int Shape::getBreadthS()                    //getter for getting breadth of shape
{
    return this->breadth;
}

Image::Image()                              //default constructor for image
{
    this->length = 0;
    this->breadth = 0;
    this->color = "Guest";
}

Image::Image(string color, int length, int breadth)       //parameterized constructor for image
{
    this->color = color;
    this->length = length;
    this->breadth = breadth;
}

// void Image::setLengthI(int length)
// {
//     this->length = length;
// }

// void Image::setBreadthI(int breadth)
// {
//     this->breadth = breadth;
// }

// void Image::setColorI(string color)
// {
//     this->color = color;
// }

void Image::addImage(string color, int length, int breadth)     //function for adding image
{
    this->length = length;
    this->breadth = breadth;
    this->color = color;
}

int Image::getLengthI()              //getter for getting length of image
{
    return this->length;
}

int Image::getBreadthI()                //getter for breadth of image
{
    return this->breadth;
}

string Image::getColorI()               //getter for color of image
{
    return this->color;
}

Deck::Deck()                             ////default constructor for deck
{
    //Default constructor of deck
}

void Deck::setT(int i)                  //setter for textbox
{
    this->t = i;
}

void Deck::setS(int i)                  //setter for shape
{
    this->s = i;
}

void Deck::setI(int i)                 //setter for image
{
    this->i = i;
}

int Deck::getT()                              //getter for textbox
{
    return this->t;
}

int Deck::getS()                         //getter for shape
{
    return this->s;
}

int Deck::getI()                            //getter for image
{
    return this->i;
}

void Deck::display()                     //display function to display all of parameters of slide
{
    if (this->getT() == 1)
    {
        cout << "<--Textbox-->" << endl;
        cout << "Length- " << getLengthTB() << endl;
        cout << "Breadth- " << getBreadthTB() << endl
             << endl;
    }

    if (getS() == 1)
    {
        cout << "Shape of type- " << getTypeS() << endl;
        if (getTypeS() == "Circle")
            cout << "Radius of Circle - " << getLengthS() << endl;
        else if (getTypeS() == "Square")
            cout << "Square of side- " << getLengthS() << endl;
        else if (getTypeS() == "Rectangle")
        {
            cout << "Length- " << getLengthS() << endl;
            cout << "Breadth- " << getBreadthS() << endl
                 << endl;
        }
    }

    if (getI() == 1)
    {
        cout << "<--Image-->" << endl;
        cout << "Length- " << getLengthI() << endl;
        cout << "Breadth- " << getBreadthI() << endl;
        cout << "Color- " << getColorI() << endl;
    }
}

list<Deck> addSlides1(list<Deck> deck)              //function  for adding slides to deck 1
{

    Deck temp;
    temp.addTextBox(100, 100);
    temp.setT(1);
    temp.addShape("Square", 150, 150);
    temp.setS(1);
    temp.addImage("Red", 100, 100);
    temp.setI(1);

    deck.push_back(temp);

    temp.addTextBox(50, 70);
    temp.setT(1);
    temp.addImage("Green", 200, 120);
    temp.setI(1);
    temp.setS(0);
    deck.push_back(temp);

    temp.addTextBox(50, 70);
    temp.setT(1);
    temp.addShape("Circle", 70, 70);
    temp.setS(1);
    temp.setI(0);
    deck.push_back(temp);

    temp.addTextBox(30, 30);
    temp.setT(1);
    temp.addShape("Rectangle", 70, 40);
    temp.setS(1);
    temp.addImage("Maroon", 80, 60);
    temp.setI(1);

    temp.setT(0);
    temp.addShape("Circle", 80, 80);
    temp.setS(1);
    temp.addImage("Blue", 180, 160);
    temp.setI(1);

    return deck;
}

list<Deck> addSlides2(list<Deck> deck)                    //function  for adding slides to deck 2
{

    Deck temp;
    temp.addTextBox(50, 70);
    temp.setT(1);
    temp.addImage("Black", 400, 220);
    temp.setI(1);
    temp.setS(0);
    deck.push_back(temp);

    temp.addTextBox(100, 100);
    temp.setT(1);
    temp.addShape("Square", 150, 150);
    temp.setS(1);
    temp.addImage("Red", 100, 100);
    temp.setI(1);
    deck.push_back(temp);

    temp.addTextBox(60, 40);
    temp.setT(1);
    temp.addShape("Rectangle", 90, 50);
    temp.setS(1);
    temp.addImage("Maroon", 80, 60);
    temp.setI(1);

    temp.addTextBox(150, 80);
    temp.setT(1);
    temp.addShape("Circle", 70, 70);
    temp.setS(1);
    temp.setI(0);
    deck.push_back(temp);

    return deck;
}

void removeSlides(list<Deck> *deck, int *a, int n)             // function to remove slides from deck
{
    list<Deck>::iterator it1 = deck->begin(), i, k = deck->begin();
    list<Deck>::iterator it2 = deck->end();
    int count = 0, z = 0;
    for (i = it1; i != it2; i++)
    {
        count++;
        for (int j = 0; j < n; j++)
        {
            if (a[j] == count)
            {
                continue;
                z++;
            }
            *k = *i;                                //copying all elements except which to have remove
            k++;
        }
    }

    while (z--)                            //erasing all elements from last of list
    {
        k = deck->end();
        k--;
        deck->erase(k);
    }
}

void copyAndPaste(list<Deck> *deck1, list<Deck> *deck2, int *slidesNumber, int numberOfSlides)     //copy and pasting last of other slide
{
    list<Deck>::iterator it1 = deck1->begin(), i;
    list<Deck>::iterator it2 = deck1->end();
    list<Deck>::iterator it3 = deck2->end();
    int count = 0;
    for (i = it1; i != it2; i++)
    {
        count++;
        for (int j = 0; j < numberOfSlides; j++)
        {
            if (count == slidesNumber[j]) // using count as a slide no. and comapring with array.
            {                               // because iterator returns a pointer not index number
                deck2->insert(it3, 1, *i);                 //inserting at last of other slide
                it3 = deck2->end();
            }
        }
    }
}

void moveSlides(list<Deck> *deck, int *a, int n)        //moving all slides at the last of a deck
{
    list<Deck>::iterator it1 = deck->begin(), i;
    list<Deck>::iterator it2 = deck->end();
    list<Deck> temp;
    list<Deck>::iterator it3 = temp.begin();
    list<Deck>::iterator it4 = temp.end();
    int count = 0;
    for (i = it1; i != it2; i++)
    {
        count++;
        for (int j = 0; j < n; j++)
        {
            if (count == a[j])
            {
                temp.insert(it4, 1, *i);              //storing slides into temporay list which to be removed
                it4 = temp.end();
            }
        }
    }

    removeSlides(deck, a, n);                          //removing all slides which to be removed

    it3 = temp.begin();
    it4 = temp.end();
    it2 = deck->end();
    for (i = it3; i != it4; i++)
    {
        deck->insert(it2, 1, *i);                 //adding all slides at last of same slide from temporay slide
        it2 = deck->end();
    }
}

void displayAll(list<Deck> *deck1, list<Deck> *deck2)         //displaying slides one by one
{
    int ch, n, count = 0;
    list<Deck>::iterator it1 = deck1->begin();
    list<Deck>::iterator it2 = deck1->end();

    for (list<Deck>::iterator i = it1; i != it2; i++)
    {
        i->display();
        cout << "Enter choice " << endl;                     //option provided in every slide to perform need
        cout << "1. Next Slide" << endl;
        cout << "2. Remove Slides" << endl;
        cout << "3. Copy And Paste Slides" << endl;
        cout << "4. Cut And Paste Slides" << endl;
        cout << "5. Move Slides " << endl;
        cin >> ch;

        switch (ch)
        {
        case 1:
            if (it2 == ++i)
            {
                cout << "No slides avaliabale" << endl;
                break;
            }
            i--;
            break;

        case 2:
        {
            cout << "Enter slide no. u want to remove- ";
            cin >> n;
            int a[n];
            cout << "Enter Slide no.s- ";
            for (int i = 0; i < n; i++)
                cin >> a[i];
            removeSlides(deck1, a, n);                      //calling functio to remove slide
            it1 = deck1->begin();                       //after removing slides now we have new begin and end
            it2 = deck1->end();
        }
        break;

        case 3:
        {
            cout << "Enter the no. of slides u want to copy to another slide- ";
            cin >> n;
            int a[n];
            cout << "Enter slides no. u want to copy- ";
            for (int i = 0; i < n; i++)
                cin >> a[i];
            copyAndPaste(deck1, deck2, a, n);              //calling function for copy and paste
            it1 = deck1->begin();
            it2 = deck1->end();
        }
        break;

        case 4:
        {
            cout << "Enter no. of slides u want to cut and paste- ";
            cin >> n;
            int a[n];
            cout << "Enter slides no.- ";
            for (int i = 0; i < n; i++)
                cin >> a[i];
            count = 0;                                //writing  function here only for cut and paste
            list<Deck> temp;
            list<Deck>::iterator it3 = temp.begin(), i;
            list<Deck>::iterator it4 = temp.end();
            for (i = it1; i != it2; i++)
            {
                count++;
                for (int j = 0; j < n; j++)
                {
                    if (a[j] == count)
                    {
                        temp.insert(it4, 1, *i);                //storing all slides that to be cutted into temporay slide
                        it4 = temp.end();
                    }
                }
            }

            removeSlides(deck1, a, n);                      //removing all slides to be cut
            for (i = it3; i != it4; i++)
            {
                deck2->insert(it2, 1, *i);                   //inserting all cutted slides at end of other deck
                it2 = deck2->end();
            }

            it1 = deck1->begin();
            it2 = deck1->end();
        }
        break;

        case 5:
        {
            cout << "Enter no. of slides u want to move- ";
            cin >> n;
            cout << "Enter slides no. u want to move- ";
            int a[n];
            for (int i = 0; i < n; i++)
                cin >> a[i];
            moveSlides(deck1, a, n);                         // call move slide function
            it1 = deck1->begin();
            it2 = deck1->end();
        }
        break;

        default:
            cout << "Enter a valid choice" << endl;
        }
    }
}
