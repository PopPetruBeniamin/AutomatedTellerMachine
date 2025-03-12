#ifndef SD_LAB2_COLLECTION_H
#define SD_LAB2_COLLECTION_H

#include "DynamicVector.h"
#include <iostream>

template<typename TElem>
class Collection {
private:
    DynamicVector<TElem> elements;
    DynamicVector<int> nrOccurrences;
public:
    Collection() = default;
    ~Collection() = default;

    void add(TElem e){
        bool exist = search(e);

        if(exist){
            for(int i = 0 ; i < elements.size() ; i++)
                if(e == elements[i])
                    nrOccurrences[i]++;
        }
        else{
            elements.push_back(e);
            nrOccurrences.push_back(1);
        }
    }
    bool remove(TElem e){
        bool exist = false;
        int position;

        //This function check if the element e exist in the DynamicVector elements and save the position
        for(int i = 0 ; i < elements.size() ; i++){
            if(elements[i] == e){
                exist = true;
                position = i;
            }
        }

        if(exist){
            if(nrOccurrences[position] > 1){
                nrOccurrences[position]--;
            } else {
                elements.pop(position);
                nrOccurrences.pop(position);
            }
            return true;
        }
        return false;
    }
    bool search(TElem e){
        for (int i = 0; i < elements.size(); i++)
            if (e == elements[i])
                return true;
        return false;
    }
    int size(){
        return elements.size();
    }
    int nroccurrences(TElem e){
        for(int i = 0 ; i < elements.size() ; i++)
            if(elements[i] == e)
                return nrOccurrences[i];
        return 0;
    }

    TElem getAt(int position) const{
        if( (position >= 0) && (position < elements.size()) )
            return elements.getAt(position);
        else
            throw std::invalid_argument("H! ");
    }
    DynamicVector<TElem>* getAllElements(){
        this->elements;
    }
};
#endif //SD_LAB2_COLLECTION_H
