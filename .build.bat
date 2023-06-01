cmake -S . -B build "-DCMAKE_TOOLCHAIN_FILE=C:/Users/pozoy/vcpkg/scripts/buildsystems/vcpkg.cmake" -DCMAKE_PREFIX_PATH="C:\Users\pozoy\vcpkg\buildtrees\opencv2\src\4.7.0-87379d1df6.clean\include\opencv2"
cmake --build ./build --config Release
