## PackagePathSetting ##
import sys
 
# Replace the value of string variable py_ext_path 
# with the actual Python extension installation path in your computer
 
py_ext_path = "D:\ProgramData\Anaconda3\envs\Origin_Python_Env\Lib\site-packages"
 
if py_ext_path not in sys.path:
    sys.path.append(py_ext_path)
