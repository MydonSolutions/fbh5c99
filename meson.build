project('fbh5c99', 'c',
  version: '0.1.0',
  default_options: [
    'c_std=c99',
    'buildtype=release',
    'b_ndebug=if-release'
  ]
)

cc = meson.get_compiler('c')
m_dep = cc.find_library('m', required : true)

src_lst = []
inc_lst = [
	include_directories('include'),
]
dep_lst = [
  m_dep,
  dependency('hdf5'),
  subproject('h5dsc99').get_variable('lib_h5ds_dep'),
]

subdir('include')
subdir('src')

lib_fbh5 = library(
  'fbh5',
  src_lst,
  include_directories: inc_lst,
  dependencies: dep_lst,
  install: true,
)

lib_fbh5_dep = declare_dependency(
  include_directories: inc_lst,
  dependencies: dep_lst,
  link_with: lib_fbh5,
)

subdir('tests')
