add_requires("catch2")

target("main")
    set_kind("binary")
    add_files("main.cpp")
    add_packages("catch2")