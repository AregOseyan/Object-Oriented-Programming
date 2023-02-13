#ifndef DATE_HPP
#define DATE_HPP
#include <iostream>
#include <stdexcept>
#define ui unsigned int

constexpr ui monthsDay[] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
class Date
{
public:
  Date() = default;
  Date(ui month, ui day, ui year);

public:
  ui getMonth() const;
  ui getDay() const;
  ui getYear() const;
  void setMonth(ui month);
  void setDay(ui day);
  void setYear(ui year);
  void resetValue();
  void display1() const;
  void display2() const;

private:
  ui m_month {};
  ui m_day {};
  ui m_year {};
};
#endif // DATE_HPP
