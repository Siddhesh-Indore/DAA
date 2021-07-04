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
    void Pair(int x,int y);
    void PairHashing(int x,int y,int z);
     int Max();
    void PairSorted(int x,int y);
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
void Array:: Pair(int x,int y)
{
    int size=x; 
    int k=y;
    for(int i=0;i<size-1;i++)
    {
        for(int j=i+1;j<size;j++)
        {
            if(A[i]+A[j]==k)
            {
                cout<<" \n "<<A[i]<<" and "<<A[j]<<" adds upto "<<k<<endl;
    
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
void Array :: PairHashing(int x,int y,int z)
{
    int size=x;
    int max=z;
    int k=y;
    int *H=new int [max+1];
    for(int i=0;i<=max;i++)
    {
        H[i]=0;
    }
    for(int i=0;i<size;i++)
    {
        if(H[k-A[i]]==1)
        {
            cout<<" \n"<<A[i]<<" + "<<k-A[i]<<" = "<<k<<endl;
        }
        H[A[i]]++;
    }
}
void Array :: PairSorted(int x,int y)
{
    int size=x;
    int k=y;
    int i=0;int j=size-1;
    while(i<j)
    {
        if(A[i]+A[j]==k)
        {
           cout<<" \n"<<A[i]<<" + "<<A[j]<<" = "<<k<<endl; 
           i++;
           j--;
        }
        else if(A[i]+A[j]>k)
        {
            j--;
        }
        else
        {
            i++;
        }
    }
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
   int y=10;
//    arr->Pair(sz,y);
//    int m =arr->Max();
//    arr->PairHashing(sz,y,m);
arr->PairSorted(sz,y);

}