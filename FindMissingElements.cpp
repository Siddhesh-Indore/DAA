#include<iostream>
using namespace std;

 int main() {
  int A[]={1,2,3,4,5,6,8,9,10,11,12};
  int l=A[0];
  int h=A[10];
  int n=11;
  int s=0;
  int Sum = (h*(h+1))/2;
  for(int i=0;i<n;i++)
  {
    s=s+A[i];
  }
 cout << "The missing number is "<<Sum-s << '\n';
  return 0;
}
