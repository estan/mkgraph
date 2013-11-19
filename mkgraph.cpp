#include <stdexcept>
#include <random>
#include <iostream>
#include <iomanip>
#include <sstream>
#include <vector>

#include "help.h"

using namespace std;

default_random_engine rng;

class Point {
public:
    Point(float x = 0, float y = 0) : x(x), y(y) {}
    float x;
    float y;
};

ostream& operator<<(ostream& out, const Point& point) {
    out << fixed << setprecision(4) << point.x << " " << point.y;
    return out;
}

void buildNormalCluster(const char *spec, vector<Point>& points) {
    stringstream ss(spec);
    int numPoints; ss >> numPoints; ss.ignore();
    float meanX; ss >> meanX; ss.ignore();
    float meanY; ss >> meanY; ss.ignore();
    float deviationX; ss >> deviationX; ss.ignore();
    float deviationY; ss >> deviationY;

    if (ss.fail() || !ss.eof())
        throw runtime_error("-n: Malformed spec\n" + normalHelp);

    normal_distribution<float> distributionX(meanX, deviationX);
    normal_distribution<float> distributionY(meanY, deviationY);

    for (int i = 0; i < numPoints; ++i) {
        points.emplace_back(distributionX(rng), distributionY(rng));
    }
}

void buildUniformCluster(const char *spec, vector<Point>& points) {
    stringstream ss(spec);
    int numPoints; ss >> numPoints; ss.ignore();
    float x; ss >> x; ss.ignore();
    float y; ss >> y; ss.ignore();
    float width; ss >> width; ss.ignore();
    float height; ss >> height;

    if (ss.fail() || !ss.eof())
        throw runtime_error("-u: Malformed spec\n" + normalHelp);

    uniform_real_distribution<float> distributionX(x, x + width);
    uniform_real_distribution<float> distributionY(y, y + width);

    for (int i = 0; i < numPoints; ++i) {
        points.emplace_back(distributionX(rng), distributionY(rng));
    }
}

int main(int argc, char *argv[]) {
    vector<Point> points;

    if (argc == 1) {
        buildNormalCluster("1000,0,0,200000,200000", points);
    } else {
        try {
            for (int i = 1; i < argc; ++i) {
                string option(argv[i]);
                if (option.compare("-h") == 0) {
                    cout << generalHelp << endl;
                    return 0;
                } else if (option.compare("-hn") == 0) {
                    cout << normalHelp << endl;
                    return 0;
                } else if (option.compare("-hu") == 0) {
                    cout << uniformHelp << endl;
                    return 0;
                } else if (option.compare("-n") == 0) {
                    if (i + 1 == argc)
                        throw runtime_error("-n: Missing arg\n" + normalHelp);
                    buildNormalCluster(argv[i + 1], points);
                    ++i;
                } else if (option.compare("-u") == 0) {
                    if (i + 1 == argc)
                        throw runtime_error("-u: Missing arg\n" + uniformHelp);
                    buildUniformCluster(argv[i + 1], points);
                    ++i;
                } else {
                    throw runtime_error("Unknown option '" + option + "'");
                }
            }
        } catch (exception& e) {
            cerr << e.what() << endl;
            return 1;
        }
    }

    std::cout << points.size() << std::endl;
    for (const Point& point : points)
        std::cout << point << std::endl;

    return 0;
}

