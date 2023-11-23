install(
    TARGETS comp-4300-init_exe
    RUNTIME COMPONENT comp-4300-init_Runtime
)

if(PROJECT_IS_TOP_LEVEL)
  include(CPack)
endif()
