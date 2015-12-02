#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main() {
  
  double N = 1000;
  double dt1 = M_PI/10;
  double dt2 = M_PI/100;
  
  //int N= (int)t/dt2;
  double Efw [2];
  double Ebw [2];
  Efw [0] = Ebw [0] = 1;
  Efw [1] = Ebw [1] = 0;
  double Efw0 ,Ebw0;
  
    
  for (int i=0; i<N; i++){
    
    //Euler Forward with dt1
    Efw0 = Efw [0];
    Efw [0] = Efw [0] + dt2*Efw [1];
    Efw [1] = Efw [1] - dt2*Efw0;
    
    
    //Euler Backward with dt1
    Ebw0 = Ebw [0];
    Ebw [0] = (Ebw [0] + dt2*Ebw [1])/(1+pow(dt2,2));
    Ebw [1] = Ebw [1] - (dt2*Ebw0+pow(dt2,2)*Ebw [1])/(1+pow(dt2,2)) ;
    
        
    cout << i*dt2 << setw(30) << Efw [0] << setw(30) << Ebw [0] << endl;    
    
  }



return 0;
}
