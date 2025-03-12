#ifndef SD_LAB2_DYNAMICVECTOR_H
#define SD_LAB2_DYNAMICVECTOR_H

template<typename TElem>
class DynamicVector{
private:
    int capacity{};
    int nrElems{};
    TElem* elems;   //vectorul de elemente

    void resize(){
        auto * aux = new TElem [2*capacity];
        for(int i=0; i<capacity; i++)
            aux[i] = this->elems[i];
        delete[] elems;
        this->elems = aux;
        this->capacity = 2*capacity;
    }
public:

    DynamicVector(){
        this->capacity = 1;
        this->nrElems = 0;
        this->elems = new TElem[this->capacity];
    }
    explicit DynamicVector(int capacitate){
        if(capacitate > 0){
            this->elems = new TElem [capacitate];
            this->nrElems = 0;
            this->capacity = capacitate;
        }
        else{
            this->capacity = 1;
            this->nrElems = 0;
            this->elems = new TElem[this->capacity];
        }
    }

    DynamicVector(const DynamicVector& other){
        this->capacity = other.capacity;
        this->nrElems = other.nrElems;
        this->elems = new TElem[this->capacity];
        for (int i = 0; i < this->nrElems; ++i) {
            this->elems[i] = other.elems[i];
        }
    }

    ~DynamicVector(){
        delete[] this->elems;
    }

    [[nodiscard]] TElem getAt(int i) const{
        if((i>=0) && (i<nrElems))
            return this->elems[i];
    }

    [[nodiscard]] int size() const{
        return this->nrElems;
    }

    void push_back(TElem e){
        if(nrElems==capacity){
            resize();
        }
        this->elems[nrElems++] = e;
    }

    void pop_back(){
        if (nrElems > 0)
            nrElems--;
    }

    void pop(int position){
        for(int i = position; i < nrElems - 1 ; i++)
            elems[i] = elems[i + 1];
        nrElems--;
    }

    TElem& operator[](int i) {
        if(i >= 0 && i < nrElems)
            return elems[i];
    }

    DynamicVector& operator=(const DynamicVector& other) {
        if (this != &other) {
            delete[] this->elems;

            this->capacity = other.capacity;
            this->nrElems = other.nrElems;
            this->elems = new TElem[this->capacity];
            for (int i = 0; i < this->nrElems; ++i) {
                this->elems[i] = other.elems[i];
            }
        }
        return *this;
    }
};

#endif //SD_LAB2_DYNAMICVECTOR_H
