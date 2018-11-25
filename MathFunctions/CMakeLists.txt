add_library(MathFunctions SHARED add.cpp)

include(GenerateExportHeader)

GENERATE_EXPORT_HEADER(MathFunctions
    BASE_NAME shared
    EXPORT_MACRO_NAME shared_EXPORTS
    EXPORT_FILE_NAME shared_EXPORTS.h
    STATIC_DEFINE SHARED_EXPORTS_BUILT_AS_STATIC
)

install(TARGETS MathFunctions DESTINATION bin)
install(FILES add.h DESTINATION include)