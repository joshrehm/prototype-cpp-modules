include(StandardOptions)

opt(MODULE_LIB_OUTPUT_PATH STRING
    "${PROJECT_OUTPUT_PATH}" 
    "Default output path for compiled module-lib binaries.")

opt(MODULE_LIB_ENABLE_TESTS BOOL OFF
    "Build module-lib unit tests")

opt(MODULE_LIB_RUN_TESTS_ON_BUILD BOOL OFF
    "Run module-lib unit tests on build")

opt(MODULE_LIB_ENABLE_CPPCHECK BOOL ON
    "Enable CppCheck static code analysis for module-lib")

opt(MODULE_LIB_WARNINGS_AS_ERRORS BOOL ${WARNINGS_AS_ERRORS}
    "Treat module-lib project compiler warnings as compiler errors")
