#include <iostream>
#include <unistd.h>
#include <list>
#include <bits/stdc++.h>
using namespace std;

class A
{
    int x, y;

public:
     A(){

     }
    A(int x, int y)
    {
        this->x = x;
        this->y = y;
    }
    void display()
    {
        cout << "X- " << x << endl;
        // cout << "y- " << y << endl;
    }
};

void add(list<A> *a)
{
    for (int i = 0; i < 5; i++)
    {
        A temp(10 + i, 20 + i);
        a->push_back(temp);
    }

    // return a;
}

int main()
{

    list<A> a;

    add(&a);
    // A *temp;
    // a.push_back(*temp);
    // a.push_back(10);
    // a.push_back(20);
    // a.push_back(30);
    // a.push_back(40);
    // a.push_back(50);
    A temp[5];
    for(int i=0;i<5;i++)
    temp[i]=A(i*5,i*10);

    list<A>::iterator it1 = a.begin(),j=a.begin(),l;
    list<A>::iterator it2 = a.end(),i;
 
    //  a.insert(it2,1,temp);
    //  it2 = a.end();

    int k=0;
    // for ( i = it1; i != it2; i++)
    // {
    //      k++;
    //      if(k==2||k==4)
    //      continue;
    //     *j=*i;
    //      j++;

    // }
      list<A> b;
      for(int i=0;i<5;i++)
      b.push_back(temp[i]);

      for(i=it1;i!=it2;i++){
          if(k==2)
          break;
          k++; 
      }

     for(l=b.begin();l!=b.end();l++)
      a.insert(i,1,*l);
     

    //  a.erase(j);
    //   j=a.end();
    //   j--;
    //  a.erase(j);


        cout<<a.size()<<endl;

     it1 = a.begin();
     it2 = a.end();

    for(i=it1;i!=it2;i++)
        i->display();
    

    return 0;
}