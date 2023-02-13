#include "DateCell.hpp"

void DateCell::setValue(const Date& date) {
  m_value = date;
}

void DateCell::setValue(const std::string& value) {
  try {
    m_value = stringToDate(value);
  }
  catch (const std::exception& e) {
    std::cerr << e.what() << std::endl;
  }
}

std::string DateCell::getStringValue() const {
  if (m_value.getMonth() && m_value.getDay() && m_value.getYear()) {
    try {
      return dateToString(m_value);
    } 
    catch (const std::exception& e) {
      std::cerr << e.what() << std::endl;
    }
  }
  return "";  
}

void DateCell::reset() {
  m_value.resetValue();
  m_color = Color::White;
}

std::string DateCell::uintToString(unsigned int value) {
  std::stringstream str;
  str << value;
  if (str.fail()) {
    throw std::runtime_error("Error! : Conversion to string failed.");
  }
  return str.str();  
}

std::string DateCell::dateToString(const Date& date) {
  std::string res = "";
  try {
    res += DateCell::uintToString(date.getMonth());
    res += "/";
    res += DateCell::uintToString(date.getDay());
    res += "/";
    res += DateCell::uintToString(date.getYear());
  }
  catch (const std::exception& e) {
    std::cerr << e.what() << std::endl;
  }
  return res;
}

Date DateCell::stringToDate(const std::string& str) {
  Date obj;
  std::string tmp = "";
  int arr[5];
  int j = 0;
  for (int i = 0; i < str.size(); ++i) {
    if (str[i] != '/' && (i != (str.size() - 1))) {
      tmp += str[i];
    }
    else {
      if (i == (str.size() - 1)) {
        tmp += str[i];
      }
      std::istringstream st(tmp);
      int num;
      st >> num;
      if (st.fail() || !st.eof()) {
        throw std::runtime_error("Error! : Conversion to Date failed.");
      }
      arr[j] = num;
      j++;
      if (j > 3) {
        throw std::runtime_error("Error! : Conversion to Date failed.");
      }
      tmp = "";
      st.clear();
    }
  }
  try {
    obj.setMonth(arr[0]);
    obj.setDay(arr[1]);
    obj.setYear(arr[2]);
  } 
  catch (const std::exception& e) {
    std::cerr << e.what() << std::endl;
  }
  return obj;
}
