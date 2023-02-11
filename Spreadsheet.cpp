#include "Spreadsheet.hpp"

Spreadsheet::Spreadsheet(ui row, ui col) noexcept
  : m_row(row)
  , m_col(col)
{
  m_cells = new Cell*[row];
  for (int i = 0; i < row; ++i) {
    m_cells[i] = new Cell[col];
  }
}

Spreadsheet::Spreadsheet(const Spreadsheet& src) noexcept
  : m_row(src.m_row)
  , m_col(src.m_col) 
{
  m_cells = new Cell*[m_row];
  for (int i = 0; i < m_row; ++i) {
    m_cells[i] = new Cell[m_col];
    for (int j = 0; j < m_col; j++) {
      m_cells[i][j] = src.m_cells[i][j];
    }
  }
}

Spreadsheet::Spreadsheet(Spreadsheet&& src) noexcept {
  moveFrom(src);
}

Spreadsheet::~Spreadsheet() {
  for (int i = 0; i < m_row; ++i) {
    delete[] m_cells[i];
  }
  delete[] m_cells;
}

void Spreadsheet::setCellAt(ui row, ui col, const Cell& cells)  {
  if (row >= this->m_row) {
    throw std::invalid_argument("Error! : Invalid argumet rows");
  }
  if (col >= this->m_col) {
    throw std::invalid_argument("Error! : Invalid argumet columns");
  }
  m_cells[row][col] = cells;
}

void Spreadsheet::setCellAt(ui row, ui col, const std::string& str) {
  if (row >= this->m_row) {
    throw std::invalid_argument("Error! : Invalid argumet rows");
  }
  if (col >= this->m_col) {
    throw std::invalid_argument("Error! : Invalid argumet columns");
  }
  m_cells[row][col].setValue(str);
}

Cell Spreadsheet::getCellAt(ui row, ui col) const
{ 
  if (row >= this->m_row) {
    throw std::invalid_argument("Error! : Invalid argumet rows");
  }
  if (col >= this->m_col) {
    throw std::invalid_argument("Error! : Invalid argumet columns");
  }
  Cell res = m_cells[row][col];
  return res;
}

ui Spreadsheet::getSizeRow() const {
  return m_row;
}

ui Spreadsheet::getSizeCol() const {
  return m_col;
}

void Spreadsheet::moveFrom(Spreadsheet& src) noexcept {
  m_col = src.m_col;
  m_row = src.m_row;
  m_cells = src.m_cells;

  src.m_col = 0;
  src.m_row = 0;
  src.m_cells = nullptr;
}

void Spreadsheet::deleteMatrix() noexcept {
  for (int i = 0; i < m_row; ++i) {
    delete[] m_cells[i];
  }
  delete[] m_cells;
  m_cells = nullptr;
  m_row = m_col = 0;
}

void Spreadsheet::copySpreadsheet(const Spreadsheet& other) {
  this->deleteMatrix();

  m_row = other.m_row;
  m_col = other.m_col;
  m_cells = new Cell*[m_row];
  for (int i = 0; i < m_row; ++i) {
    m_cells[i] = new Cell[m_col];
    for (int j = 0; j < m_col; ++j) {
      m_cells[i][j] = other.m_cells[i][j];
    }
  }
}

void Spreadsheet::addRow(ui rowNum) {
  if (rowNum >= this->m_row) {
    throw std::invalid_argument("Error! : Invalid argumet rows");
  }
  Spreadsheet newSpreadsheet(m_row + 1, m_col);
  for (int i = 0; i < m_row; ++i) {
    for (int j = 0; j < m_col; ++j) {
      if (i < rowNum) {
        newSpreadsheet.m_cells[i][j] = m_cells[i][j];
      } 
      else {
        newSpreadsheet.m_cells[i + 1][j] = m_cells[i][j];
      }
    }
  }

  for (int j = 0; j < m_col; ++j) {
    newSpreadsheet.m_cells[rowNum][j].setValue("Success");
  }
 
  copySpreadsheet(newSpreadsheet);
}

void Spreadsheet::removeRow(ui rowNum) {
  if (rowNum >= this->m_row) {
    throw std::invalid_argument("Error! : Invalid argumet rows");
  }
  int c = 0;
  Spreadsheet newSpreadsheet(m_row - 1, m_col);
  for (int i = 0; i < m_row; ++i) {
    if (i == rowNum) {
      continue;
    }
    for (int j = 0; j < m_col; ++j) {
      newSpreadsheet.m_cells[c][j] = m_cells[i][j];
    }
    c++;
  }
  
  copySpreadsheet(newSpreadsheet);
}

void Spreadsheet::addColumn(ui colNum) {
  if (colNum >= this->m_col) {
    throw std::invalid_argument("Error! : Invalid argumet columns");
  }
  Spreadsheet newSpreadsheet(m_row, m_col + 1);
  for (int i = 0; i < m_row; ++i) {
    for (int j = 0; j < m_col; ++j) {
      if (j < colNum) {
        newSpreadsheet.m_cells[i][j] = m_cells[i][j];
      }
      else {
        newSpreadsheet.m_cells[i][j + 1] = m_cells[i][j];
      }
    }
  }

  for (int i = 0; i < m_row; ++i) {
    newSpreadsheet.m_cells[i][colNum].setValue("Success");
  }

  copySpreadsheet(newSpreadsheet);
}

void Spreadsheet::removeColumn(ui colNum) {
  if (colNum >= this->m_col) {
    throw std::invalid_argument("Error! : Invalid argumet columns");
  }
  int c = 0;
  Spreadsheet newSpreadsheet(m_row, m_col - 1);
  for (int i = 0; i < m_row; ++i) {
    for (int j = 0; j < m_col; ++j) {
      if (j == colNum) {
        continue;
      }
      newSpreadsheet.m_cells[i][c] = m_cells[i][j];
      c++;
    }
    c = 0;
  }

  copySpreadsheet(newSpreadsheet);
}

void Spreadsheet::swapRows(ui row1, ui row2) {
  if ((row1 >= this->m_row) || (row2 >= this->m_row) || (row1 == row2)) {
    throw std::invalid_argument("Error! : Invalid argumet rows");
  }
  for (int i = 0; i < m_col; ++i) {
    m_cells[row1][i].swap(m_cells[row2][i]);
  }
}

void Spreadsheet::swapColumns(ui col1, ui col2) {
  if ((col1 >= this->m_col) || (col2 >= this->m_col) || (col1 == col2)) {
    throw std::invalid_argument("Error! : Invalid argumet columns");
  }
  for (int j = 0; j < m_row; ++j) {
    m_cells[j][col1].swap(m_cells[j][col2]);
  }
}

void Spreadsheet::displayMatrix() const {
  for (int i = 0; i < m_row; ++i) {
    for (int j = 0; j < m_col; ++j) {
      if (m_cells[i][j].getValue() == "") {
        std::cout << "NULL\t";
      } 
      else {
        std::cout << m_cells[i][j].getValue() << "\t";
      }
    }
    std::cout << std::endl;
  }
}

Spreadsheet& Spreadsheet::operator=(const Spreadsheet& rhs) {
  if (this != &rhs) {
    copySpreadsheet(rhs);
  }
  return *this;
}

Spreadsheet& Spreadsheet::operator=(Spreadsheet&& rhs) noexcept {
  if (this != &rhs) {
    deleteMatrix();
    moveFrom(rhs);
  }
  return *this;
}
