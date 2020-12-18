import socket
import os
import time

HOST = '127.0.0.1'  # Standard loopback interface address (localhost)
PORT = 65432        # Port to listen on (non-privileged ports are > 1023)


def follow(thefile):
    thefile.seek(0, 2)

    while True:
        line = thefile.readline()
        if line:
            yield line
        time.sleep(.3)


with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as s:
    file = open('abcd.txt', 'r')
    s.bind((HOST, PORT))
    s.listen()
    conn, addr = s.accept()
    with conn:
        print('Connected by', addr)
        while True:
            data = conn.recv(1024)
            command = data.decode()
            print('command = {}'.format(command))
            command_list = command.split()
            lines = 0

            if (command_list[0] == 'tailf'):
                for i in follow(file):
                    conn.sendall(i.encode())

            if command_list[0] == 'tail':
                n = int(command_list[1])
                file = open('myfile.txt', 'r')
                Lines = file.readlines()
                print(Lines)
                while n:
                    print(n)
                    print(type(n), Lines[0].encode())

                    conn.sendall(Lines[0].encode())
                    Lines.pop(0)
                    n -= 1
                file.close()
                Lines.clear()

            if not data:
                break
            conn.sendall(data)