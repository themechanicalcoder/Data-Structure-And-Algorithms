import socket
import os
import time

HOST = '127.0.0.1'
PORT = 65432

with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as s:
    s.connect((HOST, PORT))

    command = input()
    s.sendall(command.encode())
    while True:
        data = s.recv(1024)
        print(data.decode())

print('Received', repr(data))
