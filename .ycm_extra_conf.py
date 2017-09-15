"""
YCM config file for C-family semantic completion

"""


def FlagsForFile(filename, **kwargs):
    """
    Tells YCM what flags to pass to libclang for code analysis and
    completion

    """
    return {'flags': ['-x', 'c++',  # Language is c++
                      '-std=c++11',  # Standard is C++ 11
                      '-Wall',  # All warnings
                      '-Wextra',  # Plus extra
                      '-Werror',  # Plus errors
                      ],
            }
