#include "complex.h"

// You will add function definitons to this file
// See TODOs in complex.h

//// things to be added for part 2 ////
// TODO: operator<<
std::ostream& operator<<(std::ostream& os, const Complex& rhs)
{
    os << rhs.rel << " + " << rhs.img << "i";
    return os;
}

//// things to be added for part 3 ////
// TODO: copy constructor
Complex::Complex(const Complex& rhs)
{
    rel = rhs.rel;
    img = rhs.img;
}


// TODO: assignment operator
void Complex::operator=(const Complex& rhs)
{
    rel = rhs.rel;
    img = rhs.img;
}

// TODO: add operator
Complex Complex::operator+(const Complex& rhs)
{
    return Complex(rel + rhs.rel, img + rhs.img);
}

// TODO: minus operator
Complex Complex::operator-(const Complex& rhs)
{
    return Complex(rel - rhs.rel, img - rhs.img);
}

// TODO: times operator
Complex Complex::operator*(const Complex& rhs)
{
    return Complex(rel * rhs.rel - img * rhs.img, rel * rhs.img + img * rhs.rel);
}

// TODO: times operator (float)
Complex Complex::operator*(const float& rhs)
{
    return Complex(rel * rhs, img * rhs);
}

// TODO: divide operator
Complex Complex::operator/(const Complex& rhs)
{  
    float norm = rhs.rel * rhs.rel + rhs.img * rhs.img;
    if(norm == 0)
    {
        return Complex();
    }
    return Complex((rel * rhs.rel + img * rhs.img) / norm, (-rel * rhs.img + img * rhs.rel) / norm);
}


//// things to be added for part 4 ////
// TODO: times operator for float times complex
Complex operator*(const float& lhs, const Complex& rhs)
{
    return Complex(lhs * rhs.rel, lhs * rhs.img);
}