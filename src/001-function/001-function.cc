#include <cmath>
#include <stdexcept>
#include <roboptim/core/function.hh>

#include <roboptim/core/visualization/gnuplot.hh>
#include <roboptim/core/visualization/gnuplot-function.hh>

using namespace roboptim::visualization;
using namespace roboptim::visualization::gnuplot;

static const int FIXME = 42;
# define FIXME_IMPLEMENT_ME() \
  throw std::runtime_error ("please implement me")

// The RobOptim function you have to implement.
struct EggHolder : public roboptim::Function
{
  EggHolder ()
    // Change the first FIXME by the function input size
    // Change the second FIXME by the function output size
    : roboptim::Function (FIXME, FIXME, "EggHolder")
  {}

  // This method is used to evaluate the function.
  void impl_compute (result_t& r, const argument_t& x) const
  {
    FIXME_IMPLEMENT_ME ();
  }
};

int main()
{
  FIXME_IMPLEMENT_ME ();
  return 0;
}
