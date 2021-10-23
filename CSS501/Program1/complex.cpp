/* ---------------------------------------------------------------------------
 * complex.cpp
 *
 * Lauren Coseo - CSS 501
 *
 * Creation Date: 10/18/21
 *
 * Date of Last Modification: 10/21/21
 *
 * -------------------------------------------------------------------------*/
/* ---------------------------------------------------------------------------
 * Purpose: The complex Class holds information and performs arthimetic
 * operations and comparisons for complex numbers of the type: x + yi
 *
 * -------------------------------------------------------------------------*/
/* ---------------------------------------------------------------------------
 * Notes:
 *   -- Complexes are stored as two doubles, one real and one imaginary
 *   -- Dividing by zero returns the original complex number
 *   -- Assumes good user input
 * -------------------------------------------------------------------------*/


#include "complex.hpp"

/* ---------------------------------------------------------------------------
 * complex constructor
 *
 * description:
 * Constructs a complex object
 * Parameters are real and imag respectively.
 * Takes zero, one, two parameters. Parameters have default values of 0.0, 0.0
 
 * preconditions: arguments must be of the type double
 *
 * postconditions:
 * Constructs a new complex object
 * -------------------------------------------------------------------------*/
complex::complex(double r, double i)
{
    real = r;
    imag = i;
} // end of constructor

/* ---------------------------------------------------------------------------
 * getReal
 *
 * description:
 * Gets the value of the object's real attribute
 *
 * preconditions: None
 *
 * postconditions:
 * Returns the value of the object's real number
 * -------------------------------------------------------------------------*/
double complex::getReal()
{
    return real;
} // end of getReal

/* ---------------------------------------------------------------------------
 * getImaginary
 *
 * description:
 * Gets the value of the object's imag attribute
 *
 * preconditions: None
 *
 * postconditions:
 * Returns the value of the object's imaginary number
 * -------------------------------------------------------------------------*/
double complex::getImaginary()
{
    return imag;
} // end of getImaginary

/* ---------------------------------------------------------------------------
 * setReal
 *
 * description:
 * Sets the value of the object's real attribute
 *
 * preconditions: needs parameter r for new input
 *
 * postconditions: real attribute is assigned value of r
 * -------------------------------------------------------------------------*/
void complex::setReal(double r)
{
    real = r;
} // end of setReal

/* ---------------------------------------------------------------------------
 * setImaginary
 *
 * description:
 * Sets the value of the object's imag attribute
 *
 * preconditions: needs parameter i for new input
 *
 * postconditions: imag attribute is assigned value of i
 * -------------------------------------------------------------------------*/
void complex::setImaginary(double i)
{
    imag = i;
} // end of setImaginary

/* ---------------------------------------------------------------------------
 * operator+
 *
 * description: overloaded +
 * addition of 2 complexes, current object and parameter.
 *
 * preconditions: None
 *
 * postconditions: New complex number equal to the sum of 2 parameters
 * -------------------------------------------------------------------------*/
complex complex::operator+(const complex& rhs) const
{
    complex sum = *this;

    sum += rhs;

    return sum;
} // end of operator+

/* ---------------------------------------------------------------------------
 * operator-
 *
 * description: overloaded -
 * subtraction of 2 complexes, current object and parameter.
 *
 * preconditions: None
 *
 * postconditions: New complex number equal to the difference of 2 parameters
 * -------------------------------------------------------------------------*/
complex complex::operator-(const complex& rhs) const
{
    complex sub = *this;
    
    sub -= rhs;

    return sub;
} // end of operator-

/* ---------------------------------------------------------------------------
 * operator*
 *
 * description: overloaded *
 * multiplication of 2 complexes, current object and parameter.
 *
 * preconditions: None
 *
 * postconditions: New complex number equal to the product of 2 parameters
 * -------------------------------------------------------------------------*/
complex complex::operator*(const complex& rhs) const
{
    complex mult = *this;

    mult *= rhs;

    return mult;
} // end of operator*

/* ---------------------------------------------------------------------------
 * operator/
 *
 * description: overloaded /
 * division of 2 complexes, current object and parameter,
 * division by zero results in "ERROR" message and the original complex number
 * is returned
 *
 * preconditions: None
 *
 * postconditions: New complex number equal to the quotient of 2 parameters
 * -------------------------------------------------------------------------*/
complex complex::operator/(const complex& rhs) const
{
    complex div = *this;

    div /= rhs;
    
    return div;
} // end of operator/

/* ---------------------------------------------------------------------------
 * operator==
 *
 * description: overloaded ==
 * Compares two complex numbers to check for equality.
 * Complex numbers are equal if:
*   1) their real parts are equal AND
 *  2) their imaginary parts are equal
 *
 * preconditions: None
 *
 * postconditions:
 * Returns whether the two complex numbers are equal.
 * true if current object is == parameter, otherwise false
 * Both numbers remain unchanged.
 * -------------------------------------------------------------------------*/
