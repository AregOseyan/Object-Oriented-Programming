#include "StringCell.hpp"

void StringCell::setValue(const std::string& str) { 
  m_value = str;
}

std::string StringCell::getStringValue() const { 
  return m_value.value_or(""); 
}

void StringCell::reset() {
  m_value = std::nullopt;
  m_color = Color::White;
}
