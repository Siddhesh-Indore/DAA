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
   void MissingNew(int a, int b,int x);
   int Max();
   int Min();
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
void Array :: MissingNew(int a,int b,int x)
{
  int *B;
  B=(int *)malloc(length*sizeof(int));
  for(int i=0;i<x;i++)
  {
    B[i]=0;
  }
  int l=b;
  int h=a;
  int n=x;
  for(int i=0;i<n;i++)
  {
    B[A[i]]++;

  }
  for(int i=l;i<=h;i++)
  {
    if (B[i]==0)
      cout<<"\n Missing Elements is \n"<< i;
  }

}
int Array::Max()
{
 int max=A[0];
 int i;
 for(i=1;i<length;i++)
 {
 if(A[i]>max)
 max=A[i];
 }
 return max;
}
int Array::Min()
{
 int min=A[0];
 int i;
 for(i=1;i<length;i++)
 {
 if(A[i]<min)
 min=A[i];
 }
 return min;
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
   int max=arr->Max();
   int min=arr->Min();
   arr->MissingNew(max,min,sz);


  // arr->MissingOne(sz);
  // arr->MissingMany(sz);
   
 
  return 0;
}
