#include"Application/App.h"
#include"STD_lib.h"
int main(){
    app_init();
   traffic_start();

    while(1){
      app_start();
    }


return 0;
}

ISR(INT0_vect)
{

 button_s = Pressed;

}

