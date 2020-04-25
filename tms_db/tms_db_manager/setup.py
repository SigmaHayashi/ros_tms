<<<<<<< HEAD
# ! DO NOT MANUALLY INVOKE THIS setup.py, USE CATKIN INSTEAD
=======
## ! DO NOT MANUALLY INVOKE THIS setup.py, USE CATKIN INSTEAD
>>>>>>> 51ecc3540900cfe208d8c2ca1ecaf2184d407ca7

from distutils.core import setup
from catkin_pkg.python_setup import generate_distutils_setup

# fetch values from package.xml
setup_args = generate_distutils_setup(
    packages=['tms_db_manager'],
    package_dir={'': 'src'})

setup(**setup_args)
