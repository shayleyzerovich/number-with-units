#include <iostream>
#include <fstream>
#include <map>
#include "NumberWithUnits.hpp"
using namespace std;

namespace ariel{

            std::map<string,std::map<string,double>> units;
            NumberWithUnits temp(0,"0");
            
             void  NumberWithUnits::read_units(ifstream& units_file)
             {
             }
  
            // +,+=,+,-,-=,-
             NumberWithUnits& operator+(const NumberWithUnits& num1, const NumberWithUnits& num2){return temp;}
            NumberWithUnits& operator+=(NumberWithUnits& num1, const NumberWithUnits& num2){return num1;}
             NumberWithUnits& operator+(const NumberWithUnits& num1){return temp;}
             NumberWithUnits& operator-(const NumberWithUnits& num1, const NumberWithUnits& num2){return temp;}
             NumberWithUnits& operator-=(NumberWithUnits& num1, const NumberWithUnits& num2){return num1;}
             NumberWithUnits& operator-(const NumberWithUnits& num1){return temp;}
  
            // >, >=, <, <=, ==, !=
             bool operator>(const NumberWithUnits& num1, const NumberWithUnits& num2){return true;}
             bool operator>=(const NumberWithUnits& num1, const NumberWithUnits& num2){return true;}
             bool operator<(const NumberWithUnits& num1, const NumberWithUnits& num2){return true;}
             bool operator<=(const NumberWithUnits& num1, const NumberWithUnits& num2){return true;}
             bool operator==(const NumberWithUnits& num1, const NumberWithUnits& num2){return true;}
             bool operator!=(const NumberWithUnits& num1, const NumberWithUnits& num2){return true;}
  
            // ++ , -- 
             NumberWithUnits& operator++( NumberWithUnits& num1){return temp;}
             NumberWithUnits& operator++( NumberWithUnits& num1, int){return temp;}             
             NumberWithUnits& operator--( NumberWithUnits& num1){return temp;}    
             NumberWithUnits& operator--( NumberWithUnits& num1, int){return temp;}    
  
            // *, *=, *=
             NumberWithUnits& operator*( NumberWithUnits& num2 ,double num1){return temp;}
             NumberWithUnits& operator*(double num1,  NumberWithUnits& num2){return temp;}
             NumberWithUnits& operator*=( double num1,NumberWithUnits& num2){return temp;}  
              NumberWithUnits& operator*=( NumberWithUnits& num2, double num1){return temp;} 
  
            // >> cin input, << cout output
             std::istream& operator>> (std::istream& input , NumberWithUnits& t){
                 return input;
             }
             std::ostream& operator<< (std::ostream& output, const NumberWithUnits& t){
                 return output;
             }
            

}
