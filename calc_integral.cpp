#include <iostream>
#include <math.h>
#include <omp.h>
#include <chrono>

using namespace std;

int main() {



  int a, b;
  float x_interval = 0.1;
  float y_appr = 0;

  cout << "The function that we are approximating is y = x^2" << endl;
  cout << "And we will be using Right Riemann sum" << endl;
  cout << "Please enter the bounds of integration. Upper bound: " << endl;
  cin >> b;
  cout << "Lower bound: " << endl;
  cin >> a;

  auto start = std::chrono::system_clock::now();
  
  /*
  for (float i = a; i < b; i += x_interval) {
    y_appr += pow(i+x_interval,2) * x_interval;
  }
  */
  

  #pragma omp parallel for
  for (int i = a; i < b; i++) {
	for (float k = i+x_interval; k <= i+1; k += x_interval) {
		y_appr += pow(k,2) * x_interval;
	}
  }

  cout << "The estimated integral is: " << y_appr << endl;

  auto end = std::chrono::system_clock::now();
  auto elapsed_seconds = std::chrono::duration_cast<std::chrono::milliseconds>(end-start);
 cout << "\nruntime:" << elapsed_seconds.count() << " ms\n\n";

  return 0;
}
 

