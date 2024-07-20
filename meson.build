project('rzd', 'cpp')


deps = [
  dependency('libzip')
]

inc = include_directories('include')

src = files(
  'src/main.cpp'
)


executable(meson.project_name(), src, include_directories: inc, dependencies: deps)
