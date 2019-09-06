#include "iostream"
#include "stdlib.h"
#include "time.h"

using namespace std;

void fun (int a[], int n) {
    for (int i=0;i<n;i++) {
      for (int j=0;j<a[i];j++) {
        cout<<"** ";
      }
      cout<<"\n\n";
    }
};

void delay (float t) {
    double i, j;
    t = t*10000;
    for (i=1;i<=(2*t);i++)
        for (j=0;j<=10000;j++);
};

int main () {
  int n, pro, i, j, temp, min, loc;

  state : {
      cout<<"Hit any number key to generate an array\n";
      cin>>n;

      srand(time(0));
      int a[n];

      for (i=0;i<n;i++) {
          pro = (i+1)*n;
          pro/=2;
          if (pro>=40)
            a[i] = rand() % 40;
          else
              a[i] = rand() % pro;

          if (a[i]==0)
          a[i] = 1;
      }

      for (i=0;i<n;i++)
          cout<<a[i]<<" ";

      delay(2);
      system("cls");

      for (i=0;i<n;i++) {
        for (j=0;j<(n-1-i);j++) {
          if (a[j]>a[j+1]) {
            temp = a[j];
            a[j] = a[j+1];
            a[j+1] = temp;
          }
        }

        fun(a,n);

        delay(0.5);
        if (i==n-1)
            continue;
        else
            system("cls");
      }

      cout<<endl;
      for (i=0;i<n;i++)
          cout<<a[i]<<" ";
      cout<<"\nSORTED!";
  }
  delay(2);
  system("cls");

  char ch;
  cout<<"\nPlay again?";
  cin>>ch;
  if (ch=='y')
    goto state;
  else
    return 0;
}