bool complex::operator==(const complex& rhs) const
{
    return (real == rhs.real) && (imag == rhs.imag);
} // end of operator==

/* ---------------------------------------------------------------------------
 * operator!=
 *
 * description: overloaded !=
 * Compares two complex numbers to check for inequality.
 * Complex numbers are not equal if:
*   1) their real parts are equal OR
 *  2) their imaginary parts are equal
 *
 * preconditions: None
 *
 * postconditions:
 * Returns whether the two complex numbers are not equal.
 * true if current object is != parameter, otherwise false
 * Both numbers remain unchanged.
 * -------------------------------------------------------------------------*/
bool complex::operator!=(const complex& rhs) const
{
   return !(*this == rhs);
} // end of operator!=

/* ---------------------------------------------------------------------------
 * operator+=
 *
 * description: overloaded +=
 * Current object = current object + parameter
 *
 * preconditions: None
 *
 * postconditions: Current object is reassigned to the value of the sum
 * -------------------------------------------------------------------------*/
complex& complex::operator+=(const complex& rhs)
{
    real = real + rhs.real;
    imag = imag + rhs.imag;

    return *this;
} // end of operator +=

/* ---------------------------------------------------------------------------
 * operator-=
 *
 * description: overloaded -=
 * Current object = current object - parameter
 *
 * preconditions: None
 *
 * postconditions: Current object is reassigned to the value of the difference
 * -------------------------------------------------------------------------*/
complex& complex::operator-=(const complex& rhs)
{
    real = real - rhs.real;
    imag = imag - rhs.imag;

    return *this;
} // end of operator-=

/* ---------------------------------------------------------------------------
 * operator*=
 *
 * description: overloaded *=
 * Current object = current object * parameter
 *
 * preconditions: None
 *
 * postconditions: Current object is reassigned to the value of the product
 * -------------------------------------------------------------------------*/
complex& complex::operator*=(const complex& rhs)
{
    double newReal = real * rhs.real - imag * rhs.imag;
    double newImag = imag * rhs.real + real * rhs.imag;

    real = newReal;
    imag = newImag;
    
    return *this;
} // end of operator*=

/* ---------------------------------------------------------------------------
 * operator/=
 *
 * description: overloaded /=
 * Current object = current object / parameter
 *
 * preconditions: None
 *
 * postconditions: Current object is reassigned to the value of the quotient
 * -------------------------------------------------------------------------*/
complex& complex::operator/=(const complex& rhs)
{
    // Check for division by 0 and return original complex number
    if (rhs.real == 0 && rhs.imag == 0)
        cout << "ERROR: DIVISION BY 0" << endl;
    else
    {
        double realNumerator = real * rhs.real + imag * rhs.imag;
        double imagNumerator = imag * rhs. real - real * rhs.imag;
        double denominator = (rhs.real * rhs.real) + (rhs.imag * rhs. imag);
        real = realNumerator / denominator;
        imag = imagNumerator / denominator;
    }

    return *this;
} // end of operator/=

/* ---------------------------------------------------------------------------
 * conjugate
 *
 * description:
 * Produces the conjugate of the complex object (x - yi)
 *
 * preconditions: None
 *
 * postconditions: Returns a new complex Object
 * -------------------------------------------------------------------------*/
complex complex::conjugate() const
{
    return complex(real, -imag);
} // end of conjugate

/* ---------------------------------------------------------------------------
 * operator<<
 *
 * description: overloaded <<
 * Prints the correct format of the complex number to the screen
 * Takes into account special cases of values 0, -1, and 1
 *
 * preconditions: None
 *
 * postconditions: Complex numbers is printed out
 * -------------------------------------------------------------------------*/
ostream& operator<<(ostream &output, const complex &c)
{
    if (c.real == 0 && c.imag == 0)                 // zero complex
        output << 0;
    else if (c.real == 0 && c.imag == 1)            // only imaginary, pos 1
        output << "i";
    else if (c.real == 0 && c.imag == -1)           // only imaginary, neg 1
        output << "-i";
    else if (c.real == 0)                           // only imaginary part
        output << c.imag << "i";
    else if (c.imag == 0)                           // only real part
        output << c.real;
    else if (c.imag == 1)                           // imag 1 & pos
        output << c.real << "+i";
    else if (c.imag == -1)                          // imag 1 & neg
        output << c.real << "-i";
    else
        if (c.imag < 0)
            output << c.real << c.imag << "i";
        else
            output << c.real << "+" << c.imag << "i";
   
    return output;
} // end of operator<<

/* ---------------------------------------------------------------------------
 * operator>>
 *
 * description: overloaded >>
 * Takes user input
 *
 * preconditions:
 * takes 2 doubles as real and imag, does no error checking
 *
 * postconditions: New complex object is created
 * -------------------------------------------------------------------------*/
istream& operator>>(istream &input, complex &c)
{
   input >> c.real >> c.imag;
   
   return input;
} // end of operator>>

