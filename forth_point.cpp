#include <vector>
#include <iostream>
#include <iomanip>

namespace forth_point {
	class vector;

	class point {
	public:
		point() : x(0), y(0) {}
		point(double _x, double _y) : x(_x), y(_y) {}
		point(const point& rhs) : x(rhs.x), y(rhs.y) {}
		~point() {}

		point& operator=(const point& rhs) { x = rhs.x; y = rhs.y; return *this; }
		inline point operator+(const vector& vec);
		inline point operator-(const vector& vec);
		const double getx() const { return x; }
		const double gety() const { return y; }
		friend std::istream & operator >> (std::istream &is, point &rhs)
		{
			is >> rhs.x >> rhs.y;
			return is;
		};
	private:
		double x;
		double y;
	};

	class vector {
	public:
		vector() {}
		vector(double _x, double _y) : x(_x), y(_y) {}
		vector(const point& start, const point& end) : x(end.getx() - start.getx()), y(end.gety() - start.gety()) {}
		vector(const vector& rhs) : x(rhs.x), y(rhs.y) {}
		~vector() {}

		vector& operator=(const vector& rhs) { x = rhs.x; y = rhs.y; return *this; }
		const double getx() const { return x; }
		const double gety() const { return y; }
	private:
		double x;
		double y;
	};

	inline point point::operator+(const vector& vec) { return point(x + vec.getx(), y + vec.gety()); }
	inline point point::operator-(const vector& vec) { return point(x - vec.getx(), y - vec.gety()); }
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
	try {
		forth_point::vector reverse_of_1st_side(points.at(1), points.at(0));
		return points.at(2) + reverse_of_1st_side;
	}
	catch (out_of_range) {
		return forth_point::point();
	}
}

int main(int argc, char **argv) {
	while (!cin.eof()) {
		vector<forth_point::point> parallelogram = read_parallelogram(cin);
		forth_point::point forth = calculate_forth_point(parallelogram);
		cout << fixed << setprecision(3) << forth.getx() << " " << fixed << setprecision(3) << forth.gety() << endl;
	}

	return 0;
}