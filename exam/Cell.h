#pragma once
#include <iostream>

class Cell {
public:
    char value;
    Cell();
    void setValue(char val);
    char getValue() const;
};