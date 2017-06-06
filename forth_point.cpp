#include <vector>
#include <iostream>
#include <iomanip>

namespace forth_point {
	class point {
	public:
		point() : x(0), y(0) {}
		point(double _x, double _y) : x(_x), y(_y) {}
		point(const point& rhs) : x(rhs.x), y(rhs.y) {}
		~point() {}

		point& operator=(const point& rhs) { x = rhs.x; y = rhs.y; return *this; }
		const double getx() const { return x; }
		const double gety() const { return y; }
	private:
		double x;
		double y;
	};
}

using namespace std;

vector<forth_point::point> read_parallelogram(std::istream& is) {
	forth_point::point start, end;
	vector<forth_point::point> parallelogram;
	for (size_t i = 0; i < 2; ++i) {
		is >> start >> end;
		parallelogram.push_back(start);
	}
	parallelogram.push_back(end);
	is.ignore(1, '\n');
	return parallelogram;
}

forth_point::point calculate_forth_point(vector<forth_point::point>& points) {
	return forth_point::point();
}

int main(int argc, char **argv) {
	while (!cin.eof()) {
		vector<forth_point::point> parallelogram = read_parallelogram(cin);
		forth_point::point forth = calculate_forth_point(parallelogram);
		cout << fixed << setprecision(3) << forth.getx() << " " << fixed << setprecision(3) << forth.gety() << endl;
	}

	return 0;
}