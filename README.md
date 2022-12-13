# smartfarm

#카메라 스트리밍
# 업데이트, 업그레이드
sudo apt-get update
sudo apt-get upgrade

# 새로운 디렉토리에서 mjpg 클론
mkdir mjpg <br/>
cd ./mjpg <br/>
git clone https://github.com/jacksonliam/mjpg-streamer.git <br/>
 <br/>
cd mjpg-streamer/ <br/>
cd mjpg-streamer-experimental/ <br/>
sudo apt-get install cmake <br/>
sudo apt-get install python-imaging <br/>
sudo apt-get install libjpeg-dev <br/>
 <br/>
make CMAKE_BUILD_TYPE=Debug <br/>
sudo make install <br/>
cd ~ <br/>
 <br/>
//mjpg 실행, 자세한 것은 mjpg 옵션 참고 <br/>
mjpg_streamer -i "input_raspicam.so -vf" -o "output_http.so -p 8090 -w /usr/local/share/mjpg-streamer/www/" <br/>
 <br/>
#자신의ip주소:8090 접속  <br/>
