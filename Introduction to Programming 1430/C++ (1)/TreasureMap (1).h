//FIX ME: add includes and namespace

#pragma once
#ifndef TREASUREMAP_H
#define TREASUREMAP_H
//FIX ME: define the TreasureMap class template

#include <string>
#include <iostream>
#include <fstream>
using namespace std;
template<typename T>

class TreasureMap {
private:
    T* steps;
    int current_step = 0;
    int total_steps;
    int max_steps;
public:
    TreasureMap();
    TreasureMap(int max_steps);
    T getSteps();
    int getCurrentStep();
    int getTotalSteps();
    void addStep(T element);
    void removeStep(int index);
    void nextStep();
    void backtrack();
    bool operator==(const TreasureMap& other);
    TreasureMap operator+(const TreasureMap& other);
};
template<typename T>
TreasureMap<T>::TreasureMap() {
    total_steps = 0;
    current_step = 0;
    max_steps = 10;
    T* steps = new T[max_steps];
}

template<typename T>
TreasureMap<T>::TreasureMap(int max_steps) {
    max_steps = max_steps;
    T* steps = new T[max_steps];
}

template<typename T>
T TreasureMap<T>::getSteps() {
    return steps;
}

template<typename T>
int TreasureMap<T>::getCurrentStep() {
    return current_step;
}

template<typename T>
int TreasureMap<T>::getTotalSteps() {
    return total_steps;
}

template<typename T>
void TreasureMap<T>::addStep(T element) {
    if (total_steps == max_steps) {
        cout << "Cannot add more steps, TreasureMap is full" << endl;
    }
    else {
        steps[current_step] = element;
        total_steps++;
    }
}

template<typename T>
void TreasureMap<T>::removeStep(int index) {
        steps[index] = nullptr;
        total_steps--;
}

template<typename T>
void TreasureMap<T>::nextStep() {
    if (current_step == total_steps) {
        cout << "Cannot goto next step, treasure has already been found!" << endl;
    }
    else {
        cout << "Going from " << steps[current_step] << " to " << steps[current_step+1] << endl;
        current_step++;
        if (current_step == total_steps) {
            cout << "Congratulations, you have found the treasure!" << endl;
        }
    }
}

template<typename T>
void TreasureMap<T>::backtrack() {
    if (current_step == 0) {
        cout << "Cannot backtrack, you're at the very first step!" << endl;
    }
    else {
        cout << "Backtracking from " << steps[current_step] << " to " << steps[current_step - 1] << endl;
        current_step--;
    }
}

template<typename T>
bool TreasureMap<T>::operator==(const TreasureMap<T>& other) {
    int count = 0;
    for (int i = 0; i < other.total_steps; i++) {
        if (steps[i] == other.steps[i]) {
            count++;
        }
    }
    return (other.total_steps == total_steps) &&
        (total_steps == count);
}

template<typename T>
TreasureMap<T> TreasureMap<T>::operator+(const TreasureMap<T>& other) {
    TreasureMap<T> map;
    if (other.total_steps == total_steps) {
        return map;
    }
    else {
        for (int i = 0; i < other.total_steps; i++) {
            map.steps[i] = steps[i] + other.steps[i];
            return map;
        }
    }
}
#endif
