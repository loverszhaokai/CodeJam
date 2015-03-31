#include <iostream>
#include <iomanip>

using namespace std;


double c_g, f_g, x_g;

double run_impl()
{
        double cnt_speed = 2;
        double total_acc_time = 0;
        double last_total_time = x_g / 2;

        // Return last_total_time if the total time only but a cookie farm 
        // is larger than last_total_time
        total_acc_time += c_g / cnt_speed;
        cnt_speed += f_g;
        double cnt_total_time = x_g/cnt_speed + total_acc_time;

        while (last_total_time > cnt_total_time) {
                // Go on search if cnt_toal_time is better
                
                last_total_time = cnt_total_time;

                total_acc_time += c_g / cnt_speed;
                cnt_speed += f_g;

                cnt_total_time = x_g / cnt_speed + total_acc_time;
        }
        
        return last_total_time;
}


double run()
{
        cin >> c_g >> f_g >> x_g;

        return run_impl();
}


int main()
{
        int total_test_cases = 0;

        cin >> total_test_cases;
        cout << fixed;

        for (int tt = 1; tt <= total_test_cases; ++tt) {

                const double ret = run();

                cout << "Case #" << tt << ": " << setprecision(7) << ret << endl;
        }

        return 0;
}

