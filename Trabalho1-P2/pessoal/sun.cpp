#include "sun.h"

Sun::Sun() : Objeto (67){}

void Sun::desenha(){
    glPushMatrix();
        glRotatef(angulo,0,0,1);
        angulo += 1;
        GUI::setLight(1,0.5,13.5,0,true,false,false,false,1);
        //GUI::setLight(2,-0.5,13.5,0,true,false);
        if( sin( ( ((angulo+90)*PI)/180 ) ) < 0 ){
            glutGUI::enabled_light[1] = false;
            glutGUI::enabled_light[2] = false;
            glutGUI::enabled_light[7] = true;
        }else {
            glutGUI::enabled_light[1] = true;
            glutGUI::enabled_light[2] = true;
            glutGUI::enabled_light[7] = false;
        }
        GUI::setColor(1,1,0,1);
        GUI::drawSphere(0,15,0,2);

    glPopMatrix();
}
