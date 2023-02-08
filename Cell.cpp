#include "Cell.hpp"
#include <stdexcept>
#include <sstream>
#include <iostream>

Cell::Cell(const std::string& str, Color hue) noexcept
  : m_value(str)
  , m_color(hue) 
{ }

void Cell::setValue(const std::string& str) {
  m_value = str;
}

std::string Cell::getValue() const {
  return m_value;
}

void Cell::setColor(Color hue) {
  m_color = hue;
}

Color Cell::getColor() const { 
  return m_color;
}

int Cell::toInt() {
  int num;
  std::istringstream stringStream(m_value);
  if (!(stringStream >> num)) {
    throw std::invalid_argument("Error! : Invalid argument m_value");
  }
  return num;
}

double Cell::toDouble() {
  double num;
  std::istringstream stringStream(m_value);
  if (!(stringStream >> num)) {
    throw std::invalid_argument("Error! : Invalid argument m_value");
  }
  return num;
}

Date Cell::toDate() {
  Date obj;
  std::string tmp = "";
  int arr[5];
  int j = 0;
  for (int i = 0; i < m_value.size(); ++i) {
    if (m_value[i] != '/' && (i != (m_value.size() - 1))) {
      tmp += m_value[i];
    }
    else {
      int num;
      std::istringstream stringStream(tmp);
      if (!(stringStream >> num)) {
        throw std::invalid_argument("Error! : Invalid argument m_value");
      }
      arr[j] = num;
      j++;
      if (j > 3) {
        throw std::invalid_argument("Error! : Invalid argument m_value");
      }
      tmp = "";
    }
  }
  try {
    obj.setMonth(arr[0]);
    obj.setDay(arr[1]);
    obj.setYear(arr[2]);
  }
  catch (std::exception& e) {
    std::cout << e.what() << std::endl;
  }
  return obj;
}

void Cell::reset() {
  m_value = "";
  m_color = Color::White;
}

void Cell::swap(Cell& other) {
  std::string tmp1 = this->m_value;
  this->m_value = other.m_value;
  other.m_value = tmp1;

  Color tmp2 = this->m_color;
  this->m_color = other.m_color;
  other.m_color = tmp2;
}
