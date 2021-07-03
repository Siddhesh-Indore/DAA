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
   void DuplicateSorted(int x);
  void DuplicateSortedCount(int x);
  void DuplicateSortedHashing(int x);
  void DuplicateUnsorted(int x);
  void DuplicateUnsortedHashing(int x,int y);
  int Max();
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

void Array:: DuplicateSorted(int x)
{
    int lastDuplicate=0;
    int size=x;
    for(int i=0;i<size;i++)
    {
        if(A[i]==A[i+1] && A[i]!=lastDuplicate)
        {
            cout<<" \n The Duplicate is "<<A[i];
            lastDuplicate=A[i];
        }
    }
}
void Array :: DuplicateSortedCount(int x)
{
    int n=x;
    for(int i=0;i<n-1;i++)
    {
        if(A[i]==A[i+1])
        {
            int j=i+1;
            while(A[i]==A[j]); j++;
            cout<<"\n"<<A[i]<< " is occuring "<<j-i<< " times."<<endl;
            i=j-1;

        }
    }
}
void Array :: DuplicateSortedHashing(int x)
{
  int size=x;
  int max=A[size-1];
  int *H=new int [max+1];
  for(int i=0;i<=max;i++)
  {
    H[i]=0;
  }
  for(int i=0;i<size;i++)
  {
    H[A[i]]++;
  }
  for(int i=0;i<=max;i++)
  {
    if(H[i]>1)
    {
      cout<<"\n"<<i<<" is occuring "<<H[i]<<" times. \n";
    }
  }
}
void Array :: DuplicateUnsorted(int x)
{
  int size=x;
  for(int i=0;i<size-1;i++)
  {
    int count=1;
    if(A[i]!=-1)
    {
      for(int j=i+1;j<size;j++)
      {
        if(A[i]==A[j])
        {
          count++;
          A[j]=-1;
        }
      }
      if(count>1)
      {
        cout<<"\n"<<A[i]<<" is occuring "<<count<<" times";
      }
    }
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
void Array:: DuplicateUnsortedHashing(int x,int y)
{
  int size = x;
  int max=y;
  int *H = new int [max+1];
  for(int i=0;i<=max;i++)
  {
    H[i]=0;
  }
  for(int i=0;i<size;i++)
  {
    H[A[i]]++;

  }
  for(int i=0;i<=max;i++)
  {
    if(H[i]>1)
    {
      cout<<"\n"<<i<<" is occuring "<<H[i]<<" times. \n";
    }
  }
  
}

int main() {
   Array *arr;
   int sz,x;

 cout<<"Enter Size of Array ";
 cin>>sz;
 arr=new Array(sz);
 for (int i=0;i<sz;i++)
 {
   cout<<"Enter the Element "<<" \n ";
   cin>>x;
   arr->Append(x);
 }
   arr->Display();
   int m =arr->Max();
//    arr->DuplicateSorted(sz);
// arr->DuplicateSortedCount(sz);
// arr->DuplicateSortedHashing(sz);
// arr->DuplicateUnsorted(sz);
// arr->DuplicateUnsortedHashing(sz,m);

   return 0;
}