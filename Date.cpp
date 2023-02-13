#include "Date.hpp"

Date::Date(ui month, ui day, ui year) {
  if ((month == 0) || (month > 12)) {
    throw std::invalid_argument("Error! : Invalid argument month.");
  }
  if ((day == 0) || (day > monthsDay[month])) {
    throw std::invalid_argument("Error! : Invalid argument day.");
  }
  if (year < 2023) {
    throw std::invalid_argument("Error! : Invalid argument year.");
  }
  m_month = month;
  m_day = day;
  m_year = year;
}

ui Date::getMonth() const { 
  return m_month;
}

ui Date::getDay() const {
  return m_day;
}

ui Date::getYear() const {
  return m_year;
}

void Date::resetValue() {
  m_month = {};
  m_day = {};
  m_year = {};
}

void Date::setMonth(ui month) {
  if ((month == 0) || (month > 12)) {
    throw std::invalid_argument("Error! : Invalid argument month.");
  }
  m_month = month;
}

void Date::setDay(ui day) {
  if ((day == 0) || (day > monthsDay[m_month])) {
    throw std::invalid_argument("Error! : Invalid argument day.");
  }
  m_day = day;
}

void Date::setYear(ui year) {
    if (year < 2023) {
    throw std::invalid_argument("Error! : Invalid argument year.");
  }
  m_year = year;
}

void Date::display1() const {
  std::cout << m_month << '/' << m_day << '/' << m_year << std::endl;
}

void Date::display2() const {
  switch(m_month)
  {
    case 1:
      std::cout << "Januar" << std::endl;
      break;

    case 2:
      std::cout << "February" << std::endl;
      break;

    case 3:
     std::cout << "March" << std::endl;
     break;

    case 4:
     std::cout << "April" << std::endl;
     break;

   case 5:
     std::cout << "May" << std::endl;
     break;

   case 6:
     std::cout << "June" << std::endl;
     break;

   case 7:
     std::cout << "July" << std::endl;
     break;

   case 8:
     std::cout << "August" << std::endl;
     break;

   case 9:
     std::cout << "September" << std::endl;
     break;

   case 10:
     std::cout << "October" << std::endl;
     break;

   case 11:
     std::cout << "November" << std::endl;
     break;

   case 12:
     std::cout << "December" << std::endl;
     break;
 }
  std::cout << m_month << '/' << m_day << '/' << m_year << std::endl;
}
