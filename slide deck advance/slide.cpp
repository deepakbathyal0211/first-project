#include "slide.h"

TextBox::TextBox()
{
    this->length = 0;
    this->breadth = 0;
    this->heading = "Guest";
    this->content = "Guest";
}

TextBox::TextBox(int length, int breadth, string heading, string content)
{
    this->length = length;
    this->breadth = breadth;
    this->heading = heading;
    this->content = content;
}

void TextBox::displayTextBox()
{
    cout << "<--TextBox-->" << endl;
    cout << "Length- " << this->length << endl;
    cout << "Breadth- " << this->breadth << endl;
    cout << "Heading- " << this->heading << endl;
    cout << "Content- " << this->content << endl;
    cout << endl;
}

Shape::Shape()
{
    this->type = 0;
    this->length = 0;
    this->breadth = 0;
}

Shape::Shape(int type, int length, int breadth)
{
    this->type = type;
    this->length = length;
    this->breadth = breadth;
}

void Shape::displayShape()
{
    switch (this->type)
    {
    case 1:
        cout << "<--Rectangle-->" << endl;
        cout << "Length- " << this->length << endl;
        cout << "Breadth- " << this->breadth << endl;
        break;

    case 2:
        cout << "<--Square-->" << endl;
        cout << "Side- " << this->length << endl;
        break;

    case 3:
        cout << "<--Circle-->" << endl;
        cout << "Radius- " << this->length << endl;
        break;

    case 4:
        cout << "<--Arrow-->" << endl;
        cout << "Length- " << this->length << endl;
        break;
    }
    cout << endl;
}

Image::Image()
{
    this->length = 0;
    this->breadth = 0;
}

Image::Image(int length, int breadth)
{
    this->length = length;
    this->breadth = breadth;
}

void Image::displayImage()
{
    cout << "<--Image-->" << endl;
    cout << "Length- " << this->length << endl;
    cout << "Breadth- " << this->breadth << endl;
    cout << endl;
}

Slide::Slide()
{
    this->tCount = 0;
    this->sCount = 0;
    this->iCount = 0;
}

void Slide::addItems(Slide *temp)
{
    int ch;
    bool flag = true;
    do
    {
        cout << "Enter Your Choice" << endl;
        cout << "1. Add TextBox" << endl;
        cout << "2. Add Shape" << endl;
        cout << "3. Add Image" << endl;
        cout << "4. Exit" << endl;
        cin>>ch;
        switch (ch)
        {
        case 1:
            temp->addTextBox();
            temp->tCount++;
            break;

        case 2:
            temp->addShape();
            temp->sCount++;
            break;

        case 3:
            temp->addImage();
            temp->iCount++;
            break;

        case 4:
            flag = false;
            break;

        default:
            cout << "Enter a valid choice" << endl;
        }
    } while (flag);
}

void Slide::addTextBox()
{
    int length, breadth;
    string heading, content;
    TextBox temp;
    cout << "Enter length- ";
    cin >> length;
    cout << "Enter breadth- ";
    cin >> breadth;
    cin.ignore();
    cout << "Enter heading- ";
    getline(cin, heading);
    cout << "Enter content- ";
    getline(cin, content);

    temp = TextBox(length, breadth, heading, content);
    T.push_back(temp);

    cout << "TextBox Added Successfully" << endl;
}

void Slide::addShape()
{
    int length, breadth, type;
    Shape temp;
    cout << "Enter your choice- ";
    cout << "1. Rectangle" << endl;
    cout << "2. Square" << endl;
    cout << "3. Circle" << endl;
    cout << "4. Arrow" << endl;
    cin>>type;
    switch (type)
    {
    case 1:
        cout << "Enter length- ";
        cin >> length;
        cout << "Enter breadth- ";
        cin >> breadth;
        break;

    case 2:
        cout << "Enter side- ";
        cin >> length;
        breadth = length;
        break;

    case 3:
        cout << "Enter radius- ";
        cin >> length;
        breadth = length;
        break;

    case 4:
        cout << "Enter length- ";
        cin >> length;
        breadth = length;
        break;

    default:
        cout << "Enter a valid choice" << endl;
    }
    if (type > 0 && type < 5)
    {
        temp = Shape(type, length, breadth);
        S.push_back(temp);
    }

    cout << "Shape Added Successfully" << endl;
}

