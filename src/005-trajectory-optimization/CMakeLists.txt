ADD_EXECUTABLE(005-trajectory-optimization 005-trajectory-optimization.cc)
PKG_CONFIG_USE_DEPENDENCY(005-trajectory-optimization roboptim-core)
PKG_CONFIG_USE_DEPENDENCY(005-trajectory-optimization roboptim-trajectory)
