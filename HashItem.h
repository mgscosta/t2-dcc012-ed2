#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

#include "CovidData.h"


using namespace std;

class HashItem {
  private:
  string key;
  CovidData value;

  public:
    /**
     * Constructor
     * */
    HashItem(string key, CovidData value);

    /**
     * Destructor
     * */
    ~HashItem();

  /**
   * Getter & Setter Key
   * */
    string getKey();
    void setKey(string new_key);

  /**
   * Getter & Setter Value
   * */
    CovidData getValue();
    void setValue(CovidData new_value);


};
