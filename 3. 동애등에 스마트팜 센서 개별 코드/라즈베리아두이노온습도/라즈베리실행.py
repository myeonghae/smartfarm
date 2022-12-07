import serial

# 시리얼 포트를 열고, 9600bps로 설정
ser = serial.Serial('/dev/ttyACM0', 9600)
cmd = 'temp'

# 시리얼 포트가 열렸는지 확인
print('시리얼 포트를 열었습니다.' + ser.name)

# 시리얼 포트로 데이터를 쓴다.
ser.write(cmd.encode())

a = 1
# 반복문을 돌면서 시리얼 포트로부터 데이터를 읽는다.
while a:
    # 시리얼 포트로부터 데이터가 들어왔는지 확인
    if ser.in_waiting != 0:
        # 시리얼 포트로부터 데이터를 읽는다.
        data = ser.readline()
        # 읽은 데이터를 출력한다.
        print(data[:-2].decode())
        a = 0