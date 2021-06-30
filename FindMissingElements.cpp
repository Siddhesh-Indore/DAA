#include<iostream>
using namespace std;

class Array
{
private:
  int *A;
  int size;
  int length;

public:
  Array()
  {
    size=11;
    length=0;
    A= new int [size];
  }
  Array(int sz)
  {
    size=sz;
    length=0;
    A=new int [size];
  }
  ~Array()
  {
    delete []A;
  }
  void Display();
   void Append(int x);
   void MissingOne(int x);
   void MissingMany(int x);
};
void Array:: Append(int x)
{
  int i=0;
  if(length<size)
    A[length++]=x;
  
}
void Array::Display()
{
 int i;
 cout<<"\nElements are\n";
 for(i=0;i<length;i++)
 cout<<A[i]<<" ";
}
void Array :: MissingOne(int x)
{
  int l=A[0];
  int h=A[10];
  int n=x;
  int s=0;
  int Sum = (h*(h+1))/2;
  for(int i=0;i<n;i++)
  {
    s=s+A[i];
  }
 cout << "\n The missing number is "<<Sum-s << '\n';
}

void Array:: MissingMany(int x)
{
  int l=A[0];
  int h=A[10];
  int n=x;
  int diff = A[0]-0;
for(int i=0;i<n;i++)
{
  if(A[i]-i!=diff)
  {
    while (diff<A[i]-i) {
      cout << " \n The missing number is "<<i+diff << '\n';
      diff++;
    }
  }
}
   
}

 int main() {
   Array *arr;
   int sz,x;

 cout<<"Enter Size of Array";
 cin>>sz;
 arr=new Array(sz);
 for (int i=0;i<sz;i++)
 {
   cout<<"Enter the Element"<<"\n";
   cin>>x;
   arr->Append(x);
 }
   arr->Display();
  // arr->MissingOne(sz);
   arr->MissingMany(sz);
 
 
  return 0;
}
