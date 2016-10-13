#include <iostream>
#include"que.h"
#include<cstdlib>
#include <windows.h>

using namespace std;

int main()
{

    que<int> q, q2, q3;

    int a,f,b,m, t = 0, t1 = 0;

    float sum = 0.0, two = 0.0, one = 0.0;/*,temp,temp_time,count=0,timeSpend=0*/
    /*q.Enqueue(item, a_time, run_time)*/
    q.Enque(0,0,5);
    q.Enque(1,2,2);
    q.Enque(2,4,5);
    q.Enque(3,6,1);

    /*q.getMax(m);

    cout << endl << m << endl << endl;*/

    cout << endl << "------------------------------------------------------------" << endl;
    cout << "The Many Process States:\n" << endl;



    while(!q.IsEmpty())
    {
        q.Deque(a,f,b);
        q2.Enque(a,f,b);

        t1 = t1 + b;

        cout << "Process " << a << " status: new" << endl;
        cout << "Process " << a << " status: ready" << endl;
        cout << "Process " << a << " status: running" << endl;

        if(b==rand()%5)
        {
            cout << endl << "INTERRUPT!" << endl << endl;
            cout << "Process " << a << " status: waiting" << endl;
            cout << endl;
            int c,e,d;
            q.Deque(c,e,d);
            q2.Enque(c,e,d);
            cout << "Process " << c << " status: ready" << endl;
            cout << "Process " << c << " status: running" << endl;
            cout << "Process " << c << " status: terminated" << endl;
            cout << "Process " << c << " run-time: " << d << endl;

            cout << endl;
            cout << "Process " << a << " status: ready" << endl;
            cout << "Process " << a << " status: running" << endl;

            t1 = t1 +d;
        }

        else
        Sleep(b);
        cout << "Process " << a << " status: terminated" << endl;
        cout << "Process " << a << " run-time: " << b << endl;
        cout << endl;

    }

    //cout << endl << t1 << endl;

    /*q2.getMax(m);

    cout << endl << endl << m << endl << endl;*/

    cout << endl << "------------------------------------------------------------" << endl;
    cout << "First Come First Serve:\n" << endl;

    while(!q2.IsEmpty())
    {
        q2.Deque(a, f, b);
        q3.Enque(a, f, b);

        cout << "Process " << a << " status: ready" << endl;
        cout << "Process " << a << " status: running" << endl;
        cout << "Process " << a << " status: terminated" << endl;
        cout << "Process " << a << " run-time: " << b << endl;
        cout << endl;

        sum = sum + (t-f);
        t = t+b;

    }

    cout << "Average Waiting Time for FCFS is: " << sum/4 << " seconds!" << endl;

    cout << endl << "------------------------------------------------------------" << endl;
    cout << "Round Robin:\n" << endl;

    while(!q3.IsEmpty())
    {
        int i;
        q3.Deque(a, f, b);

        cout << "Process " << a << " status: ready" << endl;
        cout << "Process " << a << " status: running" << endl;

        for(i = 0; i<2 && i<b; i++)
        {

            Sleep(2);

        }

        cout << "Process " << a << " status: terminated" << endl;
        cout << "Process " << a << " run-time: " << i << endl;

        if(i==2)
            two++;

        if(i==1)
            one++;

        if((b-2)>0)
        q3.Enque(a,t1,b-2);

        t1 = t1+b-2;

        if(b-2 < 0)
        b = 0;

        else
        b = b-2;

        cout << "Process " << a << " remaining run-time: " << b << endl;
        cout << endl;

    }

    cout << "Average Waiting Time for RR is: " << ((one)/4) + ((two*2))/two << " seconds!!" << endl;

    return 0;
}
