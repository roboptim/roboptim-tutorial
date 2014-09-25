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

# define FIXME_IMPLEMENT_ME() \
  throw std::runtime_error ("please implement me")

// Hint: the solver type.
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

class Cost
{
  //FIXME: implement me!
};


class Constraint
{
  //FIXME: implement me!
};

int main()
{
  FIXME_IMPLEMENT_ME ();
  return 0;
}
