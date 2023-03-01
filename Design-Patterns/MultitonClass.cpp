#include <iostream>
#include <string>
#include <map>

class MultitonClass {
private:
  MultitonClass() = default;
  MultitonClass(const MultitonClass&) = default;
  MultitonClass& operator = (const MultitonClass&) { return *this; }

public:
  static void destroy() {
    for (typename std::map<std::string, MultitonClass*>::const_iterator it = m_instance.begin(); 
        it != m_instance.end(); ++it) { delete (*it).second; }
    m_instance.clear();
  }

  static MultitonClass* getInstance(const std::string& key) {
    typename std::map<std::string, MultitonClass*>::const_iterator it = m_instance.find(key);
    if (it != m_instance.end()) {
      std::cout << "Old object" << std::endl;
      return (MultitonClass*)(it->second);
    }
    std::cout << "New object" << std::endl;
    MultitonClass* instance = new MultitonClass();
    m_instance[key] = instance;
    return instance;
  }

protected:
  ~MultitonClass() = default;

private:
  static inline std::map<std::string, MultitonClass*> m_instance;
};

int main() {  
  MultitonClass* obj = MultitonClass::getInstance("ogj"); 
  MultitonClass* obj1 = MultitonClass::getInstance("ogj");
  MultitonClass* obj2 = MultitonClass::getInstance("ogj1");

  MultitonClass::destroy();
  return {};
}
