#include <iostream>

class MultitonClass {
private:
  MultitonClass() = default;
  MultitonClass(const MultitonClass&) = default;
  MultitonClass& operator = (const MultitonClass&) { return *this; }

public:
  static void destroy() {
    for (int i = 0; i < m_count; ++i) {
      delete m_instance[i];
      m_instance[i] = nullptr;
    }
  }
  static MultitonClass* createObject () {
    if (m_count > m_id) { 
      std::cout << "New object" << std::endl;
      m_instance[m_id] = new MultitonClass; 
      ++m_id;
      return m_instance[m_id - 1];
    }
    else {
      ++m_id;
      std::cout << "Old object " << ((m_id - 1) % m_count) << std::endl;
      return m_instance[(m_id - 1) % m_count];
    }
  }

protected:
  ~MultitonClass() = default;

private:
  static inline std::size_t m_id {};
  const static inline int m_count {4};
  static inline MultitonClass* m_instance[m_count];
};

int main () {
  MultitonClass* obj = MultitonClass::createObject();
  MultitonClass* obj1 = MultitonClass::createObject();
  MultitonClass* obj2 = MultitonClass::createObject();
  MultitonClass* obj3 = MultitonClass::createObject();
  
  MultitonClass* obj4 = MultitonClass::createObject();
  MultitonClass* obj5 = MultitonClass::createObject(); 
  MultitonClass* obj6 = MultitonClass::createObject();
  MultitonClass* obj7 = MultitonClass::createObject();
  MultitonClass* obj8 = MultitonClass::createObject();
  MultitonClass* obj9 = MultitonClass::createObject();
  MultitonClass* obj10 = MultitonClass::createObject();
  MultitonClass* obj11 = MultitonClass::createObject();

  MultitonClass::destroy();
  return {};
}
