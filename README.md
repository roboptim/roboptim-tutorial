roboptim-tutorial
=================

This repository contains exercises to learn how to use RobOptim. They
are ordered by difficulty so please try to go through them in the
suggested order.


How to use the tutorials?
-------------------------

To go though the tutorials, please first fork this repository (log in
/ create your GitHub acount if necessary).

Then, clone your fork on your local machine:

    $ git clone --recursive git@github.com:your_username/roboptim-tutorial.git

If you do not want to create a fork on GitHub, you can simply clone the official repository:

    $ git clone --recursive https://github.com/roboptim/roboptim-tutorial.git

Once this is done, compile this repository like you would compile any
other RobOptim package:

    $ mkdir _build
    $ cd _build
    $ cmake ..
    $ make

The code should compile but all the examples will fail! This is
normal, now you have to implement each exercise.

In each exerise directory, the README.md file describe what is
expected from you in this exercise and what result you should obtain.

Try to implement what you can and if you are stuck, you can always ask
for help on the support group:

https://groups.google.com/forum/#!forum/roboptim


Exercises
---------

 * [The first step: implementing your own function][ex1]
 * [Playing with RobOptim operators][ex2]
 * [Implementing a simple optimization problem][ex3]
 * [RobOptim Trajectory and the parametrized curves][ex4]
 * [Spline optimization][ex5]

 [ex1]: https://github.com/roboptim/roboptim-tutorial/tree/master/src/001-function
 [ex2]: https://github.com/roboptim/roboptim-tutorial/tree/master/src/002-operator
 [ex3]: https://github.com/roboptim/roboptim-tutorial/tree/master/src/003-hs71
 [ex4]: https://github.com/roboptim/roboptim-tutorial/tree/master/src/004-bspline
 [ex5]: https://github.com/roboptim/roboptim-tutorial/tree/master/src/005-trajectory-optimization


For cheaters: checking up the solutions
---------------------------------------

Solutions are available in a different branch called "answers". Once
you are done implementing the exercises, take a look at the reference
implementation!
