#include <cstdlib>
#include <iostream>

#include "vector.h"

using namespace std;

template <typename T>
struct Dimensions {
    int operator()(int* coordinates, int* sizes, int dimensions) {
        int lineal = 0;
        int factor_dimensional = 1;
        for (int i = 0; i < dimensions; i++) {
          //lineal += coordinates[i] * factor_dimensional;
          lineal += coordinates[dimensions-i-1] * factor_dimensional;
          //factor_dimensional *= sizes[i];
          factor_dimensional *= sizes[dimensions-i-1];
          /*if (i+1!=dimensions) {
            factor_dimensional *= sizes[dimensions-i-1];
          }*/
        }
        return lineal;
    }
};

struct Integer {
       typedef int T;
       typedef Dimensions<T> Operation;
};

int main(int argc, char *argv[]) {
    int dimensions = 3;
    int dimensionSizes[] = {4, 3, 3};
    int test[] = {0, 0, 0};

    Vector<Integer> my_vector(3, dimensionSizes);

    //se rellena el vector
    for (int i = 0; i < dimensionSizes[0]; i++){
      test[0] = i;
      for (int j = 0; j < dimensionSizes[1]; j++){
        test[1] = j;
        for (int k = 0; k < dimensionSizes[2]; k++) {
          test[2] = k;
          my_vector.set((i>=j?(i>=k?i:k):(j>=k?j:k)), test);
        }}}

    //se imprime el vector
    for (int i = 0; i < dimensionSizes[0]; i++){
      test[0] = i;
      for (int j = 0; j < dimensionSizes[1]; j++){
        test[1] = j;
        for (int k = 0; k < dimensionSizes[2]; k++) {
          test[2] = k;
          cout<<my_vector.lineal_value(test) <<" = " <<"(" <<test[0] <<", " <<test[1] <<", " <<test[2] <<") = " <<my_vector.get(test) <<"\n";
        }}}
    return 0;
}
