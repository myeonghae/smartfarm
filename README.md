# smartfarm

#카메라 스트리밍
# 업데이트, 업그레이드
sudo apt-get update
sudo apt-get upgrade

# 새로운 디렉토리에서 mjpg 클론
mkdir mjpg
cd ./mjpg
git clone https://github.com/jacksonliam/mjpg-streamer.git

cd mjpg-streamer/
cd mjpg-streamer-experimental/
sudo apt-get install cmake
sudo apt-get install python-imaging
sudo apt-get install libjpeg-dev

make CMAKE_BUILD_TYPE=Debug
sudo make install
cd ~

# mjpg 실행, 자세한 것은 mjpg 옵션 참고
mjpg_streamer -i "input_raspicam.so -vf" -o "output_http.so -p 8090 -w /usr/local/share/mjpg-streamer/www/"

#자신의ip주소:8090 접속 
