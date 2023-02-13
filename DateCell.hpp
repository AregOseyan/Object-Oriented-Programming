#ifndef DATECELL_HPP
#define DATECELL_HPP
#include <iostream>
#include <string>
#include <sstream>
#include <stdexcept>
#include "Cell.hpp"
#include "Date.hpp"

class DateCell : public Cell 
{
public:
  virtual void setValue(const Date& date);
  void setValue(const std::string& value) override;
  std::string getStringValue() const override;
  void reset() override;

private:
  static std::string dateToString(const Date& date);
  static std::string uintToString(unsigned int value);
  static Date stringToDate(const std::string& str);

private:
  Date m_value;
};
#endif // DATECELL_HPP
