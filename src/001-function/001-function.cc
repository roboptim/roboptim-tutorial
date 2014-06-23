#include <cmath>
#include <roboptim/core/function.hh>

#include <roboptim/core/visualization/gnuplot.hh>
#include <roboptim/core/visualization/gnuplot-function.hh>

using namespace roboptim::visualization;
using namespace roboptim::visualization::gnuplot;

struct EggHolder : public roboptim::Function
{
  EggHolder ()
    : roboptim::Function (1, 1, "EggHolder")
  {}

  void impl_compute (result_t& r, const argument_t& x) const
  {
    r[0] =
      -47 * std::sin (std::sqrt (std::abs (.5 * x[0] + 47.)))
      - x[0] * std::sin (std::sqrt (std::abs (x[0] - 47)));
  }
};

int main()
{
  Gnuplot gnuplot = Gnuplot::make_interactive_gnuplot ();

  discreteInterval_t interval (-512., 512., 1.);

  EggHolder f;

  std::cout << (gnuplot << plot (f, interval));

  return 0;
}