void Slide::addImage()
{
    int length, breadth;
    Image temp;
    cout << "Enter length- ";
    cin >> length;
    cout << "Enter breadth- ";
    cin >> breadth;
    temp = Image(length, breadth);
    I.push_back(temp);

    cout << "Image Added Successfully" << endl;
}

void Slide::displaySlide()
{
    int ch;
    cout << "<---Slide Content--->" << endl;
    list<TextBox>::iterator i;
    for (i = T.begin(); i != T.end(); i++)
        i->displayTextBox();

    list<Shape>::iterator j;
    for (j = S.begin(); j != S.end(); j++)
        j->displayShape();

    list<Image>::iterator k;
    for (k = I.begin(); k != I.end(); k++)
        k->displayImage();
}

Deck::Deck()
{
    this->slideCount = 0;
}

void Deck::addSlide()
{
    Slide temp;

    addItems(&temp);

    slides.push_back(temp);
    slideCount++;
}

Deck *createDeck(Deck *deck, int deckCount)
{
    if (deckCount == 0)
        deck = new Deck();
    else
    {
        Deck *temp = new Deck[deckCount + 1];
        for (int i = 0; i < deckCount; i++)
            temp[i] = deck[i];
        temp[deckCount] = Deck();
        delete[] deck;
        deck = temp;
    }

    while (1)
    {
        int ch;
        cout << "1. Add Slide" << endl;
        cout << "2. Exit" << endl;
        cin >> ch;
        switch (ch)
        {
        case 1:
            deck[deckCount].addSlide();
            break;

        case 2:
            break;

        default:
            cout << "Enter a valid choice" << endl;
        }
        if (ch == 2)
            break;
    }

    return deck;
}

Deck *removeDeck(Deck *deck, int deckCount, int deckNumber)
{
    int k = 0;
    for (int i = 0; i < deckCount; i++)
    {
        if ((i + 1) == deckNumber)
            continue;
        deck[k++] = deck[i];
    }

    return deck;
}

void Deck::removeSlides(int *a, int n)
{ 
    list<Slide>::iterator i, k = slides.begin();
    int count = 0, z = 0;
    for (i = slides.begin(); i != slides.end(); i++)
    {
        count++;
        for (int j = 0; j < n; j++)
        {
            if (count == a[j])
            {
                z++;
                continue;
            }
            *k = *i;
            k++;
        }
    }
    while (z--)
    {
        i = slides.end();
        i--;
        slides.erase(i);
    }
}

void Deck::moveSlides(int *a, int n, int pos)
{
    int count = 0;
    list<Slide>::iterator i, k;
    list<Slide> temp;
    for (i = slides.begin(); i != slides.end(); i++)
    {
        count++;
        for (int j = 0; j < n; j++)
        {
            if (count == a[j])
                temp.push_back(*i);
        }
    }
    count = 0;

    for (i = slides.begin(); i != slides.end(); i++)
    {
        count++;
        if (count == pos)
            break;
    }

    removeSlides(a, n);

    for (k = temp.begin(); k != temp.end(); k++)
    {
        slides.insert(i, 1, *k);
        i++;
    }
}

void Deck::copyPasteSlides(Deck *deck, int *a, int n, int pos)
{
    list<Slide>::iterator i, k;
    list<Slide> temp;
    int count = 0;
    for (i = deck->slides.begin(); i != deck->slides.end(); i++)
    {
        count++;
        if (count == pos)
            break;
    }

    count = 0;
    for (k = slides.begin(); k != slides.end(); k++)
    {
        count++;
        for (int j = 0; j < n; j++)
        {
            if (count == a[j])
                deck->slides.insert(i, 1, *k);
        }
    }
}
void Deck::cutPasteSlides(Deck *deck, int *a, int n, int pos)
{
    list<Slide>::iterator i, k = slides.begin();
    list<Slide> temp;
    int count = 0;
    for (i = slides.begin(); i != slides.end(); i++)
    {
        count++;
        for (int j = 0; j < n; j++)
        {
            if (a[j] == count)
                temp.push_back(*i);
        }
    }

    count = 0;
    for (i = deck->slides.begin(); i != deck->slides.end(); i++)
    {
        count++;
        if (count == pos)
            break;
    }

    this->removeSlides(a, n);

    for (k = temp.begin(); k != temp.end(); k++)
        deck->slides.insert(i, 1, *k);
}

