#include <stdio.h>
#include <stdlib.h>
void swap(int *x,int *y)
{
    int temp;
    temp=*x;
    *x=*y;
    *y=temp;

}
struct Array
{
    int *A;
    int size;
    int length;
};
int Delete(struct Array *arr1,int index);
void Display(struct Array arr1)
{
    int i;
    for(i=0;i<arr1.length;i++)
    {
        printf("\n %d \n",arr1.A[i]);
    }
}

void Append(struct Array *arr1,int x)
{
    if(arr1->length<arr1->size)
    {
        arr1->A[arr1->length++]=x;
    }
}
void Insert(struct Array *arr1,int index,int x)
{
    int i;
    if(index>=0 && index<=arr1->length)
    {
     for(i=arr1->length;i>index;i--)
     {
         arr1->A[i]=arr1->A[i-1];
     }
      arr1->A[index]=x;
      arr1->length++;
    }
};
int Delete(struct Array *arr1,int index)
{
    int x=0;
    x=arr1->A[index];
    if(index>=0 && index<=arr1->length)
    {
        for(int i=index;i<arr1->length-1;i++)
            arr1->A[i]=arr1->A[i+1];\
        arr1->length--;
        return x;
    }
    return 0;
};
int LinearSearch(struct Array arr1,int key)
{
    int i;
    for(i=0;i<arr1.length;i++)
    {
        if(key==arr1.A[i])
        return i;
    }
    return -1;
};

int LinearSearch1(struct Array *arr1,int key)
{
    int i;
    for(i=0;i<arr1->length;i++)
    {
        if(key==arr1->A[i])
        {
            swap(&arr1->A[i],&arr1->A[i-1]);
            return i;
        }


    }
    return -1;
};

int LinearSearch2(struct Array *arr1,int key)
{
    int i;
    for(i=0;i<arr1->length;i++)
    {
        if(key==arr1->A[i])
        {
            swap(&arr1->A[0],&arr1->A[i]);
            return 0;
        }


    }
    return -1;
};

int BinarySearch(struct Array arr1,int key)
{
    int l,h,mid;
    l=0;
    h=arr1.length-1;
    while(l<=h)
    {
        mid=(l+h)/2;
        if(key==arr1.A[mid])
            return mid;
        else if(key<arr1.A[mid])
            return h=mid-1;
        else
            return l=mid+1;
    }
    return -1;
}
int RBinarySearch(int a[],int l,int h,int key)
{
    int mid;
    if(l<=h)
    {
        mid=(l+h)/2;
        if(key==a[mid])
            return mid;
        else if (key<a[mid])
            return RBinarySearch(a,l,mid-1,key);
        else
            return RBinarySearch(a,mid+1,h,key);
    }
     return -1;
}

int Get(struct Array arr1,int index)
{
    if(index>=0 && index<arr1.length)
       return arr1.A[index];
    return -1;
}

void Set(struct Array *arr1,int index, int x)
{
    if(index>=0 && index<arr1->length)
        arr1->A[index]=x;
}

int Max(struct Array arr1)
{
    int max=arr1.A[0];
    int i;
    for(i=1;i<arr1.length;i++)
    {
        if(arr1.A[i]>max)
            max=arr1.A[i];
    }
    return max;
}

int Min(struct Array arr1)
{
    int min=arr1.A[0];
    int i;
    for(i=1;i<arr1.length;i++)
    {
        if(arr1.A[i]<min)
            min=arr1.A[i];
    }
    return min;
}

int Sum(struct Array arr1)
{
    int Total=0;
    for(int i=0;i<arr1.length;i++)
    {
        Total=Total+arr1.A[i];
    }
    return Total;
}

float Avg(struct Array arr1)
{
    int Total=0;
    for(int i=0;i<arr1.length;i++)
    {
        Total=Total+arr1.A[i];
    }
    return Total/arr1.length;
}
void Reverse(struct Array *arr1)
{
    int *B;
    int i,j;
    B=(int*)malloc(arr1->length*sizeof(int));
    for(i=arr1->length-1,j=0;i>=0;i--,j++)
    {
        B[j]=arr1->A[i];
    }
    for(i=0;i<arr1->length;i++)
    {
        arr1->A[i]=B[i];
    }
}
void Reverse1 (struct Array *arr1)
{
    int i,j,temp;
    for(i=0,j=arr1->length-1;i<j;i++,j--)
    {
        temp =arr1->A[i];
        arr1->A[i]=arr1->A[j];
        arr1->A[j]=temp;
    }
}
int InsertSort(struct Array *arr1,int x)
{
    int i=arr1->length-1;
    if (arr1->length==arr1->size)
    {
        return 0;
    }
    while(i>=0 && arr1->A[i]>x)
    {
        arr1->A[i+1]=arr1->A[i];
        i--;
    }
    arr1->A[i+1]=x;
    arr1->length++;
}

int isSorted (struct Array arr1)
{
   int i;
   for(i=0;i<arr1.length-1;i++)
   {
       if(arr1.A[i]>arr1.A[i+1])
           return 0;
   }
   return 1;
}
void Reaarange(struct Array *arr1)
{
    int i=0;
    int j=arr1->length-1;
    while(i<j)
    {
        while(arr1->A[i]<0){i++;}
        while(arr1->A[j]>0){j--;}
        if(i<j)
        {
            swap(&arr1->A[i],&arr1->A[j]);
        }
    }
}

