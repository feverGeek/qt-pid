#include "pid_incremental.h"
#include <QDebug>


pid_incremental::pid_incremental():
    kp(0), ki(0), kd(0), e_pre_1(0), e_pre_2(0), target(0), actual(0), N(0)
{
	A = kp + ki + kd;
	B = -2 * kd - kp;
	C = kd;
	e = target - actual;
}

void pid_incremental::run()
{
    static float u_increment = 0;
    for (; N > 0; N--)
    {
        e = target - actual;
        u_increment = A*e + B*e_pre_1 + C*e_pre_2;
        e_pre_2 = e_pre_1;
        e_pre_1 = e;

        u_increment += actual;
        actual = u_increment;

        emit pid_incremental_return_result_signal(target ,u_increment);
        qDebug() << u_increment;
        msleep(200);
    }
}


//void pid_incremental::pid_show()
//{
//	cout << endl;
//	cout << "The information of the incremental pid controller is as following :" << endl;
//	cout << "     kp = " << kp << endl;
//	cout << "     ki = " << ki << endl;
//	cout << "     kd = " << kd << endl;
//	cout << " target = " << target << endl;
//	cout << " actual = " << actual << endl;
//	cout << "      e = " << e << endl;
//	cout << "e_pre_1 = " << e_pre_1 << endl;
//	cout << "e_pre_2 = " << e_pre_2 << endl;
//	cout << endl;
//}

pid_incremental::~pid_incremental()
{
}

void pid_incremental::pid_incremental_update_slot(float p, float i, float d, float tar, float act)
{
    kp = p;
    ki = i;
    kd = d;
    e_pre_1 = 0;
    e_pre_2 = 0;
    target = tar;
    actual = act;
    A = kp + ki + kd;
    B = -2 * kd - kp;
    C = kd;
    e = target - actual;
}

void pid_incremental::pid_incremental_get_N_slot(int n)
{
    N = n;
}

