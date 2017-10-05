FLAGS = [
    '-Werror',
    '-Weverything',
    '-fexceptions',
    '-std=c99',
    '-x', 'c',
]


def FlagsForFile(filename, **kwargs):
  return {
    'flags': FLAGS,
  }