struct Array* merge(struct Array *arr1,struct Array *arr2)
{
 int i,j,k;
 i=j=k=0;

 struct Array *arr3=(struct Array *)malloc(sizeof(struct Array));

 while(i<arr1->length && j<arr2->length)
 {
 if(arr1->A[i]<arr2->A[j])
 arr3->A[k++]=arr1->A[i++];
 else
 arr3->A[k++]=arr2->A[j++];
 }
 for(;i<arr1->length;i++)
 arr3->A[k++]=arr1->A[i];
 for(;j<arr2->length;j++)
 arr3->A[k++]=arr2->A[j];
 arr3->length=arr1->length+arr2->length;
 arr3->size=10;

 return arr3;
}

struct Array* Union (struct Array *arr1,struct Array *arr2)
{
    int i,j,k;
    i=j=k=0;

    struct Array *arr3=(struct Array *)malloc(sizeof(struct Array));

    while(i<arr1->length && j<arr2->length)
    {
        if(arr1->A[i]<arr2->A[j])
            arr3->A[k++]=arr1->A[i++];
        else if(arr2->A[j]<arr1->A[i])
            arr3->A[k++]=arr2->A[j++];
        else

            {arr3->A[k++]=arr1->A[i++];
            j++;
            }
    }
for(;i<arr1->length;i++)
  arr3->A[k++]=arr1->A[i];
for(;j<arr2->length;j++)
  arr3->A[k++]=arr2->A[j];
arr3->length=k;
arr3->size=10;

 return arr3;
}

struct Array* Intersection (struct Array *arr1,struct Array *arr2)
{
    int i,j,k;
    i=j=k=0;

    struct Array *arr3=(struct Array *)malloc(sizeof(struct Array));

    while(i<arr1->length && j<arr2->length)
    {
        if(arr1->A[i]<arr2->A[j])
            i++;
        else if(arr2->A[j]<arr1->A[i])
            j++;
        else
            {
            arr3->A[k++]=arr1->A[i++];
            j++;
            }
    }
arr3->length=k;
arr3->size=10;

 return arr3;
}
struct Array* Difference (struct Array *arr1,struct Array *arr2)
{
    int i,j,k;
    i=j=k=0;

    struct Array *arr3=(struct Array *)malloc(sizeof(struct Array));

    while(i<arr1->length && j<arr2->length)
    {
        if(arr1->A[i]<arr2->A[j])
            arr3->A[k++]=arr1->A[i++];
        else if(arr2->A[j]<arr1->A[i])
                    j++;
        else
            {
             i++;
             j++;
            }
    }
for(;i<arr1->length;i++)
  arr3->A[k++]=arr1->A[i];
arr3->length=k;
arr3->size=10;

 return arr3;
}


int main()
{
//struct Array arr1={{2,6,10,15,25},10,5};
   //Append(&arr1,8);
   //Insert(&arr1,3,10);
   //printf("\nThe deleted number is %d\n",Delete(&arr1,2));
   //printf("\n %d \n ",LinearSearch(arr1,4));
   //printf("\n %d \n ",LinearSearch1(&arr1,4));
//   printf("\n %d \n ",LinearSearch2(&arr1,4));
//     printf("%d \n",BinarySearch(arr1,2));
//     printf("%d \n",RBinarySearch(arr1.A,0,arr1.length,2));
//     printf("%d",Get(arr1,2));
//     Set(&arr1,0,15);
//     printf("%d",Max(arr1));
//     printf("%d",Min(arr1));
//     printf("%d",Sum(arr1));
//     printf("%f",Avg(arr1));
//     Reverse(&arr1);
//     Reverse1(&arr1);
//     InsertSort(&arr1,1);
//     printf("%d",isSorted(arr1));
//     Reaarange(&arr1);

// Display(arr1);

//struct Array arr2={{3,6,7,15,20},10,5};
// struct Array *arr3;
// arr3=Union(&arr1,&arr2);
//arr3=merge(&arr1,&arr2);
//arr3=Intersection(&arr1,&arr2);
//arr3=Difference(&arr1,&arr2);
// Display(*arr3);
struct Array arr1;
int ch=0;
int x=0;int index=0;
printf("Enter the size of an Array");
scanf("%d",&arr1.size);
arr1.A=(int*)malloc(arr1.size*sizeof (int));
arr1.length=0;

do
{
    printf("\n \n Menu\n");
    printf("1. Insert \n");
    printf("2. Delete \n");
    printf("3. Search \n");
    printf("4. Sum \n");
    printf("5. Dispaly \n");
    printf("6. Exit \n");

    printf("Enter your choise");
    scanf("%d",&ch);

    switch(ch)
    {
        case 1: printf("Enter the element and Index");
                scanf("%d %d",&x,&index);
                Insert(&arr1,index,x);
                break;
        case 2: printf("Enter index");
                scanf("%d",&index);
                Delete(&arr1,index);
                printf("Delete element is %d \n",x);
                break;
        case 3: printf("Enter the element to search");
                scanf("%d",&x);
                index=LinearSearch(arr1,x);
                printf("Element index %d",index);
                break;
        case 4: printf("Sum is %d\n",Sum(arr1));
                break;
        case 5: Display(arr1);
    }

}while(ch<6);
   return 0;
}
