#include <string>
#include <iostream>
#include <vector>
using namespace std;
class BusSeating
{
public:
static double dist(const P& a, const P& b) {
        double dx = a.x - b.x, dy = a.y - b.y;
        return sqrt(dx*dx + dy*dy);
    }
    double getArrangement(string leftRow, string rightRow)
    {
        vector<P> empty; empty.reserve(20);
        int j = rightRow.size() - 1;

        for (int i = 0; i < 10; ++i) {
            if (leftRow[i]  == '-') empty.push_back({0.0, (double)i});
            if (rightRow[i] == '-') empty.push_back({2.0, (double)i});
        }
        double best = 1e100;
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                double d_ij = dist(empty[i], empty[j]);
                for (int k = j + 1; k < n; ++k) {
                    double s = d_ij
                             + dist(empty[i], empty[k])
                             + dist(empty[j], empty[k]);
                    if (s < best) best = s;
                }
            }
        }
        return best;
    }
}
;

int main()
{
    BusSeating solver;

    cout << solver.getArrangement("----------", "----------") << "  (exp 4.0)\n";
    cout << solver.getArrangement("XXX-X-XX-X", "-XXXX---XX") << "  (exp 4.0)\n";
    cout << solver.getArrangement("XXXXXXXXXX", "-X-XX-X--") << "  (exp 6.0)\n";
    cout << solver.getArrangement("XXX-X-XX-X", "XXX-X-XX-X") << "  (exp 6.82842712474619)\n";
    return 0;
}
