#pragma once
#include "Cell.h"


Cell::Cell()
{
    value = ' ';
}

void Cell::setValue(char val) {
    value = val;
}

char Cell::getValue() const {
    return value;
}