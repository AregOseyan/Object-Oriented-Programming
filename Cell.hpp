#ifndef CELL_HPP
#define CELL_HPP
#include <string>

enum class Color
{
  Blue,
  Green,
  Yellow,
  Red,
  Black,
  White
};

class Cell 
{
public:
  virtual ~Cell() = default;

public:
  virtual void setValue(const std::string& str) = 0;
  virtual std::string getStringValue() const = 0;
  virtual void reset() = 0;

  void setColor(Color hue) {
    m_color = hue;
  }
  Color getColor() const {
    return m_color;
  }

protected:
  Color m_color { Color::White };
};
#endif // CELL_HPP
