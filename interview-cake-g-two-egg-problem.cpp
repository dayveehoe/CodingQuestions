// If an egg is dropped from above that floor, it will break.
// If it is dropped from that floor or below, it will be completely undamaged
//  and you can drop the egg again.
// Given two eggs, find the highest floor an egg can be dropped from without
//  breaking, with as few drops as possible.

#include <iostream>
#include <math.h>
#include <random>

using namespace std;

int find_two_egg_delta(int floors) {
    // Delta is the first initial floor step.

    // Formula for looks like this
    // x + (x-1) + (x-2) + (x-3) + ... + 1
    // x(x + 1) / 2 = floors
    // .5x^2 + .5x - floors = 0

    // quadratic formula to solve.
    // x1 = (-b + sqrt(b * b - 4 * a * c)) / (2 * a); <- care more about this one.
    // x2 = (-b - sqrt(b * b - 4 * a * c)) / (2 * a);

    double a = 0.5;
    double b = 0.5;
    double c = floors;

    double d = (b * b) - (4.0 * a * c);
    if (d < 0.0)
        d *= -1.0;

    // Only need to positive one
    double x1 = (-1.0 * b + sqrt(d)) / (2.0 * a);
    //double x2 = (-1.0 * b - sqrt(d)) / (2.0 * a);

    // Return ceiling.
    return ceil(x1);
}

void show_two_egg_search_algo(int floors) {
    // floor to start is
    int delta = find_two_egg_delta(floors);

    cout << "Floor Dropping Algo for (" << floors << ") floors is, max " << delta << " drops." << endl;
    for (int i = delta ; i < floors ; delta--, i+= delta) {
        cout << "(" << i << ") > ";
    }
    cout << endl;
}

int solve_two_egg_problem(int floors, int breaking_point) {
    int i = 0;
    int drops = 0;
    int breaks = 0;
    int delta = find_two_egg_delta(floors);
    int ceiling = floors;

    cout << "EGG breaking at [" << breaking_point << "]. ";

    // First drop
    for (i = delta ; i <= ceiling ; i += delta ) {
        drops++;
        cout << "(" << i << ") > ";
        if (i >= breaking_point) {
            breaks++;
            cout << "BREAK > ";
            ceiling = i;
            i = i - delta + 1;
            break;
        }
        delta--;
    }

    // Corner case since floors is not evenly divided by delta.
    i = (i > ceiling) ? ceiling : i;

    // Second drop
    for (; i <= ceiling ; i++) {
        drops++;
        cout << "(" << i << ") > ";
        if (i >= breaking_point) {
            breaks++;
            cout << "BREAK * ";
            break;
        }
    }

    cout << "--- " << drops << " drops & " << breaks << " breaks." << endl;
    return i;
}

int main(int argc, char** argv) {

    srand(std::time(0));

    int floors = 100; // default starting point

    if (argc > 1) {
        int max_floors;
        max_floors = atoi(argv[1]);
        if (max_floors > 0) {
            floors = max_floors;
        }
    }

    show_two_egg_search_algo(floors);
    solve_two_egg_problem(floors, (rand() % floors) + 1);
}