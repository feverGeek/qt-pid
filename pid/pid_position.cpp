#include "pid_position.h"


pid_position::pid_position():
    kp(0), ki(0), kd(0), target(0), actual(0), e(0), e_pre(0), integral(0), N(0)
{
}

pid_position::~pid_position()
{
}

void pid_position::run()
{
    float u = 0;
    for (; N > 0; N--)
    {
        e = target - actual;
        integral += e;
        u = kp*e + ki*integral + kd*(e - e_pre);
        e_pre = e;
        actual = u;

        emit pid_position_return_result_signal(target, actual);
        qDebug() << actual;
        msleep(200);
    }
}


void pid_position::pid_position_update_slot(float p, float i, float d, float tar, float act)
{
    kp = p;
    ki = i;
    kd = d;
    target = tar;
    actual = act;
    e = target - actual;
    e_pre = e;
}

void pid_position::pid_position_get_N_slot(int n)
{
    N = n;
}
