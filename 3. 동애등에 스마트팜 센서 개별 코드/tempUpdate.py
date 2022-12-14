import MySQLdb as mydb
import serial
import time
import json

conn = mydb.connect(host='127.0.01',user='hipoper7',password='flute014', db='inhatc', charset = 'utf8')

port = '/dev/ttyACM0';
seri = serial.Serial(port, 9600)
sql = "Select * from inhatc"

print("Start")
print("---------------------------------------")


while(True):
	try:
		sql = "Select * from inhatc"
		with conn.cursor() as cur:
			cur.execute(sql)
			result = cur.fetchall()
			for data in result:
				string = data[1] + "," + data[2] + "," + data[3] + "," + data[6]
				if(data[7] == "true"):
					seri.write(string.encode())
					print("Data Changed")				
					sql = 'Update inhatc Set dataset = "false" where id = 1'
					with conn.cursor() as cur:
						cur.execute(sql)
					conn.commit()
					time.sleep(1)
				
				else :
					print("Working...")
					print("---------------------------------------")
					result = seri.readline()
                    
					result = result.decode()
					result = result.replace("\n","")
					result = result.replace("\r","")
					result = result.split(',')
					sql = 'Update inhatc Set temp="' + result[0] + '", hum="'+result[1] + '" where id = 1'
					with conn.cursor() as cur:
						cur.execute(sql)
						conn.commit()
					time.sleep(1)
				break
	except:
		print("Something Problem...")
		time.sleep(0)
		continue
	
