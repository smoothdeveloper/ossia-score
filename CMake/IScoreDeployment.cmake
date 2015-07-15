if(NOT DEPLOYMENT_BUILD)
    return()
endif()

set(JAMOMA_LIBS "Score;Modular;Foundation;DSP")
set(JAMOMA_PLUGINS "MIDI;Minuit;OSC;Automation;Scenario;Interval;Loop;AnalysisLib;DataspaceLib;FunctionLib;System;NetworkLib")

# TODO use git tags
set(CPACK_PACKAGE_NAME "i-score")
set(CPACK_PACKAGE_VENDOR "i-score")
set(CPACK_PACKAGE_DESCRIPTION_SUMMARY "An intermedia sequencer for the precise and flexible scripting of interactive scenarios.")
set(CPACK_PACKAGE_VERSION "0.3.0")
set(CPACK_PACKAGE_VERSION_MAJOR "0")
set(CPACK_PACKAGE_VERSION_MINOR "3")
set(CPACK_SOURCE_GENERATOR TGZ)
set(CPACK_SOURCE_PACKAGE_FILE_NAME "i-score")

if(${CMAKE_SYSTEM_NAME} MATCHES "Darwin")
include(CMake/IScoreDeploymentOSX.cmake)
elseif(${CMAKE_SYSTEM_NAME} MATCHES "Android")
include(CMake/IScoreDeploymentAndroid.cmake)
elseif(${CMAKE_SYSTEM_NAME} MATCHES "Linux")
include(CMake/IScoreDeploymentLinux.cmake)
elseif(${CMAKE_SYSTEM_NAME} MATCHES "Windows")
include(CMake/IScoreDeploymentWindows.cmake)
endif()


include(CPack)
