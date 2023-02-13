#include "IntCell.hpp"

void IntCell::setValue(double value) {
  m_value = value;
}

void IntCell::setValue(const std::string& str) {
  try {
    m_value = stringToInt(str);
  } 
  catch (const std::exception& e) {
    std::cerr << e.what() << std::endl;
  }
}

std::string IntCell::getStringValue() const {
  if (m_value.has_value()) {
    try {
      int num = m_value.value();
      return intToString(num);
    } 
    catch (const std::exception& e) {
      std::cerr << e.what() << std::endl;
    }
  }
  return "";
}

void IntCell::reset() {
  m_value = std::nullopt;
  m_color = Color::White;
}

std::string IntCell::intToString(int value) {
  std::stringstream str;
  str << value;
  if (str.fail()) {
    throw std::runtime_error("Error! : Conversion to string failed.");
  }
  return str.str();
}

int IntCell::stringToInt(const std::string& str) {
  std::string tmp = "";
  for (int i = 0; i < str.size(); ++i) {
    if (str[i] != ' ') {
      tmp += str[i];
    }
  }

  std::istringstream st(tmp);
  double num;
  st >> num;
  if (st.fail() || !st.eof()) {
    throw std::runtime_error("Error! : Conversion to int failed.");
  }
  return static_cast<int>(num);
}
