#include <iostream>

using s_t=size_t;
int * extend(const int * a,s_t k,s_t d, int filler) {
  int * newArray=new int[d];
  for (s_t i=0;i<std::min(k,d);++i) {
    newArray[i]=a[i];
  }
  for (s_t i=std::min(k,d);i<d;++i) {
    newArray[i]=filler;
  }
  return newArray;
}
void extend(int ** ptr_a,s_t k,s_t d, int filler) {
  int *newArray = extend(*ptr_a,k,d,filler);
  delete[] *ptr_a;  // освобождаем старый массив
  *ptr_a = newArray; // теперь ptr_a указывает на новый массив
}
int *add_row(const int* a,s_t n,s_t m, int filler) {
  return extend(a,n*m,(n+1)*m,filler);
}
int main(int argc, char const *argv[])
{
  // int *arr=new int[5]{1,2,3,4,5};
  // extend(&arr,5,10,0);
  // // int* newArr=extendVoid(*arr,5,10,0);
  // for (s_t i=0;i<6;++i) {
  //   std::cout<<arr[i]<<" ";
  // }

  int *array2=new int[4]{1,2,3,4};
  int *newMatrix=add_row(array2,2,2,0);
  for (s_t i=0;i<3;++i) {
    for (s_t j=0;j<2;j++) {
      std::cout<<newMatrix[i*2+j]<< ' ';
    }
    std::cout<<"\n";
  }
  delete[] array2;
}

