#ifndef DOUBLECELL_HPP
#define DOUBLECELL_HPP
#include <iostream>
#include <optional>
#include <stdexcept>
#include <sstream>
#include "Cell.hpp"

class DoubleCell : public Cell 
{
public:
  virtual void setValue(double value);
  void setValue(const std::string& value) override;
  std::string getStringValue() const override;
  void reset() override; 

private:
  static std::string doubleToString(double value);
  static double stringToDouble(const std::string& str);

private:
  std::optional<double> m_value;
};
#endif // DOUBLECELL_HPP
