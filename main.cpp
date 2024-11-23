#include <iostream>
#include <fstream>

#include "sumOfSeries.h"

#define BIT_TO_CHANGE_1 5
#define BIT_TO_CHANGE_2 6

void swap_bit(unsigned char* ptr, int b1, int b2){ // Test
  unsigned char bit1 = (*ptr & (1 << BIT_TO_CHANGE_1));
  unsigned char bit2 = (*ptr & (1 << BIT_TO_CHANGE_2));

  *ptr ^= bit1;
  *ptr ^= bit2;

  *ptr |= (bit1 << (BIT_TO_CHANGE_2 - BIT_TO_CHANGE_1));
  *ptr |= (bit2 >> (BIT_TO_CHANGE_2 - BIT_TO_CHANGE_1));

}

int main (int argc, char *argv[]) {
  unsigned char var = 0b10101010; 

  swap_bit(&var, BIT_TO_CHANGE_1, BIT_TO_CHANGE_2);

  std::cout << var << "\n";

  double epsilon = 0;
  double x = ;
  double epsilon_n = 0;
  int n = 0;

  std::ifstream f;
  f.open("values.txt");
  if(!f) {
    std::cout << "File open error\n";
    f.close();
    return -1;
  }
  f >> x >> epsilon;
  f.close();

  double y = sumOfSeries(x, epsilon, epsilon_n, n);

  std::cout << "y = " << y << "; n = " << n << "; epsilon_n = " << epsilon_n << "; x = " << x << "; epsilon = " << epsilon << "\n";

  return 0;
}
