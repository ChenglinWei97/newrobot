import serial.tools.list_ports
print("\n\n\n********************")
print("Start programm")
print("********************")

ports = list(serial.tools.list_ports.comports())
Arduino_ports=[]
for p in ports:
    if 'Arduino' in p.description:
        Arduino_ports.append(p)
if len(Arduino_ports)==0:
    print("no Arduino board detected")
    
if len(Arduino_ports) > 1:
    print('Multiple Arduinos found - using the first')
else:
    print("Arduino board detected")

if len(Arduino_ports) >= 1:
  print(Arduino_ports[0].device)
  arduino=serial.Serial(Arduino_ports[0].device,9600)

  print(arduino.readline())
  arduino.close()
