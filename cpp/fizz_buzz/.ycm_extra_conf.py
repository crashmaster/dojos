flags = [
'-Wall',
'-Wextra',
'-Werror',
'-std=c++14',
]


def FlagsForFile( filename, **kwargs ):
  return {
    'flags': flags,
    'do_cache': True
  }