void displayDeck(Deck *decks, int deckNumber)
{
    int ch, n, pos, deckNum;
    list<Slide>::iterator i;
    for (i = decks[deckNumber].slides.begin(); i != decks[deckNumber].slides.end(); i++)
    {
        i->displaySlide();

        while (1)
        {
            cout << "Enter choice" << endl;
            cout << "1. Add Items to this slide" << endl;
            cout << "2. Add slides to this deck" << endl;
            cout << "3. Remove slides from this deck" << endl;
            cout << "4. Move slides in this deck" << endl;
            cout << "5. Copy and paste slides from one to other deck" << endl;
            cout << "6. Cut and paste slides from one to other deck" << endl;
            cout<<"7. Next Slide"<<endl;
            cout << "8. Exit" << endl;
            cin >> ch;
            switch (ch)
            {
            case 1:
                while (1)
                {
                    cout << "Enter choice" << endl;
                    cout << "1. Add TextBox" << endl;
                    cout << "2. Add Shape" << endl;
                    cout << "3. Add Image" << endl;
                    cout << "4. Exit" << endl;
                    cin >> ch;
                    switch (ch)
                    {
                    case 1:
                        i->addTextBox();
                        i->tCount++;
                        break;

                    case 2:
                        i->addShape();
                        i->sCount++;
                        break;

                    case 3:
                        i->addImage();
                        i->iCount++;
                        break;

                    case 4:
                        break;

                    default:
                        cout << "Enter a valid choice" << endl;
                    }
                    if (ch == 4)
                        break;
                }

                break;

            case 2:
                decks[deckNumber].addSlide();
                break;

            case 3:
            {
                cout << "Enter no. of slides u want to remove- ";
                cin >> n;
                int a[n];
                cout << "Enter slides no. u want to remove- ";
                for (int j = 0; j < n; j++)
                    cin >> a[j];
                decks[deckNumber].removeSlides(a, n);
            }
            break;

            case 4: 
                {
                cout << "Enter no. of slides u want to move- ";
                cin >> n;
                int a[n];
                cout << "Enter slides no. u want to move- ";
                for (int j = 0; j < n; j++)
                    cin >> a[j];
                cout << "Enter the position u want to move slides- ";
                cin >> pos;
                decks[deckNumber].moveSlides(a, n, pos);
                }
                break;

            case 5:
                {
                cout << "Enter the deck no. in which u want to paste- ";
                cin >> deckNum;
                cout << "Enter the no. of u want to copy- ";
                cin >> n;
                int a[n];
                cout << "Enter slides no. u want to copy- ";
                for (int j = 0; j < n; j++)
                    cin >> a[j];
                cout << "Enter the position u want to paste in other deck- ";
                cin >> pos;
                decks[deckNumber].copyPasteSlides(&decks[deckNum], a, n, pos);
                }
                break;

            case 6:
                 {
                cout << "Enter the deck no. u in which want to paste- ";
                cin >> deckNum;
                cout << "Enter the no. of u want to cut- ";
                cin >> n;
                int a[n];
                cout << "Enter slides no. u want to cut- ";
                for (int j = 0; j < n; j++)
                    cin >> a[j];
                cout << "Enter the position u want to paste in other deck- ";
                cin >> pos;
                decks[deckNumber].cutPasteSlides(&decks[deckNum], a, n, pos);
                 }
                break;

             case 7:
                  break;

            case 8: 
                 return ;

            default:
                cout << "Enter a valid choice" << endl;
            }
            if (ch == 7)
                break;
        }

        cout << "************************************" << endl
             << endl;
    }
}
