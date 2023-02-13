#include "Spreadsheet.hpp"

Spreadsheet::Spreadsheet(ui row, ui col) noexcept 
  : m_row(row)
  , m_col(col)
{ }

Spreadsheet::Spreadsheet(Spreadsheet&& src) noexcept 
  : m_cells(std::move(src.m_cells))
  , m_row(src.m_row)
  , m_col(src.m_col)
{ }

void Spreadsheet::setCellAt(ui row, ui col, const std::string& str) {
  if (row >= this->m_row) {
    throw std::invalid_argument("Error! : Invalid argumet row.");
  }
  if (col >= this->m_col) {
    throw std::invalid_argument("Error! : Invalid argumet column.");
  }
  std::unique_ptr<StringCell> obj(new StringCell());
  obj->setValue(str);
  this->setCellAt(row, col, std::move(obj));  
}

void Spreadsheet::setCellAt(ui row, ui col, std::unique_ptr<Cell> cell) {
  if (row >= this->m_row) {
    throw std::invalid_argument("Error! : Invalid argumet row.");
  }
  if (col >= this->m_col) {
    throw std::invalid_argument("Error! : Invalid argumet column.");
  }
  m_cells.insert(std::make_pair(std::make_pair(row, col), std::move(cell)));
}

void Spreadsheet::displayMatrix() const {
  for (int i = 0; i < m_row; ++i) {
    for (int j = 0; j < m_col; ++j) {
      auto search = m_cells.find(std::make_pair(i, j));
      if (search != m_cells.end()) {
        std::cout << search->second->getStringValue() << "\t";
      }
      else {
        std::cout << "NULL\t";
      }
    }
    std::cout << std::endl;
  }
}

std::string Spreadsheet::getCellAt(ui row, ui col) const {
  if (row >= this->m_row) {
    throw std::invalid_argument("Error! : Invalid argumet row.");
  }
  if (col >= this->m_col) {
    throw std::invalid_argument("Error! : Invalid argumet column.");
  }
  auto search = m_cells.find(std::make_pair(row, col));
  if (search != m_cells.end()) {
    return search->second->getStringValue();
  }
  return "NULL";
}

void Spreadsheet::swapCells(std::pair<int, int> p1, std::pair<int, int> p2) {
  auto nh1 = m_cells.extract(p1);
  auto nh2 = m_cells.extract(p2);
  std::swap(nh1.key(), nh2.key());
  m_cells.insert(std::move(nh1));
  m_cells.insert(std::move(nh2));
}

ui Spreadsheet::getSizeRow() const {
  return m_row;
}

ui Spreadsheet::getSizeCol() const {
  return m_col;
}

void Spreadsheet::removeRow(ui rowNum) {
  if (rowNum >= this->m_row) {
    throw std::invalid_argument("Error! : Invalid argumet row.");
  }
  for (int j = 0; j < m_col; ++j) {
    auto search = m_cells.find(std::make_pair(rowNum, j));
    if (search != m_cells.end()) {
      m_cells.erase(std::make_pair(rowNum, j));
    }
  }
  for (int i = rowNum + 1; i < m_row; ++i) {
    for (int j = 0; j < m_col; ++j) {
      auto search = m_cells.find(std::make_pair(i, j));
      if (search != m_cells.end()) {
        auto nh = m_cells.extract(std::make_pair(i, j));
        nh.key().first = i - 1;
        m_cells.insert(std::move(nh));
      }
    }
  }
  m_row--;
}

void Spreadsheet::removeColumn(ui colNum) {
  if (colNum >= this->m_col) {
    throw std::invalid_argument("Error! : Invalid argumet column.");
  }
  for (int i = 0; i < m_row; ++i) {
    auto search = m_cells.find(std::make_pair(i, colNum));
    if (search != m_cells.end()) {
      m_cells.erase(std::make_pair(i, colNum));
    }
  }
  for (int i = 0; i < m_row; ++i) {
    for (int j = colNum + 1; j < m_col; ++j) {
      auto search = m_cells.find(std::make_pair(i, j));
      if (search != m_cells.end()) {
        auto nh = m_cells.extract(std::make_pair(i, j));
        nh.key().second = j - 1;
        m_cells.insert(std::move(nh));
      }
    }
  }
  m_col--;
}

void Spreadsheet::swapRows(ui row1, ui row2) {
  if ((row1 >= this->m_row) || (row2 >= this->m_row) || (row1 == row2)) {
    throw std::invalid_argument("Error! : Invalid argumet row.");
  }
  for (int i = 0; i < m_col; ++i) {
    swapCells(std::make_pair(row1, i), std::make_pair(row2, i));
  }
}

void Spreadsheet::swapColumns(ui col1, ui col2) {
  if ((col1 >= this->m_col) || (col2 >= this->m_col) || (col1 == col2)) {
    throw std::invalid_argument("Error! : Invalid argumet column.");
  }
  for (int j = 0; j < m_row; ++j) {
    swapCells(std::make_pair(j, col1), std::make_pair(j, col2));
  }
}

void Spreadsheet::addRow(ui rowNum) {
  if (rowNum >= m_row) {
    throw std::invalid_argument("Error! : Invalid argumet row.");
  }
  for (int i = m_row - 1; i > rowNum; --i) {
    for (int j = 0; j < m_col; ++j) {
      auto search = m_cells.find(std::make_pair(i, j));
      if (search != m_cells.end()) {
        auto nh = m_cells.extract(std::make_pair(i, j));
        nh.key().first = i + 1;
        m_cells.insert(std::move(nh));
      }
    }
  }
  m_row++;
}

void Spreadsheet::addColumn(ui colNum) {
  if (colNum >= m_col) {
    throw std::invalid_argument("Error! : Invalid argumet column.");
  }
  for (int i = 0; i < m_row; ++i) {
    for (int j = m_col; j > colNum; --j) {
      auto search = m_cells.find(std::make_pair(i, j));
      if (search != m_cells.end()) {
        auto nh = m_cells.extract(std::make_pair(i, j));
        nh.key().second = j + 1;
        m_cells.insert(std::move(nh));
      }
    }
  }
  m_col++;
}

void Spreadsheet::writeToFile() const {
  std::fstream file("Spreadsheet.txt", std::ios::in | std::ios::out | std::ios::trunc);
  if (!file) {
    std::cerr << "Error! : Unable to open file." << std::endl;
    return;
  }
  
  for (int i = 0; i < m_row; ++i) {
    for (int j = 0; j < m_col; ++j) {
      auto search = m_cells.find(std::make_pair(i, j));
      if (search != m_cells.end()) {
        file << '[' << i << ']' << '[' << j << ']' << search->second->getStringValue() << "\n";
      }
    }
  }
  file.close();
}

Spreadsheet& Spreadsheet::operator=(Spreadsheet&& rhs) noexcept {
  if (this != &rhs) {
    m_cells = std::move(rhs.m_cells);
  }
  return *this;
}
