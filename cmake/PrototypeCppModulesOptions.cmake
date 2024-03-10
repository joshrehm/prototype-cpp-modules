include(StandardOptions)

opt(PROTOTYPE_CPP_MODULES_OUTPUT_PATH STRING
    "${PROJECT_OUTPUT_PATH}" 
    "Default output path for compiled prototype-cpp-modules binaries.")

opt(PROTOTYPE_CPP_MODULES_ENABLE_TESTS BOOL OFF
    "Build prototype-cpp-modules unit tests")

opt(PROTOTYPE_CPP_MODULES_RUN_TESTS_ON_BUILD BOOL OFF
    "Run prototype-cpp-modules unit tests on build")

opt(PROTOTYPE_CPP_MODULES_ENABLE_CPPCHECK BOOL ON
    "Enable CppCheck static code analysis for prototype-cpp-modules")

opt(PROTOTYPE_CPP_MODULES_WARNINGS_AS_ERRORS BOOL ${WARNINGS_AS_ERRORS}
    "Treat prototype-cpp-modules project compiler warnings as compiler errors")
