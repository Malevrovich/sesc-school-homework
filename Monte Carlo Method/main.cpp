#include <iostream>
#include <ctime>
#include <cmath>

using namespace std;

const int NUM_OF_DOTS = 10e4;
//const double dx = 10e-5;

double solve(int num_of_dots, double dx){
	srand(time(NULL));

	double max_x = 1;
	double max_y = 1;

	double min_x = -1;
	double min_y = -1;

	int in = 0;
	int out = 0;

	for(int i = 0; i != num_of_dots; i++){
		double x;
		{
			int tmp = rand() % int((max_x - min_x) / dx);
			x = min_x + tmp * dx;
		}

		double y;
		{
			int tmp = rand() % int((max_y - min_y) / dx);
			y = min_y + tmp * dx;
		}

		if(x * x + y * y <= 1){
			in++;
		} else{
			out++;
		}
	}
	return 4 * double(in) / (out + in);
}

int main(){
	freopen("dots.txt", "w+", stdout);
	double expecting = 3.14159265359;
	for(double dx = 10e-5; dx < 1; dx += 5 * 10e-5){
		double res = solve(NUM_OF_DOTS, dx);
		cout << dx << ' ' << abs(res - expecting) << "\n";
	}
	return 0;
}


