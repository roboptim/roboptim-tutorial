#include <cmath>

#include <boost/make_shared.hpp>

#include <roboptim/core/operator/derivative.hh>
#include <roboptim/core/operator/plus.hh>
#include <roboptim/core/operator/product.hh>
#include <roboptim/core/operator/scalar.hh>

#include <roboptim/core/function/cos.hh>
#include <roboptim/core/function/sin.hh>

#include <roboptim/core/visualization/gnuplot.hh>
#include <roboptim/core/visualization/gnuplot-function.hh>

using namespace roboptim;
using namespace roboptim::visualization;
using namespace roboptim::visualization::gnuplot;

int main()
{
  Gnuplot gnuplot = Gnuplot::make_interactive_gnuplot ();

  discreteInterval_t interval (-10., 10., .1);

  boost::shared_ptr<DifferentiableFunction> cf = boost::make_shared<Cos<EigenMatrixDense> > ();
  boost::shared_ptr<DifferentiableFunction> sf = boost::make_shared<Sin<EigenMatrixDense> > ();

  boost::shared_ptr<DifferentiableFunction> f = .5 * (cf * cf + sf * sf);

  boost::shared_ptr<Function> dsf = derivative (sf, 0);

  std::cout << (gnuplot
		<< set ("multiplot layout 4,1")
		<< set ("yrange [-2:2]")
		<< plot (*cf, interval)
		<< plot (*sf, interval)
		<< plot (*f, interval)
		<< plot (*dsf, interval)
		<< unset ("multiplot"));

  return 0;
}
