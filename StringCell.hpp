#ifndef STRINGCELL_HPP
#define STRINGCELL_HPP
#include <iostream>
#include <optional>
#include <stdexcept>
#include <sstream>
#include "Cell.hpp"

class StringCell : public Cell
{
public:
  void setValue(const std::string& value) override;
  std::string getStringValue() const override;
  void reset() override;

private:
  std::optional<std::string> m_value;
};
#endif // STRINGCELL_HPP
