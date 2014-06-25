003-hs71
========

The goal is to implement and solve a small optimization problem.

This problem is the 71th problem of the Hock-Schittkowski-Collection
and is defined as:

![Optimization Problem](doc/problem.png)

...under the following constraints:

![Optimization Problem](doc/constraints.png)

Step 1: Implement the cost function
-----------------------------------

Implement the cost function `F` by defining a function the same way than
in exercise 1.

The main difference is that now you have to implement a
`DifferentiableFunction` and not a `Function` which means you also
have to provide a way to compute the gradient.


Step 2: Implement the constraints
---------------------------------

Similarly, implement the constraints `G0` and `G1` corresponing to the
first two constraints.

The third constraint only put bounds on the optimization variables and
will be handled during problem instantiation.


Step 3: Create the problem
--------------------------

Instantiate the problem. Add the two necessary constraints. Display
the problem to check that everything is working fine.


Step 4: Solve it
----------------

Instiate a solver factory, a solver and solve the problem. Display the
solver object after solving the problem.


Executing the command `./003-hs71` should give you the following
output:


    Solver:
      Plugin: cfsqp
      Problem:
        x₀ * x₃ * (x₀ + x₁ + x₂) + x₂ (differentiable function)
        Argument's bounds: (1, 5), (1, 5), (1, 5), (1, 5)
        Argument's scales: 1, 1, 1, 1
        Number of constraints: 2
        Constraint 0
            x₀ * x₁ * x₂ * x₃ (differentiable function)
            Bounds: (25, inf)
            Scales: 1
        Constraint 1
            x₀² + x₁² + x₂² + x₃² (differentiable function)
            Bounds: (40, 40)
            Scales: 1
        No starting point.
        Infinity value (for all functions): inf
      Result:
        Result:
          Size (input, output): 4, 1
          X: [4](1,4.743,3.82115,1.37941)
          Value: [1](17.014)
          Constraints values: [2](25,40)
          Lambda: [2](0.161469,1)
      Parameters:
        cfsqp.bigbnd (symbolizes infinity): 1e+10
        cfsqp.eps (final norm requirement for the Newton direction): 1e-08
        cfsqp.epseqn (maximum violation of nonlinear equality constraint): 1e-08
        cfsqp.gLgeps (N/A): 0
        cfsqp.iprint (logging level): 0
        cfsqp.mode (CFSQP mode): 100
        cfsqp.nstop (N/A): 0
        cfsqp.objeps (N/A): 0
        cfsqp.objrep (N/A): 0
        cfsqp.udelta (perturbation size used in CFSQP finite differences algorithm): 1e-08
        max-iterations (number of iterations): 3000

      CFSQP specific variables:
        Nineq: 1
        Nineqn: 1
        Neq: 1
        Neqn: 1
        CFSQP constraints: ((0, 0), 1), ((1, 0), 1)
    A solution has been found:
    Result:
      Size (input, output): 4, 1
      X: [4](1,4.743,3.82115,1.37941)
      Value: [1](17.014)
      Constraints values: [2](25,40)
      Lambda: [2](0.161469,1)



[← Prev][ex2] | [Home][main] | [Next →][ex4]

 [main]: https://github.com/roboptim/roboptim-tutorial/
 [ex2]: https://github.com/roboptim/roboptim-tutorial/tree/master/src/002-filter
 [ex4]: https://github.com/roboptim/roboptim-tutorial/tree/master/src/004-bspline
