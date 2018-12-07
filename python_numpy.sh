set MKL_NUM_THREADS=1
python -c "import ctypes; mkl_rt = ctypes.CDLL('mkl_rt.dll'); print mkl_rt.mkl_get_max_threads()"
