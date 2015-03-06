#include <boost/make_shared.hpp>

#include <roboptim/core/linear-function.hh>
#include <roboptim/core/differentiable-function.hh>
#include <roboptim/core/problem.hh>
#include <roboptim/core/solver.hh>
#include <roboptim/core/solver-factory.hh>

#include <roboptim/trajectory/cubic-b-spline.hh>
#include <roboptim/trajectory/state-function.hh>
#include <roboptim/trajectory/visualization/trajectory.hh>

using namespace roboptim;
using namespace roboptim::visualization;
using namespace roboptim::visualization::gnuplot;
using namespace roboptim::trajectory;
using namespace roboptim::trajectory::visualization;
using namespace roboptim::trajectory::visualization::gnuplot;


// Define a solver type.
//
// Cost: Differentiable Function (gradient computations but no hessian)
// Constraint: Differentiable Function or Linear Function
typedef Solver<
  DifferentiableFunction,    // cost function
  boost::mpl::vector<
    LinearFunction,          // constraint type 1
    DifferentiableFunction   // constraint type 2
    >
  > solver_t;

class Cost : public DifferentiableFunction
{
public:
  Cost ()
    // input size, output size, description
    : DifferentiableFunction (2 * 10, 1, "the cost function")
  {}

  ~Cost ()
  {}

private:

  // result = f(x)
  virtual void impl_compute (result_ref result, const_argument_ref /* x */) const
  {
    result[0] = 42.;
  }

  // grad = f.gradient (x)
  virtual void impl_gradient
  (gradient_ref grad, const_argument_ref /* x */, size_type /* i */) const
  {
    // put all the elements to zero
    grad.setZero ();
  }
};

class Constraint : public DifferentiableFunction
{
public:
  Constraint ()
    // input size, output size, description
    : DifferentiableFunction (2, 1, "the constraint")
  {}

  ~Constraint ()
  {}

private:

  // result = f(x)
  virtual void impl_compute (result_ref result, const_argument_ref x) const
  {
    result[0] = x[1];
  }

  // grad = f.gradient (x)
  virtual void impl_gradient
  (gradient_ref grad, const_argument_ref /* x */, size_type /* i */) const
  {
    grad.setZero ();
    grad[1] = 1.;
  }
};

int main ()
{
  // create a spline
  CubicBSpline::interval_t timeRange =
    CubicBSpline::makeInterval (0., 10.);

  CubicBSpline::vector_t parameters (2 * 10);
  parameters =
    CubicBSpline::vector_t::Random (2 * 10) * 10.;

  CubicBSpline spline (timeRange, 2, parameters);

  // display trajectory as Gnuplot data
  Gnuplot gnuplot =
    Gnuplot::make_interactive_gnuplot ();
  gnuplot
    << set ("multiplot layout 2,1")
    << set ("xrange [-10:10]")
    << set ("yrange [-10:10]")
    << set ("title 'Before Optimization'")
    << plot_xy (spline);

  // create the cost function
  Cost cost;

  // evaluate cost function and associated gradient at a particular point x
  std::cerr << cost (spline.parameters ()) << std::endl;
  std::cerr << cost.gradient (spline.parameters ()) << std::endl;

  // create the problem
  solver_t::problem_t problem (cost);

  // add the constraints
  boost::shared_ptr<DifferentiableFunction> constraint =
    boost::make_shared<Constraint> ();
  for (Function::value_type t = 0.; t < 1.; t += .05)
    {
      boost::shared_ptr<StateFunction<CubicBSpline> > stateFunction =
	boost::make_shared<StateFunction<CubicBSpline> >
	(spline, constraint, t * tMax, 0);

      // constraint: define associated interval
      solver_t::problem_t::intervals_t intervals (1);
      intervals[0] = Function::makeInterval (-2.5, 2.5);
      // constraint: ...and scale
      solver_t::problem_t::scales_t scales (1);
      scales[0] = 1.;
      // constraint: add it to the problem
      problem.addConstraint (stateFunction, intervals, scales);
    }

  // define the starting point
  problem.startingPoint () = spline.parameters ();

  // add bounds to one variable
  problem.argumentBounds ()[0] =
    Function::makeInterval (0, 1);

  // creating the solver
  SolverFactory<solver_t> factory ("cfsqp", problem);
  solver_t& solver = factory ();

  // display the solver and problem
  std::cerr << solver << std::endl;

  // solve the problem
  solver.solve ();

  // display the result
  std::cerr << solver.minimum () << std::endl;

  // changing the spline parameters
  switch (solver.minimum ().which ())
    {
    case solver_t::SOLVER_VALUE:
      {
	const Result& result =
	  boost::get<Result> (solver.minimum ());
	// result.x is the final optimization variables values
	spline.setParameters (result.x);
	break;
      }
    case solver_t::SOLVER_VALUE_WARNINGS:
      {
	const ResultWithWarnings& result =
	  boost::get<ResultWithWarnings> (solver.minimum ());
	// result.x is the final optimization variables values
	spline.setParameters (result.x);
	break;
      }
    case solver_t::SOLVER_NO_SOLUTION:
      {
	std::cerr << "A solution should have been found. Failing..."
		  << std::endl
		  << "No solution was found."
		  << std::endl;
	return 1;
      }
    case solver_t::SOLVER_ERROR:
      {
	std::cerr << "A solution should have been found. Failing..."
		  << std::endl
		  << boost::get<SolverError> (solver.minimum ()).what ()
		  << std::endl;
	return 1;
      }
    }

  gnuplot
    << set ("title 'After Optimization'")
    << set ("object 1 rect from -10,-2.5 to 10,2.5 fc rgb \"#cccccc\"")
    << plot_xy (spline)
    << unset ("multiplot");
  std::cout << gnuplot;
  return 0;
}
