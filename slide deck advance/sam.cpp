#include <iostream>
#include <string>
using namespace std;

int main(){
 int n;
  string s1, s2,s3;
   cout<<"Enter num- ";
   cin>>n;
   getchar();
   cout<<"Enter string1";
   getline(cin,s1);
   cout<<"Enter string2";
   getline(cin,s2);
   cout<<n<<endl<<s1<<endl<<s2<<endl;

    return 0;
}