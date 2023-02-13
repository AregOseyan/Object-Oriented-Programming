#include "DoubleCell.hpp"

void DoubleCell::setValue(double value) {
  m_value = value;
}

void DoubleCell::setValue(const std::string& str) {
  try {
    m_value = stringToDouble(str);
  }
  catch (const std::exception& e) {
    std::cerr << e.what() << std::endl;
  }
}

std::string DoubleCell::getStringValue() const {
  if (m_value.has_value()) {
    try {
      double num = m_value.value();
      return doubleToString(num);
    }
    catch (const std::exception& e) {
      std::cerr << e.what() << std::endl;
    }
  }
  return "";
}

void DoubleCell::reset() {
  m_value = std::nullopt;
  m_color = Color::White;
}

std::string DoubleCell::doubleToString(double value) {
  std::stringstream str;
  str << value;
  if (str.fail()) {
    throw std::runtime_error("Error! : Conversion to string failed.");
  }
  return str.str();
}

double DoubleCell::stringToDouble(const std::string& str) {
  std::string tmp = "";
  for (int i = 0; i < str.size(); ++i) {
    if (str[i] != ' ') {
      tmp += str[i];
    }
  }

  std::istringstream st(tmp);
  double res;
  st >> res;
  if (st.fail() || !st.eof()) {
    throw std::runtime_error("Error! : Conversion to double failed.");
  }
  return res;
}
