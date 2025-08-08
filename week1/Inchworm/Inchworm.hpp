#include <bits/stdc++.h>
using namespace std;
 
 
class Inchworm
{
  public:
  int lunchtime(int branch, int rest, int leaf) {
    return (int) (branch / gcl(rest, leaf)) + 1;
  }
};