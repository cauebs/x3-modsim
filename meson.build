project('x3-modsim', 'cpp', default_options : ['cpp_std=c++11'])

cxx = meson.get_compiler('cpp')

proportion_test = executable(
    'proportion_test',
    sources : ['tests/proportion.cpp', 'src/statistics.cpp', 'src/proportion.cpp'],
    dependencies : dependency('boost')
)

test('proportion test', proportion_test)

mean_test = executable(
    'mean_test',
    sources : ['tests/mean.cpp', 'src/statistics.cpp', 'src/mean.cpp'],
    dependencies : dependency('boost')
)

test('mean test', mean_test)

variance_test = executable(
    'variance_test',
    sources : ['tests/variance.cpp', 'src/statistics.cpp', 'src/variance.cpp'],
    dependencies : dependency('boost')
)

test('variance test', variance_test)

