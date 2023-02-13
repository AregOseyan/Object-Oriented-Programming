#ifndef INTCELL_HPP
#define INTCELL_HPP
#include <string>
#include <optional>
#include <iostream>
#include <stdexcept>
#include <sstream>
#include "Cell.hpp"

class IntCell : public Cell 
{
public:
  virtual void setValue(double value);
  void setValue(const std::string& value) override;
  std::string getStringValue() const override;
  void reset() override;

private:
  static std::string intToString(int value);
  static int stringToInt(const std::string& str);
  
private:
  std::optional<int> m_value;
};
#endif // INTCELL_HPP
