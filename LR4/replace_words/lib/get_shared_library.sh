g++ -c src/utils.cpp src/data_reader.cpp src/convert_text.cpp -fpic
g++ *.o -shared -o lib_convert_text.so
sudo cp lib_convert_text.so /usr/lib/
