#include <roboptim/trajectory/cubic-b-spline.hh>
#include <roboptim/trajectory/visualization/trajectory.hh>

#include <roboptim/core/visualization/gnuplot.hh>
#include <roboptim/core/visualization/gnuplot-function.hh>

using namespace roboptim;
using namespace roboptim::visualization;
using namespace roboptim::visualization::gnuplot;

int main()
{
  // create a spline
  CubicBSpline::interval_t timeRange =
    CubicBSpline::makeInterval (0., 10.);

  CubicBSpline::vector_t parameters (2 * 10);

  parameters = CubicBSpline::vector_t::Random (2 * 10);

  CubicBSpline spline (timeRange, 2, parameters);

  // display trajectory as Gnuplot data
  Gnuplot gnuplot = Gnuplot::make_interactive_gnuplot ();
  gnuplot
    << gnuplot::plot_xy (spline);
  std::cout << gnuplot << std::endl;
}
