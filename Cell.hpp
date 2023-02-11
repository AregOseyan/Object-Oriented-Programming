#ifndef CELL_HPP
#define CELL_HPP
#include <string>
#include <stdexcept>
#include <sstream>
#include <iostream>
#include "Date.hpp"

enum class Color
{
  Blue,
  Green,
  Yellow,
  Red,
  Black,
  White
};

class Cell 
{
public:
  Cell() = default;
  Cell(const std::string& str, Color hue) noexcept;
  
public:
  void setValue(const std::string& str);
  void setColor(Color hue);
  std::string getValue() const;
  Color getColor() const;
  int toInt();
  double toDouble();
  Date toDate();
  void reset();
  void swap(Cell& other);

private:
  std::string m_value;
  Color m_color { Color::White };
};
#endif // CELL_HPP
