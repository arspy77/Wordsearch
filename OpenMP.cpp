#include<iostream>
#include <fstream>
#include <string>
#include <omp.h>
using namespace std;

void searchDown(int j, int size, string square[100], string word);

void searchUp(int j, int size, string square[100], string word);

void searchLeft(int i, int size, string square[100], string word);

void searchRight(int i, int size, string square[100], string word);

void searchRightUp(int i, int j, int size, string square[100], string word);

void searchRightDown(int i, int j, int size, string square[100], string word);

void searchLeftUp(int i, int j, int size, string square[100], string word);

void searchLeftDown(int i, int j, int size, string square[100], string word);

bool found = false;

int main( int ac, char **av)
{
    string square[100];
    int size;
    ifstream mapFile;
    mapFile.open("square.txt");
    if (mapFile.is_open())
    {
        int i = 0;
        while (getline(mapFile,square[i])){
            i++;
        }
        size = i;
        mapFile.close();
    }

    #pragma omp parallel num_threads((int) av[2])
    { 
        int id = omp_get_thread_num();
        int total = omp_get_num_threads();
        if (id != 0){
            int start = id / total * size * 12;
        }
        else{

        }
    }
    return 0;
}

void searchDown(int j, int size, string square[100], string word){
    int k = 0;
    for (int i = 0; i < size; i++){
        if (square[i].at(j) == word.at(k)){
            if (k == word.size){
                found = true;
            }
            else{
                k++;
            }
        }
        else{
            k = 0;
        }
    }
}

void searchUp(int j, int size, string square[100], string word){
    int k = 0;
    for (int i = size - 1; i >= 0; i--){
        if (square[i].at(j) == word.at(k)){
            if (k == word.size){
                found = true;
            }
            else{
                k++;
            }
        }
        else{
            k = 0;
        }
    }
}

void searchLeft(int i, int size, string square[100], string word){
    int k = 0;
    for (int j = size - 1; j >= 0; j--){
        if (square[i].at(j) == word.at(k)){
            if (k == word.size){
                found = true;
            }
            else{
                k++;
            }
        }
        else{
            k = 0;
        }
    }
}

void searchRight(int i, int size, string square[100], string word){
    int k = 0;
    for (int j = 0; j < size; j++){
        if (square[i].at(j) == word.at(k)){
            if (k == word.size){
                found = true;
            }
            else{
                k++;
            }
        }
        else{
            k = 0;
        }
    }
}

void searchRightUp(int i, int j, int size, string square[100], string word){
    int k = 0;
    for (; (i >= 0) && (j < size); i--, j++){
        if (square[i].at(j) == word.at(k)){
            if (k == word.size){
                found = true;
            }
            else{
                k++;
            }
        }
        else{
            k = 0;
        }
    }
}

void searchRightDown(int i, int j, int size, string square[100], string word){
    int k = 0;
    for (; (i < size) && (j < size); i++, j++){
        if (square[i].at(j) == word.at(k)){
            if (k == word.size){
                found = true;
            }
            else{
                k++;
            }
        }
        else{
            k = 0;
        }
    }
}

void searchLeftUp(int i, int j, int size, string square[100], string word){
    int k = 0;
    for (; (i >= 0) && (j >= 0); i--, j--){
        if (square[i].at(j) == word.at(k)){
            if (k == word.size){
                found = true;
            }
            else{
                k++;
            }
        }
        else{
            k = 0;
        }
    }
}

void searchLeftDown(int i, int j, int size, string square[100], string word){
    int k = 0;
    for (; (i < size) && (j >= 0); i++, j--){
        if (square[i].at(j) == word.at(k)){
            if (k == word.size){
                found = true;
            }
            else{
                k++;
            }
        }
        else{
            k = 0;
        }
    }
}