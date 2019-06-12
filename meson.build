project('x3-modsim', 'cpp', default_options : ['cpp_std=c++11'])

cxx = meson.get_compiler('cpp')
boost_dep = [
]

src = ['tests.cpp', 'statistics.cpp']

executable('tests', sources : src, dependencies : boost_dep)
