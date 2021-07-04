#include<iostream>
using namespace std;

class Array
{
    private:
    int length;
    int size;
    int *A;
    public:
    Array()
    {
        size=10;
        length=0;
        A=new int[size];
    }
    Array(int sz)
    {
        size=sz;
        length=0;
        A= new int [size];
    }
    ~Array()
    {
        delete[]A;
    }
    void Display();
    void Append(int x);
    void MaxMin(int x);
};
void Array :: Display()
{
    int i;
    cout<<"\nElements are\n";
    for(i=0;i<length;i++)
    cout<<A[i]<<" ";
}
void Array:: Append(int x)
{
  int i=0;
  if(length<size)
    A[length++]=x;
}
void Array :: MaxMin(int x)
{
    int size=x;
    int max=A[0];
    int min=A[0];
    for(int i=0;i<size;i++)
    {
        if(A[i]<min)
            min=A[i];
        else if(A[i]>max)
            max=A[i];
    }
    cout<<" \n Min = "<<min<<" and Max = "<<max<<endl;
}
int main()
{
    Array *arr;
   int sz,x;

 cout<<"Enter Size of Array ";
 cin>>sz;
 arr=new Array(sz);
 for (int i=0;i<sz;i++)
 {
   cout<<"Enter the Element"<<"\n";
   cin>>x;
   arr->Append(x);
 }
   arr->Display();
   arr->MaxMin(sz);
   return 0;
}
