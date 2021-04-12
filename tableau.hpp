// DO NOT MODIFY THIS FILE

// Class used to handle multiple arrays
// dimensions. If you don't want to use this class, you
// can just ignore it.
//
// WARNING: There is a reason why such a class does not exist
// in the STL. Typing errors are not all detected at
// the compilation. For example, if you declare an array with 3
// dimensions, the compiler allows you to call the at function
// with only 2 indices. This will generate a runtime error.
//
// Example of use of the class where we create an array of
// dimensions 2 x 2 x 2 and print its contents.
//
//  unsigned int dimensions[3] = {2, 2, 2};
//  Tableau<std::string> t(std::vector<unsigned int>(dimensions, dimensions + 3));
//  t.at(0, 0, 0) = "Bonjour";
//  t.at(0, 1, 0) = "tout";
//  t.at(1, 0, 0) = "le";
//  t.at(1, 1, 0) = "monde";
//  t.at(0, 0, 1) = "comment";
//  t.at(0, 1, 1) = "allez";
//  t.at(1, 0, 1) = "-";
//  t.at(1, 1, 1) = "vous?";
//  std::cout << t.at(0, 0, 0) << ", " << t.at(0, 1, 0) << std::endl;
//  std::cout << t.at(1, 0, 0) << ", " << t.at(1, 1, 0) << std::endl;
//  std::cout << t.at(0, 0, 1) << ", " << t.at(0, 1, 1) << std::endl;
//  std::cout << t.at(1, 0, 1) << ", " << t.at(1, 1, 1) << std::endl;
//
//
//  Create an array of dimensions 2 x 2 x 2 x 3 and prints its content
//
//  unsigned int test[4] = {2, 2, 2, 3};
//  Tableau<std::string> t(std::vector<unsigned int>(test, test + 4));
//  t.at(0, 0, 0, 0) = "Bonjour";
//  t.at(0, 1, 0, 0) = "tout";
//  t.at(1, 0, 0, 0) = "le";
//  t.at(1, 1, 0, 0) = "monde";
//  t.at(0, 0, 1, 0) = "comment";
//  t.at(0, 1, 1, 0) = "allez";
//  t.at(1, 0, 1, 0) = "-";
//  t.at(1, 1, 1, 0) = "vous?";
//  t.at(0, 0, 0, 1) = "Bonjour";
//  t.at(0, 1, 0, 1) = "tout";
//  t.at(1, 0, 0, 1) = "le";
//  t.at(1, 1, 0, 1) = "monde";
//  t.at(0, 0, 1, 1) = "comment";
//  t.at(0, 1, 1, 1) = "allez";
//  t.at(1, 0, 1, 1) = "-";
//  t.at(1, 1, 1, 1) = "vous?";
//  t.at(0, 0, 0, 2) = "Bonjour";
//  t.at(0, 1, 0, 2) = "tout";
//  t.at(1, 0, 0, 2) = "le";
//  t.at(1, 1, 0, 2) = "monde";
//  t.at(0, 0, 1, 2) = "comment";
//  t.at(0, 1, 1, 2) = "allez";
//  t.at(1, 0, 1, 2) = "-";
//  t.at(1, 1, 1, 2) = "vous?";
//  std::cout << t.at(0, 0, 0, 0) << ", " << t.at(0, 1, 0, 0) << std::endl;
//  std::cout << t.at(1, 0, 0, 0) << ", " << t.at(1, 1, 0, 0) << std::endl;
//  std::cout << t.at(0, 0, 1, 0) << ", " << t.at(0, 1, 1, 0) << std::endl;
//  std::cout << t.at(1, 0, 1, 0) << ", " << t.at(1, 1, 1, 0) << std::endl;
//  std::cout << t.at(0, 0, 0, 1) << ", " << t.at(0, 1, 0, 1) << std::endl;
//  std::cout << t.at(1, 0, 0, 1) << ", " << t.at(1, 1, 0, 1) << std::endl;
//  std::cout << t.at(0, 0, 1, 1) << ", " << t.at(0, 1, 1, 1) << std::endl;
//  std::cout << t.at(1, 0, 1, 1) << ", " << t.at(1, 1, 1, 1) << std::endl;

#ifndef TABLEAUX
#define TABLEAUX

#include <assert.h>
#include <stdarg.h>
#include <vector>

template <class T>
class Tableau {
private:
  std::vector<unsigned int> m_dimensions; // dimension
  std::vector<T>  m_contenu; // content
public:
// Construct an array whose number of dimensions is dimensions.size ().
// The length of the array on each of these dimensions is specified in the dimensions vector
// Complexity: Theta (n) where n is the number of cells in the array

// Theta (n) = Theta (dimensions [0] * dimensions [1] * dimensions [2] * ...)
  Tableau(const std::vector<unsigned int>& dimensions)
    : m_dimensions(dimensions)
  {
    assert(!dimensions.empty());
    unsigned int nb_elements = 1;
    for (std::vector<unsigned int>::const_iterator i = m_dimensions.begin(); i != m_dimensions.end(); i++) {
      assert(*i > 0);		// Dimensions must be positive
      nb_elements *= *i;
    }
    m_contenu.resize(nb_elements);
  }
// Copy constructor
// Complexity: Thete (number of entries in the array) = Theta (product of the dimensions of the array)
  Tableau(const Tableau<T>& original)
    : m_dimensions(original.m_dimensions),
      m_contenu(original.m_contenu)
  {
  }
  // Return an element of the array. This element can be modified
  // Example with a three-dimensional array of type Array <std :: string>
  // t.at (1, 0, 4) = "hello";
  //
  // Complexity: Theta (d) where d is the number of dimensions of the
  // board. So for a 7-dimensional array, we have
  // Theta (d) = Theta (7) = Theta (1)
  T& at(unsigned int premier_index, ...) {
    assert(premier_index < m_dimensions[0]);
    unsigned int position = premier_index;

    va_list parametres;
    va_start(parametres, premier_index);
    for (std::vector<unsigned int>::const_iterator i = m_dimensions.begin() + 1; i != m_dimensions.end(); i++) {
      const unsigned int index = va_arg(parametres, unsigned int);
      assert(index < *i);
      position = position * *i + index;
    }
    va_end(parametres);
    return m_contenu[position];
  }


// Return an element of the array. This element cannot be changed
// Example with a three-dimensional array of type Array <std :: string>
// t.at (1, 0, 4);
//
// Complexity: Theta (d) where d is the number of dimensions of the
// board. So for a 7-dimensional array, we have
// Theta (d) = Theta (7) = Theta (1)
  const T& at(unsigned int premier_index, ...) const {
    assert(premier_index < m_dimensions[0]);
    unsigned int position = premier_index;

    va_list parametres;
    va_start(parametres, premier_index);
    for (std::vector<unsigned int>::const_iterator i = m_dimensions.begin() + 1; i != m_dimensions.end(); i++) {
      const unsigned int index = va_arg(parametres, unsigned int);
      assert(index < *i);
      position = position * *i + index;
    }
    va_end(parametres);
    return m_contenu[position];
  }
};

#endif
