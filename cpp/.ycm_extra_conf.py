import os
import ycm_core

FLAGS = [
    '-Werror',
    '-Weverything',
    '-fexceptions',
    '-std=c++1y',
    '-x', 'c++',
]


def FlagsForFile(filename, **kwargs):
  return {
    'flags': FLAGS,
  }
