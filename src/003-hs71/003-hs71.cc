#include <stdexcept>

#include <boost/shared_ptr.hpp>

#include <roboptim/core/twice-differentiable-function.hh>
#include <roboptim/core/io.hh>
#include <roboptim/core/solver.hh>
#include <roboptim/core/solver-factory.hh>

using namespace roboptim;

# define FIXME_IMPLEMENT_ME() \
  throw std::runtime_error ("please implement me")


struct F
{
  // FIXME: please implement me!
};

struct G0
{
  // FIXME: please implement me!
};

struct G1 : public TwiceDifferentiableFunction
{
  // FIXME: please implement me!
};

int main ()
{
  // Hint: this is the type of your solver.
  typedef Solver<
    DifferentiableFunction,    // cost function
    boost::mpl::vector<
      LinearFunction,          // constraint type 1
      DifferentiableFunction   // constraint type 2
      >
    > solver_t;

  // Hint: this is the type of your problem.
  typedef solver_t::problem_t problem_t;

  FIXME_IMPLEMENT_ME ();
}
