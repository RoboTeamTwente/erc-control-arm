add_library(control_arm::stm_automatic ${CMAKE_CURRENT_SOURCE_DIR}/control_arm_ert_rtw/control_arm.c)
add_library(control_arm::stm_manual ${CMAKE_CURRENT_SOURCE_DIR}/control_arm_manual_ert_rtw/control_arm_manual.c)
add_library(control_arm::webots_manual ${CMAKE_CURRENT_SOURCE_DIR}/control_arm_manual_webots_ert_rtw/control_arm_manual_webots.c)
