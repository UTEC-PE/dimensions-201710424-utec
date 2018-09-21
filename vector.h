#ifndef VECTOR_H
#define VECTOR_H

template <typename Tr>
class Vector {
    public:
        typedef typename Tr::T T;
        typedef typename Tr::Operation Operation;

    private:
        T* data;
        int dataSize;
        Operation dl;
        int dimensions;
        int* dimensionSizes;

    public:
        Vector() : data(nullptr) {};

        Vector(int dimensions, int* dimensionSizes) : dimensions(dimensions), dimensionSizes(dimensionSizes) {
            this->dataSize = 1;
            for (int i = 0; i < dimensions; i++) {
              this->dataSize *= (dimensionSizes[i]);
            }
            this->data = new int[this->dataSize];
        }

        void set(T datum, int* coordinates){
          this->data[dl(coordinates, this->dimensionSizes, this->dimensions)] = datum;
        };

        T get(int* coordinates){
          return data[dl(coordinates, this->dimensionSizes, this->dimensions)];
        };

        int lineal_value(int* coordinates){return dl(coordinates, this->dimensionSizes, this-> dimensions);};

        ~Vector(){
          delete[] this->data;
          delete[] this-> dimensionSizes;
        };
};

#endif
