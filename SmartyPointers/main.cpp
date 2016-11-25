//
//  main.cpp
//  SmartyPointers
//
//  Created by Laura del Pino Díaz on 25/11/16.
//  Copyright © 2016 Laura del Pino Díaz. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

void show (shared_ptr<vector<int>> v){

    for (int i = 0; i < v->size(); i++) {
        cout << (*v)[i] << endl;
    }
}

void swap(shared_ptr<vector<int>> v, int positionA, int positionB){
    int aux = (*v)[positionA];
    (*v)[positionA] = (*v)[positionB];
    (*v)[positionB] = aux;
}

void selectionSort(shared_ptr<vector<int>> v, int l, int r){
    for (int i = l ; i < r ; i++) {
        int min = i;
        for (int j = i+1;  j<= r; j++) {
            if ((*v)[j] < (*v)[min])
                min = j;
            swap(v,i,min);
        }
    }
}

int main(int argc, const char * argv[]) {
    
    shared_ptr<vector<int>> vectorin (new vector<int>());
    
    vectorin->push_back(10);
    vectorin->push_back(9);
    vectorin->push_back(8);
    vectorin->push_back(7);
    vectorin->push_back(6);
    vectorin->push_back(5);
    vectorin->push_back(4);
    vectorin->push_back(3);
    vectorin->push_back(2);
    vectorin->push_back(1);
    
    show(vectorin);
    
    selectionSort(vectorin, 0, vectorin->size()-1);
    
    show(vectorin);
    
    //Do not delete the vector since is a smarty pointer
    return 0;
}
