#ifndef _LIGHTS_H
#define _LIGHTS_H
class LIGHTS
{
private:
    void changeColor(uint32_t color, int wait, auto strip);
public:
    lights();
    ~lights();
    void morningLigth();
    void noonLigth();
    void afternoonLigth();
    void nightLigth();
    void complateCicle();
    //turn on at, turn off at set methots
};

#endif