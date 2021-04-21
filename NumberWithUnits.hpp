#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
using namespace std;
namespace ariel{
        class NumberWithUnits{
        
        private:
             double size;
             string unit;
        
        
        public:
            NumberWithUnits(double s,string u)
            {
                size=s;
                unit=u;
            }
            ~NumberWithUnits(){};

            static void read_units(ifstream& units_file);

            // +, +=, +, -, -=, -
            friend NumberWithUnits& operator+(const NumberWithUnits& num1, const NumberWithUnits& num2);
            friend NumberWithUnits& operator+=(NumberWithUnits& num1, const NumberWithUnits& num2);
            friend NumberWithUnits& operator+(const NumberWithUnits& num1);
            friend NumberWithUnits& operator-(const NumberWithUnits& num1, const NumberWithUnits& num2);
            friend NumberWithUnits& operator-=(NumberWithUnits& num1, const NumberWithUnits& num2);
            friend NumberWithUnits& operator-(const NumberWithUnits& num1);
          
            // >, >=, <, <=, ==, !=
            friend bool operator>(const NumberWithUnits& num1, const NumberWithUnits& num2);
            friend bool operator>=(const NumberWithUnits& num1, const NumberWithUnits& num2);
            friend bool operator<(const NumberWithUnits& num1, const NumberWithUnits& num2);
            friend bool operator<=(const NumberWithUnits& num1, const NumberWithUnits& num2);
            friend bool operator==(const NumberWithUnits& num1, const NumberWithUnits& num2);
            friend bool operator!=(const NumberWithUnits& num1, const NumberWithUnits& num2);
          
            // ++ after, ++ before, -- after, -- before
            friend NumberWithUnits& operator++( NumberWithUnits& num1);     
            friend NumberWithUnits& operator++( NumberWithUnits& num1, int);  
            friend NumberWithUnits& operator--( NumberWithUnits& num1);             
            friend NumberWithUnits& operator--( NumberWithUnits& num1, int);   
          
            // *, *, *=, *=
            friend NumberWithUnits& operator*(double num1,  NumberWithUnits& num2);
            friend NumberWithUnits& operator*(  NumberWithUnits& num2,double num1);
            friend NumberWithUnits& operator*=( double num1,NumberWithUnits  &num2);     
            friend NumberWithUnits& operator*=(  NumberWithUnits& num2, double num1);
           
          
            friend std::istream& operator>> (std::istream& input , NumberWithUnits& t);
            friend std::ostream& operator<< (std::ostream& output, const NumberWithUnits& t);
        


    };    
    
}
