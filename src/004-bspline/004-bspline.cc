#include <roboptim/trajectory/cubic-b-spline.hh>
#include <roboptim/trajectory/free-time-trajectory.hh>
#include <roboptim/trajectory/visualization/trajectory.hh>

#include <roboptim/core/visualization/gnuplot.hh>
#include <roboptim/core/visualization/gnuplot-function.hh>

using namespace roboptim;
using namespace roboptim::visualization;
using namespace roboptim::visualization::gnuplot;
using namespace roboptim::trajectory;
using namespace roboptim::trajectory::visualization;
using namespace roboptim::trajectory::visualization::gnuplot;

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
  gnuplot << plot_xy (spline);
  std::cout << gnuplot << std::endl;

  // create a free time trajectory from the original one
  FreeTimeTrajectory<CubicBSpline> freeTime (spline, 1.);

  std::cerr
    << "free time trajectory (5, scale = 1): "
    << freeTime (5.) << std::endl;

  FreeTimeTrajectory<CubicBSpline>::vector_t tmp = freeTime.parameters ();
  tmp[0] = 2.;
  freeTime.setParameters (tmp);

  std::cerr
    << "free time trajectory (5, scale = 2): "
    << freeTime (5.) << std::endl
    << "spline (.5 * tMax): "
    << spline (.5 * tMax) << std::endl
    << "free time trajectory (.5 * tMax): "
    <<  freeTime (.5 * tMax) << std::endl;
}
