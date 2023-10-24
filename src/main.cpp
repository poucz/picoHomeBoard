#include <iostream>
#include <sys/time.h>

#include "jolibMainHelper.h"

#include "modbus.h"
#include "serial_port.h"
#include "zaluzie.h"
#include "gpio.h"
#include "homeBoard.h"

int main()
{
    std::cout << "Hello World" << std::endl;
    MAIN_HELPER modul_helper;
    
    SerialPort ser;
    GPIO_BASE gpio;
    ZALUZIE zaluzie(&gpio);
    HomeBoard homeBoard(&zaluzie,0x05,&ser);


    modul_helper.addModul(&ser);
    modul_helper.addModul(&gpio);
    modul_helper.addModul(&zaluzie);
    modul_helper.addModul(&homeBoard);


    while(true){
        modul_helper.loop(4);
    }


}